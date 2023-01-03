#include <stdio.h>
#include <tchar.h>
#include "SerialClass.h"	// Library described above
#include <string>
#include <iostream>
#include <fstream>

#include "ArduinoJson-v6.20.0.h"


// application reads from the specified serial port and reports the collected data
int main()
{
	printf("Welcome to the serial test app!\n\n");

	Serial* SP = new Serial("COM3");    // adjust as needed

	if (SP->IsConnected())
		printf("We're connected \n");

	char incomingData[200] = "";		// don't forget to pre-allocate memory
	int dataLength = 200;
	int readResult = 0;

	ArduinoJson::StaticJsonDocument<200> doc;

	int iteration = 0;

	while (SP->IsConnected())
	{
		iteration++;

		readResult = SP->ReadData(incomingData, dataLength);
//		printf("Bytes read: (0 means no data available) %i\n", readResult);
//		incomingData[readResult] = 0;
//		std::string output(incomingData);
//		std::cout << std::stof(output) << "\n";
//		std::cout << incomingData << "\n";
		

		ArduinoJson::DeserializationError error = ArduinoJson::deserializeJson(doc, incomingData);
		if (error) {
			//std::cout << error.c_str() << "\n";
			continue;
		}
		const char* sensorName = doc["sensor"];
		double reading = doc["value"];
		if (sensorName)
		{
			std::cout << "Reading: " << iteration << " -> Sensor: " << sensorName << " -> Value: " << reading << "\n";
		}

		Sleep(1000);
	}

	return 0;
}