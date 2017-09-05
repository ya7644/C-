#include "Stack.h"
#include "stdio.h"

//10进制转换为其他进制的数字
status changeSystem(SqStack &stack,int num, int n)
{
	int arr[][16] ={
		{'0','1'},
		{'0','1','2','3','4','5','6','7'},
		{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}
	};

	int *ptr;

	if(n == 2 )
	{
		ptr = arr[0];
	}else if( n== 8 )
	{
		ptr = arr[1];
	}else if( n==16)
	{
		ptr= arr[2];
	}else {
	    return ERROR;
	}

	initStack(stack);

	while(num)
	{
		push(stack,ptr[num%n]);
		num /=n;
	}
	return OK;
}

void main()
{
	SqStack stack;
	changeSystem(stack,255, 16);
	stackElem e;
	while(getStackLen(stack) != 0)
	{
		pop(stack,e);
		printf("%c",e);
	}
	printf("\n");

}
