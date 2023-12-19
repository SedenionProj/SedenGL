#pragma once
#include "Source/Core.h"

namespace Seden {
	class SEDEN App {
	public:
		App();
		virtual ~App();
		void start();
		virtual void onInit();
		virtual void onUpdate();
	};

}