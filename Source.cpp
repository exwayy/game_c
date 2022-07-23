#include <iostream>
#include <conio.h>
#include <Windows.h>
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY;
int score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void draw() {
	system("cls");
	for (int i = 0; i < width + 1; i++) {
		std::cout << "#";
	}std::cout << std::endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1) std::cout << "#";
			if (i == y && j == x) std::cout << "0";
			else if (i == fruitY && j == fruitX)
				std::cout << "F";
			else
				std::cout << " ";
		}

		std::cout << std::endl;
	}

	for (int i = 0; i < width + 1; i++) {
		std::cout << "#";
	}std::cout << std::endl;
	std::cout << "Score" << score;


}

void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void logic() {
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if (x >width-2 || x < 0 || y<0 || y>height-1) gameOver = true;
	if (x == fruitX && y == fruitY) {
		score++;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}

int main() {
	setup();
	while (!gameOver) {
		Sleep(200);
		draw();
		input();
		logic();
	}	
	return 0;
}