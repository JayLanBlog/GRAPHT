#pragma once
#include "data/model/Model.h"
#include "data/shader/Shader.h"
#include "glad/glad.h"
namespace GRAPHT {
	class RenderData {
	public:
		RenderData() {};
	};
	struct ModeData
	{
		ModeData(Mesh mesh) {
			setupAndGerateDataByMesh(mesh);
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

	class TGLRender :public Render {
	public:
		TGLRender(Shader* sd) :Render(sd) {}

		void initData() {
			float vertices[] = {
	   -0.5f, -0.5f, 0.0f, // left  
		0.5f, -0.5f, 0.0f, // right 
		0.0f,  0.5f, 0.0f  // top   
			};

			unsigned int VBO;
			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
			glBindVertexArray(VAO);

			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);

			// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
			glBindBuffer(GL_ARRAY_BUFFER, 0);

			// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
			// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
			glBindVertexArray(0);

		}

		void Draw() {
			
			shader->use();

			glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
			glDrawArrays(GL_TRIANGLES, 0, 3);

		}

		unsigned int  VAO;

	};


	class ModelRender : public Render {
	public:
		vector<ModeData> modelDataList;

		ModelRender(Shader* sd) :Render(sd) {}

		ModelRender(Shader* sd,Model* model) :Render(sd) {
			for (int i = 0; i < model->meshes.size(); i++) {
				std::cout << "current model idx" << i << std::endl;
 				modelDataList.push_back(* new ModeData(model->meshes[i]));
			}
			int a = 0;
		}

		void Draw() {
			glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			for (int i = 0; i < modelDataList.size(); i++) {
				modelDataList[i].Draw(shader);
			}
		
		}

	};


}