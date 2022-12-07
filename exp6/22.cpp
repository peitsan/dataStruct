#include<iostream>
#define MAX 100
using namespace std;
typedef int TreeData;
//定义二叉链表类型
typedef struct node{
	TreeData data;
	struct node*leftchild;
	struct node*rightchild;
}BinTreeNode;
BinTreeNode*head;
int layer;	//layer用作层数的记录
int num = 0;		//num用作记录叶子结点的个数
//栈的创建
BinTreeNode* S[MAX];
int top;//栈顶指针
//二叉树的创建
void createBiTree(BinTreeNode*(&T)){
	TreeData x;
	cin>>x;
	if(x==0){
		T=NULL;
	}
	else{
		T=new BinTreeNode;
		T->data=x;
		createBiTree(T->leftchild);
		createBiTree(T->rightchild);	
	}
}
//非递归实现先序遍历
void PreOrder(BinTreeNode*(&t)) {
	if (t!=NULL){
		top=0;
		do{
			while(t!=NULL){
				cout<<t->data<<' ';
				if(t->leftchild==NULL&&t->rightchild==NULL){
					num++;
				}
				if(t ->rightchild !=NULL){
					top++;
					S[top]= t-> rightchild;
					layer++;
			}	
				t=t->leftchild;
			}
			if(top!=0){
				t=S[top];
				top--;
			}
		}while((top!=0)||(t!=NULL));
	}
}
//最大深度
int maxDepth(BinTreeNode *(&root)) {
	if(root==NULL)
		return 0;
	int leftDepth = maxDepth(root->leftchild);
	int rightDepth = maxDepth(root->rightchild);
	return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
}

int main(){
	//创建二叉树
	// cout<<"请按照先序输入二叉树储存的元素"<<endl;
	// cout<<"(用0结束当前结点的左/右子树的进一步创建,用空格间隔输入)"<<endl;
	createBiTree(head);
	// cout<<"当前二叉树中的结点的数据按先序输出如下："<<endl;
	BinTreeNode*temp=head;
	PreOrder(head);
	cout<<"\n深度：\n",
	head=temp;
	layer=maxDepth(head);
	cout<<layer;
	cout<<"\n叶子结点：\n";
	cout<<num;
	return 0;
}
