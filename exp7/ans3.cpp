//文件名:exp9-5.cpp
#include<iostream>
using namespace std;
#define MAXWORD 100
typedef struct tnode 
// typedef tnode *BTree
{
    char ch;      //字符
    int count;    //出现次数
    struct tnode *lchild,*rchild;
}  tnode ,*BTree;
void CreaTree(BTree &p,char c) //采用递归方式构造一棵二叉排序树
{
    if (p==NULL)                //p为NULL,则建立一个新结点
    {
        p=new tnode;
        p->ch=c;
        p->count=1;
        p->lchild=p->rchild=NULL;
    }
    else if (c==p->ch){
        p->count++;
    }
    else if (c<p->ch) {
        CreaTree(p->lchild,c);
    }
    else {
        CreaTree(p->rchild,c);
    }
}
void InOrder(BTree p)   //中序遍历BST
{
    if (p!=NULL) 
    {
        InOrder(p->lchild);                 //中序遍历左子树
        cout<<p->ch<<":"<<p->count<<endl;//访问根结点
        InOrder(p->rchild);                 //中序遍历右子树
    }
}
int main()
{
    BTree root=NULL;
	int i=0;
	char str[MAXWORD];
	cout<<("输入字符串:");
	gets(str);
	while (str[i]!='\0') 
	{
		CreaTree(root,str[i]);
		i++;
	}
	cout<<"字符及出现次数:\n";
	InOrder(root);
    cout<<endl;
	return 0;
}


