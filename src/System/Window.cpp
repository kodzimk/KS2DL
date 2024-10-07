#include"Window.h"

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
    }

    Window::~Window()
    {
        glfwTerminate();
    }

    void Window::clear(float r, float g, float b)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(r,g,b, 1.0f);
        glfwSwapBuffers(window);
    }

    void Window::clear(kl::Color color)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    bool Window::isOpen()
    {
        return  !glfwWindowShouldClose(this->window);
    }

    void Window::display()
    {
        glfwPollEvents();
    }
}
