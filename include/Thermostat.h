#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <iostream>
#include <cmath>

// An experiment in cybernetics.
// A thermostat with a range of 40 to 100 degrees.

class Thermostat
{

	public:
		Thermostat();
		~Thermostat();

		void turnDial(double input);
		double getCurrentTarget();
        void readSensor(double temp);
        int getAirconSetting();
        void update();

	private:
		double target;
		double current;
		int airconSetting;
		void calculateAirconSetting();
};

#endif // THERMOSTAT_H
