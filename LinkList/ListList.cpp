#include "stdio.h"
#include "LinkList.h"
#include "malloc.h"
#include "stddef.h"

//��ʼ��������
void initLinkList(LinkList &linkList)
{
	linkList = (LinkList)malloc(sizeof(LinkNode));
	linkList->next = NULL;
}

//���뵥����

//ɾ��������

//�õ�������ĳ���ڵ����ֵ

//����������
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

//��ӡ������
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

	printf("%s","��������ٸ�");
	int n;
	scanf("%d",&n);
	printf("%s%d%s\n","����Ҫ����",n,"��Ԫ��");
	createLinkList(linklist,n);
	printLinkList(linklist);




}