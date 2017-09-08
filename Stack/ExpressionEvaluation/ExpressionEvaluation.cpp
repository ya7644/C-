#include "Stack.h"
#include "stdio.h"
#include "stdlib.h"

#define OP_NUM 7

//表达式求值
bool In(char c)
{
	char op[OP_NUM] = {'+','/','-','*','(',')','#'};
	for(int i=0;i<OP_NUM;i++)
	{
		if(op[i] == c)
			return true;
	}
	return false;
}
int getIndex(char ptr)
{
	int index;
	switch(ptr)
	{
	case '+':
		index = 0;
		break;
	case '-':
		index = 1;
		break;
	case '*':
		index = 2;
		break;
	case '/':
		index = 3;
		break;
	case '(':
		index = 4;
		break;
	case ')':
		index = 5;
		break;
	case '#':
		index = 6;
		break;
	}
	return index;
}

char PreduceOPT(char ptrA, char ptrB)
{
	char ptr[7][7] ={
		'>','>','<','<','<','>','>',
		'>','>','<','<','<','>','>',
		'>','>','>','>','<','>','>',
		'>','>','>','>','<','>','>',
		'<','<','<','<','<','=',' ',
		'>','>','>','>',' ','>','>',
		'<','<','<','<','<',' ','='
	};

	return ptr[getIndex(ptrA)][getIndex(ptrB)];
}



int calculate(int opda,int opdb,char opt)
{
	switch(opt)
	{
	case '+':
		return opda+opdb;
	case '-':
		return opda-opdb;
	case '*':
		return opda*opdb;
	case '/':
		if(opdb==0)
		{
			printf("被除数不能为0\n");
			exit(1);
		}
		return opda/opdb;
	default:
			printf("算法有误\n");
			exit(1);
	}
	return ERROR;
}


void calc()
{
	SqStack OPT, OPD;
	stackElem first,input,output,input2,output2,output3,outputA,outputB,outputPtr,inputResult;
	
	int a,b;
	int opt;
	int result;
	int output3_val;
	initStack(OPT);
	initStack(OPD);
    char c ;

	first.optr = '#';
	push(OPT,first);

	c = getchar();

	while(c!='#' || (getTop(OPT)).optr!='#')
	{
		if(!In(c))
		{
			if(emptyStack(OPD) || input.num == 0)
			{
				input.num = c-'0';
				push(OPD,input);
			}else 
			{
				pop(OPD,output3);
				input.num = output3.num*10 + (c-'0');
				push(OPD,input);
			}
			c = getchar();
		}else 
		{
			output = getTop(OPT);
			input.num = 0;

			switch(PreduceOPT(output.optr,c))
			{
			case '<':
				input2.optr = c;
				push(OPT,input2);
				c = getchar();
				break;
			case '=':
				pop(OPT,output2);
				c = getchar();
				break;
			case '>':
				pop(OPT,outputPtr);
				pop(OPD,outputB);
				pop(OPD,outputA);
				
				inputResult.num = calculate(outputA.num,outputB.num,outputPtr.optr);
				push(OPD,inputResult);
				break;
			default:
				break;
			}
		}
	}

	if(!emptyStack(OPD))
	{
		stackElem result ;
		pop(OPD,result);

		printf("结果为%d\n",result.num);
	}
	clearStack(OPD);
	clearStack(OPT);
	
}

void main()
{
	calc();

}

