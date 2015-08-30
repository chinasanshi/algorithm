#include "stdio.h"
typedef  int  datatype;   /*假定线性表元素的类型为整型*/
#define  maxsize  1024    /*假定线性表的最大长度为1024*/
# define n 100            /* 图的顶点最大个数 */
typedef char VEXTYPE;  /* 顶点的数据类型 */
typedef float ADJTYPE;  /* 权值类型 */
typedef struct {
	VEXTYPE vexs[n] ;  /* 顶点信息数组 */
	ADJTYPE arcs[n][n] ; /* 边权数组 */
	int num ;    /* 顶点的实际个数 */
} GRAPH;

/***********************1。置空图**********************/
void GraphInit(GRAPH  *L)
{
	L->num = 0;
}

/***********************2。求结点数**********************/
int GraphVexs(GRAPH  *L)
{
	return (L->num);
}

/***********************3。创建图**********************/
void GraphCreate(GRAPH  *L)
{
	int i, j;
	GraphInit(L);
	printf("请输入顶点数目：");
	scanf("%d", &L->num);
	printf("请输入各顶点的信息(单个符号）：");
	for (i = 0; i < L->num; i++)
	{
		fflush(stdin);
		scanf("%c", &L->vexs[i]);
	}
	printf("请输入边权矩阵的信息：");
	for (i = 0; i < L->num; i++)
	{
		for (j = 0; j < L->num; j++)
		{
			scanf("%f", &L->arcs[i][j]);
		}
	}
	printf("图已经创建完毕！");
}

/***********************4。图的输出**********************/
void GraphOut(GRAPH  L)
{
	int i, j;
	printf("\n图的顶点数目为：%d", L.num);
	printf("\n图的各顶点的信息为：\n");
	for (i = 0; i < L.num; i++)
		printf("%c  ", L.vexs[i]);
	printf("\n图的边权矩阵的信息为：\n");
	for (i = 0; i < L.num; i++)
	{
		for (j = 0; j < L.num; j++)
		{
			printf("%6.2f ", L.arcs[i][j]);
		}
		printf("\n");
	}
	printf("图已经输出完毕！");
}

/***********************5。图的深度周游**********************/
void DFS(GRAPH  g, int qidian, int mark[])
//从第qidian个点出发深度优先周游图g中能访问的各个顶点
{
	int v1;
	mark[qidian] = 1;
	printf("%c   ", g.vexs[qidian]);
	for (v1 = 0; v1 < g.num; v1++)
	{
		if (g.arcs[qidian][v1] != 0 && mark[v1] == 0)
			DFS(g, v1, mark);
	}
}
/***********************6。图的深度周游**********************/
void GraphDFS(GRAPH  g)
//深度优先周游图g中能访问的各个顶点
{
	int qidian, v, v1, mark[maxsize];
	printf("\n深度周游：");
	printf("\n请输入起点的下标：");
	scanf("%d", &qidian);
	for (v = 0; v < g.num; v++)
	{
		mark[v] = 0;
	}
	for (v = qidian; v < g.num + qidian; v++)
	{
		//printf("v=%d   ",v);
		v1 = v % g.num;
		if (mark[v1] == 0)
			DFS(g, v1, mark);
	}
}
typedef  int DATATYPE;     //队列元素的数据类型
typedef  struct
{
	DATATYPE data[maxsize]; //队中元素
	int front, rear;  //队头元素下标、队尾元素后面位置的下标
} SEQQUEUE;
/*****************************************************************************/
void QueueInit(SEQQUEUE *sq)
//将顺序循环队列sq置空（初始化）
{
	sq->front = 0;
	sq->rear = 0;
}
/*****************************************************************************/
int QueueIsEmpty(SEQQUEUE sq)
//如果顺序循环队列sq为空，成功返回1，否则返回0
{
	if (sq.rear == sq.front)
		return (1);
	else
		return (0);
}
/*****************************************************************************/
int QueueFront(SEQQUEUE sq, DATATYPE *e)
//将顺序循环队列sq的队头元素保存到e所指地址，成功返回1，失败返回0
{
	if (QueueIsEmpty(sq))
	{ printf("queue is empty!\n"); return 0;}
	else
	{ *e = sq.data[(sq.front)]; return 1;}
}
/*****************************************************************************/
int QueueIn (SEQQUEUE *sq, DATATYPE x)
//将元素x入队列sq的队尾，成功返回1，失败返回0
{
	if (sq->front == (sq->rear + 1) % maxsize)
	{
		printf("queue is full!\n");
		return 0;
	}
	else
	{
		sq->data[sq->rear] = x;
		sq->rear = (sq->rear + 1) % maxsize;
		return (1);
	}
}
/*****************************************************************************/
int QueueOut(SEQQUEUE *sq)
//将队列sq队首元素出队列，成功返回1,失败返回0
{
	if (QueueIsEmpty(*sq))
	{
		printf("queue is empty!\n");
		return 0;
	}
	else
	{
		sq->front = (sq->front + 1) % maxsize;
		return  1;
	}
}
/***********************7。图的广度周游**********************/
void BFS(GRAPH g, int v, int mark[])
//从v出发广度优先周游图g中能访问的各个顶点
{
	int v1, v2;
	SEQQUEUE q;
	QueueInit(&q);
	QueueIn(&q, v);
	mark[v] = 1;
	printf("%c   ", g.vexs[v]);
	while (QueueIsEmpty(q) == 0)
	{
		QueueFront(q, &v1);
		QueueOut(&q);
		for (v2 = 0; v2 < g.num; v2++)
		{
			if (g.arcs[v1][v2] != 0 && mark[v2] == 0)
			{
				QueueIn(&q, v2);
				mark[v2] = 1;
				printf("%c   ", g.vexs[v2]);
			}
		}
	}
}
/***********************8。图的广度周游**********************/
void GraphBFS(GRAPH  g)
//深度优先周游图g中能访问的各个顶点
{
	int qidian, v, v1, mark[maxsize];
	printf("\n广度周游：");
	printf("\n请输入起点的下标：");
	scanf("%d", &qidian);
	for (v = 0; v < g.num; v++)
	{
		mark[v] = 0;
	}
	for (v = qidian; v < g.num + qidian; v++)
	{
		v1 = v % g.num;
		if (mark[v1] == 0)
			BFS(g, v1, mark);
	}
}

/***********************主函数**********************/

void main()
{
	GRAPH tu;
	GraphCreate(&tu);
	GraphOut(tu);
	GraphDFS(tu);
	GraphBFS(tu);
}