////递归与非递归求二叉树叶子节点个数
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
//int leaf_number(tree *p)
//{
//	if (p)
//	{
//		if (p->lchild == NULL && p->rchild == NULL)
//			return 1;
//		else
//			return(leaf_number(p->lchild) + leaf_number(p->rchild));
//	}
//	else
//		return 0;
//}
////ABDG!!H!!!CE!I!!F!!              4
////abd!e!!fg!!!c!!                  3
//void push(zhan *p,tree *x)
//{
//	p->data[p->top++] = x;
//}
//tree *pop(zhan *p)
//{
//	p->top--;
//	return p->data[p->top];
//}
//int leaf_number_2(tree *p)                     //非递归算法
//{
//	zhan s;
//	s.top = 0;
//	s.count = 0;
//	while (s.top !=0 || p)
//	{
//		if (p)
//		{										//同前序遍历相同，判断条件改变即可。
//			if (p->lchild == NULL && p->rchild == NULL)
//				s.count++;
//			push(&s, p);
//			p=p->lchild;
//		}
//		else
//		{
//			p=pop(&s);
//			p = p->rchild;
//		}
//	}
//	return s.count;
//}
//int main()
//{
//	tree *p;
//	creat_tree();
//	printf("%d\n",leaf_number(root));				//递归输出
//	printf("%d\n", leaf_number_2(root));			//非递归输出
//}