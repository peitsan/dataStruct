#include<iostream>
	using namespace std;
typedef int DataType;
#define M 100
//结点类型定义
typedef struct QNode{
	DataType data;
	struct QNode *next;
}QNode,*Queue;
//队列类型定义
typedef struct {
	Queue front;
	Queue rear;
}Que;

//打印数组 
void PrintArray(int a[],int n,int N){
	int i;
	static int count=0;
	//打印空格 
	for(i=0;i<N-count;i++){
		cout<<" ";
	}
	count++;
	for(i=0;i<n;i++){
		cout<<a[i];
	} 
	cout<<"\n";
}
//链式队列的初始化
void InitQueue(Que *LQ){
	LQ->front=LQ->rear=(QNode*)malloc(sizeof(QNode));
	if(LQ->front!=NULL){
		LQ->front->next=NULL;
	}
} 
//链式队列的是否为空
int	Empty(Que LQ){
	if(LQ.rear==LQ.front){
		return 1;
	}else{
		return 0;
	}
} 
//入队操作
int EnQueue(Que *LQ,DataType e){
	QNode *s;
	s=(QNode*)malloc(sizeof(QNode));
	if(!s){
		return 0;
	}
	s->data=e;
	s->next=NULL;
	LQ->rear->next=s;
	LQ->rear=s;
	return 1;
} 
//出队操作
int DeQueue(Que *LQ,DataType *e){
	QNode *s;
	if(LQ->front==LQ->rear){
		return 0;
	}else{
		s=LQ->front->next;//头结点的下面第一个结点 
		*e=s->data;
		LQ->front->next=s->next;//将第二个结点的指针赋值 
		if(LQ->rear==s){
			LQ->rear=LQ->front;
		} 
		free(s);
		return 1; 
	}
} 
//取队头元素
int GetHead(Que LQ,DataType *e){
	QNode *s;
	if(LQ.front==LQ.rear){
		return 0;
	}else{
		s=LQ.front->next;
		*e=s->data;
		return 1;
	}
} 
//清空队列
void ClearQueue(Que *LQ){
	while(LQ->front!=NULL){
		LQ->rear=LQ->front->next;
		free(LQ);
		LQ->front=LQ->rear;
	} 
}



//主函数
int main(){
	int i,k,n;
	DataType e,t;
	//创建定义一个临时数组，用于存放每一行的元素
	int temp[M];
	Que Q;
	k=0;
	//初始化队列
	InitQueue(&Q) ;
	//第一行元素入队
	EnQueue(&Q,1);
	//产生第n行元素入队 同时将n-1行元素保存到临时数组中
	for(n=2;n<=5;n++){
		k=0;
		//将第n行的第一个元素入队 
		EnQueue(&Q,1);
		//利用队列中第n-1行元素产生第i行的中间n-2个元素入队 
		for(i=1;i<=n-2;i++){
			DeQueue(&Q,&t);
			// 将第n-1行的元素存入临时数组
			temp[k++]=t;
			//取队头元素
			GetHead(Q,&e);
			//利用队中第n-1行元素产生第i个元素 
			t=t+e; 
			//存储
			EnQueue(&Q,t); 
		} 
		DeQueue(&Q,&t);
		//将第n-1行的最后一个元素存入临时数组
		temp[k++] =t;
		PrintArray(temp,k,5);
		//将n行最后一个元素入队 
		EnQueue(&Q,1);
	} 
	k=0;
	while(!Empty(Q)){
		DeQueue(&Q,&t);
		temp[k++]=t;
		if(Empty(Q)){
			PrintArray(temp,k,5);
		}
	} 
    return 0;
} 