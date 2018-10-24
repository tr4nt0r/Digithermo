
// Beware of bugs in the code; I have only proved it correct, not tried it.

#include <TimerOne.h>
#include <DallasTemperature.h>
#include <OneWire.h>

const uint8_t numbers[10] = {
	0b11111100,  //0
	0b01100000,  //1
	0b11011010,  //2
	0b11110010,  //3
	0b01100110,  //4
	0b10110110,  //5
	0b10111110,  //6
	0b11100000,  //7
	0b11111110,  //8
	0b11110110,  //9
};

const uint8_t letter_E = 0b10011110;
const uint8_t letter_r = 0b00001010;
const uint8_t symbol_minus = 0b10000000;

const uint8_t digit2pin[4] = { 16, 19, 18, 17 };
const uint8_t SENSOR_PIN = 2;
uint8_t active = 0;
volatile uint16_t temperature;
volatile bool sensorError = false;

OneWire wire(SENSOR_PIN);
DallasTemperature sensors(&wire);

void setup()
{
	DDRB = 0xFE; //set PB0 - PB6 as Output
	DDRC = 0x3C; //set PC2 - PC5 as Output

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
		delay(100);
	}
	sensorError = false;
	noInterrupts();
	temperature = sensors.getTempCByIndex(0)*10;
	interrupts();
	delay(1000);
}

void selftest() {
	//7-segment display selftest
	uint8_t i = 9;
	while (i --> 0) {
		temperature = 1111 * i;
		delay(500);
	}
}


void displayMultiplex() {
	digitalWrite(digit2pin[active], LOW);  //disable last digit
	active = (active ==  3) ? 0 : active + 1; //go to next digit
	digitalWrite(digit2pin[active], HIGH); //enable next digit

	if (!sensorError) {
		if(temperature < 0 && active == 3) {
			PORTB = symbol_minus;
		} else {
			uint8_t digit = abs(temperature) / pow(10, active + 1) % 10;  //get number to display on active digit
			PORTB = numbers[digit];  //Set I/Os for digit#
		}
	}
	else {
		//display Err 
		switch (active) {
		case 3:
			PORTB = 0; //Digit off			
			break;
		case 2:
			PORTB = letter_E;
			break;
		case 1:
		case 0:
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
