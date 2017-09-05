#include "Stack.h"
#include "stdio.h"
#include "stdlib.h"

//10进制转换为其他进制的数字
status changeSystem(SqStack &stack,int num, int n)
{
	int arr[][16] ={
		{'0','1'},
		{'0','1','2','3','4','5','6','7'},
		{'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}
	};

	int *ptr;

	switch(n)
	{
	case 2:
		ptr = arr[0];
		break;
	case 8:
		ptr = arr[1];
		break;	
	case 16:
		ptr = arr[2];
		break;
	default:
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
	status state = changeSystem(stack,1234456,2) ;

	if(state==-1)
	{
		printf("%s\n`","ERROR");
		exit(1);
	}

	stackElem e;
	while(getStackLen(stack) != 0)
	{
		pop(stack,e);
		printf("%c",e);
	}
	printf("\n");

}
