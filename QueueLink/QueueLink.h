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


//初始化队列
status initQueueLink(QueueLink &queueLink);
//入队列
status enQueueLink(QueueLink &queueLink,QElemType e);
//出队列
status deQueueLink(QueueLink &queueLink,QElemType &e);
//删除队列
status destoryQueueLink(QueueLink &queueLink);
//打印队列
status printQueueLink(QueueLink &queueLink);
