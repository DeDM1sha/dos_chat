#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <time.h>
void ConfigureConsoleWindow ()
{
    void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle,&structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo( handle, &structCursorInfo ); // Отключение каретки.
	//setlocale (LC_ALL, "Russian"); // Русская кодировка текста.
	system ("color B"); // Светло-голубой цвет текста.
	system ("title chat"); // Заголовок программы.
} // Функция для настройки консольного окна.

void Center (std::string Stroke)
{
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo((GetStdHandle( STD_OUTPUT_HANDLE )), &consoleInfo);
		for (unsigned short int i = 0; i < ((consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1) / 2 - strlen(Stroke.c_str()) / 2); i++)
			std::cout << " ";
    std::cout << Stroke;
} // Функция для размещения введенного нами текста по центру экрана.
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
					if (Button == 49 || Button == 50)
						break;
			}
		}
		if (Menu == "Settings")
			while (Button != 49 || Button != 50 || Button != 27)
			{
				Button = getch ();
					if (Button == 50 || Button == 49 || Button == 27)
						break;
			}
	system ("cls");
	return Button;
}
void TextInColor (std::string ColorName, std::string Text)
{
		if (ColorName == "Green")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 10));
		if (ColorName == "Red")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 12));
		if (ColorName == "Yellow")
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 14));
	std::cout << Text;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 11));
} // Функция изменения цвета текста.
int main ()
{
	char Button = 0;
	
	ConfigureConsoleWindow ();
	while (true)
	{
		long int currTime   = clock() / CLK_TCK;
		if (currTime == 1)
			break;
		Center ("██████████████████████████████████████████████\n");
		Center ("█────███────██───███████────██─██─██────██───█\n");
		Center ("█─██──██─██─██─█████████─██─██─██─██─██─███─██\n");
		Center ("█─██──██─██─██───██───██─█████────██────███─██\n");
		Center ("█─██──██─██─████─███████─██─██─██─██─██─███─██\n");
		Center ("█────███────██───███████────██─██─██─██─███─██\n");
		Center (" ██████████████████████████████████████████████\n\n");
		Center ("__________________________________\n");
		Center ("|            Меню чата           |\n");
		Center ("|                                |\n");
		Center ("|--------------------------------|\n");
		Center ("| 1. Войти в чат                 |\n");
		Center ("|--------------------------------|\n");
		Center ("| 2. Настройки                   |\n");
		Center ("|--------------------------------|\n");
		Center ("| Esc. Выйти из программы        |\n");
		Center ("|________________________________|\n");
		Button = Getch ("MainMenu");	
			if (Button == 49) // chat
			{
				//введите ник
			}
			if (Button == 50) // setings
			{
				Center ("█████████████████████████████████████──██████████████\n");
				Center ("█─██─██────██────██───██────██────██─██─██─██─██─██─█\n");
				Center ("█─██─██─██─██─██─███─███─██─██─██─██─██─██─█─███─██─█\n");
				Center ("█────██────██─██████─███────██─██─██─█──██──████─█──█\n");
				Center ("█─██─██─██─██─██─███─███─█████─██─██──█─██─█─███──█─█\n");
				Center ("█─██─██─██─██────███─███─█████────██─██─██─██─██─██─█\n");
				Center ("█████████████████████████████████████████████████████\n\n");
				Center ("__________________________________\n");
				Center ("|            Меню настроек       |\n");
				Center ("|                                |\n");
				Center ("|--------------------------------|\n");
				Center ("| 1. Цвет символов               |\n");
				Center ("|--------------------------------|\n");
				Center ("| 2. Цвет заднего фона           |\n");
				Center ("|--------------------------------|\n");
				Center ("| Esc. Вернуться в меню          |\n");
				Center ("|________________________________|\n\n");
				Button = Getch ("Settings");
					if (Button == 50)
					{
						Center ("1. ");
						TextInColor ("Green", "Зеленый");
						TextInColor ("Red", "    2. Красный \n");
						system ("pause");
					}
			}
	}
}
