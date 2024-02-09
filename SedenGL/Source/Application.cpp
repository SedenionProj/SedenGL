#include <iostream>
#include "Application.h"
#include "Log.h"
#include "Opengl/buffer.h"



namespace Seden {
	App::App()
	{
		window = new Window();

		window->setEventCallback(std::bind(&App::onEvent, this, std::placeholders::_1));

		running = true;

		float v[] = {
			 1.f,  1.f, 0.0f,
			 1.f, -1.f, 0.0f,
			-1.f, -1.f, 0.0f,
			-1.f,  1.f, 0.0f
		};
		unsigned int index[] = {
			0, 1, 3,
			1, 2, 3
		};

		shaders = new Shader("Shaders/basicVert.glsl", "Shaders/basicFrag.glsl");
		va = new VertexArray();
		ib = new IndexBuffer(sizeof(index), index);
		vb = new VertexBuffer(sizeof(v), v);
		va->AddBuffer(*vb, 3, 3, 0);


		
	}
	App::~App()
	{

	}

	void App::start()
	{
		onInit();

		while (running) {
			window->clear();
			onUpdate();
			window->display();
		}
		
	}

	void App::onInit()
	{

	}
	void App::onUpdate()
	{
		va->Bind();
		shaders->Bind();
		ib->Bind();
		glDrawElements(GL_TRIANGLES, ib->GetCount(), GL_UNSIGNED_INT, 0);
	}
	void App::onEvent(Event& ev)
	{
	}
}