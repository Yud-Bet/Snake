#pragma once

struct coord
{
	int x;
	int y;
};

class Snake
{
private:
	//w, h la kich thuoc khung game
	int w;
	int h;
	int direction;
	int length;
	coord* body;
public:
	Snake(int width, int height)
	{
		w = width;
		h = height;
		direction = 3;
		length = 3;
		body = new coord[3];
		body[0].x = width / 2;
		body[0].y = height / 2;
		for (int i = 1; i < 3; i++)
		{
			body[i].x = body[i - 1].x - 1;
			body[i].y = body[i - 1].y;
		}
	}
	void print_snake();
	void redirect(int);
	void move();
};
