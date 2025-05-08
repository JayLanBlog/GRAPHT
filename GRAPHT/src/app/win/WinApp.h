#pragma once
#include "../app.h"
#include "module/window/window.h"
#include "module/device/gpu_device.h"
#include "view/target/TObject.h"
namespace GRAPHT {
	class WinApp : public Application
	{
	public:
		WinApp();
		~WinApp();
		WinApp(GUIAPI api);
		void ceateDevice();
		void initDevice();
		virtual void init() ;
		virtual bool run();
		virtual void dstory();
	private:
		Device* gpu;
		ActorT* actor;
	};
};