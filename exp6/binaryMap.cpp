#include<iostream>
#include<string>
#define Length 11;
    using namespace std;
    typedef int datatype;

    typedef struct binT
        {
            int k;
            struct binT *left;
            struct binT *right;
        }binT;

    typedef struct stack{
        binT *tree[20];
        int k;
    }mystack;

datatype tree[]={10,9,0,0,20,15,0,0,35,0,0};
datatype layer=0,leaves = 0,n = 0;    
    binT* createBinT(binT *head){
        n++;
        if(tree[n]!=0){
            layer++;
            head = (binT*)malloc(sizeof(binT));
            head -> k = tree[n];
            head -> left = createBinT(head->left);
            head -> right = createBinT(head->right);
            cout<< layer;
        }else head = NULL;
        return head;
    }

    binT* Pop(mystack *p){
        p->k = (p->k) - 1;
        return p->tree[p->k];
    }

    bool Push(mystack *p,binT *k){
        int flag;
        flag = p->k;
        
        if(flag > 19)
        {
            return false;
        }
        else{
        p -> tree[flag] = k;
        p -> k = flag + 1;
            return true;
        }
        
    }
    void PreOrder(binT *head){
        if(head!=NULL){
             cout<<head->k;
             PreOrder(head -> left);
             PreOrder(head -> right);
        }
    }

    int CountLeaf(binT *tree){
       if(tree == NULL){
            return 0;
       }
       else if(tree->left == NULL && tree->left){
            return 1;
       }
       else  
            return CountLeaf(tree->left) + CountLeaf(tree->right);
    }

    int GetDepth(binT *tree){
        int left,right;
            if (tree == NULL){
                return 0;
            }
            else if (tree ->left == NULL && tree ->right == NULL)
                return 1;
            else {
                left = GetDepth(tree->left);
                right = GetDepth(tree->right);
            }

        if(right>= 1){
            return right+1;
        }
        else 
            return 0;
    }

    int main(){
        int length = sizeof(tree)/sizeof(int);
        binT *head;
        createBinT(head);
        PreOrder(head);
        cout<<"深度:"<<GetDepth(head)<<"\n";
        cout<<"叶子节点:"<<CountLeaf(head)<<"\n";
    }