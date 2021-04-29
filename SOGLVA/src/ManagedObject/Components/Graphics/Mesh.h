#pragma once

#ifndef MESH_H
#define MESH_H

#include <glm/gtc/matrix_transform.hpp>

#include "shader.h"
#include "stb_image.h"

/// \cond
#include <vector>
#include <string>
/// \endcond

struct Texture {
    unsigned int id;
    std::string type;
    std::string path;
};

unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma = false);

struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
};

class Mesh {
public:
    // mesh Data
    std::vector<Vertex>       vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture>      textures;
    unsigned int VAO;

    // constructor
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);

    // render the mesh
    void Draw(Shader& shader);

private:
    // render data 
    unsigned int VBO, EBO;

    // initializes all the buffer objects/arrays
    void setupMesh();
};

#endif