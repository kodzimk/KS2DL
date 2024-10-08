#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include<include-glew/GL/glew.h>
#include<include-glfw/GLFW/glfw3.h>
#include<glm/vec3.hpp>
#include"Event.h"
#include"Color.h"

namespace kl
{
	class Window
	{
	public:
		Window() = default;
		Window(int width, int height, const char* title, const char* image);
		~Window();

		void clear(kl::Color color);
		void display();
		bool pollEvent(Event& event);
		bool isOpen();

	private:
		static void keyCallback(GLFWwindow* window, int button, int scancode, int action, int mods);
		static void mouseButtonCallBack(GLFWwindow* window, int button, int action, int mode);
		static void mousePosCallBack(GLFWwindow* window, double xpos, double ypos);
		static void windowResizeCallBack(GLFWwindow* windw, int width, int height);
		static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	private:
		inline static Event* tempEvent;
	private:
		GLFWwindow* window;
		const char* title;
		int width;
		int height;
	};
}
#endif