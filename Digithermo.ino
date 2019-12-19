
// Beware of bugs in the code; I have only proved it correct, not tried it.

#include <TimerOne.h>
#include <DallasTemperature.h>
#include <OneWire.h>

const uint8_t numbers[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6f };
const uint8_t letter_E = 0x79;
const uint8_t letter_r = 0x50;
const uint8_t symbol_minus = 0x40;

const uint8_t digit2pin[4] = { 16, 19, 18, 17 };
const uint8_t SENSOR_PIN = 2;
uint8_t active = 0;
uint8_t digit = 0;
volatile int16_t temperature;
volatile bool sensorError = false;

OneWire wire(SENSOR_PIN);
DallasTemperature sensors(&wire);

void setup()
{
	DDRB = 0xFF; //set PB0 - PB6 as Output
	DDRC = 0xFF; //set PC2 - PC5 as Output

	Timer1.initialize(5000);
	Timer1.attachInterrupt(displayMultiplex);	
	selftest();
	sensors.begin();
}

void loop()
{
	//wait for sensor to connect
	while (!sensors.requestTemperaturesByIndex(0)) {
		sensorError = true;
		delay(1000);
	}
	sensorError = false;
	noInterrupts();
	temperature = (int16_t)(sensors.getTempCByIndex(0) * 10.0);
	interrupts();
	delay(1000);
}

void selftest() {
	//7-segment display selftest
	uint8_t i = 10;
	while (i-- > 0) {
		temperature = 1111 * i;
		delay(50000);
	}
}


void displayMultiplex() {
	digitalWrite(digit2pin[active], LOW);  //disable last digit
	active = (active == 3) ? 0 : active + 1; //go to next digit
	digitalWrite(digit2pin[active], HIGH); //enable next digit
	PORTB = 0;
	if (!sensorError) {

		if (temperature < 0 && active == 3) {
			PORTB = symbol_minus;
		}
		else if (abs(temperature) < pow(10, active) && active > 1){  //don't display leading zero
			PORTB = 0;
		} else {
			digit = abs(temperature) / pow(10, active) % 10;  //get number to display on active digit
			PORTB = numbers[digit];  //Set I/Os for digit
		}
	} else {
		//display Err 
		switch (active) {
		case 0:
			PORTB = 0x00; //Digit off			
			break;
		case 3:
			PORTB = letter_E;
			break;
		case 2:
		case 1:
			PORTB = letter_r;
			break;
		}
	}
}

int32_t pow(int base, int exp) {
	int32_t result = 1;
	for (;;) {
		if (exp & 1)
			result *= base;
		exp >>= 1;
		if (!exp)
			break;
		base *= base;
	}

	return result;
}
