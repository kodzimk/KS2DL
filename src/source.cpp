#include<iostream>
#include"Window.h"
#include<string>

int main(void)
{
	kl::Window window(600, 400, "Hello World", NULL);
	
	kl::Event event;
	while (window.isOpen())
	{
		if (window.pollEvent(event))
		{
			if (event.type == kl::EventType::MouseWheelScroll)
			{
				std::cout << "Delta: " + std::to_string(event.mouseWheel.delta);
			}
		}
		window.clear(kl::Color::White());
		window.display();
	}
	return 0;
}