#pragma once
#include "../app.h"

namespace GRAPHT {
	class WinApp : public Application
	{
	public:
		WinApp();
		~WinApp();
		WinApp(GUIAPI api);
		void createWindow();
		void initializeGPU();
		virtual void init() ;
		virtual bool run();
		virtual void dstory();
	private:
		SDL_Window* window;
		GUIView* gui;

		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	};
};