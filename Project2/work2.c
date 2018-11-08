//#include<stdio.h>
//#include<stdlib.h>
//typedef char datatype;
//typedef struct node {            //二叉树的结构体定义
//	datatype data;
//	struct node *lchild;
//	struct node *rchild;
//}tree;
//typedef struct stack {			//栈结构定义
//	int top;
//	tree *data[100];			//记录结点地址
//	int count;
//}zhan;
//tree *root;
//tree *creat_tree()          //递归方法创建二叉树(前序创建),输入的话需要一次全部输入。
//{
//	static int a = 0;
//	datatype ch;
//	tree *t;
//	if ((ch = getchar()) == '!')
//		t = NULL;
//	else
//	{
//		t = (tree *)malloc(sizeof(tree));
//		if (a == 0)
//		{
//			root = t;
//			a++;
//		}
//		t->data = ch;
//		t->lchild = creat_tree();
//		t->rchild = creat_tree();
//	}
//	return t;
//}
//tree *creat_tree_s()
//{
//	tree *p;
//	zhan s;
//	char a[100];
//	int i=0;
//	gets(a);
//	while (a[i] != '\0')
//	{
//		i++;
//		if (a[i-1] != '!')
//		{
//			p = (tree *)malloc(sizeof(tree));
//		}
//	}
//
//	return root;
//}
///*
//while (*str != '\0')
//{
//	str++;
//	if (*(str - 1) != '@')  //建树过程中如果一直未碰到@符号，则持续建立左子树
//	{					//并将节点压入栈中
//		stack[top++] = tempRoot;
//		if (*str != '@')    //判断当前节点是不是@节点，如果是的左子树为空
//		{
//			temp = CreateNode(str);
//			tempRoot->lChild = temp;
//			tempRoot = temp;
//		}
//		else
//		{
//			tempRoot->lChild = NULL;
//		}
//
//	}
//	if (*(str - 1) == '@' && top > 0)  //若前一个节点是@，则出栈，建立右子树
//	{
//		tempRoot = stack[--top];
//		if (*str != '@')//判断当前节点是不是@节点，如果是的右子树为空
//		{
//			temp = CreateNode(str);
//			tempRoot->rChild = temp;
//			tempRoot = temp;
//		}
//		else
//			tempRoot->rChild = NULL;
//	}
//}
//return root;
//*/
//void push(zhan *p,tree *x)
//{
//	p->data[p->top++] = x;
//}
//tree *pop(zhan *p)
//{
//	p->top--;
//	return p->data[p->top];
//}
//void inorder_(tree *t)					//中序遍历非递归算法
//{
//	zhan a;
//	int c=0;
//	a.top = 0;							//初始化
//	while (a.top != 0 || t)
//	{
//		if (t)								//t不为空，压栈
//		{
//			push(&a,t);
//
//			t = t->lchild;					//将t指向其左子树
//		}
//		else
//		{
//			t = pop(&a);					//如果t为空则弹栈，输出其根结点的值
//			c++;
//			t = t->rchild;	
//		}
//	}
//	printf("%c\n", *a.data[0]);
//}
//int main()
//{
//	creat_tree();
//	inorder_(root);
//}
////ABDG!!H!!!CE!I!!F!!              4
////abd!e!!fg!!!c!!                  3