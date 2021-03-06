#ifndef FRUIT_H
#define FRUIT_H

class Fruit
{
	private:
		int x;
		int y;
	public:
		void SetNewFruit(int x, int y)
		{
			this->x = x;
			this->y = y;
		};
		int GetFruitX() const
		{
			return x;
		};
		int GetFruitY() const
		{
			return y;
		}
		void DrawFruit()
		{
			gotoxy(x, y);
			std::cout << "*";
		};
		void EraseFruit()
		{
			gotoxy(x, y);
			std::cout << " ";
		};
};
#endif
