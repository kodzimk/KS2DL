#include<iostream>
#include"Event.h"

int main(void)
{
	kl::Window window(600, 400, "Hello World", NULL);
	
	kl::Event event(&window);

	while (window.isOpen())
	{
		/*if (event.pKey == 'A')
		{
			std::cout << 'A';
		}*/
		window.clear(kl::Color::White());
		window.display();
	}

	return 0;
}