#include <iostream>
#include "PhysicsWorld.h"

void say_hello()
{
    std::cout << "Hello, from physics_engine!\n";
}

void PhysicsWorld::Step(double dt)
{
    for (Object *obj : m_objects)
    {                                          // We are practically saying that for each pointer in the m_object vector to pointers, do the following stuff
        obj->Force += (obj->Mass * m_gravity); // apply a force to the object, using equation F=ma

        obj->Velocity += obj->Force / obj->Mass * dt;
        obj->Position += obj->Velocity * dt;

        obj->Force << 0, 0, 0; // reset net force at the end
    }
}