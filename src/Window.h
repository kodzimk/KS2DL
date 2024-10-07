#include<include-glew/GL/glew.h>
#include<include-glfw/GLFW/glfw3.h>
#include<glm/vec3.hpp>
#include"Color.h"

namespace kl
{
	class Window
	{
	public:
		Window() = default;
		Window(int width, int height, const char* title, const char* image);
		~Window();

	public:
		void clear(kl::Color color);
		void display();

	public:
		bool isOpen();

	private:
		GLFWwindow* window;
		const char* title;
		int width;
		int height;
	};
}