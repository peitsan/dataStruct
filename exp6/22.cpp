#include<iostream>
#define MAX 100
using namespace std;
typedef int TreeData;
//���������������
typedef struct node{
	TreeData data;
	struct node*leftchild;
	struct node*rightchild;
}BinTreeNode;
BinTreeNode*head;
int layer;	//layer���������ļ�¼
int num = 0;		//num������¼Ҷ�ӽ��ĸ���
//ջ�Ĵ���
BinTreeNode* S[MAX];
int top;//ջ��ָ��
//�������Ĵ���
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
//�ǵݹ�ʵ���������
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
//������
int maxDepth(BinTreeNode *(&root)) {
	if(root==NULL)
		return 0;
	int leftDepth = maxDepth(root->leftchild);
	int rightDepth = maxDepth(root->rightchild);
	return leftDepth>rightDepth?leftDepth+1:rightDepth+1;
}

int main(){
	//����������
	// cout<<"�밴��������������������Ԫ��"<<endl;
	// cout<<"(��0������ǰ������/�������Ľ�һ������,�ÿո�������)"<<endl;
	createBiTree(head);
	// cout<<"��ǰ�������еĽ������ݰ�����������£�"<<endl;
	BinTreeNode*temp=head;
	PreOrder(head);
	cout<<"\n��ȣ�\n",
	head=temp;
	layer=maxDepth(head);
	cout<<layer;
	cout<<"\nҶ�ӽ�㣺\n";
	cout<<num;
	return 0;
}
