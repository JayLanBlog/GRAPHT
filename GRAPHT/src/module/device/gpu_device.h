#pragma once
#include "module/window/window.h"
#include  "gui/GUIView.h"
namespace GRAPHT{
	class Device {
	public:
		Device() {};

		virtual void init() = 0;

		virtual void update() = 0;

		virtual void submit() = 0;

		virtual void destroy() = 0;

		GWindow* gWindow;

		GUIView* gui;

		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImVec4(1.0f, 1.0f, 1.0f, 0.00f);

		

	};


	class GLDevice :public Device {
	public:
		GLDevice();
		virtual void update();

		virtual void init();

		virtual void submit();

		virtual void destroy();

	private:

#if defined(IMGUI_IMPL_OPENGL_ES2)
		// GL ES 2.0 + GLSL 100 (WebGL 1.0)
		const char* glsl_version = "#version 100";
#elif defined(IMGUI_IMPL_OPENGL_ES3)
		// GL ES 3.0 + GLSL 300 es (WebGL 2.0)
		const char* glsl_version = "#version 300 es";
#elif defined(__APPLE__)
		// GL 3.2 Core + GLSL 150
		const char* glsl_version = "#version 150";
#else
		// GL 3.0 + GLSL 130
		const char* glsl_version = "#version 130";
#endif
		void createWindow();
		void createGui();
		void createContext();
		void initWindow();
		void initGui();
		void initGL();
		SDL_GLContext gl_context;

	};


	class VKDevice :public Device {
	public:
		VKDevice();

		virtual void update() ;

		virtual void init();

		virtual void submit();

		virtual void destroy();
	private:
		void createWindow();
		void createGui();
		void initWindow();
		void initGui();
		void initVK();
	};

}