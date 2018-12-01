/*
	编译环境dev-c++，GCC 4.9.2 内容为： 
	数据结构图的最小生成树的算法（Prim算法） 
*/ 
#include<stdio.h>
#include<stdlib.h>
typedef struct edgedata{
	int beg,end;	//开始边的下标与结束边的下标 
	int lenth;	//两边的长度 
}edge;
typedef struct mgraph{		//此函数用来创建图的邻接矩阵 
	int n,e;		//记录点与边的个数信息
	int edges[30][30];		//邻接矩阵
	char verx[30];		//顶点的信息（也就是顶点名称）
}mgraph;
void creat(mgraph *g,char *s,int c)		//邻接矩阵的创建 
{
	int i,j,k,w;
	FILE *rf;
	rf= fopen(s,"r");
	if(rf)
	{
		fscanf(rf,"%d %d",&g.n,&g.e);
		for(i=0;i<g->n;i++)
		{
			fscanf(rf,"%c",&g->verx);
		}
		for(i=0;i<g->n;i++)
		{
			for(j=0;j<g->n;j++)
			{
				if(j==i)
				g->edges[i][i]=0;
				else
				g->edges[i][j]=-1;
			}
		}
		for(k=0;k<g->e;k++)
		{
			fscanf(rf,"%d %d %d",&i,&j,&w);
			g->edges[i][j]=w;
			if(c==0)
			a[j][i]=w;
		}
		fclose(rf);
	}
	else
	{
		printf("打开文件失败无法创建!");
		exit(0);
	}
 } 
void prim(mgraph g,edge tree[m-1])
{
	edge x;		//初始化 
	int d,min,j,k,s,v;
	for(v=1;v<=g.n-1,v++)	//从0开始到各边进行循环 
	{
		tree[v-1].beg=0;	
		tree[v].end=v;
		tree[v-1].lenth=g.edges[0][v];
	}
	for(k=0;k<=g.n-3;k++)
	{
		
	}
}

int main()
 {
		
	return 0;
}
