#pragma once
#include "Source/Core.h"
#include "Source/Events/Event.h"
#include "Source/Log.h"

namespace Seden {
	class SEDEN App {
	public:
		App();
		virtual ~App();
		void start();
		virtual void onInit();
		virtual void onUpdate();
		virtual void onEvent(Event& ev);
	};
	
}
