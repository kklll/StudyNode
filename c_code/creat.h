#include<stdio.h>
#include<stdlib.h>
typedef struct mgraph {		//此函数用来创建图的邻接矩阵 
	int n, e;		//记录点与边的个数信息
	int edges[30][30];		//邻接矩阵
	char vexs[30];		//顶点的信息（也就是顶点名称）
}mgraph;
void creat(mgraph *g, char *s, int c)		//邻接矩阵的创建 
{
	int i, j, k, w;
	FILE *rf;
	rf = fopen(s, "r");
	if (rf)
	{
		fscanf(rf, "%d %d\n", &g->n, &g->e);
		for (i = 0; i < g->n; i++)
		{
			fscanf(rf, "%c\n", &g->vexs[i]);
		}
		for (i = 0; i < g->n; i++)
		{
			for (j = 0; j < g->n; j++)
			{
				if (j == i)
					g->edges[i][i] = 0;
				else
					g->edges[i][j] = 999;
			}
		}
		for (k = 0; k < g->e; k++)
		{
			fscanf(rf, "%d %d %d\n", &i, &j, &w);
			g->edges[i][j] = w;
			if (c == 0)
				g->edges[j][i] = w;
		}
		fclose(rf);
	}
	else
	{
		printf("打开文件失败无法创建!");
		exit(0);
	}
}

