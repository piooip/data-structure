#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<assert.h>
#include<math.h>
#include<string.h>
#include<assert.h>
#include<conio.h>

//��������
typedef struct pointxy
{
	int x;
	int y;
}MYPOINT;
//�ߵ�����;
struct snake
{
	int num;//�ߵĽ���
	MYPOINT xy[100];//�������100��
	char position;//����
}snake;
//ʳ�������
struct food
{
	MYPOINT fdxy;//ʳ���xy����
	int eatgrage;//����ʳ���ж��ٷ�
	int flag;//ʳ���Ƿ����
}food;
enum movePosition { right = 77, left = 75, down = 80, up = 72};
void initsnake();//��ʼ����
void drawsnake();//����
void movesnake();//�ƶ���
void keydown();//��������
void initfood();//��ʼ��ʳ��
void drawfood();//��ʳ��
void eatfood();//��ʳ��
int snakedie();//��ʲôʱ���
void showgrade();//��ʾ����

int main()
{
	HWND hWnd;
	srand((unsigned int)time(NULL));//���������ֵ���ı�ʳ��λ��
	hWnd = initgraph(640, 480);
	setbkcolor(WHITE);//���ô�����ɫΪ��ɫ
	initsnake();
	while (1)
	{
		cleardevice();//ˢ��
		if (food.flag == 0)
		{
			initfood();
		}
		drawfood();
		drawsnake();
		if (snakedie())
		{
			break;
		}
		eatfood();
		showgrade();
		movesnake();
		while (_kbhit())
		{
			keydown();
		}
		Sleep(50);//VC������s��Ҫ��д
	}
	getchar();//��ֹ����
	closegraph();
	return 0;


}

void initsnake()
{
	snake.xy[2].x = 0;
	snake.xy[2].y = 0;

	snake.xy[1].x = 10;
	snake.xy[1].y = 0;

	snake.xy[0].x = 20;
	snake.xy[0].y = 0;
	snake.num = 3;
	snake.position = right;
	food.flag = 0;
}
void drawsnake()
{
	for (int i = 0;i < snake.num;i++)
	{
		setlinecolor(BLACK);
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 10, snake.xy[i].y + 10);
	}
}
void movesnake()
{
	for (int i = snake.num - 1;i > 0;i--)
	{
		snake.xy[i].x = snake.xy[i - 1].x;
		snake.xy[i].y = snake.xy[i - 1].y;
	}
	switch(snake.position)
	{
		case right:
			snake.xy[0].x += 10;
			break;
		case left:
			snake.xy[0].x -= 10;
			break;
		case down:
			snake.xy[0].y += 10;
			break;
		case up:
			snake.xy[0].y -= 10;
			break;
		default:
			break;
	}
}
void keydown()
{
	char userkey = 0;
	userkey = _getch();
	switch(userkey)
	{
		case right:
			if (snake.position != left)
				snake.position = right;
			break;
		case left:
			if (snake.position != right)
				snake.position = left;
			break;
		case down:
			if (snake.position != up)
				snake.position = down;
			break;
		case up:
			if (snake.position != down)
				snake.position = up;
			break;
	}

}
//ʳ���������
void initfood()
{
	food.fdxy.x = rand() % 65 * 10;//��ֹ�߳Բ���ʳ��
	food.fdxy.y = rand() % 48 * 10;//��ͷ���Ǵ���10�ı�����
	food.flag = 1;
	//���ʳ�������������
	for (int i = 0;i > snake.num;i++)
	{
		if (food.fdxy.x == snake.xy[i].x && food.fdxy.y == snake.xy[i].y)
		{
			food.fdxy.x = rand() % 65 * 10;//��������ʳ��
			food.fdxy.y = rand() % 48 * 10;
		}
	}
}
void drawfood()
{
	fillrectangle(food.fdxy.x, food.fdxy.y, food.fdxy.x + 10, food.fdxy.y + 10);//***
}
void eatfood()
{
	//1.�߱䳤��
	//2.ʳ����������
	//3.����Ҫ����
	if (snake.xy[0].x == food.fdxy.x && snake.xy[0].y == food.fdxy.y)
	{
		snake.num++;
		food.eatgrage += 10;
		food.flag = 0;
	}
}
int snakedie()
{
	HWND hWnd=NULL;
	if (snake.xy[0].x > 640 || snake.xy[0].x < 0 || snake.xy[0].y>480 || snake.xy[0].y < 0)
	{
		outtextxy(200, 200, "��ײ��ǽ�ˣ�");
		MessageBox(hWnd, "Game Over","ײǽ����",MB_OK);
		return 1;
	}
	//�Լ����Լ�
	for (int i = 1;i < snake.num;i++)
	{
		if (snake.xy[0].x == snake.xy[i].x && snake.xy[0].y == snake.xy[i].y)
		{
			outtextxy(200, 200, "��ײ���Լ���");
			MessageBox(hWnd,"Game Over��","��ɱ����",MB_OK);
			return 1;
		}
	}
	return 0;
}
void showgrade()
{
	char grade[100] = "";
	sprintf(grade, "%d", food.eatgrage);
	setbkmode(TRANSPARENT);//�������ָ�ʽΪ͸���ķ�ʽ
	settextcolor(LIGHTBLUE);//����������ɫ
	outtextxy(560, 20, "����");
	outtextxy(610, 20, food.eatgrage);
}
void print(char* s)
{
	if (*s)
	{
		print(++s);
		printf("%c", *s);
	}
}
