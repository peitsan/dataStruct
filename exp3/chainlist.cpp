#include <iostream>
    using namespace std;

typedef struct Node_type{
    int l;
    Node_type *next;
}Node_type;
// ����һ��ѭ��������
Node_type* createChainList(Node_type* head, int n){
    while(n){//ѭ�����뺯��
    Node_type *p;
        p = (Node_type*)malloc(sizeof(Node_type));
        cin>>p->l;
        head->next=p;        
        head=head->next;   
        n--; //��ִ��n�����������ѭ�� ÿ������head���ƶ�����һ���ڵ�
        } 
   
    return head;
}

void display(Node_type *head,Node_type *tmp) //��ӡ��ʾ����
        tmp=tmp->next;  //��ʼ��
		if(tmp==head){   //�ж��Ƿ�����Ϊ��
			cout<<"������Ϊ��"<<endl;
		}
		else{
			while(tmp!=head->next){     //�ǿ����������
				cout<<tmp->l<<"  ";
				tmp=tmp->next;
			}
		}
    }

void destroy(Node_type *head, Node_type *tmp) //�����ڴ溯��
    {   //��ʱͷ�ڵ���βָ�� tmp��ͷָ��
        while(tmp->next!=head){  //�����ڴ溯�� ͷ�ڵ㲻����ͷ�ڵ�λ�� һֱ����
            tmp=tmp->next;
	    	free(head);
	    }
    }
int main(){
    Node_type *head = NULL,*p,*temp;  //��ʼ���ṹ��ָ�� βָ�� ��ʱָ��
    int sum = 0;
    char cmd = 'y';
     p =(Node_type*)malloc(sizeof(Node_type));
    // ��̬���ٴ����ڵ�ռ�
    p->l= 0;
    p->next = NULL;
    head = p;
    temp = head;
    while(cmd == 'y'){     //�жϺ����Ƿ�ѭ������
            cout<<"����ڵ����\n";
            fflush(stdin);
            cin>>sum;
             //����һ�����ȸ����ĵ�����
            head = createChainList(head,sum);
            cout<<"��������'y';���������������ַ�,����ӡ���";
            cin>>cmd;
    }
 
        display(head,temp);  //��ӡ���
        destroy(head,temp);  //���տռ�
    return 0;
}



