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

//坐标属性
typedef struct pointxy
{
	int x;
	int y;
}MYPOINT;
//蛇的属性;
struct snake
{
	int num;//蛇的节数
	MYPOINT xy[100];//蛇最多有100节
	char position;//方向
}snake;
//食物的属性
struct food
{
	MYPOINT fdxy;//食物的xy坐标
	int eatgrage;//吃了食物有多少分
	int flag;//食物是否存在
}food;
enum movePosition { right = 77, left = 75, down = 80, up = 72};
void initsnake();//初始化蛇
void drawsnake();//画蛇
void movesnake();//移动蛇
void keydown();//按键处理
void initfood();//初始化食物
void drawfood();//画食物
void eatfood();//吃食物
int snakedie();//蛇什么时候挂
void showgrade();//显示分数

int main()
{
	HWND hWnd;
	srand((unsigned int)time(NULL));//设置随机数值，改变食物位置
	hWnd = initgraph(640, 480);
	setbkcolor(WHITE);//设置窗口颜色为白色
	initsnake();
	while (1)
	{
		cleardevice();//刷新
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
		Sleep(50);//VC环境下s需要大写
	}
	getchar();//防止闪屏
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
//食物随机出现
void initfood()
{
	food.fdxy.x = rand() % 65 * 10;//防止蛇吃不到食物
	food.fdxy.y = rand() % 48 * 10;//蛇头都是处于10的倍数上
	food.flag = 1;
	//如果食物出现在蛇身上
	for (int i = 0;i > snake.num;i++)
	{
		if (food.fdxy.x == snake.xy[i].x && food.fdxy.y == snake.xy[i].y)
		{
			food.fdxy.x = rand() % 65 * 10;//重新生成食物
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
	//1.蛇变长了
	//2.食物重新生成
	//3.分数要增加
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
		outtextxy(200, 200, "你撞南墙了！");
		MessageBox(hWnd, "Game Over","撞墙警告",MB_OK);
		return 1;
	}
	//自己吃自己
	for (int i = 1;i < snake.num;i++)
	{
		if (snake.xy[0].x == snake.xy[i].x && snake.xy[0].y == snake.xy[i].y)
		{
			outtextxy(200, 200, "你撞了自己！");
			MessageBox(hWnd,"Game Over！","自杀警告",MB_OK);
			return 1;
		}
	}
	return 0;
}
void showgrade()
{
	char grade[100] = "";
	sprintf(grade, "%d", food.eatgrage);
	setbkmode(TRANSPARENT);//设置文字格式为透明的方式
	settextcolor(LIGHTBLUE);//设置文字颜色
	outtextxy(560, 20, "分数");
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
