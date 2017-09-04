#define LIST_INIT_LEN 100
#define LIST_INCREMENT_LEN 10

#define OK 1
#define ERROR -1


typedef int ElemType;
typedef int Status;

typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

//≥ı ºªØ¡¥±Ì
Status initList(SqList &L);
Status insertList(SqList &L,int i, ElemType &e);
Status deleteList(SqList &L,int i, ElemType &e);
Status getElem(SqList &L,int i, ElemType &e);
void Merge_List(SqList La,SqList Lb,SqList &Lc);


