///*
//    编译环境dev-c++，GCC 4.9.2 内容为：
//	数据结构图的最小生成树的算法（卡鲁斯卡尔算法）
//*/
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct mgraph{		//此函数用来创建图的邻接矩阵 
//	int n,e;		//记录点与边的个数信息
//	int edges[30][30];		//邻接矩阵
//	char verx[30];		//顶点的信息（也就是顶点名称）
//}mgraph;
//typedef struct edgedata
//{
//	int beg,end;
//	int len;
//}edge;
//void QuickSort(edge edges[],int left,int right)
//{			//快速排序 
//	edge x;
//	int i,j,flag=1;
//	if(left<right)
//	{
//		i=left;
//		j=right;
//		x=edges[i];
//		while(i<j)
//		{
//			while(i<j&&x.len<edges[j].len)
//				j--;
//			if(i<j)
//				edges[i++]=edges[j];
//			while(i<j&&x.len>edges[i].len)
//				i++;
//			if(i<j)
//				edges[j--]=edges[i];
//		}
//		edges[i]=x;
//		QuickSort(edges,left,i-1);		//递归实现方法 
//		QuickSort(edges,i+1,right);		
//	}
//}
//void getedge(mgraph g,edge edges[])
//{		//获取可到达边,使用edges数组储存每条边信息 
//	int i,j,k=0;
//	for(i=0;i<g.n;i++)
//		for(j=0;j<i;j++)
//			if(g.edges[i][j]!=0&&g.edges[i][j]<999)
//			{
//				edges[k].beg=i;
//				edges[k].end=j;
//				edges[k++].len=g.edges[i][j];
//			}	
//}
//void kruskal(mgraph g)
//{
//	int i,j,k=0,lt;//lt变量用于储存中间变量
//	int cnvx[30];
//	edge edges[900];
//	edge tree[30];
//	getedge(g,edges);
//	QuickSort(edges,0,g.e-1);
//	for(i=0;i<g.n;i++)
//		cnvx[i]=i;
//	for(i=0;i<g.n-1;i++)
//	{
//		while(cnvx[edges[k].beg]==cnvx[edges[k].end])
//			k++;
//		tree[i]=edges[k];
//		lt=cnvx[edges[k].end];
//		for(j=0;j<g.n;j++)
//			if(cnvx[j]==lt)
//			cnvx[j]=cnvx[edges[k].beg];
//		k++;
//	}
//	printf("最小生成树为:\n");
//	for(j=0;j<g.n-1;j++)
//	{
//		printf("%c------>%c\n",g.verx[tree[j].end],g.verx[tree[j].beg]);
//	}
//}
//void creat(mgraph *g,char *s,int c)		//邻接矩阵的创建 
//{
//	int i,j,k,w;
//	FILE *rf;
//	rf= fopen(s,"r");
//	if(rf)
//	{
//		fscanf(rf,"%d %d\n",&g->n,&g->e);
//		for(i=0;i<g->n;i++)
//		{
//			fscanf(rf,"%c\n",&g->verx[i]);
//		}
//		for(i=0;i<g->n;i++)
//		{
//			for(j=0;j<g->n;j++)
//			{
//				if(j==i)
//				g->edges[i][i]=0;
//				else
//				g->edges[i][j]=999;
//			}
//		}
//		for(k=0;k<g->e;k++)
//		{
//			fscanf(rf,"%d %d %d\n",&i,&j,&w);
//			g->edges[i][j]=w;
//			if(c==0)
//			g->edges[j][i]=w;
//		}
//		fclose(rf);
//	}
//	else
//	{
//		printf("打开文件失败无法创建!");
//		exit(0);
//	}
// } 
// int main()
// {
// 	mgraph g;
// 	char filename[30]={"Data.txt"};
// 	creat(&g,filename,0);
// 	kruskal(g);
// }
