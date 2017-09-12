typedef int QElemType;
typedef bool status;

#define OK true;
#define ERROR false;

typedef struct QNode
{
	QElemType data;
	QNode *next;
}QNode,*QNodePtr;

typedef struct QueueLink
{
	QNodePtr first;
	QNodePtr last;
}QueueLink;


//��ʼ������
status initQueueLink(QueueLink &queueLink);
//�����
status enQueueLink(QueueLink &queueLink,QElemType e);
//������
status deQueueLink(QueueLink &queueLink,QElemType &e);
//ɾ������
status destoryQueueLink(QueueLink &queueLink);
//��ӡ����
status printQueueLink(QueueLink &queueLink);
