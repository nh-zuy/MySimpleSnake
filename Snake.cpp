#include "Snake.h"
#include "Board.h"
#include "Menu.h"

int main()
{
	resizeConsole(600, 500);
	Snake snake;
	Menu menu;
	
	menu.ControlMenu();
	system("cls");
	DrawTheBoard();
	while (true)
	{
		snake.OperateSnake();
		snake.Moving();
	};
	return 0;
}
