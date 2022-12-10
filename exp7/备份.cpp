#include <iostream>
    using namespace std;
    #define size 20
    typedef int dataType;   
    typedef int Stack;

    typedef struct TreeNode {
        dataType data;
        TreeNode* left;
        TreeNode* right;
    }TreeNode, *Tree;
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    int length = 0;
    void Push (dataType data){
        Stack *tmp = (Stack *)realloc(stack,sizeof(Stack));
        tmp[sizeof(tmp)/sizeof(*tmp)+1] = data;
        stack = tmp;
        length++;
    }
    void insertTreeNode(Tree& T,dataType data){
        if (T != NULL)
        {
           Tree node = (Tree)malloc(sizeof(Tree));
            node->data = data;
            node->left = NULL;
            node->right = NULL;
            T = node;
        }
        else if(data < T->data){
            insertTreeNode(T->left,data);
        }
        else if(data > T->data){
            insertTreeNode(T->right,data);
        }
    }
    void initial(Tree& Tree){
        Tree = NULL;
        dataType tmp;
        while (cin>>tmp){
            if(typeid(tmp)==typeid(dataType)){
                insertTreeNode(Tree,tmp);
            }
        }
    }
    void MidOrderMap(Tree& T){
        if(T){
            MidOrderMap(T->left);
            Push(T->data);
            cout << T->data << "\t";
            MidOrderMap(T->right);
        }
    }
    int BinarySearch(Stack *arr,int len,int target){
        int low = 0;
        int high = len;
        int mid = 0;
         while (low <= high) {
        mid = (low + high) / 2;
        if (target < arr[mid]) high = mid - 1;
        else if (target > arr[mid]) low = mid + 1;
        else 
          return mid;
         }
        return -1;
    }
    int main(){
        Tree BinTree;
        dataType target;
        initial(BinTree);
        MidOrderMap(BinTree);
        cout<<"请输入查找目标:\n";
        cin>>target;
        int index = BinarySearch(stack,length,target);//二分查找
            if (index != -1) {
                cout << "查找" << stack[index] << "成功";
            }
            else {
                cout << "查找失败";
        }
    }