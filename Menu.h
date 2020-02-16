#ifndef MENU_H
#define MENU_H
#include "Graphic.h"
#include "Setting.h"

#define MAX_LIST 3

class Menu
{
	private:
		std::string List[MAX_LIST];
		int Pointer;
		Setting setting;
	public:
		Menu()
		{
			List[0] = "START";
			List[1] = "ABOUT";
			List[2] = "EXIT";
			Pointer = 0;
		}
		void DrawMenu()
		{
			for (int Option = 0; Option < MAX_LIST; Option++)
			{
				if (Pointer == Option)
				{
					ToMau(setting.GetWidth()/2, setting.GetHeight()/3 + Option * 4, List[Option], 28);
				}
				else
				{
					gotoxy(setting.GetWidth()/2, setting.GetHeight()/3 + Option * 4);
					std::cout << List[Option];
				};
			};
		};
		void ABOUT()
		{
			system("cls");
			gotoxy(setting.GetWidth()/2 - 18, setting.GetHeight()/2);
			std::cout << "PROJECT: SIMPLE SNAKE";
			gotoxy(setting.GetWidth()/2 - 18, setting.GetHeight()/2 - 3);
			std::cout << "GITHUB: https://github.com/nh-zuy";
		};
		void MoveUp()
		{
			if (Pointer == 0)
			{
				Pointer = MAX_LIST - 1;
			}
			else
			{
				Pointer--;
			};
		};
		void MoveDown()
		{
			if (Pointer == MAX_LIST - 1)
			{
				Pointer = 0;
			}
			else
			{
				Pointer++;
			}
		};
		void ControlMenu()
		{
			int flag = -1;
			while (true) //THE MAIN LOOP
			{
				system("cls");
				DrawMenu();
				while (true)
				{
					if (kbhit())
					{
						char c = getch();
						if (c == 'w')
						{
							MoveUp();
							break;
						}
						else if (c == 's')
						{
							MoveDown();
							break;
						}
						else if (c == 13)
						{
							if (Pointer == 0)
							{
								flag = 0;
								break;
							}
							else if (Pointer == 1)
							{
								ABOUT();
								getch();
								break;
							}
							else if (Pointer == 2)
							{
								flag = 2;
								break;
							};
						};
					};
				};
				
				if (flag == 0)
				{
					break;
				}
				else if (flag == 2)
				{
					system("cls");
					gotoxy(setting.GetWidth()/2, setting.GetHeight()/2);
					std::cout << "END";
					exit(0);
				};
			};
		};
};
#endif
