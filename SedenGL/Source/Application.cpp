#include <iostream>
#include "Application.h"
#include "Log.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Seden {
	App::App()
	{

	}
	App::~App()
	{

	}

	void App::start()
	{
        std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
        // Init GLFW
        glfwInit();
        // Set all the required options for GLFW
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        // Create a GLFWwindow object that we can use for GLFW's functions
        GLFWwindow* window = glfwCreateWindow(800, 800, "LearnOpenGL", NULL, NULL);
        glfwMakeContextCurrent(window);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }

        // Set the required callback functions
        
        // Load OpenGL functions, gladLoadGL returns the loaded version, 0 on error.
        gladLoadGL();

        // Successfully loaded OpenGL
        std::cout << "Loaded OpenGL " << GLFW_VERSION_MAJOR << "." << GLFW_VERSION_MINOR << std::endl;

        // Define the viewport dimensions
        glViewport(0, 0, 800, 800);

        // Game loop
        while (!glfwWindowShouldClose(window))
        {
            // Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
            glfwPollEvents();

            // Render
            // Clear the colorbuffer
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            // Swap the screen buffers
            glfwSwapBuffers(window);
        }

        // Terminates GLFW, clearing any resources allocated by GLFW.
        glfwTerminate();


		onInit();
		onUpdate();
	}

	void App::onInit()
	{
		SEDEN_INFO("onInit() function should be overriden")
	}
	void App::onUpdate()
	{
		SEDEN_INFO("onUpdate() function should be overriden")
	}

}