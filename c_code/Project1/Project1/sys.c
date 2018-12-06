/*
实验四  排序方法实践（2学时）
1、实验目的
通过本实验掌握排序的基本算法和过程以及查找的基本方法和过程。
2、实验内容
设计一个排序和查找系统。能够实现对给定的一组学生的借书证信息（如：卡号、姓名、系别、班号等）进行排序和查找。
1)按照卡号顺序进行排序；
2）能够实现查找某个系的所有的借书卡号并输出。
3、实验要求
（1）建立关于借书证信息结点的结构体；
（2）定义借书证信息的记录并录入基本信息；
（3）写出用某种排序算法（如冒泡排序）按关键字对记录进行排序的算法函数；
（4）对借书证信息的记录按系名建立索引查找结构；
（5）输入某个要查找的系名，用索引查找方法查找并输出该系的所有借书证信息。
*/
/*
编译环境 vs2017，排序。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define m 100
typedef struct node
{
	char id[15];
	char name[10];
	char department[15];
	char classid[15];
}info;
int creat(char file[30],info info[m])
{
	int n, i;
	FILE *fp = fopen(file, "r");
	if (fp)
	{
		printf("文件读取成功\n");
	}
	else
	{
		printf("文件读取失败\n");
		exit(0);
	}
	fscanf(fp, "%d\n",&n);
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s \n", &info[i].name, &info[i].id, &info[i].department, &info[i].classid);
	}
	printf("未排序前的顺序为:\n");
	for (i = 0; i < n; i++)
	{
		printf("%s %s %s %s \n", info[i].name, info[i].id, info[i].department, info[i].classid);
	}
	return n;
}
void QuickSort(info y[m],int left,int right,int n)
{
	info x;
	int i, j, flag = 1;
	if (left < right)
	{
		i = left;
		j = right;
		x = y[i];
		while (i < j)
		{
			while (i < j&&strcmp(x.id,y[j].id)<0)
				j--;
			if (i < j)
				y[i++] = y[j];
			while (i<j&&strcmp(x.id, y[j].id)> 0)
				i++;
			if (i < j)
				y[j--] = y[i];
		}
		y[i] = x;
		QuickSort(y, left, i - 1,n);		//递归实现方法 
		QuickSort(y, i + 1, right,n);
	}
}
int main()
{
	info x[m];
	int n,i;
	n=creat("sort.txt", x);
	printf("\n\n排序后的结果为:\n");
	QuickSort(x,0,7,n);
	for (i = 0; i < n; i++)
	{
		printf("%6s %s %s %s \n", x[i].name, x[i].id, x[i].department, x[i].classid);
	}
	return 0;
}