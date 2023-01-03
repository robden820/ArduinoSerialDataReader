# ArduinoSerialDataReader
Reading serial data from Arduino into a C++ program.

Current Progress:
  -> Using C++ Serial Communication code from https://playground.arduino.cc/Interfacing/CPPWindows/
  -> Makes use of ArduinoJson library from https://arduinojson.org/


Known Issues:
  -> Some kind of sync issue between Arduino code and C++. Can't read data every loop iteration.
  -> Delay between analog read update and C++ read update.
