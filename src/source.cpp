#include<stdio.h>
#include"System/Window.h"

int main(void)
{
	kl::Window window(600, 400, "Hello World", NULL);

	while (window.isOpen())
	{
		window.clear(0.0f,1.0f,0.0f);
		window.display();
	}
	return 0;
}