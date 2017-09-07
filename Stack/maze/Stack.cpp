#include "Stack.h"
#include "stdlib.h"


//��ʼ��
status initStack(SqStack &stack)
{
	stack.base = (stackElem *)malloc(sizeof(stackElem) * INIT_STATCK_SIZE);
	if(!stack.base) return ERROR;

	stack.top = stack.base;
	stack.stacksize = INIT_STATCK_SIZE;
	return OK;
}

//����
status pop(SqStack &stack,stackElem &e)
{
	if(stack.base == stack.top) return ERROR;
	e = *(--stack.top);
	return OK;
}
//ѹ��
status push(SqStack &stack,stackElem e)
{
	if(stack.top-stack.base >= stack.stacksize)
	{
		stack.base = (stackElem *)realloc(stack.base, sizeof(stackElem) * (STACKINCREMENTSIZE+stack.stacksize) );
		if(stack.base) return ERROR;
		stack.top = stack.base+stack.stacksize;
		stack.stacksize +=STACKINCREMENTSIZE;
	}
	*stack.top = e;
	stack.top++;
	return OK;
}
//����
status destoryStack(SqStack &stack)
{
	if(stack.base == stack.top ) return OK;
	free(stack.base);
	return OK;
}

//�õ�ջ��Ԫ��
stackElem getTop(SqStack &stack)
{
	if(stack.base == stack.top) exit(1);
	return *stack.top;
}
//���
status clearStack(SqStack &stack)
{
	if(stack.base == stack.top) return OK;
	stack.top = stack.base;
	return OK;
}

//�õ�ջ����
int getStackLen(SqStack &stack)
{
	return stack.top - stack.base;
}
bool emptyStack(SqStack &stack)
{
	return stack.base == stack.top;
}