#pragma once
#include "../Graphics/Shader.h"
#include "../Transform.h"
#include "../IComponent.h"


class Lighting : public IComponent
{
public:
    // model data 
    Transform transform;

    // shader
    Shader shader;

    // draws the model, and thus all its meshes
    void Draw(Shader& shader);

    virtual void Start() override;

    virtual void Update() override;

    virtual void Exit() override;

private:


};