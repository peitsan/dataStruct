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
//����ѭ�������ͷ�ڵ� ��Ϊѭ������ı�־λ
    Node *h;
    
//�ֶ��������ݿ������
     int getlen(linkList list){
        int count = 0;
        linkList p = list;
        while(p!=list)
        {	
            count++;//�������ۼ� 
            p = p->next; //ָ��pָ����һ������� 
        }
        return count;
    }

     bool checkDuplication(dataType item,linkList list){
        Node *head;
         for(head=list->next;head!=h;head=head->next)//��һ��Ԫ��ָ��list 
        {
         if(strcmp(head->dataBase.stuNum,item.stuNum)== 0) {
           return true;
          } 
        }
         return false;
    }
//���ݿ������ӡ
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
		for(head=list->next;head!=h;head=head->next)//��һ��Ԫ��ָ��list 
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
       
//���ݿ��ʼ��(ѭ�������ʼ��)
     linkList initial() //��ʼ��ͷ���
    {
        Node *p;
        p = (Node*)malloc(sizeof(Node)); //����ͷ���ռ�
        if(p == NULL)
            cout<<"�����ڴ�ռ�ʧ��!"<<endl;
        else
        {
            p->next = p;
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
        while(p!=list)
		p = p->next;//�ҵ������־λ���ĵ�ַ               
        cout<<"�����������ѧ����Ϣ����n:";
        cin>>n;
        int i = 0,tmp[n];
        cout<<"��������n��ѧ����Ϣ(��ʽ:\"ѧ�� ���� �ֻ���\"):\n";                        
        while(n--)
        {   
            q=(Node*)malloc(sizeof(Node));
            cin>>q->dataBase.stuNum>>q->dataBase.stuName>>q->dataBase.stuPhone; //��˳������ѧ����Ϣ�б�
             if(!checkDuplication(q->dataBase,list)){
                    length += 1;
                    q->next = h;
                    p->next = q;    
                    p = q;
                    tmp[i]=0;
                }
            else{
                q = h;
                tmp[i] = 1;
            }
            i++;
        }
        
        n = i;
        for(i = 0; i < n ; i++)
          if(tmp[i])
             cout<<"��"<<i+1<<"�������Ѿ������ݿ����ظ�,��ֹ����!\n"<<endl;
        return list;
}

//���ݶ�λ�����ݿ��в����ӽڵ����� 
     linkList insertNode(linkList list,int x,dataType item)
        {
            linkList p,q = list;
            int j=1;
            while(j<x&&q!=h)
            {
                q = q ->next;
                j++; 
            }//Ѱ�ҵ�i�������
            if(j!=x||q==h)
                cout<<"�����в����ڵ�i�������"<<endl;
            p = (linkList)malloc(sizeof(linkList));//����һ���µ������
            p ->dataBase = item;//��item���½���������
            p ->next = q ->next;
            q ->next = p;//���½������i�������֮��
            length += 1;
         return q;
        }

//����ѧ����ѧ�Ŷ�λ�����ݿ��е���ź�����
    dataType findIndexByStuNum(linkList list)
    {   dataType item;
        Node *p = list;
        int place = 0;
        cout<<"�������ѯѧ�������ѧ��:\n";
        cin>>item.stuNum;
            while(p->next !=h && strcmp(p->dataBase.stuNum,item.stuNum)!=0)
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
            else {
                cout<<"û�в�ѯ��ѧ��Ϊ:"<<item.stuNum<<"��ѧ����Ϣ!\n"<<endl;
                return list->dataBase;
            }
    }

//���ݶ�λ�������ݲ�������
     void insertBySort(linkList list){
    int x;
    loopInsert:cout<<"������������ݵ�Ŀ��λ�����:\n";
    cin>>x;
    char cmd;
    if(typeid(x) != typeid(int)){
        cout<<"�������ݷǷ�! ���������밴\"Y\"��,�����������!\n"<<endl;
        cin>>cmd;
        if(cmd == 'Y') goto loopInsert;
    }
    else if(x>length){
        cout<<"���ݿ��ڸ�λ��û����Ӧ����,���ܳ������ݿⳤ��!\n";
        cout<<"�������ݷǷ�! ���������밴\"Y\"��,�˳�ָ������!\n"<<endl;
         cin>>cmd;
        if(cmd == 'Y') goto loopInsert;
    }
    else{
        dataType item;
          loopInsertInput:cout<<"�밴��ʽ����������ѧ����Ϣ(��ʽ:\"ѧ�� ���� �ֻ���\"):\n"<<endl; 
          cin>>item.stuNum>>item.stuName>>item.stuPhone; //��˳������ѧ����Ϣ�б�
          if(!checkDuplication(item,list)){
             insertNode(list,x,item);
             coutlist(list);
          }
          else {
            cout<<"�����ѧ����Ϣ�������ݿ����ظ�!\n"; 
            cmd = ' ';
            cout<<"���������밴\"Y\"��,�˳�ָ������!\n"<<endl;
            cin >> cmd;
            if(cmd == 'Y') goto loopInsertInput;
          }
    }   
}

//��������ֶ�ɾ�����ݿ��е�ָ������ڵ�
     void deleteBySort(linkList list){
        int index;
        linkList p = list;
        loopDelBySort:cout<<"������ɾ��Ŀ������\n";
        cin>>index;
        if(p != h){
            if(typeid(index)!=typeid(int)||index>length||index<0){
                cout<<"����ѧ����ŷǷ�!���������밴\"Y\",�����������!\n"<<endl;
                char cmd;
                cin>>cmd;
                if(cmd == 'Y'){
                    goto loopDelBySort;
                }
            }
            else{
                int i = 1;
                linkList q = (linkList)malloc(sizeof(linkList));
                 while(i!= index){
                    i ++;
                    p= p->next;
                 }
                    q = p->next->next;
                    p->next =q;
                    length --;
              }
        }
        else {
            cout<<"���ݿ�Ϊ��,�������!\n"<<endl;
        }
    }

//����ѧ���ֶ�ɾ�����ݿ��е�ָ������ڵ�
     void deleteByStuNum(linkList list){
        dataListType stuNum[11];
        linkList p = list;
        loopdeleteByStuNum:cout<<"������ɾ��Ŀ���ѧ��\n";
        cin>>stuNum;
        if(p != h){
            int i= 0,place= 0;
            while(stuNum[i]!= '\0'){
                i ++;
            };
            if(i!=10){
                cout<<"����ѧ��ѧ�ŷǷ�!���������밴\"Y\",�����������!\n"<<endl;
                char cmd;
                cin>>cmd;
                if(cmd == 'Y'){
                    goto loopdeleteByStuNum;
                }
            }
            else{
                linkList q = (linkList)malloc(sizeof(linkList));
                 while(p->next!=h && strcmp(p->dataBase.stuNum,stuNum)!=0){
                    place++;
                    p= p->next;
                 }
                 i = 0; 
                 p = list;
                while(i!= place -1){
                    i ++;
                    p= p->next;
                 }
                    q = p->next->next;
                    p->next =q;
                    length --;
            }
        }
        else {
            cout<<"���ݿ�Ϊ��,�������!\n"<<endl;
        }
    }

//ɾ��ָ�����ݲ������
     void deletePanel(linkList list){
    dataType item;
    char cmd;
    loopDelete:char x;
     cout<<"|**********************************************************|"<<"\n"; 
     cout<<"|**----------------------�� �� �� ��---------------------**|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"|**\t \t \t \t \t \t \t **|"<<"\n"; 
     cout<<"|**\t \t ��0���������ɾ��ѧ����Ϣ \t \t **|"<<"\n"; 
      cout<<"|**\t \t ��1������ѧ��ɾ��ѧ����Ϣ \t \t **|"<<"\n"; 
     cout<<"|**\t \t \t \t \t \t \t **|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"������ɾ��ָ��:\n";
    cin>>x;
        switch(x)
        {
            case '0':{
                deleteBySort(list);
                    coutlist(list);
                    break;
            };
            case '1':{
                deleteByStuNum(list);
                coutlist(list);
                    break;
            };
            default :{
               cout<<"����ָ��Ƿ�! ���������밴\"Y\"��,�˳�ָ������!\n"<<endl;
                cin>>cmd;
                if(cmd == 'Y') goto loopDelete;     
            }  
        }
}

//����ѧ����ѧ�Ÿ���������
     void updateByStuNum(linkList list)
    {   dataType item;
        linkList p = list,q,head = list;
        int place = 0, index = getlen(list);
        cout<<"�������޸�ѧ�������ѧ��:\n";
        cin>>item.stuNum;
            while(p->next !=h && strcmp(p->dataBase.stuNum,item.stuNum)!=0)
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
                p->dataBase = q->dataBase;
                }
            else {
               cout<<"û�в�ѯ��ѧ��Ϊ:"<<item.stuNum<<"��ѧ����Ϣ!\n"<<endl;
            }
      length = getlen(list);    
    }
    
     void reset(linkList list){
                    dataType item;
                    list = initial();  
                    list->next = h;
                    list->dataBase = item;
                    length = 0;
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
        dataListType handle = 0;  
	    dataType item; 
	    cout<<"���ݿ������ʼ��!"<<endl;   //��ʼ��ѭ������
	    list = initial();  
        cout<<"�������ݿ�!"<<endl;     //�״�������Ҫ�������ݵ���
        list->next = h;
        list->dataBase = item; 
	    cout<<"���ݿ�������,�밴�ղ˵��������ݲ���!"<<endl;     //�״�������Ҫ�������ݵ���
        loop:handle = menu(handle);
            switch(handle){
                case '\n':{
                    list = inputDataList(list);   
                    coutlist(list);
                    goto loop;
                }
                case '0':{
                    list = inputDataList(list);   
                    coutlist(list);
                    goto loop;
                }
                case '1':{
                    insertBySort(list);
                    goto loop;
                }
                case '2':{
                    deletePanel(list);
                    goto loop;
                }
                case '3':{
                    item = findIndexByStuNum(list);
                    goto loop;
                }
                case '4':{
                   updateByStuNum(list);
                   coutlist(list);
                    goto loop;
                }
                case '5':{ 
                    coutlist(list);
                    goto loop;
                }
                case '6':{
                    reset(list);
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