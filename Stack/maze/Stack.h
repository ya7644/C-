#define INIT_STATCK_SIZE 100
#define STACKINCREMENTSIZE 100

typedef int status;

#define ERROR -1;
#define OK 1;

typedef struct Point
{
	int x;
	int y;
}Point;

typedef struct RoutePoint
{
	int cur_pos;
	Point point;
	int dir;
}RoutePoint;

typedef RoutePoint stackElem;
typedef int mazeElem;

typedef struct {
	stackElem *top;
	stackElem *base;
	int stacksize;
}SqStack;

//��ʼ��
status initStack(SqStack &stack);
//����
status pop(SqStack &stack,stackElem &e);
//ѹ��
status push(SqStack &stack,stackElem e);
//����
status destoryStack(SqStack &stack);
//�õ�ջ��Ԫ��
stackElem getTop(SqStack &stack);
//���
status clearStack(SqStack &stack);
//�õ�ջ����
int getStackLen(SqStack &stack);

bool emptyStack(SqStack &stack);
