#pragma once
#include <data/texture/Texture.h>
#include <string>
#include <vector>
using namespace std;
#define MAX_BONE_INFLUENCE 4
namespace GRAPHT {

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
        //bone indexes which will influence this vertex
        int m_BoneIDs[MAX_BONE_INFLUENCE];
        //weights from each bone
        float m_Weights[MAX_BONE_INFLUENCE];
    };

	class Mesh {

    public:
        vector<Vertex>       vertices;
        vector<unsigned int> indices;
        vector<Texture>      textures;
        // constructor
        Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures) {
            this->vertices = vertices;
            this->indices = indices;
            this->textures = textures;
            // now that we have all the required data, set the vertex buffers and its attribute pointers.
           // setupMesh();
        }

	};

    



}