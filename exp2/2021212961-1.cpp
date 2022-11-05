#include<iostream>
    using namespace std;
    // 构造一个单链表结构体，其中*next为后键
    typedef struct Node_Type{
        int db;
        struct Node_Type *next;
    }Node_Type;

  // 创建链表函数，由于返回值为链表节点 需要用Node_Type做声明
    Node_Type *createlinklist(Node_Type *h,int n,int f){
        //初始化前键p后面q 和临时t结构体指针，传入f为标记flag
        Node_Type *p,*q,*t;
            p=h->next;
            //使p指针指向头指针head
            if(f == 1){
                t = h;
                for(int i=0;i<n;i++){
                    q = (Node_Type*)malloc(sizeof(Node_Type));
                    cin>>q->db;
                    t->next = q;
                    t = q;
                }
                t->next = NULL;
            }
            else{
                t = h;
                  for (int i=0; i<n; i++) {
                     q = (Node_Type*)malloc(sizeof(Node_Type));
                   cin>>q->db;
                    t->next = q;
                    t = q;}
	         t->next=p;}
            return h;
      }
  void print(Node_Type *h){
  	Node_Type *t = h;
    //逐个打印输出链表 每次打印释放一次节点内存 其中 t为
	while(h!=NULL){
        t=h->next;
		    cout<<t->db<<" ";
	    	free(h);
		    h = t;
	}
}      
    int main(){
          Node_Type *head = NULL,*tmp;
          int flag = 1,num = 0;   //初始化节点元素标记为,定义链表长度num
          char cmd ='y';   //循环执行标记
          head = (Node_Type*)malloc(sizeof(Node_Type));
           //初始化头结点并且将后键赋空
          head->next=NULL;
          while(cmd == 'y'){     //判断函数是否循环进行
            cout<<"输入节点个数\n";
            fflush(stdin);
            cin>>num;
             //创建一个长度给定的单链表
            createlinklist(head,num,flag);
            cout<<"若继续输'y';若跳出输入任意字符,将打印结果";
            cin>>cmd;
          }
          // 打印输出单链表
          print(head);
        return 0;  
    }
