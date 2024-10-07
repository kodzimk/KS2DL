#include"../Event.h"


namespace kl
{
	Event::Event()
	{
		type = EventType::None;
	}

	Event::Event(Window* window)
	{
		type = EventType::None;
		glfwSetWindowUserPointer(window->window,window);
		glfwSetKeyCallback(window->window, keyCallback);
		glfwSetMouseButtonCallback(window->window, mouseButtonCallBack);
		glfwSetCursorPosCallback(window->window, mousePosCallBack);
		glfwSetWindowSizeCallback(window->window, windowResizeCallBack);
	}

	Event::~Event()
	{

	}

	void Event::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		pKey = char(key + 65);
	}
	void Event::mouseButtonCallBack(GLFWwindow* window, int button, int action, int mode)
	{
		/*  MouseButton mb(button, action);*/

	}
	void Event::mousePosCallBack(GLFWwindow* window, double xpos, double ypos)
	{
		/*MousePos mp(xpos, ypos);*/
	}
	void Event::windowResizeCallBack(GLFWwindow* window, int width, int height)
	{

	}

}