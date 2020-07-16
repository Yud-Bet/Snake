#include "Snake.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "my_console.h" 
#include "snake_map.h"

using namespace std::this_thread;
using namespace std::chrono;


int main()
{
	Snake a(30, 20);
	Food food;
	food.newfood(a);
	snake_map newMap(30, 20);
	ShowConsoleCursor(false);
	for (;;)
	{	//basic moving
		int inp = inputKey();
		if (inp == KEY_UP)
		{
			a.redirect(0);
		}
		else if (inp == KEY_DOWN)
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
		else a.move();
		
		
		if (a.getBody(0).x == food.getVitri().x && a.getBody(0).y == food.getVitri().y) {
			a.make_longer();
			food.newfood(a);
		}
		
		if (a.is_snake_being_eaten() || newMap.is_map_being_eaten(a.getBody(0)))
		{
			system("CLS");
			std::cout << "GAME OVER";
			return 0;
		}

		newMap.print_map();
		a.print_snake();
		food.print_food();
		sleep_for(milliseconds(80));
		system("CLS");
	}
}


/*old main
	Snake a(40, 20);
	ShowConsoleCursor(false);
	for (;;)
	{
		a.move();
		a.print_snake();
		a.make_longer();
		sleep_for(milliseconds(100));
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
*/