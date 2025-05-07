#pragma once
#include "../app.h"
#include "view/target/TObject.h"
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

		ActorT* actor;
		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImVec4(1.0f, 1.0f, 1.0f, 0.00f);

	};
};