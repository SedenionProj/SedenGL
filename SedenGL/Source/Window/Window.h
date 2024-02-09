#pragma once
#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Events/Event.h"
#include <functional>



namespace Seden {
	typedef std::function<void(Event&)> EventCallback;

	class Window {
	public:

		Window();
		~Window();

		void clear();
		void display();

		int getWidth();
		int getHeight();

		void setEventCallback(EventCallback function);

		GLFWwindow* window;
	private:
		int width;
		int height;
		EventCallback EventCallbackFunction;
	};
}