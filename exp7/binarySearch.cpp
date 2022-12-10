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
    Stack *stack = new Stack[size];//100����char
    int length = 0;
    void Push (dataType data,Stack* inorder){
        // Stack *inorder = (Stack *)realloc(inorder,sizeof(Stack)); //ÿ�β�������һ���ڴ�ռ�ס��
        cout << _msize(inorder)/sizeof(dataType)<<endl;
        inorder[_msize(inorder)/sizeof(dataType)] = data;
    }
    void initial(Tree& Tree,dataType& data){
        if(Tree == NULL){
            Tree = new TreeNode;
            Tree -> data = data;
            Tree -> count = 1;
            Tree -> left = Tree ->right = NULL;
        }//��ʼ�����ڵ�
        else if(typeid(data)==typeid(dataType)&&isdigit(data)){ //ֻȡ��Χ��"0-9"���ַ�����������
                if (data == Tree->data)
                Tree->count ++;
                else if (data < Tree->data)
                    initial(Tree->left,data);
                else if (data > Tree->data)
                    initial(Tree->right,data);
        } //��������������
        //����0-9���͵��ַ��������� ����ѭ��;
    }
    void MidOrderMap(Tree& T,Stack* inorder){
         cout << sizeof(inorder) <<"\n";
        if(T){
            int n = _msize(inorder)/sizeof(dataType) + 1;
            inorder = (Stack *)realloc(inorder,n*sizeof(Stack));
            MidOrderMap(T->left,inorder);
            Push(T->data,inorder);
            cout<<T->data<<":"<<T->count<<endl;//���ʸ����
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
    int main(){
        Tree BinTree = NULL;
        dataType target;
        int i = 0;
        cout<<"�����������ַ���!\n";
        gets(stack); //��������ַ�������˳��ջ
        cout<<"�ַ�����ջ!\n";
        while(*(stack+i) != '\0'){
            initial(BinTree,*(stack+i));
            i ++;
            //�ݹ鴴����0-9�ַ�����ɵĶ���������
        }
        //�Դ����Ķ��������������������,������������д���ջ;
        // Stack *inorder = new Stack[sizeof(Stack)];//���ڴ洢�����������
        Stack *inorder = (Stack*)malloc(sizeof(Stack));//���ڴ洢�����������
        MidOrderMap(BinTree,inorder);
        cout<<"����������У�\n";
        i = 0;
        while(*(inorder+i)!='\0'){
             i ++;
            cout<<*(inorder+i)<<" ";
        }
        cout<<"\n";
        cout<<"ͨ�����ַ��������ֳ��ֵĴ�����\n";
         cout<<"����������ҵ�����:\n";
         cin.get(target);
        int index = BinarySearch(stack,length,target);//���ֲ���
            if (index != -1) {
                cout << "����" << stack[index] << "�ɹ�";
            }
            else {
                cout << "����ʧ��";
        }
    }