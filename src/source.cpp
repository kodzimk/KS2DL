#include<stdio.h>
#include"Window.h"

int main(void)
{
	kl::Window window(600, 400, "Hello World", NULL);
	

	while (window.isOpen())
	{
		window.clear(kl::Color::White());
		window.display();
	}

	return 0;
}