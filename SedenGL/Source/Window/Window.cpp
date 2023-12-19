#include "Window.h"
#include "../Log.h"

namespace Seden {
	Seden::Window::Window()
	{
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        window = glfwCreateWindow(800, 800, "LearnOpenGL", NULL, NULL);
        glfwMakeContextCurrent(window);
        if (window == NULL)
        {
            SEDEN_ERROR("glfw window initialisation failled");
            glfwTerminate();
        }
        
        // Set the required callback functions

        gladLoadGL();

        glViewport(0, 0, 800, 800);

        //while (!glfwWindowShouldClose(window))
        //{
        //    

        //    
        //}        
	}
    Window::~Window()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    void Window::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void Window::display()
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    int Window::getWidth()
    {
        return 0;
    }
    int Window::getHeight()
    {
        return 0;
    }
}