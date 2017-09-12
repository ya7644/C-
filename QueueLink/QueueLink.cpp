#include "QueueLink.h"
#include "stdlib.h"
#include "stdio.h"

//��ʼ������
status initQueueLink(QueueLink &queueLink)
{
	queueLink.first = queueLink.last = (QNodePtr)malloc(sizeof(QNode));
	if(!queueLink.first) return ERROR;
	queueLink.first->next = NULL;
	return OK;
}
//�����
status enQueueLink(QueueLink &queueLink,QElemType e)
{
	QNodePtr q = (QNodePtr)malloc(sizeof(QNode));
	q->data = e;
	q->next = NULL;
	queueLink.last->next = q;
	queueLink.last = q;
	return OK;
}
//������
status deQueueLink(QueueLink &queueLink,QElemType &e)
{
	if(queueLink.first == queueLink.last) return ERROR;

	QNodePtr q = queueLink.first->next;
	e = q->data;
	queueLink.first->next = q->next;
	if(q == queueLink.last) queueLink.last = queueLink.first;
	free(q);
	return OK;
}
//ɾ������
status destoryQueueLink(QueueLink &queueLink)
{
	QNodePtr q = queueLink.first->next;
    QNodePtr p;
	while(q)
	{
		p = q->next;
		free(q);
		q = p;
	}
	return OK;
}
//��ӡ����
status printQueueLink(QueueLink &queueLink)
{
	QNodePtr q = queueLink.first->next;
	while(q)
	{
		printf("%d ",q->data);
		q = q->next;
	}
	printf("\n");
	return OK;
}

void main()
{
    QueueLink queueLink;
	QElemType e;
	initQueueLink(queueLink);
	enQueueLink(queueLink,1);
	enQueueLink(queueLink,2);
	enQueueLink(queueLink,3);

	deQueueLink(queueLink,e);
	printf("%d\n",e);
	deQueueLink(queueLink,e);
	printf("%d\n",e);
	printQueueLink(queueLink);
}


