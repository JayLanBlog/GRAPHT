#pragma once
#include <data/model/Mesh.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

namespace GRAPHT {

	class Model {
	public:
		int modelID;
		//vector<Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
		vector<Mesh>    meshes;
		string directory;
		bool gammaCorrection;
		Model(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures) {
			meshes.push_back({ vertices ,indices ,textures });
		}

		Model() {
			
		}
		void pushToMeshList(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures) {
			meshes.push_back({ vertices ,indices ,textures });
		}
	};
	
	
	
};