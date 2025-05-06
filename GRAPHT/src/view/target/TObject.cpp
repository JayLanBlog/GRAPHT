#include "TObject.h"

namespace GRAPHT {

	
	void ActorT::init() {
		shader = new GLShader("E:/WorkLearn/FrameWork/GRAPHT/GRAPHT/resource/shader/1.model_loading.vs", "E:/WorkLearn/FrameWork/GRAPHT/GRAPHT/resource/shader/1.model_loading.fs");
	//	shader->generate();
		MaterailManager* manager = MaterailManager::getManager();
		Model* model = &manager->models[0];
		render = new ModelRender(shader, model);
		camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));

	}

	void ActorT::paramInit() {
		shader->use();
		projection = glm::perspective(glm::radians(camera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		glm::mat4 view = camera->GetViewMatrix();
		shader->setMat4("projection", projection);
		shader->setMat4("view", view);
		glm::mat4 modelM = glm::mat4(1.0f);
		modelM = glm::translate(modelM, glm::vec3(0.0f, 0.0f, 0.0f));
		modelM = glm::scale(modelM, glm::vec3(1.0f, 1.0f, 1.0f));
		shader->setMat4("model", modelM);
	}

	void ActorT::Draw() {
		render->Draw();
	}

}