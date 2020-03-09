#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
    public:
        Entity();
        virtual ~Entity();
        virtual void update() = 0;

    private:
};

#endif // ENTITY_H
