#include "gpu_device.h"

namespace GRAPHT {
	GLDevice::GLDevice() {
		createWindow();
		createGui();
		createContext();
	}


	void GLDevice::init() {
		// Setup Platform/Renderer backends
		initWindow();
		initGui();
		initGL();
	};
	void GLDevice::createWindow() {
		gWindow = new GLWindow();
	}

	void GLDevice::createGui() {
		gui = new GLGUI(gWindow->sdlWindow);
	}

	void GLDevice::createContext() {
		SDL_SetWindowPosition(gWindow->sdlWindow, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
		gl_context = SDL_GL_CreateContext(gWindow->sdlWindow);
		if (gl_context == nullptr)
		{
			printf("Error: SDL_GL_CreateContext(): %s\n", SDL_GetError());
			return;
		}
	}

	void GLDevice::initWindow() {
		SDL_GL_MakeCurrent(gWindow->sdlWindow, gl_context);
		SDL_GL_SetSwapInterval(1); // Enable vsync
		SDL_ShowWindow(gWindow->sdlWindow);
	}
	void GLDevice::initGui() {
		gui->init();
	}

	void GLDevice::initGL() {
		// Setup Platform/Renderer backends
		ImGui_ImplSDL3_InitForOpenGL(gWindow->sdlWindow, gl_context);
		ImGui_ImplOpenGL3_Init(glsl_version);
	}

	void GLDevice::update() {
		// Resize swap chain?
		int fb_width, fb_height;
		SDL_GetWindowSize(gWindow->sdlWindow, &fb_width, &fb_height);

		gui->resize(fb_width, fb_height);

		gui->startFrame();


		ImGuiIO& io = ImGui::GetIO();

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


		gui->renderFrame(clear_color);
		gWindow->update(ImVec4(0, 0, io.DisplaySize.x, io.DisplaySize.y), clear_color);
		gui->renderGuiData();
	};

	void GLDevice::submit() {
		gWindow->swapper();
	};

	void GLDevice::destroy() {
		if (gui) {
			delete gui;
		}
		SDL_GL_DestroyContext(gl_context);
		if (gWindow) {
			delete gWindow;
		}
		SDL_Quit();

	};

	VKDevice::VKDevice() {
		createWindow();
		createGui();
	}

	void VKDevice::update() {
		// Resize swap chain?
		int fb_width, fb_height;
		SDL_GetWindowSize(gWindow->sdlWindow, &fb_width, &fb_height);
		gui->resize(fb_width, fb_height);

		gui->startFrame();


		ImGuiIO& io = ImGui::GetIO();

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


		gui->renderFrame(clear_color);
		gWindow->update(ImVec4(0, 0, io.DisplaySize.x, io.DisplaySize.y), clear_color);
		gui->renderGuiData();

	}

	void VKDevice::init() {
		initWindow();
		initGui();
		initVK();
	}

	void VKDevice::submit() {
		gWindow->swapper();
	}

	void VKDevice::destroy() {
	
	}
	void VKDevice::createWindow() {
		gWindow = new VKWindow();
	}
	void VKDevice::createGui() {
		gui = new VulkanGUI(gWindow->sdlWindow);
	}
	void  VKDevice::initWindow() {
	}
	void VKDevice::initGui() {
	
	}
	void VKDevice::initVK() {
	
	}




}