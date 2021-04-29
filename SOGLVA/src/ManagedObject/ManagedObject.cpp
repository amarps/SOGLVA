#include "ManagedObject.h"


ManagedObject::~ManagedObject()
{
    for (auto& iComponent : components)
    {
        delete iComponent.second;
    }
}

void ManagedObject::Update()
{
    for (auto& iComponent : components)
    {
        iComponent.second->Update();
    }
}
