#include <iostream>

void DrawTheBoard();

void DrawTheBoard()
{
	for (int i = 0; i < 58; i++)
	{
		std::cout << "-";
	};
	std::cout << std::endl;
	for (int i = 0; i < 33; i++)
	{
		for (int j = 0; j < 58; j++)
		{
			if (j == 0 || j == 57)
			{
				std::cout << "|";
			}
			else
			{
				std::cout << " ";
			}
			
		};
		std::cout << std::endl;
	};
	for (int i = 0; i < 58; i++)
	{
		std::cout << "-";
	};
}
