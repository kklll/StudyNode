/*
		编译环境vs2017
		内容为图的创建与遍历
*/
//vs2017 禁用fopen，fscanf，允许fopen_s,fscanf_s  预处理器添加 _CRT_SECURE_NO_WARNINGS防止警告。
//附上fopen和fopen_s fscanf和fscanf_s用法的比较 https://blog.csdn.net/razy_monkey/article/details/50215271
#include<stdio.h>
#include<stdlib.h>
//首先创建邻接表EdgeNode
typedef struct 	node
{
	int adjvex;
	struct node *next;
}EdgeNode;			//邻接表中的边表节点（体结点结构体）
typedef struct VertexNode
{
	char vertex;
	EdgeNode *FirstEdge;
}VertexNode;		//邻接表中表结点（头结点机构体定义）
typedef struct LinkedGraph
{
	VertexNode adjlist[100];
	int n, e;
}LinkedGraph;		//邻接表的结构定义，adjlist储存表头节点，n存顶点个数，e存表的条数。

LinkedGraph * Creat(char *filename, int c)		//创建邻接表的函数（文件读取）c来标记有向图还是无向图（1，有0，无）
{
	LinkedGraph *g;
	g = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	int i, j, k;
	static EdgeNode *s;
	FILE *fp = NULL;			//定义文件指针fp
	fp = fopen(filename, "r");		//设置只读模式
	if (fp)
	{
		fscanf(fp, "%d %d\n", &g->n, &g->e);
		for (i = 0; i < g->n; i++)
		{
			fscanf(fp, "%c ", &g->adjlist[i].vertex);
			//课本上该处为"%ls"具体用法参见：https://blog.csdn.net/ymzhou117/article/details/6932069
			g->adjlist[i].FirstEdge = NULL;
		}
		for (i = 0; i < g->e; i++)
		{
			fscanf(fp, "%d %d", &j, &k);
			s = (EdgeNode *)malloc(sizeof(EdgeNode));
			s->adjvex = k;
			s->next = g->adjlist[j].FirstEdge;		//
			g->adjlist[j].FirstEdge = s;
			if (c == 0)			//无边表的话反向再来一遍
			{
				s = (EdgeNode*)malloc(sizeof(EdgeNode));
				s->adjvex = j;
				s->next = g->adjlist[k].FirstEdge;
				g->adjlist[k].FirstEdge = s;
			}
		}
		fclose(fp);
		printf("图创建完成！");
	}
	else
	{
		printf("文件打开失败，无法进行操作!");
	}
	return g;
}
/*
创建完场，遍历部分
*/
int visited[100];             //标记数组
LinkedGraph * dfs(LinkedGraph *g, int i)
{
	EdgeNode *p;
	printf("\n");
	printf("访问到:");
	printf("%c", g->adjlist[i].vertex);
	visited[i] = 1;
	p = g->adjlist[i].FirstEdge;
	while (p)
	{
		if (!visited[p->adjvex])
			dfs(g, p->adjvex);
		p = p->next;
	}
}
void dfstraverse(LinkedGraph *g)
{/* 深度优先遍历图g*/
	int i;
	for (i = 0; i < g->n; i++)
		visited[i] = 0;
	for (i = 0; i < g->n; i++)
		if (!visited[i])  /* vi未访问过*/
			dfs(g, i);
	printf("\n\n");
}
int visited_2[100];
void bfs(LinkedGraph *g,int i)				//广度优先遍历
{
	int j;
	EdgeNode *p;
	int queue[100], front, rear;		//队列结构的变量定义
	front = rear = 0;				//初始化队列
	printf("访问到:");
	printf("%c\n", g->adjlist->vertex);
	visited_2[i] = 1;
	queue[rear++] = i;
	while (rear>front)
	{
		j = queue[front++];
		p = g->adjlist[j].FirstEdge;
		while (p)
		{
			if (visited_2[p->adjvex] == 0)
			{
				printf("访问到:");
				printf("%c\n", g->adjlist[p->adjvex].vertex);
				queue[rear++] = p->adjvex;
				visited_2[p->adjvex] = 1;
			}
			p = p->next;
		}
	}
}
int bfstraverse(LinkedGraph *g)
{

	int i, count = 0;
	for (i = 0; i < g->n; i++)
	{
		visited_2[i] = 0;
	}
	for (i = 0; i < g->n; i++)
	{
		if (!visited_2[i])
		{
			/*printf("\n");*/
			count++;
			bfs(g, i);
		}
	}
}
int main()
{
	LinkedGraph *g;
	g = Creat("C:\\Users\\10129\\source\\repos\\Project2\\Project2\\Data.txt", 0);
	printf("深度优先遍历顺序为:\n");
	dfstraverse(g);				//深度遍历
	printf("广度优先遍历顺序为:\n");
	bfstraverse(g);				//广度遍历
	return 0;
}
