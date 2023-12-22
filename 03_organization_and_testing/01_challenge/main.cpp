#include <iostream>
// #include "temp_sensor.h"

namespace Sensor {
    float readTemperature();
}

int main() {
    std::cout << "Temperature reading: " << Sensor::readTemperature() << std::endl;
    return 0;
}