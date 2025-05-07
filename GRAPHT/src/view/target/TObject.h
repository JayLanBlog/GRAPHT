#pragma once
#include "view/render/Render.h"
#include "module/loader/MaterialManager.h"
#include "module/camera/camera.h"
namespace GRAPHT{
	class ActorT {
	public:
		GLShader* shader;
		//ModelRender* render;
		TGLRender* render;
		glm::mat4 projection;
		Camera* camera;
		const unsigned int SCR_WIDTH = 800;
		const unsigned int SCR_HEIGHT = 600;

		ActorT() {
			init();
			//paramInit();
		}
		void init();

		void paramInit();

		void Draw();

	};

}