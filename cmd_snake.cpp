#include <iostream>
#include <conio.h>
#include <Windows.h>
bool gameOver; 
const int width = 20; //width of gamezone
const int height = 20; //height if gamezone 
int x, y, fruitX, fruitY; // coordinates of our snake and fruits
int score; // our score
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setup() { //setup start values
	gameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void draw() {
	system("cls"); //if you use linux, change "cls" -> "clear"
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

void input() { // here we use conio.h to get our button presses
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
	switch (dir)// here we change position of the snake
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
	}// here we check position of the snake сonsidering death by walls
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
		Sleep(200); //change if too slow
		draw();
		input();
		logic();
	}	
	return 0;
}
