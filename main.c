#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "console.h"
#include <conio.h>
#include <time.h>
#include <string.h>

#define Width  80
#define Height  30

void index();
void play();
void huongdan();
void tacgia();
void mucchoi();
void dieukhien();
void lose();

int mode;
int point=0;
int speed;

enum TrangThai {UP, DOWN, LEFT, RIGHT};

struct toaDo
{
	int x;
	int y;
};

struct Foods
{
	toaDo td;
};

struct Snake
{
	toaDo dot[50];
	int n;
	TrangThai tt;
};

void cauhinh (Snake &S, Foods &f)
{
	S.n=3;
	S.dot[0].x = rand()%72;
	S.dot[0].y = rand()%20;
	S.tt = RIGHT;
	
	f.td.x = (rand()%72) +2;
	f.td.y = (rand()%20) +3;

	switch(mode)
	{
		case 1: speed=150; break;
		case 2: speed=100; break;
		case 3: speed=25; break;
		case 4: speed=200; break;
	}
}

void ConRan_Moi (Snake S, Foods f)
{
	clrscr();
	TextColor(10);
	switch (mode)
	{
		case 1:printf("Mode: Easy"); break;
		case 2:printf("Mode: Normal"); break;
		case 3:printf("Mode: Hard"); break;
		case 4:printf("Mode: Funny"); break;
	};
	printf(" \t\t\tGOOD LUCK HAVE FUN!\t\t\t Point: %d\n", point);
	int i=196;
	int j=179;
	printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i);
	printf("\n");
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf("%c                              		                                      %c\n", j,j);
	printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i,i);

	//in con ran
	TextColor(12);
	gotoXY(S.dot[0].x, S.dot[0].y);
	putchar (254);
	 for (int i = 1 ; i < S.n ; ++i)
	 {
	 	gotoXY(S.dot[i].x, S.dot[i].y);
	 	printf("o");
	 }

	//in moi
	TextColor(9);
	gotoXY(f.td.x, f.td.y);
	printf("*");

}

void dieukhien(Snake &S)
{
	//di chuyen dot ran
	for (int i = S.n-1; i > 0 ; --i)
	{
		S.dot[i]=S.dot[i-1];
	}
 
	//dieu khien dau con ran
	if (_kbhit())
		{
			char key = getch();

			if (key == 'A' || key == 'a' && S.tt!=RIGHT)
				S.tt=LEFT;
			else if (key == 'S' || key == 's' && S.tt!= UP)
				S.tt=DOWN;
			else if (key == 'D' || key == 'd' && S.tt!= LEFT)
				S.tt=RIGHT;
			else if (key == 'W' || key == 'w' && S.tt!= DOWN)
				S.tt=UP;
		}

		if (S.tt == DOWN)
			S.dot[0].y++;
		else if (S.tt == UP)
			S.dot[0].y--;
		else if (S.tt == LEFT)
			S.dot[0].x--;
		else if (S.tt == RIGHT)
			S.dot[0].x++;
	
}

void ranAnMoi(Snake &S, Foods &f)
{
	//an moi va con ran dai ra
	if (S.dot[0].x == f.td.x && S.dot[0].y == f.td.y)
	{
		S.n++;
		point++;

		//moi xuat hien cho khac
		f.td.x = (rand()%65) +3;
		f.td.y = (rand()%15) +3;
		gotoXY(f.td.x, f.td.y);
		printf("*");
		if (mode == 4 && speed > 30)
			speed -= 20;
	}
}

int dieukienchet(Snake &S)
{
	//dam vao tuong hoac can vao than la chet
			if (S.dot[0].x < 1 || S.dot[0].x >= Width-2 ||
				S.dot[0].y < 2 || S.dot[0].y >= Height-5)
			{
				return 0;
			}
			for (int i = 1; i < S.n; ++i)
			{
				if (S.dot[0].x == S.dot[i].x && S.dot[0].y == S.dot[i].y)
				{
					return 0;
				}
			}
}
void index()
{
	clrscr();
	TextColor(10);
	printf("\n");
	printf("			      |||||      |||      |||        ||||        |||   |||   |||||||||	\n");
	printf("			    |||   |||    |||||    |||       ||||||       |||  |||    |||		\n");
	printf("			     |||         ||| ||   |||      |||  |||      ||| |||     |||		\n");
	printf("			       |||       |||  ||  |||     |||    |||     ||||||      |||||||||	\n");
	printf("			         |||     |||   || |||    ||||||||||||    ||| |||     |||		\n");
	printf("			    |||   |||    |||    |||||   |||        |||   |||  |||    |||		\n");
	printf("			      |||||      |||      |||  |||          |||  |||   |||   |||||||||	\n");
	TextColor(12);
	printf("			                                                                   by Nora\n");
	printf("\n\n\n");
	TextColor(8);
	printf("			                     1. Bat dau choi\n");
	printf("			                     2. Huong dan choi\n");
	printf("			                     3. Tac gia\n");
	int choose=getch();
	switch(choose)
	{
		case '1':
		{
			mucchoi();
		} break;
		case '2': huongdan(); break;
		case '3': tacgia(); break;
	}

}

void mucchoi()
{
	clrscr();
	TextColor(10);
	printf("\n\n\t\tChon che do choi: ");
	TextColor(12);
	printf("\n\n\n\t\t\t\t");
	printf("1. Easy\n");
	printf("\n\t\t\t\t");
	printf("2. Normal\n");
	printf("\n\t\t\t\t");
	printf("3. Hard\n");
	printf("\n\t\t\t\t");
	printf("4. Funny\n");
	TextColor(8);
	int choose=getch();
	switch(choose)
	{
		case 49: mode=1; break;
		case 50: mode=2; break;
		case 51: mode=3; break;
		case 52: mode=4; break;
	};
}


void huongdan()
{
	clrscr();
	TextColor(12);
	printf("\n\n\n");
	printf("				Su dung phim W,S,A,D de di chuyen\n");
	printf("				W - di len\n");
	printf("				S - di xuong\n");
	printf("				A - sang trai\n");
	printf("				D - sang phai\n");
	printf("\n\n\n");
	TextColor(8);
	printf("				An phim bat ki de quay lai...\n");
	int choose=getch();
	if (choose)
		index();
}

void tacgia()
{
	clrscr();
	TextColor(12);
	printf("\n\n\n\t\t\t\t");
	printf("Made by Bui Ngoc Minh - KTPM1 - K11 - Hanoi University of Industry\n");
	printf("\n\n\n");
	TextColor(8);
	printf("An phim bat ki de quay lai...\n");
	int choose=getch();
	if (choose)
		index();
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

int main()
{
	Snake S;
	Foods f;
	gotoXY(35,5);
	index();
	srand(time(NULL));
	hidecursor();
	cauhinh(S,f);
	
	while (1)
	{
		
		ConRan_Moi(S,f);
		

		//di chuyen
		dieukhien(S);
		
		ranAnMoi(S,f);

		//funny
		

		//dam vao tuong hoac can vao than la chet
			int die=dieukienchet(S);
			if (die==0)
			{
				break;
			}
		Sleep (speed);
	}
	TextColor(default_ColorCode);
	gotoXY(Width/2-5,Height/2-2);
	printf("YOU LOSE!");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("An enter de thoat...");
	while (getch() != 13)	;
	
	return 0;
}
