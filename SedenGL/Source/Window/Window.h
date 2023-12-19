#pragma once
#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Seden {
	class Window {
	public:
		Window();
		~Window();

		void clear();
		void display();

		int getWidth();
		int getHeight();

		GLFWwindow* window;
	private:
		int width;
		int height;
		
	};
}