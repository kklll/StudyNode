////编译环境vs2017
//
////顺序串
//#include<stdio.h>
//#include<stdlib.h>
//#define maxsize 100
//typedef struct {
//	char str[maxsize];
//	int len;
//}seqstr;
//int position[20];
//seqstr *strcreat(seqstr *s)
//{
//	int i = 0;
//	gets(s->str);
//	while (s->str[i] != '\0')
//	{
//		i++;
//	}
//	s->len = i;
//	printf("操作完成！\n");
//	return(s);
//}
//seqstr *strassign(seqstr *s, seqstr *t)
//{
//	int i = 0;
//	while (t->str[i] != '\0')
//	{
//		s->str[i] = t->str[i];
//		i++;
//	}
//	s->str[i] = '\0';
//	s->len = i + 1;
//	return s;
//}
//int strlen(seqstr *s)
//{
//	int i = 0;
//	while (s->str[i] != '\0')
//		i++;
//	return i + 1;
//}
//int strempty(seqstr *s)
//{
//	if (!s->str[0])
//		return 1;
//	else
//	{
//		return 0;
//	}
//}
//void strclean(seqstr *s)
//{
//	if (s->len != 0)
//		s->len = 0;
//	printf("删除完成！\n");
//}
//int strcompare(seqstr *s1, seqstr *s2)
//{
//	int i = 0, j = 0, res;
//	while (s1->str[i] && s2->str[i])
//	{
//		if (s1->str[i] > s2->str[i])
//		{
//			res = 1;
//			break;
//		}
//		else if (s1->str[i] < s2->str[i])
//		{
//			res = -1;
//			break;
//		}
//		i++;
//	}
//	if (!s1->str[i] && s2->str[i])
//		res = 1;
//	else if (!s2->str[i] && s1->str[i])
//		res = -1;
//	else if (!s1->str[i] && !s2->str[i])
//		res = 0;
//	return res;
//}
//seqstr *strconcat(seqstr *s1, seqstr *s2)
//{
//	int i = 0, j = 0;
//	while (s1->str[i] != '\0')
//		i++;
//	while (s2->str[j] != '\0')
//	{
//		s1->str[i + j] = s2->str[j];
//		j++;
//	}
//	s1->str[i + j] = '\0';
//	s1->len = i + j;
//	return s1;
//}
//void substring(seqstr *s, int i, int len)
//{
//	int j;
//	if (s->str[i - 1] != NULL || s->str[i + len - 1] != NULL)
//	{
//		printf("无法找到此字串！");
//		exit(0);
//	}
//	else
//	{
//		j = i - 1;
//		while (j < i + len - 1)
//		{
//			printf("%c", s->str[j]);
//			j++;
//		}
//	}
//}
//int *getnext(seqstr *p)
//{
//	static int next[100];
//	int i, j;
//	next[0] = -1;
//	i = 0;
//	j = -1;
//	while (i < p->len)
//	{
//		if (j == -1 || p->str[i] == p->str[j])
//		{
//			++i;
//			++j;
//			next[i] = j;
//		}
//		else
//		{
//			j = next[j];
//		}
//	}
//	return next;
//}
//int *index(seqstr *t, seqstr *p, int next[])
//{
//	int i, j;
//	i = 0;
//	j = 0;
//	while (i < t->len&&j < p->len)
//	{
//		if (j == -1 || t->str[i] == p->str[j])
//		{
//			i++; j++;
//		}
//		else
//			j = next[j];
//	}
//	if (j == p->len)
//		return(i - p->len + 1);
//	else
//	{
//		return -1;
//	}
//}
//seqstr *strinsert(seqstr *s, int i, seqstr *t)
//{
//	int j;
//	if (i<0 || i>s->len + 1)
//	{
//		printf("输入错误，无法插入！\n");
//		exit(0);
//	}
//	for (j = s->len - 1; j >= i - 1; j--)
//		s->str[j + t->len] = s->str[j];
//	s->str[t->len + s->len] = '\0';
//	for (j = 0; j <= t->len - 1; j++)
//		s->str[i + j - 1] = t->str[j];
//	return s;
//}
//seqstr *strdelete(seqstr *s, int i, int len)
//{
//	int j;
//	if (i<1 || i>s->len || i + len - 1 > s->len)
//	{
//		printf("输入错误，无法删除！\n");
//		exit(0);
//	}
//	for (j = len + i - 1; j < s->len; j++)
//		s->str[j - len] = s->str[j];
//	s->len = s->len - len;
//	s->str[s->len] = '\0';
//	return s;
//}
//int *replace_index(seqstr *t, seqstr *p, int next[])
//{
//	int i, j, k = 0, count = 0;
//	static int position[20];    //注意position必须为static，要不然呵呵呵（return数组后无法正常使用，因为函数return后数组被收回）,
//	i = 0;                      //但是static 会把未初始化数据初始化为0，下面有需要用的的地方。
//	j = 0;
//	while (i < t->len)    //循环找到所有匹配
//	{
//		while (i < t->len&&j < p->len)          //kmp
//		{
//			if (j == -1 || t->str[i] == p->str[j])
//			{
//				i++; j++;
//			}
//			else
//				j = next[j];
//		}
//		if (j == p->len)
//		{
//			position[count] = i - p->len;
//			count++;
//		}
//		else
//		{
//			position[count] = -1;
//			break;
//		}
//		if (position[count] == -1)
//			break;
//		else
//		{
//			i = position[count - 1] + 1;
//			j = 0;
//		}
//	}
//	if (position[0] == 0)
//		position[0] = -2;
//	return position;
//}
//seqstr *strreplace(seqstr *s, seqstr *t1, seqstr *t2)
//{
//	int *position_1, i = 0, len, dis, j, k;
//	position_1 = replace_index(s, t1, getnext(t1));
//	while (position_1[i] && position_1[i] != -1)
//	{
//		if (position_1[i] == -2)
//			position_1[i] = 0;
//		i++;
//	}
//	i = 0;
//	if (position_1[0] == -1)
//	{
//		printf("没有查找到该字符，替换错误！\n");
//		exit(0);
//	}
//	while (position_1[i] != -1)
//	{
//		k = position_1[i];
//		s = strdelete(s, k + 1, t1->len);
//		dis = t2->len - t1->len;
//		s = strinsert(s, k + 1, t2);
//		for (j = 0; position_1[j] != -1; j++)
//		{
//			position_1[j] = dis + position_1[j];
//		}
//		i++;
//	}
//	i = 0;
//	while (s->str[i] != '\0')
//	{
//		printf("%c", s->str[i]);
//		i++;
//	}
//}
//int main()
//{
//	int len;
//	seqstr *d;
//	seqstr *h1, *h2, *h3;
//	seqstr a[100], b[100], c[100];
//	h1 = strcreat(a);
//	h2 = strcreat(b);
//	h3 = strcreat(c);
//	/*printf("%s\n  %d\n", h1->str,h1->len); //测试数据
//	printf("%s\n  %d\n", h2->str, h2->len);
//	printf("%d", index(h1, h2,getnext(h2)));
//	printf("\n");
//	d=strinsert(h1, 2, h2);
//	puts(d->str);*/
//	strreplace(h1, h2, h3);
//	return 0;
//}
