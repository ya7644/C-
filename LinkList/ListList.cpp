#include "stdio.h"
#include "LinkList.h"
#include "malloc.h"
#include "stddef.h"

//初始化单链表
void initLinkList(LinkList &linkList)
{
	linkList = (LinkList)malloc(sizeof(LinkNode));
	linkList->next = NULL;
}

//插入单链表

//删除单链表

//得到单链表某个节点的数值

//创建单链表
void createLinkList(LinkList &linkList,int n)
{
	LinkList q;

	while(n--)
	{
			q = (LinkList)malloc(sizeof(LinkNode));
			scanf("%d",&(q->data));
			q->next = linkList->next;
			linkList->next = q;
	}
}

//打印单链表
void printLinkList(LinkList &linkList)
{
	LinkList q = linkList->next;
	while(q != NULL)
	{
		printf("%d ",q->data);
		q = q->next;
	}
	printf("\n");
}


void main()
{

	LinkList linklist;
	initLinkList(linklist);

	printf("%s","清输入多少个");
	int n;
	scanf("%d",&n);
	printf("%s%d%s\n","您需要输入",n,"个元素");
	createLinkList(linklist,n);
	printLinkList(linklist);




}