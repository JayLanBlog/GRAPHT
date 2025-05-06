#pragma once
#include "data/model/Model.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
namespace GRAPHT {
	class MaterialLoaderProxy {
	public:
		string modlePath;
		vector<Texture> textures_loaded;
		MaterialLoaderProxy(string path):modlePath(path) {
		
		}

		virtual Model* laodModelFromPath(string const& path) = 0;
	};

	class AssimpLoaderProxy : public MaterialLoaderProxy {
	public:
		AssimpLoaderProxy(string path) :MaterialLoaderProxy(path) {
			//laodModelFromPath(path);
		}
		virtual Model* laodModelFromPath(string const& path);

		Model* process(aiNode* node, const aiScene* scene);

		void processNode(Model *model,aiNode* node,const aiScene* scene);

		Mesh processMesh(aiMesh* mesh, const aiScene* scene);

		vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);

	};

	class MaterailManager {
	private:
		
		MaterialLoaderProxy* proxy;

		MaterailManager() {
			cout << "MaterailManager Construct "  << endl;
			string path = "resource/obj/backpack/backpack.obj";
			proxy = new AssimpLoaderProxy(path);
			Model * model = proxy->laodModelFromPath(path);
			model->modelID = count++;
			modelDict[path] = model->modelID;
			models.push_back(*model);
		}
	public:
		
		vector<Model> models;
		map<string, int> modelDict;
		//map<int, Model> modelIndexDict;
		int count = 0;
		static MaterailManager* getManager() {
			if (!manager) {
				manager = new MaterailManager();
			}
			return manager;
		}
		//Model* laodModelFromAssmip(string const& path);
		static MaterailManager* manager;
	private:
		
	};
	 

}