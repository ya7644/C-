//通过堆栈实现迷宫的算法
#include "Stack.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#define MAZE_X_SIZE 8
#define MAZE_Y_SIZE 8


//初始化迷宫
status initMaze(mazeElem maze[MAZE_X_SIZE][MAZE_Y_SIZE])
{
	int i,j;
	
	srand((unsigned)time(NULL));  

	for(i=0;i<MAZE_X_SIZE;i++)
	{
		for(j=0; j<MAZE_Y_SIZE;j++)
		{
			if(i==0 && j==0) 
			{
				maze[i][j] = 0;
			}else if(i==MAZE_X_SIZE-1 && j==MAZE_Y_SIZE-1)
			{
				maze[i][j] = 0;
			} else {
				maze[i][j] = rand()%2;
			}
			
		}
	}
	return OK;
}

//打印迷宫
status printMaze(mazeElem maze[MAZE_X_SIZE][MAZE_Y_SIZE])
{
	int i,j;
	char a[2]={' ','.'};
	for(i=0;i<MAZE_X_SIZE;i++)
	{
		for(j=0; j<MAZE_Y_SIZE;j++)
		{	
			if(maze[i][j]==-1)
			{
				printf("%c",'*');
			} else if(maze[i][j]==2) {
				printf("%c",'=');
			}else {
				printf("%c",a[maze[i][j]]);
			}	
			
			//printf("%d",maze[i][j]);
		}
		printf("\n");
	}
	return OK;
}

bool Pass(mazeElem maze[MAZE_X_SIZE][MAZE_Y_SIZE],Point curpos)
{
	return maze[curpos.x][curpos.y] == 0;
}

void FootPrint(mazeElem (&maze)[MAZE_X_SIZE][MAZE_Y_SIZE],Point curpos)
{
	maze[curpos.x][curpos.y] = 2;
}

Point NextPos(Point curpos, int dir)
{
	switch(dir)
	{
	case 1:
		curpos.y+=1;
		break;
	case 2:
		curpos.x-=1;
		break;
	case 3:
		curpos.y-=1;
		break;
	case 4:
		curpos.x+=1;
		break;
	default:
		break;
	}
	return curpos;
}
void MarkPrint(mazeElem (&maze)[MAZE_X_SIZE][MAZE_Y_SIZE],Point curpos)
{
	maze[curpos.x][curpos.y] = -1;
}

SqStack MazeRoute(mazeElem (&maze)[MAZE_X_SIZE][MAZE_Y_SIZE],Point start,Point end)
{
	Point curpos = start;
	RoutePoint e;
	SqStack s;
	int curstep=1;
	initStack(s);
	do {
	    if( Pass(maze,curpos) )
		{
			FootPrint(maze,curpos);
	        e.cur_pos = curstep++;
		    e.dir = 1;
		    e.point = curpos;

			push(s,e);
			if(curpos.x==end.x && curpos.y == end.y) 
			{
				return s;
			}
			curpos = NextPos(curpos,1);
		
		}else{
			if(!emptyStack(s))
			{
				pop(s,e);
				while(e.dir==4 && !emptyStack(s) )
				{
					MarkPrint(maze,e.point);
					pop(s,e);
				}

				if(e.dir < 4)
				{
					e.dir++;
					push(s,e);
					curpos =  NextPos(e.point,e.dir);
				}
			}
		}
		}while( !emptyStack(s) );
		return s;
}

void main()
{
    mazeElem maze[MAZE_X_SIZE][MAZE_Y_SIZE];
	Point start,end;
	start.x =0;
	start.y =0;

	end.x = MAZE_X_SIZE -1;
	end.y = MAZE_Y_SIZE -1;

	bool getOne = false;

	initMaze(maze);
	 int maze[8][8]={{0,0,0,0,0,0,0,0},{0,0,1,0,0,1,0,0},{0,1,1,0,0,0,1,0},
   {0,1,0,0,0,0,0,0},{0,1,1,1,0,0,1,0},{0,0,0,1,0,0,1,0},
   {0,0,0,1,1,1,1,0},{0,0,0,0,0,0,0,0}},i,j,flag;
      struct Point start,end;
      start.x=1;start.y=2;
      end.x=4;end.y=6;

	printMaze(maze);
	
    SqStack s = MazeRoute(maze,start,end);

	printf("\n");
	printMaze(maze);

    RoutePoint e;
	
	if(!emptyStack(s))
	{
	    while(!emptyStack(s))
		{
		pop(s,e);
		printf("%d:(%d,%d)\n",e.cur_pos,e.point.x, e.point.y);
		}
	}

}

