/*

1、实验目的
通过本实验掌握二叉的建立和递归遍历、非递归遍历算法，了解二叉树在实际中的应用并熟练运用二叉树解决实际问题。
2、实验内容
根据前序遍历的顺序建立一棵二叉树，并根据遍历规则遍历二叉树。
打印输出。
3、实验要求
（1）根据前序遍历的顺序创建一棵二叉树；
（2）对二叉树进行前序、中序、后序遍历。

*/
//编译环境vs2017
#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct node{            //二叉树的结构体定义
	datatype data;
	struct node *lchild;
	struct node *rchild;
}tree;
typedef struct stack {			//栈结构定义
	int top;
	tree *data[100];			//记录结点地址
	datatype tag[100];			//记录左右分支是否都已经遍历完成(用于非递归的后序遍历)
}zhan;
tree *root;
tree *creat_tree()          //递归方法创建二叉树(前序创建),输入的话需要一次全部输入。
{
	static int a = 0;
	datatype ch;
	tree *t;
	if ((ch = getchar()) == '!')
		t = NULL;
	else
	{
		t = (tree *)malloc(sizeof(tree));
		if (a == 0)
		{
			root = t;
			a++;
		}
		t->data = ch;
		t->lchild = creat_tree();
		t->rchild = creat_tree();
	}
	return t;
}
void preorder(tree *t)			//前序遍历递归算法
{
	if (t)
	{
		printf("%c", t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}
void inorder(tree *t)					//中序遍历递归算法
{
	if (t)
	{
		inorder(t->lchild);
		printf("%c", t->data);
		inorder(t->rchild);
	}
}
void postorder(tree *t)					//后序遍历递归算法
{
	if (t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%c", t->data);
	}
}
void push(zhan *p,tree *x)
{
	p->data[p->top++] = x;
}
tree *pop(zhan *p)
{
	p->top--;
	return p->data[p->top];
}
void preorder_(tree *t)					//前序遍历非递归算法
{
	zhan a;
	a.top = 0;							//栈的初始化
	while (a.top != 0 || t)
	{
		if (t)
		{
			printf("%c", t->data);
			push(&a, t);
			t = t->lchild;
		}
		else
		{
			t = pop(&a);
			t = t->rchild;
		}
	}
}
void inorder_(tree *t)					//中序遍历非递归算法
{
	zhan a;
	a.top = 0;							//初始化
	while (a.top != 0 || t)
	{
		if (t)								//t不为空，压栈
		{
			push(&a,t);
			t = t->lchild;					//将t指向其左子树
		}
		else
		{
			t = pop(&a);					//如果t为空则弹栈，输出其根结点的值
			printf("%c", t->data);
			t = t->rchild;	
		}
	}
}
void postorder_(tree *t)					//后序遍历非递归算法
{
	zhan a;
	a.top = 0;
	while (t || a.top != 0)
	{
		if (t)								
		{
			a.data[a.top] = t;				//如果t结点不为空的话，压栈，这写复杂了
			a.tag[a.top] = 0;		
			a.top++;
			t = t->lchild;					//转左子树
		}
		else if (a.tag[a.top-1]==1)			//如果这个结点的左右子树都遍历过了，就弹栈，遍历栈中上一结点
		{
			a.top--;
			t = a.data[a.top];
			printf("%c", t->data);
			t = NULL;						//将t设置为null，然后进行while中判断，如果栈中元素也遍历完了，就结束
		}
		else
		{
			t = a.data[a.top - 1];			//如果只遍历了左子树情况处理。
			a.tag[a.top - 1] = 1;
			t = t->rchild;
		}
	}
}
int main()
{
	printf("请输入创建的二叉树前序遍历顺序：\n");
	creat_tree();
	printf("二叉树创建完成！\n\n");
	printf("前序遍历结果为:\n");
	preorder(root);
	printf("\n\n");
	printf("中序遍历结果为:\n");
	inorder(root);
	printf("\n\n");
	printf("后序遍历结果为:\n");
	postorder(root);
	printf("\n\n");
	printf("前序遍历结果为(非递归):\n");
	preorder_(root);
	printf("\n\n");
	printf("中序遍历结果为(非递归):\n");
	inorder_(root);
	printf("\n\n");
	printf("后序遍历结果为(非递归):\n");
	postorder_(root);
	printf("\n\n");
	return 0;
}