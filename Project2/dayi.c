//编译环境vs2017

//顺序串
#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
typedef struct {
	char str[maxsize];
	int len;
}seqstr;
void strcreat(seqstr *s)
{
	int i=0;
	gets(s->str);
	while (s->str[i] != '\0')
	{
		i++;
	}
	s->len = i;
	printf("操作完成！");
}
void strassign(seqstr *s, seqstr *t)
{
	int i=0;
	while (t->str[i] != '\0')
	{
		s->str[i] = t->str[i];
		i++;
	}
	s->str[i] = '\0';
	s->len = i+1;
}
int strlen(seqstr *s)
{
	int i = 0;
	while (s->str[i] != '\0')
		i++;
	return i+1;
}
int strempty(seqstr *s)
{
	if (!s->str[0])
		return 1;
	else
	{
		return 0;
	}
}
void strclean(seqstr *s)
{
	if (s->len != 0)
		s->len = 0;
	printf("删除完成！");
}
int strcompare(seqstr *s1, seqstr *s2)
{
	int i = 0, j = 0, res;
	while (s1->str[i] && s2->str[i])
	{
		if (s1->str[i] > s2->str[i])
		{
			res = 1;
			break;
		}
		else if (s1->str[i] < s2->str[i])
		{
			res = -1;
			break;
		}
		i++;
	}
	if (!s1->str[i]&&s2->str[i])
		res = 1;
	else if (!s2->str[i]&&s1->str[i])
		res = -1;
	else if(!s1->str[i]&&!s2->str[i])
		res = 0;
	return res;
}
void strconcat(seqstr *s1, seqstr *s2)
{
	int i=0, j=0;
	while (s1->str[i] != '\0')
		i++;
	while (s2->str[j]!='\0')
	{
		s1->str[i + j] = s2->str[j];
			j++;
	}
	s1->str[i+j] = '\0';
	s1->len = i + j;
	puts(s1);
	printf("%d\n", s1->len);
}

int main()
{
	int x;
	char a[10],b[20];
	gets(a);
	gets(b);
	if (strempty(a))
		printf("1\n");
	else
	{
		printf("0\n");
	}
	printf("%d\n",strcompare(a, b));
	strconcat(a, b);
	return 0;
}