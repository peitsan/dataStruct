#include<iostream>
    using namespace std;
//���ݿ���ֲ��
    typedef char dataListType;
//���ݿ��ֶζ���
    typedef struct dataType{
        dataListType stuNum[11];
        dataListType stuName[7];
        dataListType stuPhone[12];
    }dataType;
//���ݿ�ѭ������ڵ㶨��
    typedef struct Node{
        dataType dataBase;
        struct Node *next;
    }Node,*linkList;
    int length;

//���ݿ��ʼ��(ѭ�������ʼ��)
    linkList initial() //��ʼ��ͷ���
    {
        Node *p;
        p = (Node*)malloc(sizeof(Node)); //����ͷ���ռ�
        if(p == NULL)
            cout<<"�����ڴ�ռ�ʧ��!"<<endl;
        else
        {
            p->next = NULL;
            length = 0;
            cout<<"��ʼ���ɹ�!"<<endl; 
        }
        return p;
    }

//��������(ѭ�������ֵ�ڵ�����)
    linkList inputDataList(linkList list)
    {
        Node *p,*q;
        p = list;   
        int n;               
        cout<<"�����뵼��ѧ����Ϣ����n:";
        cin>>n;
        cout<<"��������n��ѧ����Ϣ(��ʽ:\"ѧ�� ���� �ֻ���\"):\n";                        
        while(n--)
        {
            q=(Node*)malloc(sizeof(Node));
            cin>>q->dataBase.stuNum>>q->dataBase.stuName>>q->dataBase.stuPhone; //��˳������ѧ����Ϣ�б�
            length += 1;
            q->next = NULL;
            p->next = q;
            p = q;
        } 
        return list;
    } 


//���ݴ�ӡ�������
    void coutlist(linkList list){
    int index = 0;
	Node *head;
	if(length == 0)//����Ϊ��   
		cout<<"ѧ����Ϣ���ݿ�Ϊ��!"<<endl;
	//����Ϊ���������ӡ��Ԫ�� 
	else 
	{
		cout<<"ѧ����Ϣ����(ѧ��/����/�ֻ���):\n";
        	cout<<"* �������������������������������������������������������������������������� *\n";
             cout<<"|���| \t "<<"ѧ ��\t "<<"| �� �� "<<" | "<<" �� �� ��\t|\n";
             cout<<"* �������������������������������������������������������������������������� *\n";
		for(head=list->next;head!=NULL;head=head->next)//��һ��Ԫ��ָ��list 
        {
         if(head->dataBase.stuPhone!="") {
            cout<<"| "<< ++index<<" "<<" | "<<head->dataBase.stuNum<<"| "<<head->dataBase.stuName<<" | "<<head->dataBase.stuPhone<<" |\n";
          } 
         }
         
        cout<<"* �������������������������������������������������������������������������� *\n";
          cout<<"| ��������:"<<length<<"\t\t\t\t|\n";
        cout<<"* �������������������������������������������������������������������������� *\n";
		cout<<endl<<endl;
	}
}

// 2021212961 ����� 13364063027
    char menu(char handle){
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"|**------------����ѭ�������ѧ���������ϵͳ------------**|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"|**---------------------ϵͳ�����˵�---------------------**|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"|**\t \t \t \t \t \t \t **|"<<"\n"; 
     cout<<"|**\t \t ��0��ѧ����Ϣ�������� \t \t \t **|"<<"\n"; 
      cout<<"|**\t \t ��1��ָ��λ�ü���ѧ����Ϣ \t \t **|"<<"\n"; 
       cout<<"|**\t \t ��2��ɾ��ָ��ѧ����Ϣ���� \t \t **|"<<"\n"; 
        cout<<"|**\t \t ��3����ѧ�Ų�ѯѧ��������Ϣ \t \t **|"<<"\n"; 
        cout<<"|**\t \t ��4����ѧ���޸�ѧ��������Ϣ \t \t **|"<<"\n"; 
         cout<<"|**\t \t ��5����ǰ���ݿ�����ѧ����Ϣ \t \t **|"<<"\n"; 
         cout<<"|**\t \t ��6��������ݿ� \t \t \t **|"<<"\n"; 
         cout<<"|**\t \t ��7���ر����ݿ� \t \t \t **|"<<"\n"; 
     cout<<"|**\t \t \t \t \t \t \t **|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"���������ָ��,Ĭ��Ϊ��0��:"<<"\n"<<endl; 
    cin>>handle;
    return handle;
    }

  int main(){
        linkList list;
        dataListType n,i,handle;  
	    dataType item; 
	    cout<<"���ݿ������ʼ��!"<<endl;   //��ʼ��ѭ������
	    list = initial();  
        cout<<"�������ݿ�!"<<endl;     //�״�������Ҫ�������ݵ���
        list = (Node*)malloc(sizeof(Node)); 
        list->next = NULL;
        list->dataBase = item; 
	    cout<<"���ݿ�������,�밴�ղ˵��������ݲ���!"<<endl;     //�״�������Ҫ�������ݵ���
        loop:handle = menu(handle);
            switch(handle){
                case '0':{
                    list = inputDataList(list);   
                    coutlist(list);
                    goto loop;
                }
                case '1':{
                    list = inputDataList(list);   
                    coutlist(list);
                    goto loop;
                }
                case '2':{
                    list = inputDataList(list);   
                    coutlist(list);
                    goto loop;
                }
                case '3':{
                    list = inputDataList(list);   
                    coutlist(list);
                    goto loop;
                }
                case '4':{
                    list = inputDataList(list);   
                    coutlist(list);
                    goto loop;
                }
                case '5':{ 
                    coutlist(list);
                    goto loop;
                }
                case '6':{
                    list = initial();  
                    list = (Node*)malloc(sizeof(Node)); 
                    list->next = NULL;
                    list->dataBase = item; 
                    goto loop;
                }
                case '7':{
                    cout<<"������ֹ"<<endl;
                    break;
                }
                default :{
                    cout<<"����ָ���������������룡"<<endl;
                    goto loop;
                }
            }   
        return 0;
    }   