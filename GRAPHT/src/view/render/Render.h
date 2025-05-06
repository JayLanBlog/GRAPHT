#pragma once
#include "data/model/Model.h"
#include "data/shader/Shader.h"
namespace GRAPHT {
	class RenderData {
	public:
		RenderData() {};
	};
	struct ModeData
	{
		ModeData(Mesh mesh) {
		//	setupAndGerateDataByMesh(mesh);
		}
		unsigned int VBO, EBO;
		unsigned int VAO;
		vector<GLTexture> textures;
		vector<unsigned int> indices;
		void setupAndGerateDataByMesh(Mesh  mesh);
		
		void Draw(Shader * shader);
	};
	

	class Render {
	public:
		Render() {};
		//Shader
		Render(Shader* sd):shader(sd) {
		
		};

		Shader* shader;
	};


	class ModelRender : public Render {
	public:
		vector<ModeData> modelDataList;

		ModelRender(Shader* sd) :Render(sd) {}

		ModelRender(Shader* sd,Model* model) :Render(sd) {
			for (int i = 0; i < model->meshes.size(); i++) {
				modelDataList.push_back(* new ModeData(model->meshes[i]));
			}
			
		}

		void Draw() {
			for (int i = 0; i < modelDataList.size(); i++) {
				modelDataList[i].Draw(shader);
			}
		
		}

	};


}