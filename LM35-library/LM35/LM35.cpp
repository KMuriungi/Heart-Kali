#include "LM35.h"

LM35::LM35(int pin) : _pin(pin) {
	pinMode(pin, OUTPUT);
}

LM35::~LM35(){ }

double LM35::read() {
	int sensorValue = analogRead(_pin);
	double temperature = (sensorValue * 0.48875855);
	return temperature;
}

double LM35::read(int times) {
	int sum = 0;

	for (int i = 0; i < times; i++) sum += analogRead(_pin);

	double average = (sum * 0.48875855) / times;
	return average;
}