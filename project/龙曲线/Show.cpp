#include "Show.h"
#include<graphics.h>
#include<conio.h>
#include<math.h>
#define RED RGB(227,23,13)	//宏定义线的颜色
void Show::draw(string s, int n)
{
	initgraph(1000, 700);				//初始化图形化界面大小
	setbkcolor(WHITE);					//设置背景填充颜色	
	cleardevice();						//进行填充	
	setcolor(RED);					//设置直线颜色
	setorigin(1000 / 2, 300);		//设置原点
	if (n > 9)
		setaspectratio(pow(0.80, n - 5), pow(0.80, n - 5));
	for (int i = 0; i < s.length(); i++)
		//对结果字符串进行遍历
	{
		char j = s.at(i);
		if (j == 'F') {
			//如果为F则向前画线10像素
			Show::forward(10);
		}
		if (j == '+') {
			//如果为+则左转90°
			Show::left();
		}
		if (j == '-') {
			;
			//如果为-则右转90°
			Show::right();
		}
		if (j == 'X' || j == 'Y')
		{
			//如果为X或者Y，则不进行操作
			continue;
		}
	}
	int x = _getch();					// 检测键盘输入。
	closegraph();						// 关闭绘图窗口
}

void Show::forward(int dis)
{
	switch (angle)
	{
		//三种情况下的坐标转换方法
	case 0:
		linerel(dis, 0);
		//以坐标轴为轴进行以坐标为基准的画线
		//EasyX坐标轴为左上角为坐标原点，
		//向右x坐标为正，逐渐增大
		//向下y坐标为正，坐标点逐渐增大
		break;
	case 90:
		linerel(0, -dis);
		break;
	case 180:
		linerel(-dis, 0);
		break;
	case 270:
		linerel(0, dis);
		break;
	default:
		break;
	}
}

void Show::left()
{
	//左转函数，将原点的角度加上90°且与360进行取余运算得到左转后的角度
	angle = (angle + 90) % 360;
}

void Show::right()
{
	//右转函数，将原点的角度减去90°且与360进行取余运算得到左转后的角度
	//需要考虑两种情况，如0°右转后角度为270°，需要考虑小于0时转换关系
	if (angle - 90 < 0)
	{
		angle = 360 - 90;
	}
	else
	{
		angle = (angle - 90) % 360;
	}
}
