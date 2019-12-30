#include "Snake.h"
#include "Board.h"

int main()
{
	resizeConsole(600, 500);
	Snake snake;
	
	DrawTheBoard();
	while (true)
	{
		snake.OperateSnake();
		snake.Moving();
	};
	return 0;
}
