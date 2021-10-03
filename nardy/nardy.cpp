// nardy.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Using SDL and standard IO
#include <pch.h>
#include <SDL.h>
#include <ctime>
#include <stdio.h>
#include <iostream>
// Константы поверхностей нажатия клавиш
enum KeyPressSurfaces
{
 KEY_PRESS_SURFACE_DEFAULT,
 KEY_PRESS_SURFACE_UP,
 KEY_PRESS_SURFACE_DOWN,
 KEY_PRESS_SURFACE_LEFT,
 KEY_PRESS_SURFACE_RIGHT,
 KEY_PRESS_SURFACE_TOTAL
};
using namespace std;
//Screen dimension constants
const int SCREEN_WIDTH = 1026;
const int SCREEN_HEIGHT = 732;
int hodwhite( int pw[26], int pb[26]);
int hodblack( int pw[26], int pb[26]);
int hod1(int h1);
int hod2(int h2);
int hod3(int h3);
int hod4(int h4);
int  vyborwhite( int pw[26], int pb[26],int j,int h1,int h2,int h3,int h4);
int  vyborblack( int pw[26], int pb[26],int j, int h1, int h2, int h3, int h4);
int otrisovka( int pw[26], int pb[26], int h1, int h2);
int Handle_Event(SDL_Event* e, int pw[26], int pb[26]);
int Handle_Event1(SDL_Event* e, int pw[26], int pb[26]);
//Запускает SDL и создает окно
bool init();

// Загрузка носителей информации
bool loadMedia();

// Освобождает средства массовой информации и выключает SDL
void close();

// Окно, в которое мы будем рендерить
SDL_Window* gWindow = NULL;

// Поверхность, содержащаяся в окне
SDL_Surface* gScreenSurface = NULL;

// Изображение, которое мы загрузим и покажем на экране
static SDL_Surface* stol = NULL;
static SDL_Surface* fishkawhite = NULL;
static SDL_Surface* fishkablack = NULL;
static SDL_Surface* number1 = NULL;
static SDL_Surface* number2 = NULL;
static SDL_Surface* number3 = NULL;
static SDL_Surface* number4 = NULL;
static SDL_Surface* number5 = NULL;
static SDL_Surface* number6 = NULL;
static SDL_Surface* hodwhite0 = NULL;
static SDL_Surface* hodblack0 = NULL;
static SDL_Surface* WinW = NULL;
static SDL_Surface* WinB = NULL;
static SDL_Surface* none = NULL;
bool init()
{
	// Флаг инициализации
	bool success = true;

	// Инициализация SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Создать окно
		gWindow = SDL_CreateWindow("NARDY", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Получить поверхность окна
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}
bool loadMedia()
{
	bool success = true;
	//stol = SDL_LoadBMP("D:/study/nardy/stol.bmp");
	stol = SDL_LoadBMP("stol1.bmp");
	fishkawhite = SDL_LoadBMP("white.bmp");
	fishkablack = SDL_LoadBMP("black.bmp");
	number1 = SDL_LoadBMP("number1.bmp");
	number2 = SDL_LoadBMP("number2.bmp");
	number3 = SDL_LoadBMP("number3.bmp");
	number4 = SDL_LoadBMP("number4.bmp");
	number5 = SDL_LoadBMP("number5.bmp");
	number6 = SDL_LoadBMP("number6.bmp");
	hodwhite0 = SDL_LoadBMP("hodwhite.bmp");
	hodblack0 = SDL_LoadBMP("hodblack.bmp");
	WinW = SDL_LoadBMP("whitewin.bmp");
	WinB = SDL_LoadBMP("blackwin.bmp");
	none = SDL_LoadBMP("none.bmp");
	return success;
}
void close()
{
	int a = 1;
	// Разгрузочная поверхность
	SDL_FreeSurface(stol);
	stol = NULL;

	// Уничтожить окно
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	while (a == 1) {
	
	}
	// Выход из подсистем SDL
	SDL_Quit();

}
int main(int argc, char* args[])
{
	setlocale(0, "RUS");
	srand(time(NULL));
	int pw[26],pb[26];
	// Запустите SDL и создайте окно
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		// Загрузка носителей информации
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			for (int j = 0; j < 26; j++)
			{
				pw[j] = 0;
				pb[j] = 0;
			}
			pw[0] = 15;
			pb[13] = 15;

			hodwhite(pw,pb);
			// Подождите две секунды
			//SDL_Delay(10000000000000);
		}
	}
	return 0;
}
int Handle_Event(SDL_Event* e, int pw[26], int pb[26])
{
	int j = -1;
	if (SDL_PollEvent(e))
	{
		if (e->type == SDL_MOUSEBUTTONDOWN)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);
			//cout << x << " " << y << endl;
			if (x >= 30 && y >= 417 && x <= 84 && y <= 709){
				j=0;
			}
			if (x >= 101 && y >= 417 && x <= 154 && y <= 709) {
				j = 1;
			}
			if (x >= 171 && y >= 417 && x <= 223 && y <= 709) {
				j = 2;
			}
			if (x >= 241 && y >= 417 && x <= 293 && y <= 709) {
				j = 3;
			}
			if (x >= 311 && y >= 417 && x <= 364 && y <= 709) {
				j = 4;
			}
			if (x >= 380 && y >= 417 && x <= 433 && y <= 709) {
				j = 5;
			}
			if (x >= 501 && y >= 417 && x <= 554 && y <= 709) {
				j = 6;
			}
			if (x >= 572 && y >= 417 && x <= 624 && y <= 709) {
				j = 7;
			}
			if (x >= 640 && y >= 417 && x <= 693 && y <= 709) {
				j = 8;
			}
			if (x >= 711 && y >= 417 && x <= 764 && y <= 709) {
				j = 9;
			}
			if (x >= 780 && y >= 417 && x <= 833 && y <= 709) {
				j = 10;
			}
			if (x >= 850 && y >= 417 && x <= 903 && y <= 709) {
				j = 11;
			}

			if (x >= 852 && y >= 23 && x <= 907 && y <= 318) {
				j = 13;
			}
			if (x >= 782 && y >= 23 && x <= 836 && y <= 318) {
				j = 14;
			}
			if (x >= 712 && y >= 23 && x <= 766 && y <= 318) {
				j = 15;
			}
			if (x >= 643 && y >= 23 && x <= 697 && y <= 318) {
				j = 16;
			}
			if (x >= 572 && y >= 23 && x <= 627 && y <= 318) {
				j = 17;
			}
			if (x >= 502 && y >= 23 && x <= 556 && y <= 318) {
				j = 18;
			}
			if (x >= 382 && y >= 23 && x <= 436 && y <= 318) {
				j = 19;
			}
			if (x >= 312 && y >= 23 && x <= 366 && y <= 318) {
				j = 20;
			}
			if (x >= 242 && y >= 23 && x <= 296 && y <= 318) {
				j = 21;
			}
			if (x >= 172 && y >= 23 && x <= 225 && y <= 318) {
				j = 22;
			}
			if (x >= 102 && y >= 23 && x <= 156 && y <= 318) {
				j = 23;
			}
			if (x >= 32 && y >= 23 && x <= 87 && y <= 318) {
				j = 24;
			}

			if (x >= 959 && y >= 313 && x <= 1013 && y <= 418) {
				hodwhite(pw, pb);
			}
			cout << j<<endl;
		}
	}
	return j;
}
int Handle_Event1(SDL_Event* e, int pw[26], int pb[26])
{
	int a = -1;
	if (SDL_PollEvent(e))
	{
		if (e->type == SDL_MOUSEBUTTONDOWN)
		{
			//Get mouse position
			int x, y;
			SDL_GetMouseState(&x, &y);
			//cout << x << " " << y << endl;
			if (x >= 151 && y >= 341 && x <= 203 && y <= 392) {
				a = 1;
			}
			if (x >= 260 && y >= 341 && x <= 313 && y <= 392) {
				a = 2;
			}
			if (x >= 621 && y >= 341 && x <= 673 && y <= 392) {
				a = 3;
			}
			if (x >= 730 && y >= 341 && x <= 783 && y <= 392) {
				a = 4;
			}

			if (x >= 959 && y >= 313 && x <= 1013 && y <= 418) {
				hodwhite(pw, pb);
			}
			cout << a << endl;
		}
	}
	return a;
}
int hodwhite(int pw[26],int pb[26])
{
	cout << "white";
	int h1 = -1000, h2 = -1000, h3 = -1000, h4 = -1000,j=0;
	h1 = 1 + rand() % 6;
	h2 = 1 + rand() % 6;
	hod1(h1);
	hod2(h2);
	if (h1 == h2)
	{
		hod3(h1);
		hod4(h1);
		h3 = h1;
		h4 = h1;
	}
	cout << h1 << h2 << h3 << h4;
	vyborwhite(pw, pb, j, h1, h2, h3, h4);
	hodblack(pw,pb);
	return 0;
}
int  vyborwhite(int pw[26], int pb[26], int j, int h1, int h2, int h3, int h4)
{
	int a, k = 0, p = 0, rw1 = 0, rw2 = 0, rw3 = 0, rw4 = 0,n,b, h=0;
	SDL_Rect position;
	SDL_Rect position1;
	position.x = 959;
	position.y = 313;
	otrisovka(pw, pb, h1, h2);
	if (h1 != h2 && p == 0)
	{
		k = 2;
	}
	if (h1 == h2)
	{
		h3 = h1;
		h4 = h1;
	}
	b = h1;
	n = h2;
	while (k < 4)
	{
		hod1(h1);
		hod2(h2);
		if (b == n)
		{
			hod3(h3);
			hod4(h4);
		}
		SDL_BlitSurface(hodwhite0, NULL, gScreenSurface, &position);
		if (rw1 == 1)
		{
			position1.x = 150;
			position1.y = 340;
			SDL_BlitSurface(none, NULL, gScreenSurface, &position1);
		}
		if (rw2 == 1)
		{
			position1.x = 260;
			position1.y = 340;
			SDL_BlitSurface(none, NULL, gScreenSurface, &position1);
		}
		if (rw3 == 1)
		{
			position1.x = 620;
			position1.y = 340;
			SDL_BlitSurface(none, NULL, gScreenSurface, &position1);
		}
		if (rw4 == 1)
		{
			position1.x = 730;
			position1.y = 340;
			SDL_BlitSurface(none, NULL, gScreenSurface, &position1);
		}
		SDL_UpdateWindowSurface(gWindow);
		cout << "Ввод столбца";
		int j = -1;
		int a = -1;
		int i = 12, t, w[15], q = 1, r1, r2, z, kd, min = 26;
		j = 12;
		while (pw[j] == 0) {
			for (int p = 0; p < 15; p++) {
				w[p] = 0;
			}
			while (pw[i] == 0)
			{
				i = rand() % 25;
			}
			while (pw[j] == 0)
			{
				j = rand() % 25;
			}
			cout << "рандом" << i << " " << j << endl;
			w[0] = i;
			w[1] = j;
			cout << w[0] << " " << w[1];
			while (q < 14) {
				i = rand() % q + 1;
				j = rand() % q + 1;
				kd = (w[i] + w[j])/2;
				if (rand() % 10 == 1) {
					kd += 1;
				}
				if (rand() % 10 == 2) {
					kd += 2;
				}
				if (rand() % 10 == 3) {
					kd += 3;
				}
				if (rand() % 10 == 4) {
					kd += 4;
				}
				if (rand() % 10 == 6 && kd>=1) {
					kd -= 1;
				}
				if (rand() % 10 == 7 && kd >= 2) {
					kd -= 2;
				}
				if (rand() % 10 == 8 && kd >= 3) {
					kd -= 3;
				}
				if (rand() % 10 == 9 && kd >= 4) {
					kd -= 4;
				}
				if (pw[kd] != 0 && kd<25) {
					q += 1;
					w[q] = kd;
				}
				cout << " " << w[q];
			}
			cout << endl;
			if (h == 30) {
				hodblack(pw,pb);
			}
			h += 1;
			for (int u = 0; u < 15; u++) {
				if (w[u] < 12 && w[u] + h1 >= 12) {
					if (w[u] + h1 + 1 >0 && w[u] + h1 + 1 < min && pb[w[u] + h1 + 1] == 0) {
						min = w[u] + h1 + 1;
						j = w[u];
						a = 1;
					}
				}
				else {
					if (w[u] + h1 > 0 && w[u] + h1 < min && pb[w[u] + h1] == 0) {
						min = w[u] + h1;
						j = w[u];
						a = 1;
					}
				}

				if (w[u] < 12 && w[u] + h2 >= 12) {
					if (w[u] + h2 + 1 > 0 && w[u] + h2 + 1 < min && pb[w[u] + h2 + 1] == 0) {
						min = w[u] + h2 + 1;
						j = w[u];
						a = 2;
					}
				}
				else {
					if (w[u] + h2 > 0 && w[u] + h2 < min && pb[w[u] + h2] == 0) {
						min = w[u] + h2;
						j = w[u];
						a = 2;
					}
				}

				if (w[u] < 12 && w[u] + h3 >= 12) {
					if (w[u] + h3 + 1 > 0 && w[u] + h3 + 1 < min && pb[w[u] + h3 + 1] == 0) {
						min = w[u] + h3 + 1;
						j = w[u];
						a = 3;
					}
				}
				else {
					if (w[u] + h3 > 0 && w[u] + h3 < min && pb[w[u] + h3] == 0) {
						min = w[u] + h3;
						j = w[u];
						a = 3;
					}
				}

				if (w[u] < 12 && w[u] + h4 >= 12) {
					if (w[u] + h4 + 1 > 0 && w[u] + h4 + 1 < min && pb[w[u] + h4 + 1] == 0) {
						min = w[u] + h4 + 1;
						j = w[u];
						a = 4;
					}
				}
				else {
					if (w[u] + h4 > 0 && w[u] + h4 < min && pb[w[u] + h4] == 0) {
						min = w[u] + h4;
						j = w[u];
						a = 4;
					}
				}
			}
		}
		cout << endl << j << " " << a << " " << min << endl;
		SDL_Delay(800);
		switch (a) {
		case 1:
			if (rw1 != 1) {
				if (j + h1 >= 25)
				{
					pw[j] = pw[j] - 1;
					pw[25] = pw[25] + 1;
					h1 = -1000;
					k = k + 1;
					rw1 = 1;
				}
				else
				{
					if (j < 12 && j + h1 >= 12)
					{
						j = j + 1;
					}
					if (pb[j + h1] == 0 && p == 0)
					{
						if (j < 13 && j + h1 >= 13)
						{
							j = j - 1;
						}
						pw[j] = pw[j] - 1;
						if (j < 12 && j + h1 >= 12)
						{
							pw[j + h1 + 1] = pw[j + h1 + 1] + 1;
							h1 = -1000;
						}
						else
						{
							pw[j + h1] = pw[j + h1] + 1;
							h1 = -1000;
						}
						k = k + 1;
						rw1 = 1;
					}
				}
			}
			otrisovka(pw, pb, h1, h2);
			break;
		case 2:
			if (rw2 != 1) {
				if (j + h2 >= 25)
				{
					pw[j] = pw[j] - 1;
					pw[25] = pw[25] + 1;
					h2 = -1000;
					k = k + 1;
					rw2 = 1;
				}
				else
				{
					if (j < 12 && j + h2 >= 12)
					{
						j = j + 1;
					}
					if (pb[j + h2] == 0 && p == 0)
					{
						if (j < 13 && j + h2 >= 13)
						{
							j = j - 1;
						}
						pw[j] = pw[j] - 1;
						if (j < 12 && j + h2 >= 12)
						{
							pw[j + h2 + 1] = pw[j + h2 + 1] + 1;
							h2 = -1000;
						}
						else
						{
							pw[j + h2] = pw[j + h2] + 1;
							h2 = -1000;
						}
						k = k + 1;
						rw2 = 1;
					}
				}
			}
			otrisovka(pw, pb, h1, h2);
			break;
		case 3:
			if (rw3 != 1) {
				if (j + h3 >= 25)
				{
					pw[j] = pw[j] - 1;
					pw[25] = pw[25] + 1;
					h3 = -1000;
					k = k + 1;
					rw3 = 1;
				}
				else
				{
					if (j < 12 && j + h3 >= 12)
					{
						j = j + 1;
					}
					if (pb[j + h3] == 0 && p == 0)
					{
						if (j < 13 && j + h3 >= 13)
						{
							j = j - 1;
						}
						pw[j] = pw[j] - 1;
						if (j < 12 && j + h3 >= 12)
						{
							pw[j + h3 + 1] = pw[j + h3 + 1] + 1;
							h3 = -1000;
						}
						else
						{
							pw[j + h3] = pw[j + h3] + 1;
							h3 = -1000;
						}
						k = k + 1;
						rw3 = 1;
					}
				}
			}
			otrisovka(pw, pb, h1, h2);
			break;
		case 4:
			if (rw4 != 1) {
				if (j + h4 >= 25)
				{
					pw[j] = pw[j] - 1;
					pw[25] = pw[25] + 1;
					h4 = -1000;
					k = k + 1;
					rw4 = 1;
				}
				else
				{
					if (j < 12 && j + h4 >= 12)
					{
						j = j + 1;
					}
					if (pb[j + h4] == 0 && p == 0)
					{
						if (j < 13 && j + h4 >= 13)
						{
							j = j - 1;
						}
						pw[j] = pw[j] - 1;
						if (j < 12 && j + h4 >= 12)
						{
							pw[j + h4 + 1] = pw[j + h4 + 1] + 1;
							h4 = -1000;
						}
						else
						{
							pw[j + h4] = pw[j + h4] + 1;
							h4 = -1000;
						}
						k = k + 1;
						rw4 = 1;
					}
				}
			}
			otrisovka(pw, pb, h1, h2);
			break;
		}
		if(pw[25]>=15)
		{
			position1.x = 140;
			position1.y = 220;
			SDL_BlitSurface(WinW, NULL, gScreenSurface, &position1);
			SDL_UpdateWindowSurface(gWindow);
			SDL_Delay(8000);
			close();
		}
	}
	return 0;
}
int hodblack(int pw[26],int pb[26])
{
	cout << "black";
	int h1 = -1, h2 = -1, h3 = 0, h4 = 0,j=0;
	h1 = 1 + rand() % 6;
	h2 = 1 + rand() % 6;
	hod1(h1);
	hod2(h2);
	if (h1 == h2)
	{
		hod3(h1);
		hod4(h1);
		h3 = h1;
		h4 = h1;
	}
	cout << h1 << h2 << h3 << h4;
	vyborblack(pw, pb, j, h1, h2, h3, h4);
	hodwhite(pw, pb);
	return 0;
}
int vyborblack(int pw[26], int pb[26], int j, int h1, int h2, int h3, int h4)
{
	int a, k = 0, p = 0, rb1 = 0, rb2 = 0, rb3 = 0, rb4 = 0;
	SDL_Rect position;
	SDL_Rect position1;
	position.x = 959;
	position.y = 313;
	otrisovka(pw, pb, h1, h2);
	if (h1 != h2 && p == 0)
	{
		k = 2;
	}
	while(k<4)
	{
		SDL_BlitSurface(hodwhite0, NULL, gScreenSurface, &position);
		if (rb1 == 1)
		{
			position1.x = 150;
			position1.y = 340;
			SDL_BlitSurface(none, NULL, gScreenSurface, &position1);
		}
		if (rb2 == 1)
		{
			position1.x = 260;
			position1.y = 340;
			SDL_BlitSurface(none, NULL, gScreenSurface, &position1);
		}
		if (rb3 == 1)
		{
			position1.x = 620;
			position1.y = 340;
			SDL_BlitSurface(none, NULL, gScreenSurface, &position1);
		}
		if (rb4 == 1)
		{
			position1.x = 730;
			position1.y = 340;
			SDL_BlitSurface(none, NULL, gScreenSurface, &position1);
		}
		SDL_BlitSurface(hodblack0, NULL, gScreenSurface, &position);
		SDL_UpdateWindowSurface(gWindow);
		cout << "Ввод столбца";
		SDL_Event e;
		int j = -1;
		while (j < 0)
		{
			j = Handle_Event(&e, pw, pb);
		}
		if (pb[j] != 0)
		{
			p = 0;
		}
		else
		{
			p = 1;
		}
		cout << "Ввод кубика";
		int a = -1;
		while (a < 0)
		{
			a = Handle_Event1(&e, pw, pb);
		}
		switch (a) {
		case 1:
			if (rb1 != 1) {
				if (j < 12 && j + h1 >= 12)
				{
					pb[j] = pb[j] - 1;
					pb[12] = pb[12] + 1;
					k = k + 1;
					rb1 = 1;
				}
				else
				{
					if (j < 25 && j>13 && j + h1 >= 25)
					{
						if (pw[j + h1 - 25] == 0 && p == 0)
						{
							pb[j] = pb[j] - 1;
							pb[j + h1 - 25] = pb[j + h1 - 25] + 1;
							k = k + 1;
							rb1 = 1;
						}
					}
					else
					{
						if (pw[j + h1] == 0 && p == 0)
						{
							pb[j] = pb[j] - 1;
							pb[j + h1] = pb[j + h1] + 1;
							k = k + 1;
							rb1 = 1;
						}
					}
				}
			}
			otrisovka(pw, pb, h1, h2);
			break;
		case 2:
			if (rb2 != 1) {
				if (j < 12 && j + h2 >= 12)
				{
					pb[j] = pb[j] - 1;
					pb[12] = pb[12] + 1;
					k = k + 1;
					rb2 = 1;
				}
				else
				{
					if (j < 25 && j>13 && j + h2 >= 25)
					{
						if (pw[j + h2 - 25] == 0 && p == 0)
						{
							pb[j] = pb[j] - 1;
							pb[j + h2 - 25] = pb[j + h2 - 25] + 1;
							k = k + 1;
							rb2 = 1;
						}
					}
					else
					{
						if (pw[j + h2] == 0 && p == 0)
						{
							pb[j] = pb[j] - 1;
							pb[j + h2] = pb[j + h2] + 1;
							k = k + 1;
							rb2 = 1;
						}
					}
				}
			}
			otrisovka(pw, pb, h1, h2);
			break;
		case 3:
			if (rb3 != 1) {
				if (j < 12 && j + h3 >= 12)
				{
					pb[j] = pb[j] - 1;
					pb[12] = pb[12] + 1;
					k = k + 1;
					rb3 = 1;
				}
				else
				{
					if (j < 25 && j>13 && j + h3 >= 25)
					{
						if (pw[j + h3 - 25] == 0 && p == 0)
						{
							pb[j] = pb[j] - 1;
							pb[j + h3 - 25] = pb[j + h3 - 25] + 1;
							k = k + 1;
							rb3 = 1;
						}
					}
					else
					{
						if (pw[j + h3] == 0 && p == 0)
						{
							pb[j] = pb[j] - 1;
							pb[j + h3] = pb[j + h3] + 1;
							k = k + 1;
							rb3 = 1;
						}
					}
				}
			}
			otrisovka(pw, pb, h1, h2);
			break;
		case 4:
			if (rb4 != 1) {
				if (j < 12 && j + h4 >= 12)
				{
					pb[j] = pb[j] - 1;
					pb[12] = pb[12] + 1;
					k = k + 1;
					rb4 = 1;
				}
				else
				{
					if (j < 25 && j>13 && j + h4 >= 25)
					{
						if (pw[j + h4 - 25] == 0 && p == 0)
						{
							pb[j] = pb[j] - 1;
							pb[j + h4 - 25] = pb[j + h4 - 25] + 1;
							k = k + 1;
							rb4 = 1;
						}
					}
					else
					{
						if (pw[j + h4] == 0 && p == 0)
						{
							pb[j] = pb[j] - 1;
							pb[j + h4] = pb[j + h4] + 1;
							k = k + 1;
							rb4 = 1;
						}
					}
				}
			}
			otrisovka(pw, pb, h1, h2);
			break;
		}
		if (pb[12] >= 15)
		{
			position1.x = 140;
			position1.y = 220;
			SDL_BlitSurface(WinB, NULL, gScreenSurface, &position1);
			SDL_UpdateWindowSurface(gWindow);
			SDL_Delay(8000);
			close();
		}
	}
	return 0;
}
int hod1(int h1)
{
	SDL_Rect position;
	position.x =150;
	position.y = 340;
	switch (h1) {
	case 1:
		SDL_BlitSurface(number1, NULL, gScreenSurface, &position);
		break;
	case 2:
		SDL_BlitSurface(number2, NULL, gScreenSurface, &position);
		break;
	case 3:
		SDL_BlitSurface(number3, NULL, gScreenSurface, &position);
		break;
	case 4:
		SDL_BlitSurface(number4, NULL, gScreenSurface, &position);
		break;
	case 5:
		SDL_BlitSurface(number5, NULL, gScreenSurface, &position);
		break;
	case 6:
		SDL_BlitSurface(number6, NULL, gScreenSurface, &position);
		break;
	}
	SDL_UpdateWindowSurface(gWindow);
	return h1;
}
int hod2(int h2){
	SDL_Rect position;
	position.x = 260;
	position.y = 340;
	switch (h2) {
	case 1:
		SDL_BlitSurface(number1, NULL, gScreenSurface, &position);
		break;
	case 2:
		SDL_BlitSurface(number2, NULL, gScreenSurface, &position);
		break;
	case 3:
		SDL_BlitSurface(number3, NULL, gScreenSurface, &position);
		break;
	case 4:
		SDL_BlitSurface(number4, NULL, gScreenSurface, &position);
		break;
	case 5:
		SDL_BlitSurface(number5, NULL, gScreenSurface, &position);
		break;
	case 6:
		SDL_BlitSurface(number6, NULL, gScreenSurface, &position);
		break;
	}
	SDL_UpdateWindowSurface(gWindow);
	return h2;
}
int hod3(int h3)
{
	SDL_Rect position;
	position.x = 620;
	position.y = 340;
	switch (h3) {
	case 1:
		SDL_BlitSurface(number1, NULL, gScreenSurface, &position);
		break;
	case 2:
		SDL_BlitSurface(number2, NULL, gScreenSurface, &position);
		break;
	case 3:
		SDL_BlitSurface(number3, NULL, gScreenSurface, &position);
		break;
	case 4:
		SDL_BlitSurface(number4, NULL, gScreenSurface, &position);
		break;
	case 5:
		SDL_BlitSurface(number5, NULL, gScreenSurface, &position);
		break;
	case 6:
		SDL_BlitSurface(number6, NULL, gScreenSurface, &position);
		break;
	}
	SDL_UpdateWindowSurface(gWindow);
	return h3;
}
int hod4(int h4)
{
	SDL_Rect position;
	position.x = 730;
	position.y = 340;
	switch (h4) {
	case 1:
		SDL_BlitSurface(number1, NULL, gScreenSurface, &position);
		break;
	case 2:
		SDL_BlitSurface(number2, NULL, gScreenSurface, &position);
		break;
	case 3:
		SDL_BlitSurface(number3, NULL, gScreenSurface, &position);
		break;
	case 4:
		SDL_BlitSurface(number4, NULL, gScreenSurface, &position);
		break;
	case 5:
		SDL_BlitSurface(number5, NULL, gScreenSurface, &position);
		break;
	case 6:
		SDL_BlitSurface(number6, NULL, gScreenSurface, &position);
		break;
	}
	SDL_UpdateWindowSurface(gWindow);
	return h4;
}
int otrisovka(int pw[26], int pb[26],int h1,int h2)
{
	SDL_Rect position[15][26];
	int x1 = 30, y1 = 655, y2 = 25, x2 = 922;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			position[i][j].x = x1 + j * 70;
			position[i][j].y = y1 - i * 17;
			if (j >= 6)
			{
				position[i][j].x = 50 + x1 + j * 70;
				position[i][j].y = y1 - i * 17;
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		position[i][12].x = 958;
		position[i][12].y = 655 - 11 * i;
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 13; j < 25; j++)
		{
			position[i][j].x = x2 - (j - 12) * 70;
			position[i][j].y = y2 + i * 17;
			if (j >= 19)
			{
				position[i][j].x = -50 + x2 - (j - 12) * 70;
				position[i][j].y = y2 + i * 17;
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		position[i][25].x = 958;
		position[i][25].y = 25 + 11 * i;
	}
	SDL_BlitSurface(stol, NULL, gScreenSurface, NULL);
	hod1(h1);
	hod2(h2);
	if (h1 == h2)
	{
		hod3(h1);
		hod4(h1);
	}
	for (int j = 0; j < 26; j++)
	{
		for (int i = 0; i < pw[j]; i++)
		{
			SDL_BlitSurface(fishkawhite, NULL, gScreenSurface, &position[i][j]);
		}
		for (int i = 0; i < pb[j]; i++)
		{
			SDL_BlitSurface(fishkablack, NULL, gScreenSurface, &position[i][j]);
		}
	}
	SDL_UpdateWindowSurface(gWindow);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
