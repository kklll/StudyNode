#pragma once
#include <string>
#include<iostream>
using namespace std;
/*
进行工具类的定义：
	其中draw函数为进行图形化界面输出的函数
	angle，为点上的角度变换
	froward为图形向前画线
	left将原点角度向左转90°
	right将原点角度向右转动80°
*/
class Show
{
public:
	Show();
	static void draw(string s, int n);
	static int angle;
	static void forward(int dis);
	static void left();
	static void right();
};