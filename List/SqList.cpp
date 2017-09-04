#include "List.h"
#include "stdio.h"
#include <malloc.h> 
#include "stdlib.h"

Status initList(SqList &L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_LEN *sizeof(ElemType));
	if(!L.elem) exit(ERROR);
	L.listsize = LIST_INIT_LEN;
	L.length = 0; 
	return OK;
}

Status insertList(SqList &L,int i, ElemType &e)
{
	

	//i数值不合法
	if(i<0 || i > L.length) 
	{
		exit(ERROR);
	}

	//length大于规定的长度
	if(L.listsize <= L.length)
	{
		 ElemType *newptr = (ElemType *)realloc(L.elem, (LIST_INCREMENT_LEN+L.listsize)*sizeof(ElemType));
	
		if(!newptr) 
		{
			exit(ERROR);
		}

		L.elem = newptr;
		L.listsize += LIST_INCREMENT_LEN;
	}

	ElemType *q = L.elem + i -1 ;
	ElemType *q_end= L.elem + L.length - 1;

	while(q_end-- > q
	{
		*(q_end+1) = *q_end;
	}

	*q = e;
	++L.length;
	return OK;
}
Status getElem(SqList &L,int i, ElemType &e)
{
	if(i<0 || i>L.length+1) 
	{
		exit(ERROR);
	}

	ElemType *q = L.elem + i - 1;

	e = *q;
	return OK;
}

Status deleteList(SqList &L,int i, ElemType &e)
{
	ElemType *p = L.elem +i -1;
	ElemType *p_end = L.elem + L.length -1;

	if(i<1 || i>L.length+1)
	{
		exit(ERROR);
	}

	e = *p;


	while( p< p_end )
	{
		*(p-1) = *(p++);
	}


	L.length--;

	return OK;
}


void Merge_List(SqList La,SqList Lb,SqList &Lc)
{
	int La_length = La.length;
	int Lb_length = Lb.length;
	int Lc_length = La_length + Lb_length;
	Lc.length = Lc.listsize = Lc_length;
	Lc.elem = (ElemType *)malloc(Lc.listsize *sizeof(ElemType));

	if(!Lc.elem)
	{
		exit(ERROR);
	}
	

	ElemType *p,*q,*p_end,*q_end,*pc;

	p = La.elem;
	q = Lb.elem;
	pc = Lc.elem;


	p_end = La.elem + La.length-1;
	q_end = Lb.elem + Lb.length-1;

	while( p <=p_end && q <= q_end )
	{
		if(*p<*q)
		{
			*pc++ = *p++;
		} else {
		    *pc++ = *q++;
		}
	}

	while( p <= p_end )
	{
		*pc++ = *p++;
	}

	while( q <= q_end )
	{
		*pc++ = *q++;
	}
}


void main()
{
   SqList La,Lb,Lc;
   initList(La);
   initList(Lb);
  
   ElemType k,delete_k;

   for(ElemType i=1;i<50;i++)
   {
	   insertList(La,i,i);
   }

   for(i=1;i<200;i++)
   {
	   insertList(Lb,i,i);
   }

   /*
    for(i=1;i<200;i++)
   {
	   getElem(La,i,k);
	   printf("La的%d位为%d\n",i,k);
   }

  */
   /*
	deleteList(La,13,delete_k);
	printf("删除的La的%d位为%d\n",13,delete_k);
  */
   Merge_List(La,Lb,Lc);

   for(i=1;i<Lc.length;i++)
   {
	   getElem(Lc,i,k);
	   printf("Lc的%d位为%d\n",i,k);
   }

}