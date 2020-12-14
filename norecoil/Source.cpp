#include <Windows.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <stdio.h>
#include "Weapons.h"

#include <fcntl.h> 

#include <io.h>
#include <fcntl.h> 
#include <cstdio>

#define FG_RED "\033[31m"
#define FG_PURPLE "\033[35m"
#define FG_GREEN "\033[32m"
#define FG_YELLOW "\033[33m"
#define FG_WHITE "\033[0m"

int currentwep = 0;
int scope = 0;
int barrel = 0;
int randomizer = 0;
int playerfov = 90;
float playersens = 0.5;
bool enabled = false;

void DrawGui()
{
	system("cls");
	system("color 5");
	_setmode(_fileno(stdout), 0x20000);
	wprintf("\n"
		L"               ██████╗  █████╗ ███╗   ███╗███████╗\n"
		L"              ██╔════╝ ██╔══██╗████╗ ████║██╔════╝\n"
		L"              ██║  ███╗███████║██╔████╔██║█████╗\n"
		L"              ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝\n"
		L"              ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗\n"
		L"               ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝\n"
		L"            ███████╗███████╗███╗   ██╗███████╗███████╗\n"
		L"            ██╔════╝██╔════╝████╗  ██║██╔════╝██╔════╝\n"
		L"            ███████╗█████╗  ██╔██╗ ██║███████╗█████╗\n"
		L"            ╚════██║██╔══╝  ██║╚██╗██║╚════██║██╔══╝\n"
		L"            ███████║███████╗██║ ╚████║███████║███████╗\n"
		L"            ╚══════╝╚══════╝╚═╝  ╚═══╝╚══════╝╚══════╝\n\n"


	);
	_setmode(_fileno(stdout), _O_TEXT);
	std::cout << FG_WHITE << " -------------------------------------------------------------- " << std::endl;

	std::cout << FG_WHITE << "              " "[" << FG_PURPLE << "WEAPONS" << FG_WHITE << "]" << "           |"  FG_WHITE << "        " "[" << FG_PURPLE << "ATTACHMENTS" << FG_WHITE << "]" << std::endl;

	std::cout << "                                  |" << std::endl;
	std::cout << "                                  |" << std::endl;

	std::cout << FG_WHITE << "            " "[" << FG_PURPLE << "F2" << FG_WHITE << "]" << "AK-47" << "             |" << FG_WHITE << "        " "[" << FG_PURPLE << "LEF" << FG_WHITE << "]" << "No Scope" << std::endl;
	std::cout << FG_WHITE << "            " "[" << FG_PURPLE << "F3" << FG_WHITE << "]" << "Thompson" << "          |" << FG_WHITE << "        " "[" << FG_PURPLE << "UP" << FG_WHITE << "]" << "Holo" << std::endl;
	std::cout << FG_WHITE << "            " "[" << FG_PURPLE << "F4" << FG_WHITE << "]" << "Custom SMG" << "        |" << FG_WHITE << "        " "[" << FG_PURPLE << "RIG" << FG_WHITE << "]" << "Simple" << std::endl;
	std::cout << FG_WHITE << "            " "[" << FG_PURPLE << "F5" << FG_WHITE << "]" << "LR-300" << "            |" << FG_WHITE << "        " "[" << FG_PURPLE << "PGD" << FG_WHITE << "]" << "x8" << std::endl;
	std::cout << FG_WHITE << "            " "[" << FG_PURPLE << "F6" << FG_WHITE << "]" << "MP5A4" << "             |" << FG_WHITE << "        " "[" << FG_PURPLE << "DOW" << FG_WHITE << "]" << "Supressor" << std::endl;
	std::cout << FG_WHITE << "            " "[" << FG_PURPLE << "F7" << FG_WHITE << "]" << "S.A.R." << "            |" << FG_WHITE << "        " "[" << FG_PURPLE << "NM1" << FG_WHITE << "]" << "Boost" << std::endl;
	std::cout << FG_WHITE << "            " "[" << FG_PURPLE << "F8" << FG_WHITE << "]" << "M249" << "              |" << FG_WHITE << "        " "[" << FG_PURPLE << "NM2" << FG_WHITE << "]" << "No Barrel" << std::endl;

	std::cout << " -------------------------------------------------------------- " << std::endl << std::endl;
	std::cout << std::endl;


	std::cout << FG_WHITE << "                 " "[" << FG_GREEN << "i" << FG_WHITE << "]" << "Current Held Weapon: ";
	switch (currentwep)
	{
	case 0:
		std::cout << "AK-47" << std::endl;
		break;
	case 1:
		std::cout << "Thompson" << std::endl;
		break;
	case 2:
		std::cout << "Custom SMG" << std::endl;
		break;
	case 3:
		std::cout <<  "LR-300" << std::endl;
		break;
	case 4:
		std::cout << "MP5A4" << std::endl;
		break;
	case 5:
		std::cout << "S.A.R." << std::endl;
		break;
	case 6:
		std::cout << "M249" << std::endl;
		break;
	}
	std::cout << FG_WHITE << "                 " "[" << FG_GREEN << "i" << FG_WHITE << "]" << "Current Scope: " ;
	switch (scope)
	{
	case 0:
		std::cout << "None" << std::endl;
		break;
	case 1:
		std::cout << "Holo" << std::endl;
		break;
	case 2:
		std::cout << "X8" << std::endl;
		break;
	case 3:
		std::cout << "X16" << std::endl;
		break;
	}
	std::cout << FG_WHITE << "                 " "[" << FG_GREEN << "i" << FG_WHITE << "]" << "Current Barrel:";
	switch (barrel)
	{
	case 0:
		std::cout << "None" << std::endl;
		break;
	case 1:
		std::cout << "Suppressor" << std::endl;
		break;
	case 2:
		std::cout << "X8" << std::endl;
		break;
	case 3:
		std::cout << "X16" << std::endl;
		break;
	}
	std::cout << std::endl;

	std::cout << FG_WHITE << "                        " "[" << (enabled ? FG_GREEN "INS" : FG_RED "INS")  << FG_WHITE << "]" << "Enabled";


}

float Randomize(float val, int perc)
{
	srand(time(NULL));
	float range = val * perc / 100;

	if (range <= 0.5) return val;
	if (range > 0.5) range = 1;

	int result = 1 + (rand() % (int)range);

	if( (1 + (rand() % 1) > 0)) return val + result;
	else return val + (result * -1);
}

void QuerySleep(int ms) // Sleep / Delay
{
	LONGLONG timerResolution;
	LONGLONG wantedTime;
	LONGLONG currentTime;

	QueryPerformanceFrequency((LARGE_INTEGER*)&timerResolution);
	timerResolution /= 1000;

	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	wantedTime = currentTime / timerResolution + ms;
	currentTime = 0;
	while (currentTime < wantedTime)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
		currentTime /= timerResolution;
	}
}

void Smoothing(double delay, double control_time, float x, float y) 
{
	int x_ = 0, y_ = 0, t_ = 0;
	for (int i = 1; i <= (int)control_time; ++i) 
	{
		int xI = i * x / (int)control_time;
		int yI = i * y / (int)control_time;
		int tI = i * (int)control_time / (int)control_time;
		mouse_event(1, (int)xI - (int)x_, (int)yI - (int)y_, 0, 0);
		QuerySleep((int)tI - (int)t_);
		x_ = xI; y_ = yI; t_ = tI;
	}
	QuerySleep((int)delay - (int)control_time);
}

float getScope(float val)
{
	if (scope == 1)
		return val * 1.2;
	if (scope == 2)
		return val * 3.84;
	return val;
}

float tofovandsens(float sens, int fov, float val)
{
	float a = (0.5 * fov * val) / ( sens * 90);
	
	return getScope(a);

}

int main()
{
	int count = 0;

	SetConsoleTitle(L"Gamesense");

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);

	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { MoveWindow(hwnd, 800, 200, 520, 800, TRUE); }
	SetLayeredWindowAttributes(hwnd, 1000, 1000, LWA_ALPHA);

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);


	SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	
	DrawGui();
	
	while (true)
	{
		if (GetKeyState(VK_F2) & 0x8000)
		{
			if(currentwep != 0)
			{
				currentwep = 0;
				DrawGui();
			}
		}
		if (GetKeyState(VK_F3) & 0x8000)
		{
			if (currentwep != 1)
			{
				currentwep = 1;
				DrawGui();
			}
		}
		if (GetKeyState(VK_F4) & 0x8000)
		{
			if (currentwep != 2)
			{
				currentwep = 2;
				DrawGui();
			}
		}
		if (GetKeyState(VK_F5) & 0x8000)
		{
			if (currentwep != 3)
			{
				currentwep = 3;
				DrawGui();
			}
		}
		if (GetKeyState(VK_F6) & 0x8000)
		{
			if (currentwep != 4)
			{
				currentwep = 4;
				DrawGui();
			}
		}
		if (GetKeyState(VK_F7) & 0x8000)
		{
			if (currentwep != 5)
			{
				currentwep = 5;
				DrawGui();
			}
		}
		if (GetKeyState(VK_F8) & 0x8000)
		{
			if (currentwep != 6)
			{
				currentwep = 6;
				DrawGui();
			}
		}
		if (GetAsyncKeyState(VK_INSERT) == -32767)
		{
			enabled = !enabled;
			DrawGui();
		}
		if (GetAsyncKeyState(VK_LEFT) == -32767)
		{
			scope = 0;
			DrawGui();
		}
		if (GetAsyncKeyState(VK_UP) == -32767)
		{
			scope = 1;
			DrawGui();
		}
		if (GetAsyncKeyState(VK_DOWN) == -32767)
		{
			barrel = 1;
			DrawGui();
		}
		if (GetAsyncKeyState(VK_RIGHT) == -32767)
		{
			barrel = 0;
			DrawGui();
		}
		if (GetAsyncKeyState(VK_PRIOR) == -32767)
		{
			scope = 2;
			DrawGui();
		}
		if(enabled == true)
		{
			if (GetAsyncKeyState(VK_LBUTTON) && GetAsyncKeyState(VK_RBUTTON))
			{

				switch (currentwep)
				{
				case 0:
					if (count < Weapons::ak::pattern.size())
					{
						Smoothing(Weapons::ak::delay, Weapons::ak::controltime.at(count), Randomize(tofovandsens(playersens, playerfov, Weapons::ak::pattern.at(count).x),randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::ak::pattern.at(count).y),randomizer));
						count++;
					}
					break;
				case 1:
					if (count < Weapons::thompson::pattern.size())
					{
						Smoothing(Weapons::thompson::delay, Weapons::thompson::delay, Randomize(tofovandsens(playersens, playerfov, Weapons::thompson::pattern.at(count).x),randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::thompson::pattern.at(count).y),randomizer));
						count++;
					}
					break;
				case 2:
					if (count < Weapons::smg::pattern.size())
					{
						Smoothing(Weapons::smg::delay, Weapons::smg::delay, Randomize(tofovandsens(playersens, playerfov, Weapons::smg::pattern.at(count).x),randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::smg::pattern.at(count).y),randomizer));
						count++;
					}
					break;
				case 3:
					if (count < Weapons::lr::pattern.size())
					{
						Smoothing(Weapons::lr::delay, Weapons::lr::delay, Randomize(tofovandsens(playersens, playerfov, Weapons::lr::pattern.at(count).x),randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::lr::pattern.at(count).y),randomizer));
						count++;
					}
					break;
				case 4:
					if (count < Weapons::mp5::pattern.size())
					{
						Smoothing(Weapons::mp5::delay, Weapons::mp5::delay, Randomize(tofovandsens(playersens, playerfov, Weapons::mp5::pattern.at(count).x),randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::mp5::pattern.at(count).y),randomizer));
						count++;
					}
					break;
				case 5:
					if (count < Weapons::semi::pattern.size())
					{
						Smoothing(Weapons::semi::delay, Weapons::semi::delay, Randomize(tofovandsens(playersens, playerfov, Weapons::semi::pattern.at(count).x),randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::semi::pattern.at(count).y),randomizer));
					}
					break;
				case 6:
						Smoothing(Weapons::m249::delay, Weapons::m249::delay, Randomize(tofovandsens(playersens, playerfov, Weapons::m249::pattern.at(count).x), randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::m249::pattern.at(count).y), randomizer));
					break;
				default:
					break;
				}
			
			}
			else
				count = 0;
		}
		
	}

}