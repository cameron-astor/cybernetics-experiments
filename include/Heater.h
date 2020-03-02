#ifndef HEATER_H
#define HEATER_H


class Heater
{
    public:
        Heater();
        ~Heater();
        void update();

    private:
        int pwrSetting;
        double pwrConsumption;

};

#endif // HEATER_H
