#include<iostream>
#include<string.h>
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
    //�������ݿ������
    int getlen(linkList list){
        int count = 0;
        linkList p = list;
        while(p!=NULL)
        {	
            count++;//�������ۼ� 
            p = p->next; //ָ��pָ����һ������� 
        }
        return count;
    }

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
    
    void linkListPop(linkList* pphead)
    {
        if (*pphead == NULL)
        {
            return;
        }
        else if ((*pphead)->next == NULL)
        {
            free(*pphead); //��pListָ����ǿ��ڴ�ռ��ͷ�
            *pphead = NULL;//��pListָ����Ϊ��
        }
        else
        {
            linkList tail = *pphead; //βɾ ��Ҫ֪��β��βǰ�Ľṹ��(��Ϊ��)
            linkList prev = NULL;
            while (tail->next != NULL)
            {
                prev = tail;   //С����ָ��
                tail = tail->next;
            }
            free(tail);
            prev->next = NULL;
        }
    
    }
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
        while(p->next!=NULL)
		p = p->next;//�ҵ�����ĩβ���ĵ�ַ               
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

//���ݶ�λ�����ݿ��в����ӽڵ����� 
      linkList insertNode(linkList list,int x,dataType item)
        {
            linkList p,q = list;
            int j=1;
            while(j<x&&q!=NULL)
            {
                q = q ->next;
                j++; 
            }//Ѱ�ҵ�i�������
            if(j!=x||q==NULL)
                printf("�����в����ڵ�i�������");
            p = (linkList)malloc(sizeof(linkList));//����һ���µ������
            p ->dataBase = item;//��item���½���������
            p ->next = q ->next;
            q ->next = p;//���½������i�������֮��
            return p;
        }


//����ѧ����ѧ�Ŷ�λ�����ݿ��е���ź�����
    dataType findIndexByStuNum(linkList list)
    {   dataType item;
        Node *p = list;
        int place = 0;
        cout<<"�������ѯѧ�������ѧ��:\n";
        cin>>item.stuNum;
            while(p->next !=NULL && strcmp(p->dataBase.stuNum,item.stuNum)!=0)
            {  
                place++;
                p = p->next;
            }
             if(strcmp(p->dataBase.stuNum,item.stuNum)==0){
                 cout<<"ѧ��Ϊ:"<<item.stuNum<<"��ѧ�����Ϊ:#"<<place<<"\n";
                cout<<"* �������������������������������������������������������������������������� *\n";
                cout<<"|���| \t "<<"ѧ ��\t "<<"| �� �� "<<" | "<<" �� �� ��\t|\n";
                cout<<"* �������������������������������������������������������������������������� *\n";
                cout<<"| "<< place <<" "<<" | "<<p->dataBase.stuNum<<"| "<<p->dataBase.stuName<<" | "<<p->dataBase.stuPhone<<" |\n";
                cout<<"* �������������������������������������������������������������������������� *\n"<<endl;
                return p->dataBase;
                }
            else cout<<"û�в�ѯ��ѧ��Ϊ:"<<item.stuNum<<"��ѧ����Ϣ!\n"<<endl;
          
    }
    
//����ѧ����ѧ�Ÿ���������
    linkList updateByStuNum(linkList list)
    {   dataType item;
        linkList p = list,q,head = list;
        int place = 0, index = getlen(list);;
        cout<<"�������޸�ѧ�������ѧ��:\n";
        cin>>item.stuNum;
            while(p->next !=NULL && strcmp(p->dataBase.stuNum,item.stuNum)!=0)
            {  
                place++;
                p = p->next;
            }
             if(strcmp(p->dataBase.stuNum,item.stuNum)==0){
                cout<<"ѧ��Ϊ:"<<item.stuNum<<"��ѧ�����Ϊ:#"<<place<<"\n";
                cout<<"������������º���������ֻ��ţ���ʽ:\"���� �ֻ���\"��:"<<"\n"; //��bug
                q=(Node*)malloc(sizeof(Node));
                cin>>q->dataBase.stuName>>q->dataBase.stuPhone;
                strcpy(q->dataBase.stuNum,item.stuNum);
                q->next = p->next;
                while(index>place && head->next!=NULL)
                {
                    linkListPop(&head);
                    index--; 
                }
                head->next = q;
                return q;
                }

            else {
               cout<<"û�в�ѯ��ѧ��Ϊ:"<<item.stuNum<<"��ѧ����Ϣ!\n"<<endl;
               return list;
            }
          
    }
   

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
                    item = findIndexByStuNum(list);
                    goto loop;
                }
                case '4':{
                   list = updateByStuNum(list);
                   getlen(list);
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