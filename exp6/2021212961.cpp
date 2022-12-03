#include<iostream>
using namespace std;
typedef int datatype;
typedef struct TreeNode *BinT;
struct TreeNode{
     datatype Data;
     BinT left;
     BinT right;
};


typedef struct Snode *Stack;
struct Snode{
     BinT Data;
     Stack next;
};

int i = 0, layer = 0,leaves =0;
Stack CreateStack()
{
     Stack s;
     s = (Stack)malloc(sizeof(struct Snode));
     s->next = NULL;
     return s;
}
int Empty(Stack s)
{
     return s->next == NULL;
}
void Push(Stack s, BinT item)
{
     Stack tmp = (Stack)malloc(sizeof(struct Snode));
     tmp->Data = item;
     tmp->next = s->next;
     s->next = tmp;
}
BinT Pop(Stack s)
{
     BinT val;
     Stack tmp = s->next;
     val = tmp->Data;
     s->next = tmp->next;
     free(tmp);
     return val;
}


BinT Initial()
{    
     datatype tree[]={10,9,0,0,20,15,0,0,35,0,0};
     BinT bt = (BinT)malloc(sizeof(struct TreeNode));
     i++;
    //  cout<<bt->Data;
      if(tree[i]!=0){
          if(bt->Data = NULL)
             bt->Data = tree[i];
          else{
            bt->left = Initial();
            bt->right = Initial();
            layer++;
          }
        }
      else{
         bt = NULL;
         leaves++;
      }

     return bt;
}

BinT CreateBinT()
{    
     BinT bt;
     bt = (BinT)malloc(sizeof(struct TreeNode));
     return bt;
}

//堆栈实现先序遍历
void PreOrder(BinT BT)
{
     BinT t = BT;
     Stack s = CreateStack();
     while(t || !Empty(s))
     {
          while(t){
               Push(s, t);
               cout<<t->Data;
               t = t->left;
          }
          if(!Empty(s))
          {
               t = Pop(s);
               t = t->right;
          }
     }
}
BinT bt = CreateBinT();
int main()
{
     Initial();
     PreOrder(bt);
      cout<<"深度:"<<layer;
      cout<<"叶子节点数:"<<leaves;
}

