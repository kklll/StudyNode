#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include"Show.h"
using namespace std;
string result;//	定义全局变量result来记录图形的字符串结果
string toUpper(string s);
void dragonCurve(const string seed, int n);//完整代输出
void dragonCurve2(const string seed, int n, unsigned long long int p, unsigned long long int l);//部分输出
void menu();//显示目录的函数
void function1();//显示全部龙曲线函数
void function2();//显示指定位置龙曲线的函数
int choose(int y);//如果为偶数则进行除二操作，直到为奇数为止
void show(int x);//判断奇数所在位置为

int choose(int y)
{
	if (y % 2 == 1)
		return y;
	else
		return choose(y / 2);
}
void show(int x)
{
	int a = choose(x);
	if (((a + 1) / 2) % 2 == 0) {
		result += '-';
	}
	else {
		result += '+';
	}
}

int main()
{
	int num;
	menu();

	while (true)
	{
		cin >> num;
		switch (num)
		{
		case 1:
			system("cls");
			function1();
			break;
		case 2:
			system("cls");
			function2();
		case -1:
			exit(0);
			break;
		}
	}

	return 0;
}

void dragonCurve(const string seed, int n) {//递归生成龙曲线的画图表示
	if (n == 0) {
		//cout << seed;
		result.append(seed);
		return;
	}
	for (int i = 0; i < seed.size(); i++) {
		if (seed[i] == 'X')
			dragonCurve("X+YF", n - 1);
		//进行逐代递归替换
		else if (seed[i] == 'Y')
			dragonCurve("FX-Y", n - 1);
		//进行逐代递归替换
		else {
			result += seed[i];
			//进行总结果的字符串连接
		}
	}
}

void dragonCurve2(const string seed, int n, unsigned long long int p, unsigned long long int l) {//递归生成龙曲线的画图表示
	for (int i = p; i < p + l; i++)
	{
		if (i % 6 == 1 || i % 6 == 5)
		{
			result += 'F';
		}
		if (i % 6 == 2)
		{
			result += 'X';
		}
		if (i % 6 == 4) {
			result += 'Y';
		}
		if (i % 3 == 0)
		{
			int x = i / 3;
			show(x);
		}
	}
}

//static变量的初始化。
int Show::angle = 0;
string toUpper(string s)
/*
将小写字母转换为大写字母，统一字符形式，
这样可以防止非正常输入造成的程序崩溃
*/
{
	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if ((c >= 'a') && (c <= 'z'))
			s[i] = s[i] - 32;
	}
	return s;
}
void menu()
{
	cout << "本程序有以下功能：" << endl;
	cout << "1:输出整代龙曲线的图形以及图形表达式。" << endl;
	cout << "2:输出指定部分龙曲线的表达式以及图形。" << endl;
	cout << "退出请输入-1：" << endl;
	cout << "请输入您选择功能的序号：" << endl;
}
void function1()
{
	cout << "请输入您双曲线的起始种子:(例如:FX)" << endl;
	cout << "其中各个字母表示为:" << endl;
	cout << "F：向前方移动一格并画线。" << endl;
	cout << "+：向左旋转90度。" << endl;
	cout << "-：向右旋转90度。" << endl;
	cout << "X、Y：忽略。" << endl;
	string seed;
	cin >> seed;
	seed = toUpper(seed);
	int count;
	cout << "请输入您的测试用例的个数:";
	cin >> count;
	int i = 0;
	while (i < count)
	{
		int n;//龙曲线代数
		cout << "请输入龙曲线的世代n（0<=n<=50）。" << endl;
		cin >> n;
		dragonCurve(seed, n);	//种子和代数
		cout << "龙曲线的字符串表示为：" << endl;
		cout << result << endl;
		cout << "龙曲线的字符长度为：" << endl;
		cout << result.length() << endl;
		system("pause");
		Show::draw(result, n);
		result.clear();
		Show::angle = 0;
		i++;
	}
	system("pause");
	system("cls");
	menu();
}
void function2()
{
	cout << "请输入您双曲线的起始种子:(例如:FX)" << endl;
	cout << "其中各个字母表示为:" << endl;
	cout << "F：向前方移动一格并画线。" << endl;
	cout << "+：向左旋转90度。" << endl;
	cout << "-：向右旋转90度。" << endl;
	cout << "X、Y：忽略。" << endl;
	string seed;
	cin >> seed;
	seed = toUpper(seed);
	int count;
	cout << "请输入您的测试用例的个数:";
	cin >> count;
	int i = 0;
	while (i < count)
	{
		int n;//龙曲线代数
		unsigned long long int p;//龙曲线起始位置
		unsigned long long int l;//要显示的龙曲线长度
		cout << "请输入龙曲线的世代n（0<=n<=50）、p以及l（1<=p<=1 000 000 000、1<=l<=50）。" << endl;
		cin >> n >> p >> l;
		if (p > 3 * pow(2, n) - 1 || p > 3 * pow(2, n) - 1 + l)
		{
			cout << "长度指定越界，请重新指定!" << endl;
			exit(0);
		}
		dragonCurve2(seed, n, p, l);	//种子和代数
		cout << "龙曲线的字符串表示为：" << endl;
		cout << result << endl;
		cout << "龙曲线的字符长度为：" << endl;
		cout << result.length() << endl;
		system("pause");
		Show::draw(result, 2);
		result.clear();
		Show::angle = 0;
		i++;
	}
	system("pause");
	system("cls");
	menu();
}