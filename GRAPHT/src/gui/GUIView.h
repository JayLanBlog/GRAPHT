#pragma once

#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_vulkan.h"
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

	class GUIView
	{
	public:
		GUIView(SDL_Window* w):window(w) {};
		GUIView() {};
		virtual ~GUIView() {};
		
		virtual void init() = 0;

		virtual void startFrame() = 0;

		virtual void renderFrame(ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f)) = 0;

		virtual void resize(int fb_width, int fb_height) = 0;

		virtual  SDL_Window*  createWIndow() = 0;

		virtual void destory() = 0;

		SDL_Window* window;

	private:
	};

	class GLGUI :public GUIView {
	public:
		GLGUI(SDL_Window* w);
		GLGUI();
		virtual void init();

		virtual void destory();

		virtual void startFrame() ;

		virtual void renderFrame(ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f));

		virtual void resize(int fb_width, int fb_height);

		virtual  SDL_Window*  createWIndow();

	private:
		SDL_GLContext gl_context;

	};

	class VulkanGUI :public GUIView {
	public:
		VulkanGUI(SDL_Window* w);
		VulkanGUI();
		virtual  SDL_Window*  createWIndow();

		virtual void init();

		virtual void destory();


		virtual void startFrame();

		virtual void renderFrame(ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f));

		virtual void resize(int fb_width, int fb_height);

		void CleanupVulkanWindow();

		void CleanupVulkan();

		void FrameRender(ImGui_ImplVulkanH_Window* wd, ImDrawData* draw_data);

		void FramePresent(ImGui_ImplVulkanH_Window* wd);

		static void check_vk_result(VkResult err);

		void varyfyExtensions();

		void createSurfaceAndInitialize();

		

		void SetupVulkanWindow(ImGui_ImplVulkanH_Window* wd, VkSurfaceKHR surface, int width, int height);

		void SetupVulkan(ImVector<const char*> instance_extensions);
#ifdef APP_USE_VULKAN_DEBUG_REPORT
		 VKAPI_ATTR VkBool32 VKAPI_CALL debug_report(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage, void* pUserData)
		{
			(void)flags; (void)object; (void)location; (void)messageCode; (void)pUserData; (void)pLayerPrefix; // Unused arguments
			fprintf(stderr, "[vulkan] Debug report from ObjectType: %i\nMessage: %s\n\n", objectType, pMessage);
			return VK_FALSE;
		}
#endif // APP_USE_VULKAN_DEBUG_REPORT

		static bool IsExtensionAvailable(const ImVector<VkExtensionProperties>& properties, const char* extension);

	private:
		 VkAllocationCallbacks* g_Allocator = nullptr;
		 VkInstance               g_Instance = VK_NULL_HANDLE;
		 VkPhysicalDevice         g_PhysicalDevice = VK_NULL_HANDLE;
		 VkDevice                 g_Device = VK_NULL_HANDLE;
		 uint32_t                 g_QueueFamily = (uint32_t)-1;
		 VkQueue                  g_Queue = VK_NULL_HANDLE;
		 VkPipelineCache          g_PipelineCache = VK_NULL_HANDLE;
		 VkDescriptorPool         g_DescriptorPool = VK_NULL_HANDLE;

		 ImGui_ImplVulkanH_Window g_MainWindowData;
		 uint32_t                 g_MinImageCount = 2;
		 bool                     g_SwapChainRebuild = false;


	};


};