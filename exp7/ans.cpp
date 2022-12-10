
#include<iostream>
#include<vector>
using namespace std;
typedef struct BSTNode {
    int data;    //结点数据域
    BSTNode* lchild, * rchild;    //左右孩子指针
}BSTNode, * BSTree;
void InsertBST(BSTree& T, int e); //二叉排序树的插入
void CreateBST(BSTree& T); //二叉排序树的创建
void InOrderTraverse(BSTree& T);//中序遍历
int BinarySearch(vector<int>arr, int len, int target) {
    cout<<"二分查找元素——"<<target<<"\n"<<endl;
    int low = 0;
    int high = len;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (target < arr[mid]) high = mid - 1;
        else if (target > arr[mid]) low = mid + 1;
        else return mid;
    }
    return -1;
}

vector<int>arry;
int main()
{
    BSTree T;
    cout<<"创建二叉树!\n"<<endl;
    CreateBST(T);//创建二叉树
    InOrderTraverse(T);//中序遍历
    int temp_i = 0;
    cin >> temp_i;
    int index = BinarySearch(arry, arry.size(), temp_i);//二分查找
    if (index != -1) {
        cout << "查找" << arry[index] << "成功";
    }
    else {
        cout << "查找失败";
    }
    return 0;
}
void InsertBST(BSTree& T, char e) {
    //当二叉排序树T中不存在关键字等于e的数据元素时，则插入该元素
    if (!T)
    {
        BSTree S = new BSTNode; //生成新结点
        S->data = e;             //新结点S的数据域置为e
        S->lchild = S->rchild = NULL;//新结点S作为叶子结点
        T = S;                    //把新结点S链接到已找到的插入位置
    }
    else if (e < T->data)
        InsertBST(T->lchild, e);//插入左子树
    else if (e > T->data)
        InsertBST(T->rchild, e);//插入右子树
}
void CreateBST(BSTree& T) {
    //依次读入一个关键字为key的结点，将此结点插入二叉排序树T中
    T = NULL;
    char ch;
    while (cin.get(ch))
    {
        if(isdigit(ch))
            InsertBST(T, ch);  //插入二叉排序树T中
    }
}
void InOrderTraverse(BSTree& T) {
    if (T)
    {
        cout<<"中序遍历序列:\n"<<endl;
        InOrderTraverse(T->lchild);
        arry.push_back(T->data);
        cout << T->data << "\t";
        InOrderTraverse(T->rchild);
    }
}
