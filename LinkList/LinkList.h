typedef int ElemType;


typedef struct LinkNode
{
	ElemType data;
	LinkNode * next;
}*LinkList,LinkNode;

//��ʼ��������
void initLinkList(LinkList &linkList);

//���뵥����

//ɾ��������

//�õ�������ĳ���ڵ����ֵ

//����������
void createLinkList(LinkList &linkList);

//��ӡ������
void printLinkList(LinkList &linkList);
