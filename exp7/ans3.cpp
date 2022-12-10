//�ļ���:exp9-5.cpp
#include<iostream>
using namespace std;
#define MAXWORD 100
typedef struct tnode 
// typedef tnode *BTree
{
    char ch;      //�ַ�
    int count;    //���ִ���
    struct tnode *lchild,*rchild;
}  tnode ,*BTree;
void CreaTree(BTree &p,char c) //���õݹ鷽ʽ����һ�ö���������
{
    if (p==NULL)                //pΪNULL,����һ���½��
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
void InOrder(BTree p)   //�������BST
{
    if (p!=NULL) 
    {
        InOrder(p->lchild);                 //�������������
        cout<<p->ch<<":"<<p->count<<endl;//���ʸ����
        InOrder(p->rchild);                 //�������������
    }
}
int main()
{
    BTree root=NULL;
	int i=0;
	char str[MAXWORD];
	cout<<("�����ַ���:");
	gets(str);
	while (str[i]!='\0') 
	{
		CreaTree(root,str[i]);
		i++;
	}
	cout<<"�ַ������ִ���:\n";
	InOrder(root);
    cout<<endl;
	return 0;
}


