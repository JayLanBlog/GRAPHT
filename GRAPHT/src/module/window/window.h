#pragma once
#include <stdio.h>          // printf, fprintf
#include <stdlib.h>         // abort
#include <SDL3/SDL.h>¡¢
#include <common/core.h>
//Vulkan Impl
#include <SDL3/SDL_vulkan.h> 
//OpengGL Impl
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL3/SDL_opengles2.h>
#else
#include <SDL3/SDL_opengl.h>
#include "imgui_impl_opengl3.h"
#endif


namespace GRAPHT {

	class GWindow
	{
	public:
		GWindow();
		virtual ~GWindow();
		virtual void init() = 0;
		virtual void update(ImVec4 view,ImVec4 clear_color) =0 ;
		virtual void swapper() = 0;
		SDL_Window* sdlWindow;

	};


	class GLWindow :public GWindow{
	public:
		GLWindow();
		~GLWindow() {};
		virtual void init();
		virtual void update(ImVec4 view, ImVec4 clear_color);
		virtual void swapper();
	};

	class VKWindow :public GWindow {
	public:
		VKWindow();
		~VKWindow() {};
		virtual void init();
		virtual void update(ImVec4 view, ImVec4 clear_color);
		virtual void swapper();
	};
}