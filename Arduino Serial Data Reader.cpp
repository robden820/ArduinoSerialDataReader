#include <stdio.h>
#include <tchar.h>
#include "SerialClass.h"
#include <string>
#include <iostream>
#include <fstream>

#include "ArduinoJson-v6.20.0.h"


// application reads from the specified serial port and reports the collected data
int main()
{
	std::cout << "Welcome to the serial test app!\n\n" ;

	Serial* SP = new Serial("COM3");    // adjust as needed

	if (SP->IsConnected())
	{
		std::cout << "We're connected \n";
	}
		
	char incomingData[200] = "";		// don't forget to pre-allocate memory
	int dataLength = 200;
	int readResult = 0;

	ArduinoJson::StaticJsonDocument<200> doc;

	int iteration = 0;

	while (SP->IsConnected())
	{
		iteration++;

		readResult = SP->ReadData(incomingData, dataLength);
		incomingData[readResult] = 0;
		
		ArduinoJson::DeserializationError error = ArduinoJson::deserializeJson(doc, incomingData);
		if (error) {
			std::cout << error.c_str() << "\n";
			continue;
		}
		const char* sensorName = doc["sensor"];
		double reading = doc["value"];
		double reading2 = doc["value2"];
		if (sensorName)
		{
			std::cout << "Iteration: " << iteration << " -> Sensor: " << sensorName << " -> Value: " << reading << " -> Value 2: " << reading2 << "\n";
		}

		Sleep(1000);
	}

	return 0;
}