#include <glad/glad.h>
#include <gl/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define PI 3.1415926

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "camera.h"

#include <vector>
#include <iostream>
using namespace std;


std::vector<float> drawglobeVBO(){
	vector<float> c;
	GLfloat R = 0.7f;	// radius
	GLint statck = 15;	// How many slices are cut horizontally
	GLfloat angle = 2*PI/statck;
	GLfloat NumAngle = 0;
	GLfloat x = 0;
	GLfloat y = 0;
	for (int i = 0; i <= statck; i++)
	{
		for (float j = 0.0f; j <= R;)
		{
			if ((R-j)>=0)
			{
				GLfloat x = (R-j) * glm::sin(NumAngle);
				GLfloat y = (R-j) * glm::cos(NumAngle);
				NumAngle += angle;
				c.push_back(x);
				c.push_back(y);
				c.push_back(0.0f);
				c.push_back(0.0f);
				c.push_back(0.0f);
				c.push_back(0.0f);
			}
			j += 0.25f;
		}

	}
	return c;
}

std::vector<int> drawglobeEBO(){
	vector<int> ebo;
	vector<float> lc =drawglobeVBO();
	int length = lc.size()/3;
	for (int i=0;i<=length;i++)
	{
			if ((!(i%2))&&(i!=0))
			{
				ebo.push_back(i);
				ebo.push_back(i);
			} 
			else
			{
				ebo.push_back(i);
			}
		}
	return ebo;
}


int main()
{
	//drawglobeEBO();
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800, 800, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	 glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	 glEnable(GL_DEPTH_TEST);
	  Shader lampShader("6.lamp.vs", "6.lamp.fs");
	  vector<float> mmc = drawglobeVBO();
	  vector<int> mfc = drawglobeEBO();

	  unsigned int VBO, cubeVAO;
	  glGenVertexArrays(1, &cubeVAO);
	  glGenBuffers(1, &VBO);
	  glBindVertexArray(cubeVAO);
	  glBindBuffer(GL_ARRAY_BUFFER, VBO);
	  glBufferData(GL_ARRAY_BUFFER, mmc.size()*sizeof(float),&mmc[0], GL_STATIC_DRAW);
	  // &Vertor [0] refers to the address of this vector. &Vector does not refer to a vector address.

	  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	  glEnableVertexAttribArray(0);

	  unsigned int EBO;
	  glGenBuffers(1, &EBO);
	  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	  glBufferData(GL_ELEMENT_ARRAY_BUFFER, mfc.size()*sizeof(float),&mfc[0], GL_STATIC_DRAW);
	  // &Vertor [0] refers to the address of this vector. &Vector does not refer to a vector address.

	  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	  glEnableVertexAttribArray(0);

	  /*glm::mat4 projection = glm::perspective(45.0f, (float)800 / (float)600, 0.1f, 100.0f);

	  glm::mat4 view = camera.GetViewMatrix();*/
	  while (!glfwWindowShouldClose(window)){
		  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		  lampShader.use();
		  glBindVertexArray(cubeVAO);
		  glDrawElements(GL_TRIANGLES, mfc.size(), GL_UNSIGNED_INT,0);
		  glfwSwapBuffers(window);
		  glfwPollEvents(); 
	  }
	  glDeleteVertexArrays(1, &cubeVAO);
	  glDeleteBuffers(1, &VBO);

	  glfwTerminate();
	  return 0;
}