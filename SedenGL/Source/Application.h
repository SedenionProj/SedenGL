#pragma once
#include "Core.h"
#include "Window/Window.h"

#include "Opengl/buffer.h"
#include "Opengl/VertexArray.h"
#include "Opengl/Shader.h"

namespace Seden {
	class SEDEN App {
	public:
		App();
		virtual ~App();
		void start();
		virtual void onInit();
		virtual void onUpdate();
	private:
		Window* window;
		bool running;
	private:
		IndexBuffer* ib;
		VertexArray* va;
		VertexBuffer* vb;
		Shader* shaders;
	};
	
}