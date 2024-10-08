#include"../Window.h"
#include<iostream>

namespace kl
{
    Window::Window(int width, int height, const char* title, const char* image)
        : width(width), height(height), title(title)
    {
        if (!glfwInit())
            throw "Not Initialized glfw!!!";

        window = glfwCreateWindow(width, height, title, NULL, NULL);

        if (!window)
        {
            glfwTerminate();
            throw "Problem with window!!!";
        }

        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window, this);
        glfwSetKeyCallback(window, keyCallback);
        glfwSetMouseButtonCallback(window, mouseButtonCallBack);
        glfwSetCursorPosCallback(window, mousePosCallBack);
        glfwSetWindowSizeCallback(window, windowResizeCallBack);
    }

    Window::~Window()
    {
        glfwTerminate();
    }



    void Window::clear(kl::Color color)
    {
        tempEvent->type = EventType::None;
        tempEvent->keyboard.type = EventType::None;
        tempEvent->keyboard.key = -1;

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(color.r, color.g, color.b, color.a);
        glfwSwapBuffers(window);
    }

    bool Window::isOpen()
    {
        return  !glfwWindowShouldClose(this->window);
    }
    void Window::display()
    {
   
    }

    bool Window::pollEvent(Event& event)
    {
        glfwPollEvents();
        tempEvent = &event;

        return event.type != EventType::None;
    }


     void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        tempEvent->keyboard.update(key, action);
        tempEvent->type = tempEvent->keyboard.type;
    }
    void Window::mouseButtonCallBack(GLFWwindow* window, int button, int action, int mode)
    {
        /*  MouseButton mb(button, action);*/

    }
    void Window::mousePosCallBack(GLFWwindow* window, double xpos, double ypos)
    {
        /*MousePos mp(xpos, ypos);*/
    }
    void Window::windowResizeCallBack(GLFWwindow* window, int width, int height)
    {

    }

}
