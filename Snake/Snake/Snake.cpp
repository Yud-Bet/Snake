#include "Snake.h"
#include "my_console.h"
#include <iostream>
#include <math.h>


void Snake::print_snake()
{
	for (int i = 0; i < length; i++)
	{
		gotoxy(body[i].x, body[i].y);
		std::cout << char(254);
	}
}
void Snake::redirect(int d)
{
	if (d == direction || abs(d - direction) == 2) return ;
	else if (direction == 0)
	{
		if (d == 1)
		{
			for (int i = length - 1; i > 0; i--)
			{
				body[i] = body[i - 1];
			}
			body[0].x --;
		}
		else if (d == 3)
		{
			for (int i = length - 1; i > 0; i--)
			{
				body[i] = body[i - 1];
			}
			body[0].x ++;
		}
		direction = d;
	}
	else if (direction == 1)
	{
		if (d == 0)
		{
			for (int i = length - 1; i > 0; i--)
			{
				body[i] = body[i - 1];
			}
			body[0].y --;
		}
		else if (d == 2)
		{
			for (int i = length - 1; i > 0; i--)
			{
				body[i] = body[i - 1];
			}
			body[0].y ++;
		}
		direction = d;
	}
	else if (direction == 2)
	{
		if (d == 1)
		{
			for (int i = length - 1; i > 0; i--)
			{
				body[i] = body[i - 1];
			}
			body[0].x --;
		}
		else if (d == 3)
		{
			for (int i = length - 1; i > 0; i--)
			{
				body[i] = body[i - 1];
			}
			body[0].x ++;
		}
		direction = d;
	}
	else if (direction == 3)
	{
		if (d == 0)
		{
			for (int i = length - 1; i > 0; i--)
			{
				body[i] = body[i - 1];
			}
			body[0].y --;
		}
		else if (d == 2)
		{
			for (int i = length - 1; i > 0; i--)
			{
				body[i] = body[i - 1];
			}
			body[0].y ++;
		}
		direction = d;
	}
}
void Snake::move()
{
	if (direction == 0)
	{
		for (int i = length - 1; i > 0; i--)
		{
			body[i].x = body[i - 1].x;
			body[i].y = body[i - 1].y;
		}
		body[0].y--;
		if (body[0].y < 0) body[0].y = h;
	}
	else if (direction == 1)
	{
		for (int i = length - 1; i > 0; i--)
		{
			body[i].x = body[i - 1].x;
			body[i].y = body[i - 1].y;
		}
		body[0].x--;
		if (body[0].x < 0) body[0].x = w;
	}
	else if (direction == 2)
	{
		for (int i = length - 1; i > 0; i--)
		{
			body[i].x = body[i - 1].x;
			body[i].y = body[i - 1].y;
		}
		body[0].y++;
		if (body[0].y > h) body[0].y = 0;
	}
	else if (direction == 3)
	{
		for (int i = length - 1; i > 0; i--)
		{
			body[i].x = body[i - 1].x;
			body[i].y = body[i - 1].y;
		}
		body[0].x++;
		if (body[0].x > w) body[0].x = 0;
	}
}
int Snake::getLength() {
	return length;
}
void Snake::make_longer()
{
	if (length < mem_allocated)
	{
		body[length] = body[length - 1];
		length++;
	}
	else
	{
		mem_allocated *= 2;
		coord* temp = new coord[mem_allocated];
		for (int i = 0; i < length; i++)
		{
			temp[i] = body[i];
		}
		delete[] body;
		body = temp;

		body[length] = body[length - 1];
		length++;
	}
}
bool Snake::is_snake_being_eaten()
{
	for (int i = 1; i < length; i++)
	{
		if (body[0].x == body[i].x && body[0].y == body[i].y)
			return true;
	}
	return false;
}
coord Snake::getBody(int n) {
	return body[n];
}
int Snake::getw() {
	return w;
}
int Snake::geth() {
	return h;
}


