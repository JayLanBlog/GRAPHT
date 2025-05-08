#pragma once
#include "glad/glad.h"
#include "../GUIView.h"

namespace GRAPHT {


	class Application
	{
	public:
		Application() {
			gpuAPI = OPENGL;
		}
		Application(GUIAPI api):gpuAPI(api) {

		};
		~Application() {};
	   virtual void init() = 0;
	   virtual bool run() = 0;
	   void launch() {
		   bool done = false;
		   while (!done)
		   {
			   done = run();
		   }
	   }
	   virtual void dstory() = 0;
	   GUIAPI gpuAPI;
	private:
		
	};

	

}