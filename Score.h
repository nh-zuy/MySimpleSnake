#ifndef SCORE_H
#define SCORE_H

class Score
{
	private:
		int x;
		int y;
		int value;
	public:
		Score()
		{
			value = 0;
			x = 65;
			y = 3;
		};
		void UpradeScore()
		{
			value++;
		};
		int GetScore() const
		{
			return value;
		}
		void DrawScore()
		{
			gotoxy(x - 2, y - 1);
			std::cout << "SCORE";
			gotoxy(x, y);
			std::cout << value;
		};
};

#endif
