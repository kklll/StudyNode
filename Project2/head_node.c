//编译环境vs2017，内容为带头单链表。

#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct  link_node
{
	datatype info;
	struct link_node *next;
}node;							//定义链表结构体
void *init()
{
	node *head;
	head = (node *)malloc(sizeof(node));
	head->next = NULL;
	return head;
}
void display(node *head)		//链表显示函数
{
	node *p;
	p = head->next;
	if (!p)
		printf("此链表为空\n");
	else
	{
		printf("此链表各节点值为:\n");
		while (p)
		{
			printf("%5d", p->info);
			p = p->next;
		}
		printf("\n");
	}
}
node *find(node *head, int i)		//查找结点i位置处的数据地址
{
	int j = 0;
	node *p = head;
	if (i < 0)
	{
		printf("带头节点的链表不存在第%d个结点！", i);
		return NULL;
	}
	else if (i == 0)
		return p;
	while (p&&i != j)
	{
		p = p->next;
		j++;
	}
	return p;
}
node *insert(node *head, datatype x, int i)			//数据插入，（在节点i处后插）
{
	node *p, *q;
	q = find(head, i);
	if (!q)
	{
		printf("找不到第%d节点,不能插入%d!\n", i, x);
		return head;
	}
	else
	{
		p = (node*)malloc(sizeof(node));	//分配内存
		p->info = x;
		p->next = q->next;
		q->next = p;
		return head;
	}
}
node *dele(node *head, datatype x)		//删除一个值为x的节点
{
	node *pre = head, *p = NULL;
	p = head->next;
	while (p&&p->info != x)
	{
		pre = p;
		p = p->next;
	}
	if (p)
	{
		pre->next = p->next;
		free(p);
	}
	return head;
}
node *creat(node *head)
{
	node *h = NULL, *q = NULL, *p = NULL;
	int a, n, i;
	printf("输入链表节点个数:\n");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("输入第%d个数据:\n", i);
		scanf_s("%d", &a);
		p = (node *)malloc(sizeof(node));
		p->info = a;
		p->next = NULL;
		if (i == 1)
		{
			head->next = p;
			q = p;
		}
		else
		{
			q->next = p;
			q = p;
		}
	}
	return h;
}
int main()
{
	node *head;
	head=init();
	creat(head);
	display(head);
}
