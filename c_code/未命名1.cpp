#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#define MAXSIZE 100
typedef int keytype;
typedef struct{
	keytype key;
	keytype  ckey;
	char name[20];
}recordtype; 
typedef struct{
	recordtype r[MAXSIZE+1];
	int length;
}table;
void quicksort(table *tab,int left,int right)
{
	int i,j;
	if(left<right)
	{
		i=left;j=right;
		tab->r[0]=tab->r[i];
		do
		{
			while(tab->r[j].key>tab->r[0].key&&i<j)
			j--;
			if(i<j)
			{
				tab->r[i].key=tab->r[j].key ;
				i++;
			}
			while(tab->r[i].key<tab->r[0].key&&i<j)
			i++;
			if(i<j)
			{
				tab->r[j].key=tab->r[i].key;
				j--;
			}
		}
			while(i!=j);
			tab->r[i]=tab->r[0];
			quicksort(tab,left,i-1);
			quicksort(tab,i+1,right);
		 
	}
}
void create(table *tab)
{
	int j;
	//tab=(table*)malloc(sizeof(table));
	printf("请输入学生人数：\n");
	scanf("%d",&tab->length);
	printf("输入信息：\n") ;
	for(j=1;j<=tab->length;j++)
	{
		printf("姓名:");
	    scanf("%s",&tab->r[j].name);
	    printf("班级:");
	    scanf("%d",&tab->r[j].ckey);
	    printf("学号:");
	    scanf("%d",&tab->r[j].key);
	}
}
/*void print(table *tab)
{
	    printf("姓名\t\t");
	    printf("班级\t\t");
 	    printf("学号\t\t\n");
	for(int i=1;i<=tab->length;i++)
	{
		printf("%s\t\t",tab->r[i].name) ;
	    printf("%d\t\t",tab->r[i].ckey);
	    printf("%d\t\t\n",tab->r[i].key);
	}	
}*/
void print(table *tab)
{
    for(int i=1;i<=tab->length;i++)
    {
        printf("姓名：%s  ",tab->r[i].name);
        printf("系名：%s  ",tab->r[i].key);
        printf("班号：%d  ",tab->r[i].ckey);
        printf("\n");
    }
}
int main()
{
	int i;
	table tab;
	create(&tab);
	quicksort(&tab,1,tab.length);
	print(&tab);
	system("pause") ;
	return 0;
}

