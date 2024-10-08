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
        glfwSetScrollCallback(window, scroll_callback);
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

    void Window::close()
    {
        glfwSetWindowShouldClose(window, 1);
    }

    void Window::setSize(int width, int height)
    {
        glfwSetWindowSize(window, width, height);
    }

    void Window::setPosition(int x, int y)
    {
        glfwSetWindowPos(window, x, y);
        position.x = x;
        position.y = y;
    }

    bool Window::getVisiblity()
    {
        return this->visibility;
    }

    void Window::setTitle(const char* title)
    {
        glfwSetWindowTitle(window, title);
    }

    bool Window::hasFocus()
    {
        return true;
        glfwwindowcapt
    }

    void Window::setVisibility(bool visibility)
    {

        if (visibility)
        {
            glfwHideWindow(window);
            this->visibility = false;
        }
        else
        {
            glfwShowWindow(window);
            this->visibility = true;
        }

    }

    glm::vec2 Window::getPosition()
    {
        return position;
    }

    bool Window::pollEvent(Event& event)
    {
        tempEvent = &event;
        glfwPollEvents();

        return event.type != EventType::None;
    }

     void Window::scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
     {
         tempEvent->mouseWheel.update(xoffset, yoffset);
         tempEvent->type = tempEvent->mouseWheel.type;
     }

     void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
     {
        tempEvent->keyboard.update(key, action);
        tempEvent->type = tempEvent->keyboard.type;
     }
     void Window::mouseButtonCallBack(GLFWwindow* window, int button, int action, int mode)
     {
        tempEvent->mouse.update(button, action);
        tempEvent->type = tempEvent->mouse.type;
     }
     void Window::mousePosCallBack(GLFWwindow* window, double xpos, double ypos)
     {
        tempEvent->mouseMoved.update(xpos, ypos);
        tempEvent->type = tempEvent->mouseMoved.type;
     }
     void Window::windowResizeCallBack(GLFWwindow* window, int width, int height)
     {
         tempEvent->type = Resized;
     }

}
