#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <string.h>
#include <sstream>
#include <locale.h>
void ConfigureConsoleWindow (bool Choise)
{
    void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle,&structCursorInfo);
	structCursorInfo.bVisible = Choise;
	SetConsoleCursorInfo( handle, &structCursorInfo ); // отключение каретки
} // функции для настройки консольного чата.

void Center (std::string Stroke)
{
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo((GetStdHandle( STD_OUTPUT_HANDLE )), &consoleInfo);
		for (unsigned short int i = 0; i < ((consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1) / 2 - strlen(Stroke.c_str()) / 2); i++)
			std::cout << " ";
    std::cout << Stroke;
} // Функция для размещения введенного нами текста по центру экрана.
void cls ()
{
	system ("cls");
}
char Getch (std::string Menu)
{
	unsigned short int Button = 0;
		if (Menu == "MainMenu")
		{
			while (true)
			{
				Button = getch ();
					if (Button == 27) // выход из программы
					{
						std::cout.flush ();
						exit (0);
					}
					if (Button == 49 || Button == 50 || Button == 51)
						break;
			}
		}
		if (Menu == "Settings")
			while (true)
			{
				Button = getch ();
					if (Button == 50 || Button == 49 || Button == 9)
						break;
			}
		if (Menu == "Color_Settings")
			while (true)
			{
				Button = getch ();
					if ((Button >= 49 && Button <= 55) || (Button == 9))
						break;
			}
		if (Menu == "Background_Settings")
			while (true)
			{
				Button = getch ();
					if ((Button >= 48 && Button <= 55) || (Button == 9))
						break;
			}
		if (Menu == "Reference")
			while (true)
			{
				Button = getch ();
					if (Button == 9)
						break;
			}

	return Button;
}
void CoutCenterNameColor (std::string Stroke, unsigned short int ColorNumber)
{
	std::cout << "        					   ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((ColorNumber << 4) | 7));
    std::cout << Stroke;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 7));
}
int main ()
{
	unsigned short int Button = 0, ColorNumber = 11, BackgroundColorNumber = 0;
	char NickName [12] = {' ',' ',' ',' ',' ',' ',' ',' ',' ', ' '}; // Этот массив нужен для того, чтобы не производить проверки на длину введенного никнейма, вся строка автоматически обрежется под эти 12 символов
	std::string Message, word;
	system ("color B"); // Светло-голубой цвет текста.
	system ("title chat_user_1"); //  Заголовок программы.
	system("mode con cols=126 lines=31"); // Отключение боковой меню с
	ConfigureConsoleWindow (false);
	while (true)
	{
		cls ();
		Center (" #####~~~~####~~~~####~~~~~~~~~~~~####~~~##~~##~~~####~~~######\n");
		Center (" ##~~##~~##~~##~~##~~~~~~~~~~~~~~##~~##~~##~~##~~##~~##~~~~##  \n");
		Center (" ##~~##~~##~~##~~~####~~~#####~~~##~~~~~~######~~######~~~~##  \n");
		Center (" ##~~##~~##~~##~~~~~~##~~~~~~~~~~##~~##~~##~~##~~##~~##~~~~##  \n");
		Center (" #####~~~~####~~~~####~~~~~~~~~~~~####~~~##~~##~~##~~##~~~~##  \n\n");


        Center ("__________________________________\n");
		Center ("|           Chat menu            |\n");
		Center ("|                                |\n");
		Center ("|--------------------------------|\n");
		Center ("| 1. Login to chat               |\n");
		Center ("|--------------------------------|\n");
		Center ("| 2. Settings                    |\n");
		Center ("|--------------------------------|\n");
		Center ("| 3. Reference                   |\n");
		Center ("|--------------------------------|\n");
		Center ("| Esc. Exit the program          |\n");
		Center ("|________________________________|\n");

		Button = Getch ("MainMenu");
			if (Button == 49) // chat
			{
				cls ();
				ConfigureConsoleWindow (true);
				Center ("#####~~#####~~~####~~######~~####~~######~#####~~##~~##\n");
				Center ("##~~##~##~~~~~##~~~~~~~##~~~##~~~~~~~##~~~##~~##~~#### \n");
				Center ("#####~~####~~~##~###~~~##~~~~####~~~~##~~~#####~~~~##  \n");
				Center ("##~~##~##~~~~~##~~##~~~##~~~~~~~##~~~##~~~##~~##~~~##  \n");
				Center ("  ##~~##~#####~~~####~~######~~####~~~~##~~~##~~##~~~##  \n\n\n\n");




				Center ("Enter your nickname: ");
				std::cin >> NickName;
				std::ofstream Write ("m\\first.txt");
				Write << "";
				Write.close ();
				cls ();
				Center ("##~~~##~#####~##~~~~~~####~~~####~~##~~~##~~~~######~~####~~~~~~####~~##~~##~~####~~###### \n");
				Center ("##~~~##~##~~~~##~~~~~##~~##~##~~##~###~###~~~~~~##~~~##~~##~~~~##~~##~##~~##~##~~##~~~##   \n");
				Center ("##~#~##~####~~##~~~~~##~~~~~##~~##~##~#~##~~~~~~##~~~##~~##~~~~##~~~~~######~######~~~##   \n");
				Center ("#######~##~~~~##~~~~~##~~##~##~~##~##~~~##~~~~~~##~~~##~~##~~~~##~~##~##~~##~##~~##~~~##   \n");
				Center ("  ~##~##~~#####~######~~####~~~####~~##~~~##~~~~~~##~~~~####~~~~~~####~~##~~##~##~~##~~~##   \n\n\n");








				//T - 165, 133, 166, 84
				Button = 13;
				unsigned short int Size2 = 0, Size3 = 0, LastSize2 = 0, LastSize3 = 0;

					while (true)
					{
						std::cout << "\n";
							if (Button == 13) // режим ввода сообщений
							{
									while (true)
									{
										getline(std::cin, Message);
										std::cout << "\n";
										std::cout << NickName << ": ";
											if (Message.length() > 0)
												break;
									}
								std::cout << "\n";
								Button = 165;
							}
							if (Button == 165 || Button == 133 || Button == 166 || Button == 84) // режим чтения сообщений
							{
								//while (true)
								//{
									//{начало считывания сообщений второго пользователя
										std::ifstream Read ("m\\second.txt");
											while (std::getline (Read, word))
											{
												std::istringstream stream (word); // запись одной строки в переменную word
												Size2++;
											} // считываем нынешнее количество строчек в файле у второго пользователя
										Read.close ();
											if (Size2 > LastSize2)
											{
												Size2 = 0;
												std::ifstream Read ("m\\second.txt");
													while (std::getline (Read, word))
													{
														std::istringstream stream (word); // запись одной строки в переменную word
														Size2++;
															if (Size2 > LastSize2)
																std::cout << word << "\n"; // выводим целую новую строчку
													}
												Read.close ();
											}
									//} // конец считывания сообщений второго пользователя
								//}
							}
					}
				std::cout << "\n";
				system ("pause");
			} // конец меню с чатом
			if (Button == 50) // setings
			{
				while (true)
				{
					cls ();
					Center ("~####~~#####~~######~######~######~##~~##~~####~~~#### \n");
					Center ("##~~~~~##~~~~~~~##~~~~~##~~~~~##~~~###~##~##~~~~~##    \n");
					Center ("~####~~####~~~~~##~~~~~##~~~~~##~~~##~###~##~###~~#### \n");
					Center ("~~~~##~##~~~~~~~##~~~~~##~~~~~##~~~##~~##~##~~##~~~~~##\n");
					Center ("~####~~#####~~~~##~~~~~##~~~######~##~~##~~####~~~#### \n\n");

					Center ("__________________________________\n");
					Center ("|         Settings menu          |\n");
					Center ("|                                |\n");
					Center ("|--------------------------------|\n");
					Center ("| 1. Character color             |\n");
					Center ("|--------------------------------|\n");
					Center ("| 2. Color of the background     |\n");
					Center ("|--------------------------------|\n");
					Center ("| Tab. Back to the menu          |\n");
					Center (" |________________________________|\n\n");
					Button = Getch ("Settings");
						if (Button == 9)
							break;
						if (Button == 49) // настройки цвета символов
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | 9));
							Center ("1. Blue\n");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | 10));
							Center ("2. Green\n");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | 11));
							Center ("3. Light blue\n");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | 12));
							Center ("4. Red\n");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | 13));
							Center ("5. Lilac\n");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | 14));
							Center ("6. Yellow\n");
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | 15));
							Center ("7. White\n");
							Button = Getch ("Color_Settings");
								switch (Button)
								{
									case 49: ColorNumber = 9;
									break;
									case 50: ColorNumber = 10;
									break;
									case 51: ColorNumber = 11;
									break;
									case 52: ColorNumber = 12;
									break;
									case 53: ColorNumber = 13;
									break;
									case 54: ColorNumber = 14;
									break;
									case 55: ColorNumber = 15;
								}
							Button = 0;
						} // Конец настроек цвета символа
						if (Button == 50) // настройки заднего фона
						{
							CoutCenterNameColor("0. Black \n",0);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | ColorNumber));
							CoutCenterNameColor("1. Blue\n",9);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | ColorNumber));
							CoutCenterNameColor("2. Light Green\n",10);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | ColorNumber));
							CoutCenterNameColor("3. Light blue\n",11);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | ColorNumber));
							CoutCenterNameColor("4. Light red\n",12);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | ColorNumber));
							CoutCenterNameColor("5. Light purple\n",13);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | ColorNumber));
							CoutCenterNameColor("6. Light yellow\n",14);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | ColorNumber));
							CoutCenterNameColor("7. Bright white\n",15);
							Button = Getch ("Background_Settings");
								switch (Button)
								{
									case 48: BackgroundColorNumber = 0;
									break;
									case 49: BackgroundColorNumber = 9;
									break;
									case 50: BackgroundColorNumber = 10;
									break;
									case 51: BackgroundColorNumber = 11;
									break;
									case 52: BackgroundColorNumber = 12;
									break;
									case 53: BackgroundColorNumber = 13;
									break;
									case 54: BackgroundColorNumber = 14;
									break;
									case 55: BackgroundColorNumber = 15;
								}
						} // Конец настроек цвета заднего фона
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((BackgroundColorNumber << 4) | ColorNumber));
				}
			} // конец меню с настройками

			if (Button == 51) // setings
			{
				cls ();
				Center ("#####~~#####~~######~#####~~#####~~#####~~##~~##~~####~~#####\n");
				Center ("##~~##~##~~~~~##~~~~~##~~~~~##~~##~##~~~~~###~##~##~~##~##   \n");
				Center ("#####~~####~~~####~~~####~~~#####~~####~~~##~###~##~~~~~#### \n");
				Center ("##~~##~##~~~~~##~~~~~##~~~~~##~~##~##~~~~~##~~##~##~~##~##   \n");
				Center ("##~~##~#####~~##~~~~~#####~~##~~##~#####~~##~~##~~####~~#####\n\n");

				Center ("_________________________________________\n");
				Center ("|                                        |\n");
				Center ("|          Software version: 1.0         |\n");
				Center ("|----------------------------------------|\n");
				Center ("|          Developers:                   |\n");
				Center ("|                                        |\n");
				Center ("| Betterthan_Drugs                       |\n");
				Center ("| DeDxM1shaz                             |\n");
				Center ("|----------------------------------------|\n");
				Center ("| The program works in                   |\n");
				Center ("| local area networks(Wi-Fi).            |\n");
				Center ("| Designed for Windows.                  |\n");
				Center ("|----------------------------------------|\n");
				Center ("|    Functions for working with chat:    |\n");
				Center ("|                                        |\n");
				Center ("|To start typing a message, press T.     |\n");
				Center ("|After entering the message, press Enter.|\n");
				Center ("|----------------------------------------|\n");
				Center ("| Tab. Back to the menu                  |\n");
				Center (" |________________________________________|\n\n");
				Button = Getch ("Reference");
		}
	}
}
