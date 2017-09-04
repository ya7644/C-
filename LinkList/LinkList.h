typedef int ElemType;


typedef struct LinkNode
{
	ElemType data;
	LinkNode * next;
}*LinkList,LinkNode;

//初始化单链表
void initLinkList(LinkList &linkList);

//插入单链表

//删除单链表

//得到单链表某个节点的数值

//创建单链表
void createLinkList(LinkList &linkList);

//打印单链表
void printLinkList(LinkList &linkList);
