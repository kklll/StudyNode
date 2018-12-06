///*
//	编译环境vs2017（2017真香）
//	内容为:拓扑排序
//*/
//#include<stdio.h>
//#include<stdlib.h>
//#define m 30
//typedef char vertextype;
//typedef struct node
//{
//	int adjvex;
//	struct node *next;
//}edgenode;
//typedef struct de{
//	edgenode * firstedge;
//	vertextype vertex;
//	int id;
//}vertexnode;
//typedef struct {
//	vertexnode adjlist[m];
//	int n, e;
//}aovgraph;
//int topsort(aovgraph g)
//{
//	int k = 0, i, j, v, flag[m];
//	int queue[m];
//	int front, rear;
//	edgenode *p;
//	front = rear = 0;	//队列的初始化操作
//	for (i = 0; i < g.n; i++)
//		flag[i] = 0;
//	printf("\nAOV网的拓扑序列为：");
//	for (i = 0; i < g.n; i++)
//	{
//		if (g.adjlist[i].id == 0 && flag[i] == 0)
//		{
//			queue[rear++] = i;
//			flag[i] = 1;
//		}
//		while (rear > front)
//		{
//			v = queue[front++];
//			printf("%c ", g.adjlist[v].vertex);
//			k++;	//计数器，用来判断有没有环。
//			p = g.adjlist[v].firstedge;
//			while (p)
//			{
//				j = p->adjvex;	//j储存顶点的下标值
//				if (--g.adjlist[j].id==0&&flag[j]==0)
//				{
//					queue[rear++] = j;
//					flag[j] = 1;
//				}
//				p = p->next;
//			}
//		}
//	}
//	return k;
//}
//aovgraph * Creat(char *filename, int c)		//创建邻接表的函数（文件读取）c来标记有向图还是无向图（1，有0，无）
//{
//	aovgraph *g;
//	g = (aovgraph *)malloc(sizeof(aovgraph));
//	int i, j, k;
//	static edgenode *s;
//	FILE *fp = NULL;			//定义文件指针fp
//	fp = fopen(filename, "r");		//设置只读模式
//	if (fp)
//	{
//		fscanf(fp, "%d %d\n", &g->n, &g->e);
//		for (i = 0; i < g->n; i++)
//		{
//			fscanf(fp, "%c%d ", &g->adjlist[i].vertex,&g->adjlist[i].id);
//			g->adjlist[i].firstedge = NULL;
//		}
//		for (i = 0; i < g->e; i++)
//		{
//			fscanf(fp, "%d %d\n", &j, &k);
//			s = (edgenode *)malloc(sizeof(edgenode));
//			s->adjvex = k;
//			s->next = g->adjlist[j].firstedge;		//
//			g->adjlist[j].firstedge = s;
//			if (c == 0)			//无边表的话反向再来一遍
//			{
//				s = (edgenode*)malloc(sizeof(edgenode));
//				s->adjvex = j;
//				s->next = g->adjlist[k].firstedge;
//				g->adjlist[k].firstedge = s;
//			}
//		}
//		fclose(fp);
//		printf("图创建完成！");
//	}
//	else
//	{
//		printf("文件打开失败，无法进行操作!");
//	}
//	return g;
//}
//int main()
//{
//	aovgraph *g;
//	g = Creat("sortdata.txt", 1);
//	topsort(*g);
//}