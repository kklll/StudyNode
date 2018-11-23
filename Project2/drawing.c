//#include<stdio.h>
//#include<stdlib.h>
////首先创建邻接表EdgeNode
//typedef struct 	node
//{
//	int adjvex;
//	struct node *next;
//}EdgeNode;			//邻接表中的边表节点（体结点结构体）
//typedef struct VertexNode
//{
//	char vertex;
//	EdgeNode *FirstEdge;
//}VertexNode;		//邻接表中表结点（头结点机构体定义）
//typedef struct LinkedGraph
//{
//	VertexNode adjlist[100];
//	int n, e;
//}LinkedGraph;		//邻接表的结构定义，adjlist储存表头节点，n存顶点个数，e存表的条数。
//
//LinkedGraph * Creat(LinkedGraph *g, char *filename, int c)		//创建邻接表的函数（文件读取）c来标记有向图还是无向图（1，有0，无）
//{
//	int i, j, k;
//	static EdgeNode *s;
//	FILE *fp = NULL;			//定义文件指针fp
//	fp = fopen(filename, "r");		//设置只读模式
//	if (fp)
//	{
//		fscanf(fp, "%d%d\n", &g->n, &g->e);
//		for (i = 0; i < g->n; i++)
//		{
//			fscanf(fp, "%c", &g->adjlist[i].vertex);
//			//课本上该处为"%ls"具体用法参见：https://blog.csdn.net/ymzhou117/article/details/6932069
//			g->adjlist[i].FirstEdge = NULL;
//		}
//		for (i = 0; i < g->e; i++)
//		{
//			fscanf(fp, "%d%d", &j, &k);
//			s = (EdgeNode *)malloc(sizeof(EdgeNode));
//			s->adjvex = k;
//			s->next = g->adjlist[j].FirstEdge;		//
//			g->adjlist[j].FirstEdge = s;
//			if (c == 0)			//无边表的话反向再来一遍
//			{
//				s = (EdgeNode*)malloc(sizeof(EdgeNode));
//				s->adjvex = j;
//				s->next = g->adjlist[k].FirstEdge;
//				g->adjlist[k].FirstEdge = s;
//			}
//		}
//		fclose(fp);
//		printf("图创建完成！");
//	}
//	else
//	{
//		printf("文件打开失败，无法进行操作!");
//	}
//}
///*
//创建完场，遍历部分
//*/
//int visited[100];             //标记数组
//LinkedGraph * dfs(LinkedGraph *g, int i)
//{
//	EdgeNode *p;
//	printf("访问到:%c\n", g->adjlist[i].vertex);
//	visited[i] = 1;
//	p = g->adjlist[i].FirstEdge;
//	while (p)
//	{
//		if (!visited[p->adjvex])
//			dfs(g, p->adjvex);
//		p = p->next;
//	}
//}
//
//void dfstraverse(LinkedGraph *g)
//{/* 深度优先遍历图g*/
//	int i;
//	for (i = 0; i < g->n; i++)
//		visited[i] = 0;
//	for (i = 0; i < g->n; i++)
//		if (!visited[i])  /* vi未访问过*/
//			dfs(g, i);
//}
//int main()
//{
//	LinkedGraph g;
//	Creat(&g, "E:\\Data.txt", 0);
//	dfstraverse(&g);
//	return 0;
//}
