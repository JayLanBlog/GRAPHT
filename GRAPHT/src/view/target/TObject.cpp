#include "TObject.h"
#include "glad/glad.h"
namespace GRAPHT {

	
	void ActorT::init() {
		shader = new GLShader("E:/WorkLearn/FrameWork/GRAPHT/GRAPHT/resource/shader/hello.vs", "E:/WorkLearn/FrameWork/GRAPHT/GRAPHT/resource/shader/hello.fs");
	//	shader->generate();
	//	MaterailManager* manager = MaterailManager::getManager();
		//Model* model = &manager->models[0];
		//render = new ModelRender(shader, model);
		//camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));
		render = new TGLRender(shader);
		render->initData();

	}

	void ActorT::paramInit() {
		
		glEnable(GL_DEPTH_TEST);

	}

	void ActorT::Draw() {
		render->Draw();
	}

}