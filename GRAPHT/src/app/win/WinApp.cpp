#include "WinApp.h"

namespace GRAPHT {


	void WinApp::init() {
		if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
		{
			printf("Error: SDL_Init(): %s\n", SDL_GetError());
			return ;
		}

		createWindow();

		initializeGPU();
			
		//Get GL Funciton Addr After Create Window
		gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
		//TShader* shader = new TShader("E:/WorkLearn/FrameWork/GRAPHT/GRAPHT/resource/shader/1.model_loading.vs", "E:/WorkLearn/FrameWork/GRAPHT/GRAPHT/resource/shader/1.model_loading.fs");

		actor = new ActorT();
	}
	void WinApp::initializeGPU() {
	
		switch (gpuAPI)
		{
		case VULKAN:
			gui = new VulkanGUI();
			break;
		case OPENGL:
			gui = new GLGUI();
			break;

			
		default:
			break;
		}
	}

	void WinApp::createWindow() {
		
	}

	 bool WinApp::run() {
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			ImGui_ImplSDL3_ProcessEvent(&event);
			if (event.type == SDL_EVENT_QUIT)
				return true;
			if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == SDL_GetWindowID(window))
				return true;
		}
		// [If using SDL_MAIN_USE_CALLBACKS: all code below would likely be your SDL_AppIterate() function]
		if (SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED)
		{
			SDL_Delay(10);
			return false;
		}
		// Resize swap chain?
		int fb_width, fb_height;
		SDL_GetWindowSize(window, &fb_width, &fb_height);

		gui->resize(fb_width,fb_height);

		gui->startFrame();

		
	     ImGuiIO& io = ImGui::GetIO(); (void)io;
	
		// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
		if (show_demo_window)
			ImGui::ShowDemoWindow(&show_demo_window);

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
		{
			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

			ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
			ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &show_another_window);

			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

			if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
			ImGui::End();
		}

		// 3. Show another simple window.
		if (show_another_window)
		{
			ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
			ImGui::Text("Hello from another window!");
			if (ImGui::Button("Close Me"))
				show_another_window = false;
			ImGui::End();
		}

	//	actor->Draw();
		gui->renderFrame(clear_color);

		return false;

	}


	void WinApp::dstory() {
		if (gui) {
			gui->destory();
		}
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

		if (gui) {
			delete gui;
		}
	}


}