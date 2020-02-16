#ifndef SNAKE_H
#define SNAKE_H
#include "Graphic.h"
#include "Point.h"
#include "Fruit.h"
#include "Score.h"
#include "Setting.h"
#include <conio.h>
#include <dos.h>
#include <ctime>
#define MAX_SNAKE_SIZE 69
enum Direction{UP, DOWN, LEFT, RIGHT, NONE};

class Snake
{
	private:
		Point* cell[MAX_SNAKE_SIZE];
		int size;
		Direction dir;
		Fruit fruit;
		Score score;
		Setting setting;
	public:
		Snake()
		{
			size = 1;
			cell[0] = new Point(20, 20);
			//No moving
			dir = NONE;
			//Set the body is NULL
			for (int i = 1; i < MAX_SNAKE_SIZE; i++)
			{
				cell[i] = NULL;
			};
			
			//Set the first fruit on the board
			srand((unsigned)time(NULL));
			fruit.SetNewFruit(rand()%(setting.GetWidth() - 2) + 2, rand()%(setting.GetHeight() - 3) + 3);
		};
		//Destructor
		~Snake()
		{
			delete[] cell;
		}
		//Add a cell at the end of the snake when he get a fruit
		void AddCell(int x, int y)
		{
			cell[size++] = new Point(x, y); //Set a new sell at the last of the snake
		}
		//Turn the snake when hit a keydown
		void TurnUp()
		{
			if (dir != DOWN) 
			{
				dir = UP;                               //    W
			}                                           // A     D
		};                                              //    s
		void TurnDown()
		{
			if (dir != UP)
			{
				dir = DOWN;
			}
		};
		void TurnLeft()
		{
			if (dir != RIGHT)
			{
				dir = LEFT;
			}
		};
		void TurnRight()
		{
			if (dir != LEFT)
			{
				dir = RIGHT;
			}
		};
		//Operate the snake 
		//   w
		//a     d
		//   s
		//Check direction -> check moving
		void OperateSnake()
		{
			if (kbhit())
			{
				char c = getch();
				switch(c)
				{
					case 'w': TurnUp();
								break;
					case 's': TurnDown();
								break;
					case 'a': TurnLeft();
								break;
					case 'd': TurnRight();
								break;
				};
				
			};
		};
		//In this function, we will show the snake moving on the board
		void Moving()
		{
			//Erasing the old body after moving
			//Idea: we will erase the all the cell and update the new positon 
			//      of each cell 
			for (int i = 0; i < size; i++)
			{
				cell[i]->Erase();
			};
			
			//The body following the head
			//The next cell will be equivalent to the previous cell
			for (int i = size - 1; i > 0; i--)
			{
				cell[i-1]->TakePoint(cell[i]); // cell i <- cell (i - 1);
			};
			
			//Check the direction of the snake
			//Idea: We just move the head and the body will be follow it
			switch(dir)
			{
				case UP: cell[0]->MoveUp();
							break;
				case DOWN: cell[0]->MoveDown();
							break;
				case LEFT: cell[0]->MoveLeft();
							break;
				case RIGHT: cell[0]->MoveRight();
							break;
			};
			
			//If a collision fruit and snake occurs
			//Add a new cell -> Update score -> Update level -> Update speed -> Update fruit
			if (fruit.GetFruitX() == cell[0]->GetX() && fruit.GetFruitY() == cell[0]->GetY())
			{
				AddCell(0,0); //Add a new cell
				score.UpradeScore(); //Update the score with the score increment 1
				//We will raise the difficult of the game if player get 10 score
				if (score.GetScore() % 10 == 0)
				{
					setting.UpradeLevel(); // Uprade the level
					setting.UpradeSpeed(); // and after, uprade the speed
				};
				
				fruit.EraseFruit(); //Erase the eaten fruit
				srand((unsigned)time(NULL));
				do
				{
					fruit.SetNewFruit(rand()%(setting.GetWidth() - 2) + 2,
									  rand()%(setting.GetHeight() - 3) + 3); 
									  //Set a new fruit.
									  //It will be not similar to the postion of the snake.
				} while ( fruit.GetFruitX() == cell[0]->GetX() && 
						  fruit.GetFruitY() == cell[0]->GetY() );
			};
			
			//Check if the head collide with the body
			//And the game over.
			//I'm disappointed with that ending sence because i don't know how to end the game better.
			for (int i = 1; i < size; i++)
			{
				if (cell[0]->GetX() == cell[i]->GetX() && cell[0]->GetY() == cell[i]->GetY())
				{
					system("cls");
					gotoxy(setting.GetWidth()/2, setting.GetHeight()/2);
					std::cout << "END";
					exit(0);
				};
			};
		
			//Now we print the snake, the fruit, the score and the level		
			for (int i = 0; i < size; i++)
			{
				cell[i]->Draw();
			};
			score.DrawScore();
			setting.DrawLevel();
			fruit.DrawFruit();
			
			Sleep(setting.GetSpeedSnake()); //Easilly realizing the difference
		}
};
#endif
