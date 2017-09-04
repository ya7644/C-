#include "stdio.h"
#include "Stack.h"
#include "stdlib.h"


//初始化
status initStack(SqStack &stack)
{
	stack.base = (stackElem *)malloc(sizeof(stackElem) * INIT_STATCK_SIZE);
	if(!stack.base) return ERROR;

	stack.top = stack.base;
	stack.stacksize = INIT_STATCK_SIZE;
	return OK;
}

//弹出
status pop(SqStack &stack,stackElem &e)
{
	if(stack.base == stack.top) return ERROR;
	e = *(--stack.top);
	return OK;
}
//压入
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
//销毁
status destoryStack(SqStack &stack)
{
	if(stack.base == stack.top ) return OK;
	free(stack.base);
	return OK;
}
//得到栈顶元素
stackElem getTop(SqStack &stack)
{
	if(stack.base == stack.top) return ERROR;
	return *stack.top;
}
//清空
status clearStack(SqStack &stack)
{
	if(stack.base == stack.top) return OK;
	stack.top = stack.base;
	return OK;
}

//得到栈长度
int getStackLen(SqStack &stack)
{
	return stack.top - stack.base;
}

void main()
{
	SqStack stack;
	initStack(stack);
	push(stack,1);
	push(stack,2);
	push(stack,3);
	push(stack,4);
	stackElem e;

	while(getStackLen(stack) !=0)
	{
		pop(stack,e);
		printf("%d\n",e);
	}	
	destoryStack(stack);
}