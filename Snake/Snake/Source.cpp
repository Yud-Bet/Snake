#include "Snake.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "my_console.h"

using namespace std::this_thread;
using namespace std::chrono;

int main()
{
	Snake a(30, 20);
	ShowConsoleCursor(false);
	for (;;)
	{
		a.move();
		a.print_snake();
		sleep_for(milliseconds(50));
		system("CLS");
		int inp = inputKey();

		if (inp == KEY_UP)
		{
			a.redirect(0);
		}
		else if (inp==KEY_DOWN)
		{
			a.redirect(2);
		}
		else if (inp == KEY_RIGHT)
		{
			a.redirect(3);
		}
		else if (inp == KEY_LEFT)
		{
			a.redirect(1);
		}
	}
}