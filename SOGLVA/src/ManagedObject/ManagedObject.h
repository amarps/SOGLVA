#pragma once

#include "Components/IComponent.h"

#include "Components/Camera.h"
#include "Components/Transform.h"
#include "Components/Graphics/Mesh.h"
#include "Components/Graphics/Model.h"
#include "Components/Graphics/Shader.h"

#include <map>
#include <typeinfo>

class ManagedObject
{
private:
    std::map<std::string, IComponent*> components;

public:
    std::string name;

    void AddComponent(IComponent* component)
    {
        components[typeid(*component).name()] = component;
    }

    IComponent* GetComponent(IComponent* component)
    {
        std::string tName = typeid(component).name();
        return components[tName];
    }

    ManagedObject(std::string name = "Default Object")
    {
    }

    ~ManagedObject();


    void Update();
};
