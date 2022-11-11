#include <iostream>
    using namespace std;

typedef struct Node_type{
    int l;
    Node_type *next;
}Node_type;
// 创建一个循环单链表
Node_type* createChainList(Node_type* head, int n){
    while(n){//循环输入函数
    Node_type *p;
        p = (Node_type*)malloc(sizeof(Node_type));
        cin>>p->l;
        head->next=p;        
        head=head->next;   
        n--; //当执行n次输入后跳出循环 每次输入head会移动到下一个节点
        } 
   
    return head;
}

void display(Node_type *head,Node_type *tmp) //打印显示函数
    {  
        tmp=tmp->next;  //初始化
		if(tmp==head){   //判断是否单链表为空
			cout<<"单链表为空"<<endl;
		}
		else{
			while(tmp!=head->next){     //非空则依次输出
				cout<<tmp->l<<"  ";
				tmp=tmp->next;
			}
		}
    }

void destroy(Node_type *head, Node_type *tmp) //回收内存函数
    {   //此时头节点是尾指针 tmp是头指针
        while(tmp->next!=head){  //回收内存函数 头节点不返回头节点位置 一直回收
            tmp=tmp->next;
	    	free(head);
	    }
    }
int main(){
    Node_type *head = NULL,*p,*temp;  //初始化结构体指针 尾指针 临时指针
    int sum = 0;
    char cmd = 'y';
     p =(Node_type*)malloc(sizeof(Node_type));
    // 动态开辟创建节点空间
    p->l= 0;
    p->next = NULL;
    head = p;
    temp = head;
    while(cmd == 'y'){     //判断函数是否循环进行
            cout<<"输入节点个数\n";
            fflush(stdin);
            cin>>sum;
             //创建一个长度给定的单链表
            head = createChainList(head,sum);
            cout<<"若继续输'y';若跳出输入任意字符,将打印结果";
            cin>>cmd;
    }
 
        display(head,temp);  //打印输出
        destroy(head,temp);  //回收空间
    return 0;
}



