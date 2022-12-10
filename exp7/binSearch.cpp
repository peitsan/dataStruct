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
    Stack *inorder = (Stack*)malloc(sizeof(Stack));//���ڴ洢�����������
   
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
        if(T){
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
        cout<<"�����������ַ���!\n";
        gets(stack); //��������ַ�������˳��ջ
        cout<<"�ַ�����ջ!\n";
        while(*(stack+i) != '\0'){
            initial(BinTree,*(stack+i));
            i ++;
            //�ݹ鴴����0-9�ַ�����ɵĶ���������
        }
        //�Դ����Ķ��������������������,������������д���ջ;
        MidOrderMap(BinTree,inorder);
        cout<<"����������У�\n";
        i = 0;
        //������ӡջ��Ԫ��
        while(*(inorder+i)!='\0'){
             i ++;
            cout<<*(inorder+i)<<" ";
        }
        cout<<"\n";
        cout<<"ͨ�����ַ��������ֳ��ֵĴ�����\n";
         cout<<"����������ҵ�����:\n";
         cin.get(target);
        int index = BinarySearch(inorder,_msize(inorder)/sizeof(dataType),target);//���ֲ���
            if (index != -1) {
                cout << "����" << inorder[index] << "�ɹ�"<<'\n';
                 cout << "Ԫ��" << inorder[index] << "������"<<getTimes(BinTree,inorder[index])<< "��"<<endl;
            }
            else {
                cout << "����ʧ��";
        }
    }