#include<iostream>
    using namespace std;
    // ����һ��������ṹ�壬����*nextΪ���
    typedef struct Node_Type{
        int db;
        struct Node_Type *next;
    }Node_Type;

  // ���������������ڷ���ֵΪ����ڵ� ��Ҫ��Node_Type������
    Node_Type *createlinklist(Node_Type *h,int n,int f){
        //��ʼ��ǰ��p����q ����ʱt�ṹ��ָ�룬����fΪ���flag
        Node_Type *p,*q,*t;
            p=h->next;
            //ʹpָ��ָ��ͷָ��head
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
    //�����ӡ������� ÿ�δ�ӡ�ͷ�һ�νڵ��ڴ� ���� tΪ
	while(h!=NULL){
        t=h->next;
		    cout<<t->db<<" ";
	    	free(h);
		    h = t;
	}
}      
    int main(){
          Node_Type *head = NULL,*tmp;
          int flag = 1,num = 0;   //��ʼ���ڵ�Ԫ�ر��Ϊ,����������num
          char cmd ='y';   //ѭ��ִ�б��
          head = (Node_Type*)malloc(sizeof(Node_Type));
           //��ʼ��ͷ��㲢�ҽ��������
          head->next=NULL;
          while(cmd == 'y'){     //�жϺ����Ƿ�ѭ������
            cout<<"����ڵ����\n";
            fflush(stdin);
            cin>>num;
             //����һ�����ȸ����ĵ�����
            createlinklist(head,num,flag);
            cout<<"��������'y';���������������ַ�,����ӡ���";
            cin>>cmd;
          }
          // ��ӡ���������
          print(head);
        return 0;  
    }
