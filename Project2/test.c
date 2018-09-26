////编译环境vs2017，内容为单链表。
//
//#include<stdio.h>
//#include<stdlib.h>
//typedef int datatype;
//typedef struct  link_node
//{
//	datatype info;
//	struct link_node *next;
//}node;							//定义结构体
//void *init()
//{
//	return NULL;
//}
//void display(node *head)		//链表显示函数
//{
//	node *p;
//	p = head;
//	if (!p)
//		printf("此链表为空，无法输入\n");
//	else
//	{
//		printf("此链表各节点值为:\n");
//		while (p)
//		{
//			printf("%5d", p->info);
//			p = p->next;
//		}
//		printf("\n");
//	}
//}
//node *find(node *head, int i)		//查找结点i位置处的数据地址
//{
//	int j = 1;
//	node *p = head;
//	if (i < 1)
//		return NULL;
//	while (p&&i != j)
//	{
//		p = p->next;
//		j++;
//	}
//	return p;
//}
//node *insert(node *head, datatype x, int i)			//数据插入，（在节点i处后插）
//{
//	node *p, *q;
//	q = find(head, i);
//	if (!q&&i != 0)
//		printf("找不到第%d节点,不能插入%d!\n", i, x);
//	else
//	{
//		p = (node*)malloc(sizeof(node));	//分配内存
//		p->info = x;
//		if (i == 0)		//如果插入位置为第一个节点之后
//		{
//			p->next = head;
//			head = p;
//		}
//		else
//		{
//			p->next = q->next;
//			q->next = p;
//		}
//	}
//	return head;
//}
//node *dele(node *head, datatype x)		//删除一个值为x的节点
//{
//	node *pre = NULL, *p = NULL;
//	if (!head)
//	{
//		printf("链表为空！");
//		return head;
//	}
//	p = head;
//	while (p&&p->info != x)
//	{
//		pre = p;
//		p = p->next;
//	}
//	if (p)
//	{
//		if (!pre)		//如果删除节点为开始的head节点
//			head = head->next;
//		else            //如果删除键点为中间节点
//			pre->next = p->next;
//		free(p);
//	}
//	return head;
//}
//node *creat()
//{
//	node *h = NULL, *q = NULL, *p = NULL;
//	int a, n, i;
//	printf("输入链表节点个数:\n");
//	scanf_s("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		printf("输入第%d个数据:\n", i);
//		scanf_s("%d", &a);
//		p = (node *)malloc(sizeof(node));
//		p->info = a; p->next = NULL;
//		if (i == 1)
//		{
//			h = p; q = p;
//		}
//		else
//		{
//			q->next = p; q = p;
//		}
//	}
//	return h;
//}
//int main()
//{
//	int i, j;
//	node *head = NULL;
//	head = creat();
//	display(head);
//	printf("请输入插入数值:\n");
//	scanf_s("%d", &i);
//	printf("请输入插入位置:\n");
//	scanf_s("%d", &j);
//	head = insert(head, i, j);
//	display(head);
//	printf("请输入查找结点:\n");
//	scanf_s("%d", &i);
//	printf("该结点值为:\n%5d\n", *find(head, i));
//	printf("请输入要删除数值:\n");
//	scanf_s("%d", &i);
//	head = dele(head, i);
//	display(head);
//}
