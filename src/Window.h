#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include<include-glew/GL/glew.h>
#include<include-glfw/GLFW/glfw3.h>
#include<glm/vec3.hpp>
#include<glm/vec2.hpp>
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
		bool pollEvent(Event& event);
		void display();
		void close();
		void setSize(int width, int height);
		void setPosition(int x,int y);
		bool getVisiblity();
		void setTitle(const char* title);
		bool hasFocus();
		void setVisibility(bool visibility);
		glm::vec2 getPosition();
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
		glm::vec2 position = {0.0f,0.0f};
		int width;
		int height;
	private:
		bool visibility - true;
	};
}
#endif