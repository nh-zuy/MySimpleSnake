#ifndef SETTINGS_H
#define SETTINGS_H

class Setting
{
	private:
		int WidthBoard; // = 58
		int HeightBoard; // = 35
		int SpeedSnake; // THe defaule speed of the snake is 100 and can increase
		int IncreSpeed; //This's the speed of inscreasing speed snake
		bool GameStatus;
		int Level; // That's level of the game
	public:
		Setting()
		{
			WidthBoard = 58;
			HeightBoard = 35;
			SpeedSnake = 100;
			IncreSpeed = 10;
			Level = 1;
			GameStatus = true;
		};
		bool EndGame()
		{
			GameStatus = false;
			return GameStatus;
		};
		int GetWidth()
		{
			return WidthBoard;
		}
		int GetHeight()
		{
			return HeightBoard;
		};
		int GetSpeedSnake()
		{
			return SpeedSnake;
		};
		int GetLevel()
		{
			return Level;
		};
		void UpradeLevel()
		{
			Level++;
		};
		void DrawLevel()
		{
			gotoxy(63, 10);
			std::cout << "LEVEL";
			gotoxy(65, 11);
			std::cout << Level;
		};
		void UpradeSpeed()
		{
			SpeedSnake -= IncreSpeed * Level;
		};
};

#endif
