#pragma once
#include "../GUIView.h"

namespace GRAPHT {
	enum GUIAPI
	{
		OPENGL = 0,
		VULKAN = 1
	};

	class Application
	{
	public:
		Application() {
			gpuAPI = GUIAPI::OPENGL;
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