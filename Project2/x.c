:////编译环境vs2017
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef char datatype;
//typedef struct  link_node
//{
//	char name[20];
//	char xuehao[20];
//	char phone[20];
//	struct link_node *next;
//}node;							//定义结构体
//node *init()
//{
//	return NULL;
//}
//void display(node *head)		//链表显示函数
//{
//	node *p;
//	p = head;
//	if (!p)
//		printf("此链表为空！\n");
//	else
//	{
//		printf("%5s\t%5s\t%5s\n", "姓名", "学号", "联系方式");
//		while (p)
//		{
//			printf("%5s\t", p->name);
//			printf("%5s\t", p->xuehao);
//			printf("%5s\t", p->phone);
//			p = p->next;
//			printf("\n");
//		}
//		printf("\n");
//		printf("完成！\n");
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
//node *insert(node *head)			//数据插入，（在节点i处后插）
//{
//	node *p, *q;
//	int i;
//	printf("请输入要插入的结点位置:");
//	scanf_s("%d", &i);
//	q = find(head, i);
//	if (!q&&i != 0)
//		printf("找不到第%d节点,不能插入.\n", i);
//	else
//	{
//		p = (node*)malloc(sizeof(node));	//分配内存
//		printf("请输入学号:");
//		getchar();
//		gets(p->xuehao);
//		printf("请输入姓名:");
//		gets(p->name);
//		printf("请输入联系方式(手机号码):");
//		gets(p->phone);
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
//	printf("完成！\n");
//	return head;
//}
//node *dele(node *head)		//删除学号为x的节点
//{
//	node *pre = NULL, *p = NULL;
//	char name[20];
//	if (!head)
//	{
//		printf("链表为空！");
//		return head;
//	}
//	p = head;
//	printf("请输入要删除的学生的姓名：");
//	getchar();
//	gets(name);
//	while (p&&strcmp(p->name,name)!=0)
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
//	}
//	free(p);
//	printf("完成！\n");
//	return head;
//}
//node *creat()
//{
//	node *h=NULL, *q=NULL, *p=NULL;
//	int n, i;
//	printf("输入要录入学生个数:\n");
//	scanf_s("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//
//		printf("输入第%d个数据:\n", i);
//		p = (node *)malloc(sizeof(node));
//		if(i==1)
//		getchar();
//		printf("请输入学号:");
//		gets(p->xuehao);
//		printf("请输入姓名:");
//		gets(p->name);
//		printf("请输入联系方式(手机号码):");
//		gets(p->phone);
//		p->next = NULL;
//		if (i == 1)
//		{
//			h = p; q = p;
//		}
//		else
//		{
//			q->next = p; q = p;
//		}
//	}
//	printf("完成！\n");
//	return h;
//}
//void display_name(node *head)
//{
//	node *p=head;
//	char name[20];
//	printf("请输入要找同学的姓名:");
//
//	getchar();
//	gets(name);
//	while (strcmp(p->name,name)!=0 && p!=NULL)
//		p = p->next;
//	if (!p)
//	{
//		printf("找不到该同学");
//	}
//	else
//	{	
//		printf("\n");
//		printf("该同学学号为:%s\n", p->xuehao);
//		printf("该同学姓名为:%s\n", p->name);
//		printf("该同学联系方式为:%s\n", p->phone);
//		printf("\n");
//		printf("完成！\n");
//	}
//}
//int main()
//{
//	node *head=NULL;
//	int func;
//	printf("本程序有以下功能:\n");
//	printf("1:创建学生联系方式\n");
//	printf("2:插入学生联系方式:\n");
//	printf("3:删除某位学生联系方式\n");
//	printf("4:以姓名为索引索引学生联系方式\n");
//	printf("5:输出全部学生信息\n");
//	printf("6:退出系统\n");
//	printf("请选择功能序号:");
//	scanf_s("%d", &func);
//	while (func != 6)
//	{
//		switch (func)
//		{
//		case 1:
//			head = init();
//			head = creat();
//			break;
//		case 2:
//			head = insert(head);
//			break;
//		case 3:
//			head = dele(head);
//			break;
//		case 4:
//			display_name(head);
//			break;
//		case 5:
//			display(head);
//			break;
//		}
//		printf("\n");
//		system("pause");
//		system("cls");
//		printf("本程序有以下功能:\n");
//		printf("1:创建学生联系方式\n");
//		printf("2:插入学生联系方式:\n");
//		printf("3:删除某位学生联系方式\n");
//		printf("4:以姓名为索引索引学生联系方式\n");
//		printf("5:输出全部学生信息\n");
//		printf("6:退出系统\n");
//		printf("请选择功能序号:");
//		scanf_s("%d", &func);
//		printf("\n");
//	}
//	return 0;
//}
