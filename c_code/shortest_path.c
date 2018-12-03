/*
	编译环境dev-c++，GCC 4.9.2 内容为：
	数据结构最短路径的生成
*/
#include<stdio.h>
#include<stdlib.h>
#include"creat.h"		//引入邻接矩阵的创建函数 
#define m 30
typedef enum {
	false, true
}bool;	//将1替换为true，将0替换为false 
typedef int dist[m];	//距离向量 
typedef int path[m];	//路径向量 
void dj(mgraph g, int v0, path p, dist d)
{
	bool final[m];		//标记是否求出最短路径 
	int i, j, k, v, min, x;
	//以上为栈结构内的变量
	for (v = 0; v < g.n; v++)	//执行初始化 
	{
		final[v] = false;
		d[v] = g.edges[v0][v];
		if (d[v] < 999 && d[v] != 0)
			p[v] = v0;
		else
			p[v] = -1;
	}

	final[v0] = true;
	d[v0] = 0;
	for (i = 1; i < g.n; i++)
	{
		min = 999;	//此时无最小长度，相当于初始化。 
		for (k = 0; k < g.n; ++k)
			if (!final[k] && d[k] < min)
			{
				v = k;	//v来记录当前节点。 
				min = d[k];
			}
			printf("\n%c--->%c---%d\n " ,g.vexs[v0],g.vexs[v],min);
			if (min == 999)
				return;
			final[v] = true;	//表示其已经求出最短路径。 
		for (k = 0; k < g.n; ++k)
		{
			if (!final[k] && (min + g.edges[v][k] < d[k]))
			{
				d[k] = min + g.edges[v][k];
				p[k] = v;
			}
		}
	}
}
void print(mgraph g, path p, dist d)
{
	int st[m], i, pre, top = -1;
	//以上为栈结构内的变量
	for (i = 0; i < g.n; i++)
	{
		st[++top] = i;
		printf("\n距离为%3d,路径为:\n", d[i]);
		pre = p[i];
		while (pre != -1)
		{
			st[++top] = pre;
			pre = p[pre];
		}
		while (top > 0)
			printf("%2d", st[top--]);
	}
}
int main()
{
	mgraph g;
	path p;
	dist d;
	int v0;
	creat(&g, "s-data.txt", 1);
	printf("请输入原点序号：\n");
	scanf("%d", &v0);
	dj(g, v0, p, d);
	print(g, p, d);

}
