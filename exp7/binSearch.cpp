#include <iostream>
    using namespace std;
    #define size 100
    typedef char dataType;   
    typedef char Stack;
    typedef struct TreeNode {
        int count;
        dataType data;
        TreeNode* left;
        TreeNode* right;
    }TreeNode, *Tree;
    Stack *stack = new Stack[size];//100个空char
    Stack *inorder = (Stack*)malloc(sizeof(Stack));//用于存储中序遍历序列
   
    void Push (dataType data,Stack* inorder){
        int length = _msize(inorder)/sizeof(dataType) +1;
        inorder[_msize(inorder)/sizeof(dataType)] = data;
        inorder = (Stack *)realloc(inorder,length*sizeof(Stack));
    }
    void initial(Tree& Tree,dataType& data){
        if(Tree == NULL){
            Tree = new TreeNode;
            Tree -> data = data;
            Tree -> count = 1;
            Tree -> left = Tree ->right = NULL;
        }//初始化根节点
        else if(typeid(data)==typeid(dataType)&&isdigit(data)){ //只取范围在"0-9"的字符插入排序树
                if (data == Tree->data)
                Tree->count ++;
                else if (data < Tree->data)
                    initial(Tree->left,data);
                else if (data > Tree->data)
                    initial(Tree->right,data);
        } //创建二叉排序树
        //不是0-9类型的字符结束程序 继续循环;
    }
    void MidOrderMap(Tree& T,Stack* inorder){
        if(T){
            MidOrderMap(T->left,inorder);
            Push(T->data,inorder);
            cout<<T->data<<":"<<T->count<<endl;//访问根结点
            MidOrderMap(T->right,inorder);
        }
    }
    int BinarySearch(Stack *arr,int len,dataType target){
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
    int getTimes(Tree& T,dataType element){
        int count = 0;
        if(T->data == element)
            return T->count;
        else if(T->data != element && T){
            getTimes(T->left,element);
            if(T->data == element){
                count = T->count;
            }
            getTimes(T->right,element);
        }
        return count;
    };
    int main(){
        Tree BinTree = NULL;
        dataType target;
        int i = 0;
        cout<<"请输入任意字符串!\n";
        gets(stack); //将输入的字符串存入顺序栈
        cout<<"字符串入栈!\n";
        while(*(stack+i) != '\0'){
            initial(BinTree,*(stack+i));
            i ++;
            //递归创建由0-9字符串组成的二叉排序树
        }
        //对创建的二叉排序树进行中序遍历,将中序遍历数列存入栈;
        MidOrderMap(BinTree,inorder);
        cout<<"中序遍历序列！\n";
        i = 0;
        //遍历打印栈内元素
        while(*(inorder+i)!='\0'){
             i ++;
            cout<<*(inorder+i)<<" ";
        }
        cout<<"\n";
        cout<<"通过二分法查找数字出现的次数！\n";
         cout<<"请输入需查找的数字:\n";
         cin.get(target);
        int index = BinarySearch(inorder,_msize(inorder)/sizeof(dataType),target);//二分查找
            if (index != -1) {
                cout << "查找" << inorder[index] << "成功"<<'\n';
                 cout << "元素" << inorder[index] << "出现了"<<getTimes(BinTree,inorder[index])<< "次"<<endl;
            }
            else {
                cout << "查找失败";
        }
    }