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

        window = glfwCreateWindow(800, 800, "SedenGL", NULL, NULL);
        glfwMakeContextCurrent(window);
        if (window == NULL)
        {
            SEDEN_ERROR("glfw window initialisation failled");
            glfwTerminate();
        }
        
        glfwSetWindowUserPointer(window, &EventCallbackFunction);

        glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
        EventCallback& callbackFunction = *(EventCallback*)glfwGetWindowUserPointer(window);

        switch (action)
            {
            case GLFW_PRESS:
            {
                KeyPressedEvent event(key);
                callbackFunction(event);
                break;
            }
            case GLFW_RELEASE:
            {
                KeyReleasedEvent event(key);
                callbackFunction(event);
                break;
            }
            case GLFW_REPEAT:
            {   
                KeyRepeatEvent event(key);
                callbackFunction(event);
                break;
            }
            }
        });

        glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
        {
            EventCallback& callbackFunction = *(EventCallback*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            callbackFunction(event);
        });

        glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
        {
            EventCallback& callbackFunction = *(EventCallback*)glfwGetWindowUserPointer(window);
            switch (action)
            {
                case GLFW_PRESS:
                {
                    MousePressEvent event(button, mods);
                    callbackFunction(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseReleaseEvent event(button, mods);
                    callbackFunction(event);
                    break;
                }
            }
            
        });

        glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos)
        {
            EventCallback& callbackFunction = *(EventCallback*)glfwGetWindowUserPointer(window);

            CursorPosEvent event((float)xPos, (float)yPos);
            callbackFunction(event);
        });

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
    void Window::setEventCallback(EventCallback function)
    {
        EventCallbackFunction = function;
    }
}