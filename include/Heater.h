#ifndef HEATER_H
#define HEATER_H

#include <Appliance.h>

class Heater : public Appliance
{
    public:
        Heater();
        ~Heater();
        void update();

    private:
        int pwrSetting;

};

#endif // HEATER_H
