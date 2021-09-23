#define STB_IMAGE_IMPLEMENTATION

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <shader/shader.h>

#include <iostream>
#include <math.h>

#include "stb_image/stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// forward declarations
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
   // glfw: initialize and configure
   glfwInit();
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

   // glfw window creation
   GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr,nullptr);
   if(window == nullptr)
   {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return -1;
   }
   glfwMakeContextCurrent(window);
   glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

   // glad: load all OpenGL function pointers
   if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
   {
      std::cout << "Failed to initialize GLAD" << std::endl;
      return -1;
   }

   // configure global opengl state
   // -------------------------------------------
   glEnable(GL_DEPTH_TEST);


   // build and compile our shader program
   // ---------------------------------------
   Shader ourShader("../shaders/learnopengl/3.3.shader.vs", "../shaders/learnopengl/3.3.shader.fs");
   
   // render loop
   //----------------------------------------
   while(!glfwWindowShouldClose(window))
   {
      // input
      processInput(window);
      
      // render
      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      ourShader.use();


      // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
      //------------------------------------------
      glfwSwapBuffers(window);
      glfwPollEvents();
   }

   // glfw: terminate, clearing all previously allocated GLFW resources
   //---------------------------------------------------
   glfwTerminate();

   return 0;
}

// called every loop to check whether ESC is pressed. If that's the case the window closes
void processInput(GLFWwindow *window)
{
   if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(window,true);
}

// checks whether the window has changed size to adjust the viewport too
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
   glViewport(0,0, width, height);
}
