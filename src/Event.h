#pragma once
#include"Window.h"

namespace kl
{
	enum EventType
	{
		None = -1,
		KeyPressed,
		KeyReleased,
		KeyRepeated
	};

	 class Event
	{
	public:
		Event();
		Event(Window* window);
		~Event();
	private:
		static void keyCallback(GLFWwindow* window, int button, int scancode, int action, int mods);
		static void mouseButtonCallBack(GLFWwindow* window, int button, int action, int mode);
		static void mousePosCallBack(GLFWwindow* window, double xpos, double ypos);
		static void windowResizeCallBack(GLFWwindow* windw, int width, int height);
	public:
		 EventType type;
		 static char pKey;
	};

	 char Event::pKey = ' ';

}