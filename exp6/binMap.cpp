#include<iostream>
#include<string>
#define Length 11;
int layer,leaves = 0;
    using namespace std;
    typedef int datatype;
    typedef struct binT
        {
            datatype k;
            struct binT *left;
            struct binT *right;
        }binT;

    typedef struct stack{
        binT *head;
        stack *next;
    }stack,*mystack;
    
    bool Empty(stack *db)
    {
       if(db->next == NULL)
       return true;
       else return false;
    }

    stack* createBinT(){
        stack *node = (stack*)malloc(sizeof(stack));
        node->next = NULL;
        return node;
    }

    void Push(stack *db,binT *data){
        stack *node = (stack*)malloc(sizeof(stack));
        node->head = data;
        node->next = db->next;
        db->next = node;
    }

    binT* Pop(stack *db){
        binT *val = (binT*)malloc(sizeof(binT));
        stack *node = db->next;
        val = node->head;
        db->next = node->next;
        free(node);
        return val;
    }
    
    binT* InsertNode(datatype data)
    {    printf("1");
        binT *node = (binT*)malloc(sizeof(binT));
        if(data!=0){  
            node->k = data;
            node->left = InsertNode(data);
            node->right = InsertNode(data);
        }
        return node;
    }
    //堆栈实现先序遍历
    void PreOrder(binT* node)
        {   printf("1");
            binT* t = node;
            stack *stk = createBinT();
            while(t || Empty(stk))
            {
                while(t){
                    Push(stk, t);
                    cout<< t-> k;
                    t = t->left;
                }
                if(!Empty(stk))
                {
                    t = Pop(stk);
                    t = t->right;
                }
            }
        }
    binT* InitialTree()
    {   datatype tree[]={10,9,0,0,20,15,0,0,35,0,0};
        binT *node = (binT*)malloc(sizeof(binT));
        for(int i = 0; i<11; i++)
          node = InsertNode(tree[i]);
        return node;
    }
int main()
{   mystack database = createBinT();
    database->head=InitialTree();
    PreOrder(database->head);
}