#pragma once
#define KEY_UP		1072
#define KEY_DOWN	1080
#define KEY_LEFT	1075
#define KEY_RIGHT	1077
#define KEY_NONE	-1

void gotoxy(int, int);
int inputKey();
void ShowConsoleCursor(bool);