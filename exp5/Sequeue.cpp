#include<iostream>
    using namespace std;
    // 图的深度遍历DFS 非递归实现
    typedef struct Node_Type{
        int db;
        struct Node_Type *next;
    }Node_Type;



bool enqueue(int m){
    if(((m->rear+1) % M) == m->front){
        return true;
    }
    else{
        return false;
    }
}
// 尾插法
typedef struct Qnode {
    int data;
    struct Qnode *next;
}Qnode;
Qnode *head,*tail;
typedef struct Queue {
  Qnode head;
  Qnode tail;
} Queue;
Queue *queue;
void insert(int Data)    //入队
{
   Qnode *s;  //插入的节点
    s->data = Data;  
    s->next = NULL; 
    if( queue->head== NULL && queue->tail == NULL)   //队列空 可以直接头插 
    {
        head = s;
    }
    else                          
    {
        tail->next = s;
        tail = s;
    }
 }
 void main(){
    N = malloc(sizeof(Qnode))
 }