#include <iostream>
#include "Graphic.h"
#include "Setting.h"

#ifndef POINT_H
#define POINT_H

class Point
{
	private:
		int x;
		int y;
		Setting setting;
	public:
		//Set default position = 0, 0
		Point()
		{
			x = y = 10;
		};
		
		//Initialize the position
		Point(int x, int y)
		{
			this->x = x;
			this->y = y;
		};
		
		//Get x, y
		int GetX()
		{
			return x;
		};
		int GetY()
		{
			return y;
		};
		
		//Set the position
		void SetPoint(int x, int y)
		{
			this->x = x;
			this->y = y;
		};
		
		//Take the positon of the previous cell
		void TakePoint(Point* p)
		{
			p->x = x;
			p->y = y;
		};
		
		//Draw cell and Erase
		void Draw()
		{
			gotoxy(x, y);
			std::cout << char(254);
		}
		void Erase()
		{
			gotoxy(x, y);
			std::cout << " ";
		}
		
		//Functions for moving
		void MoveUp()
		{
			if (y == 2)
			{
				y = setting.GetHeight();
			};
			y--;
		};
		void MoveDown()
		{
			if (y == setting.GetHeight() - 1)
			{
				y = 1;
			}
			y++;
		};
		void MoveLeft()
		{
			if (x == 2)
			{
				x = setting.GetWidth();
			}
			x--;
		};
		void MoveRight()
		{
			if (x == setting.GetWidth() - 1)
			{
				x = 1;
			}
			x++;
		};
};

#endif
