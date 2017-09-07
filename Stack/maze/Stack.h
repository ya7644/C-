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

//初始化
status initStack(SqStack &stack);
//弹出
status pop(SqStack &stack,stackElem &e);
//压入
status push(SqStack &stack,stackElem e);
//销毁
status destoryStack(SqStack &stack);
//得到栈顶元素
stackElem getTop(SqStack &stack);
//清空
status clearStack(SqStack &stack);
//得到栈长度
int getStackLen(SqStack &stack);

bool emptyStack(SqStack &stack);
