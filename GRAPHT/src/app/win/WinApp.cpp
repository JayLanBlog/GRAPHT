#include "WinApp.h"

namespace GRAPHT {


	void WinApp::init() {
		if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
		{
			printf("Error: SDL_Init(): %s\n", SDL_GetError());
			return ;
		}
		ceateDevice();
		initDevice();
		gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
		actor = new ActorT();
	//	gui->actor = new ActorT();
	}

	 bool WinApp::run() {
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			ImGui_ImplSDL3_ProcessEvent(&event);
			if (event.type == SDL_EVENT_QUIT)
				return true;
			if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == SDL_GetWindowID(gpu->gWindow->sdlWindow))
				return true;
		}
		// [If using SDL_MAIN_USE_CALLBACKS: all code below would likely be your SDL_AppIterate() function]
		if (SDL_GetWindowFlags(gpu->gWindow->sdlWindow) & SDL_WINDOW_MINIMIZED)
		{
			SDL_Delay(10);
			return false;
		}
		// Resize swap chain?
		int fb_width, fb_height;
		SDL_GetWindowSize(gpu->gWindow->sdlWindow, &fb_width, &fb_height);

		//actor->Draw();

		gpu->update();

		actor->Draw();

		//gui->swapper();
		//gWindow->swapper();
		gpu->submit();
		return false;

	}
	 void WinApp::ceateDevice() {
		 switch (gpuAPI)
		 {
		 case VULKAN:
			 gpu = new VKDevice();
			 break;
		 case OPENGL:
			 gpu = new GLDevice();
			 break;


		 default:
			 break;
		 }
	 }
	 void WinApp::initDevice() {
		 gpu->init();
	 }


	void WinApp::dstory() {
	
	}
	WinApp::WinApp(GUIAPI api) :  Application(api) {
		init();
	}

	WinApp::WinApp():Application()
	{
	
		init();
	}

	WinApp::~WinApp()
	{
		dstory();


	}


}