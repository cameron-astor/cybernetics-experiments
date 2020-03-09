#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <Entity.h>

class Appliance : public Entity
{
    public:
        Appliance();
        virtual ~Appliance();
        virtual void update() = 0;

    protected:
        int wattage;
};

#endif // APPLIANCE_H
