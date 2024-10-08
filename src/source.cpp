#include<iostream>
#include"Window.h"


int main(void)
{
	kl::Window window(600, 400, "Hello World", NULL);
	
	kl::Event event;
	

	while (window.isOpen())
	{
		if (window.pollEvent(event))
		{
			if (event.type == kl::EventType::KeyRepeated)
			{
				std::cout << char(event.keyboard.key + 65);
			}
		}
		window.clear(kl::Color::White());
		window.display();
	}

	return 0;
}