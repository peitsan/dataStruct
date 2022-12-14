#include <iostream>
#include <cstring>
#include <assert.h>
    #define MAX 100
    #define MULTITEST 10
    #define SINGTEST 1
    using namespace std;
    
//���ݿ���ֲ��
    typedef char dataListType;
//���ݿ��ֶζ���
    typedef struct dataType{
        dataListType testID[13];
        dataListType name[7];
        dataListType identification[19];
        dataListType testStatus;
        dataListType testType;
        dataListType testTime[20];
    }dataType;
    
    typedef struct queueNode{
        dataType *dataBase;
        int front;
        int rear;
    }QNode,*QList;
    
    int testSumTimes = 0;
//��ӡ˳������е�Ԫ��
    void coutQueue(QList Que)
    {
        //������ͷ����β�е�ÿ��Ԫ�أ��������ӡ���
        for(int i=Que->front; i<Que->rear; ++i)
        {
            cout<<"|"<<Que->dataBase[i].testID<<"|"<<Que->dataBase[i].name<<"|"<<Que->dataBase[i].identification<<"|"<<Que->dataBase[i].testStatus<<"|\n";
        }
        cout<<endl<<endl;
    }

//��Ӳ���
    void PushQue(QList Que, dataType item)
    {
        //�ж϶����Ƿ��д洢�ռ�
        if(Que->rear >= MAX)
            return;
        //������д洢�ռ䣬���������
        Que->dataBase[Que->rear++] = item;
    }

//����
    void PopQue(QList Que)
    {
        //�ж϶����е�Ԫ���Ƿ�Ϊ��
        if(Que->front == Que->rear)
            return;
        //��������е�Ԫ�ز�Ϊ�գ����г��Ӳ���
        Que->front++;
    }

//��ȡ��ͷԪ��
    void getHead(QList Que, dataType *item)
    {
        //�ж϶����е�Ԫ���Ƿ�Ϊ��
        if(Que->front == Que->rear)
            return;
        //��������е�Ԫ�ز�Ϊ�գ�ȡ����ͷԪ��
        *item = Que->dataBase[Que->front];
    }

//��ȡ����Ԫ�ظ���
    int getlen(QList Que)
    {
        //��βָ��λ�ü�ȥͷָ���λ�þ��Ƕ�����Ԫ�صĸ���
        return (Que->rear - Que->front);
    }

//��ն���
    void reset(QList Que)
    {
        //����ͷָ��Ͷ�βָ�붼����Ϊ0
        Que->front = Que->rear = 0;
    }

//���ٶ���
    void destroyQue(QList Que)
    {
        //�ͷŶ��еĴ洢�ռ�
        free(Que->dataBase);
        //�����пռ��λ��ָ���ÿ�
        Que->dataBase = NULL;
    }

    void initial(QList Que,QList Q1,QList Q2,QList Q3,QList Q4,QList Tested)
    {
        //Ϊ˳����п��ٴ洢�ռ�S
        Que->dataBase = (dataType *)malloc(sizeof(dataType) * MAX);
        Tested->dataBase = (dataType *)malloc(sizeof(dataType) * MAX);
        Q1->dataBase = (dataType *)malloc(sizeof(dataType) * MULTITEST);
         Q2->dataBase = (dataType *)malloc(sizeof(dataType) * MULTITEST);
          Q3->dataBase = (dataType *)malloc(sizeof(dataType) * MULTITEST);
           Q4->dataBase = (dataType *)malloc(sizeof(dataType) * MULTITEST);
         assert(Que->dataBase != NULL);
          assert(Q1->dataBase != NULL);
           assert(Q2->dataBase != NULL);
            assert(Q3->dataBase != NULL);
             assert(Q4->dataBase != NULL);
              assert(Tested->dataBase != NULL);
        //��ʼ��ʱ����ͷ�Ͷ�β����0λ��
        Que->front = Que->rear = 0;
        Q1->front = Q1->rear = 0;
        Q2->front = Q2->rear = 0;
        Q3->front = Q3->rear = 0;
        Q4->front = Q4->rear = 0;
        Tested->front = Tested->rear = 0;
    }

    dataListType* testIDGenerator(){
        dataListType Encode[15];
        time_t rawtime;
        time ( &rawtime );
         struct tm * ptm;
         ptm = gmtime(&rawtime); 
         string s = "";
         s  += to_string(ptm->tm_year + 1900 -2000);
         if(ptm->tm_mon + 1<10){
                s  += string("0");
                s  += to_string(ptm->tm_mon + 1);
            }   
        else {
            s  += to_string(ptm->tm_mon + 1);
        } 
        if(ptm->tm_mday + 1<10){
                 s  += string("0");
                 s  += to_string(ptm->tm_mday);
        }
        else
          s  += to_string(ptm->tm_mday);
        if(ptm->tm_hour + 1<10){
             s  += string("0");
             s  += to_string(ptm->tm_hour); //�˴���ʱ��Ϊ��ʱ��ʱ�� ���ڽ�����c++ת���ѶȽϴ� �˴���ת��ʱ���
        }
        else
          s  += to_string(ptm->tm_hour);
        if(ptm->tm_min + 1<10){
             s  += string("0");
             s  += to_string(ptm->tm_min);
         }
         else {
             s  += to_string(ptm->tm_min);
         }
         if(999<testSumTimes<10000){
            s  += to_string(testSumTimes);
         }
         else if(99<testSumTimes<1000){
            s  += string("0");
            s  += to_string(testSumTimes);
         }
         else if(9<testSumTimes<100){
            s  += string("00");
            s  += to_string(testSumTimes);
         }
          else if(0<=testSumTimes<10){
            s  += string("000");
            s  += to_string(testSumTimes);
         }
            // cout<<s<<endl;  
            strcpy(Encode,s.c_str());
         dataListType* p = Encode;
         return p;
    }
    dataListType* testTimeGenerator(){
        dataListType Time[20];
        time_t rawtime;
        time ( &rawtime );
         struct tm * ptm;
         ptm = gmtime(&rawtime); 
         string s = "";
         s  += to_string(ptm->tm_year + 1900);
         s  += "-";
         if(ptm->tm_mon + 1<10){
                s  += string("0");
                s  += to_string(ptm->tm_mon + 1);
            }   
        else {
            s  += to_string(ptm->tm_mon + 1);
        }
        s  += "-"; 
        if(ptm->tm_mday + 1<10){
                 s  += string("0");
                 s  += to_string(ptm->tm_mday);
        }
        else
          s  += to_string(ptm->tm_mday);
        s  += "-";
        if(ptm->tm_hour + 1<10){
             s  += string("0");
             s  += to_string(ptm->tm_hour); //�˴���ʱ��Ϊ��ʱ��ʱ�� ���ڽ�����c++ת���ѶȽϴ� �˴���ת��ʱ���
        }
        else
          s  += to_string(ptm->tm_hour);
        s  += ":";
        if(ptm->tm_min + 1<10){
             s  += string("0");
             s  += to_string(ptm->tm_min);
         }
         else {
             s  += to_string(ptm->tm_min);
         }
         s  += ":";
         if(ptm->tm_sec + 1<10){
             s  += string("0");
             s  += to_string(ptm->tm_sec);
         }
         else {
             s  += to_string(ptm->tm_sec);
         }
            // cout<<s<<endl;  
            strcpy(Time,s.c_str());
         dataListType* p = Time;
         return p;
    }
  
//�������뻺�����еĴ������Ա������Ϣ  
    void inputToDataBase(QList Que){
         dataType item;
         int n,i= 0 ;
         cout<<"�����뻺����д������Ա����n:\n";
         cin>>n; 
         cout<<"��������nλ�ܼ첡�˵Ļ�����Ϣ(��ʽ:\" ���� ����֤��\"):\n";
         i = n;
         while(n--){
            cin>>item.name>>item.identification;
            strcpy(item.testTime,testTimeGenerator());
            strcpy(item.testID,testIDGenerator());                      //�ֶ�testStatus��״̬�뺬��: '0'�ڻ������ '1'�ڶ����д���� '2'�����ɳ��� '3'���� '4'���� 
            item.testStatus= '0';
            item.testType= '0';                          //�ֶ�testType��״̬�뺬��: '0'δ�� '1'��� '2'���� 
            int len = 0;
            while(item.identification[len]!='\0')
                ++len;
            if(len == 18){
              PushQue(Que,item);
              testSumTimes++;
            }
            else{
                cout<<"��"<<i - n<<"��������Ϣ����֤����Ƿ�,������!\n";
            }
        }
        cout<<endl<<endl;
    }
//״̬��ת����
    dataListType* testTypeTran(dataListType status){
      dataListType *s;
        switch(status){
            case '0':{
               s =  "δ��";
               break;}
            case '1':{
                s = "����";
                break;}
            case '2':{
                s = "���";
                break;}
        }
        return s;
    }
    dataListType* testStatusTran(dataListType status){
        dataListType *s;
        switch(status){
            case '0':{
               s =  "������";
               break;}
            case '1':{
                s = "�����";
                break;}
            case '2':{
                s = "�Ѽ��";
                break;}
            case '3':{
                s = "����";
                break;}
            case '4':{
                s = "����";
                break;}
        }
        return s;
    }
//��ӡ�������еĴ������Ա������Ϣ
    void coutWaitingPool(QList Que){
    int index = 0;
    int length = Que->rear-Que->front; //�ӳ�
	QNode *head;
        if(length == 0)//����Ϊ��   
            cout<<"��ǰû����Ա���ں����⻺�����!"<<endl;
        //���в�Ϊ���������ӡ��Ԫ�� 
        else 
        {
		    cout<<"�����⻺������ܼ���Ա��Ϣ����:\n";
        	 cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
             cout<<"|���| \t"<<"�� �� �� �� "<<" | �� �� "<<" |"<<"\t�� �� �� �� ֤ �� "<<" | ���� | "<<" �� �� ʱ ��\t|"<<"�����|\n";
             cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
		for(int i = 0; i < length;i ++)//��һ��Ԫ��ָ��list 
        {
         if(Que->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Que->dataBase[i].testID<<" "<<" | "<<Que->dataBase[i].name<<" | "<<Que->dataBase[i].identification<<" | "<<testTypeTran(Que->dataBase[i].testType)<<" | "<<Que->dataBase[i].testTime<<" | "<<testStatusTran(Que->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Que->dataBase[i].testID<<" "<<" | "<<Que->dataBase[i].name<<" | "<<Que->dataBase[i].identification<<" | "<<testTypeTran(Que->dataBase[i].testType)<<" | "<<Que->dataBase[i].testTime<<" | "<<testStatusTran(Que->dataBase[i].testStatus)<<" |\n";
          }  
         }
        cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
        cout<<"| �� �� �� �� :"<<length<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
		cout<<endl<<endl;
	    }
    }
    
//��ӡ��֧�����е��ܼ���Ա������Ϣ
    void coutWaitingQue(QList Q1,QList Q2,QList Q3,QList Q4){
        int index = 0;
        int length = (Q1->rear-Q1->front)+(Q2->rear-Q2->front)+(Q3->rear-Q3->front)+(Q4->rear-Q4->front); //�ӳ�
	    QNode *head;
        if(length == 0)//����Ϊ��   
            cout<<"��ǰû����Ա���ڼ������!"<<endl;
        //���в�Ϊ���������ӡ��Ԫ�� 
        else 
        {
		    cout<<"����̨��������ܼ���Ա��Ϣ����:\n";
        	 cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
             cout<<"|���| \t"<<"�� �� �� �� "<<" | �� �� "<<" |"<<"\t�� �� �� �� ֤ �� "<<" | ���� | "<<" �� �� ʱ ��\t|"<<"�����|\n";
             cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
	    cout<<"| �� �� �� һ �� :"<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
        for(int i = 0; i < (Q1->rear-Q1->front);i ++)//��һ��Ԫ��ָ��list 
        {
         if(Q1->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Q1->dataBase[i].testID<<" "<<" | "<<Q1->dataBase[i].name<<" | "<<Q1->dataBase[i].identification<<" | "<<testTypeTran(Q1->dataBase[i].testType)<<" | "<<Q1->dataBase[i].testTime<<" | "<<testStatusTran(Q1->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Q1->dataBase[i].testID<<" "<<" | "<<Q1->dataBase[i].name<<" | "<<Q1->dataBase[i].identification<<" | "<<testTypeTran(Q1->dataBase[i].testType)<<" | "<<Q1->dataBase[i].testTime<<" | "<<testStatusTran(Q1->dataBase[i].testStatus)<<" |\n";
          }  
         }
           cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
        cout<<"| �� �� �� �� �� :"<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
        for(int i = 0; i < (Q2->rear-Q2->front);i ++)//��һ��Ԫ��ָ��list 
        {
         if(Q2->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Q2->dataBase[i].testID<<" "<<" | "<<Q2->dataBase[i].name<<" | "<<Q2->dataBase[i].identification<<" | "<<testTypeTran(Q2->dataBase[i].testType)<<" | "<<Q2->dataBase[i].testTime<<" | "<<testStatusTran(Q2->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Q2->dataBase[i].testID<<" "<<" | "<<Q2->dataBase[i].name<<" | "<<Q2->dataBase[i].identification<<" | "<<testTypeTran(Q2->dataBase[i].testType)<<" | "<<Q2->dataBase[i].testTime<<" | "<<testStatusTran(Q2->dataBase[i].testStatus)<<" |\n";
          }  
         }
           cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
        cout<<"| �� �� �� �� �� :"<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
        for(int i = 0; i < (Q3->rear-Q3->front);i ++)//��һ��Ԫ��ָ��list 
        {
         if(Q3->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Q3->dataBase[i].testID<<" "<<" | "<<Q3->dataBase[i].name<<" | "<<Q3->dataBase[i].identification<<" | "<<testTypeTran(Q3->dataBase[i].testType)<<" | "<<Q3->dataBase[i].testTime<<" | "<<testStatusTran(Q3->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Q3->dataBase[i].testID<<" "<<" | "<<Q3->dataBase[i].name<<" | "<<Q3->dataBase[i].identification<<" | "<<testTypeTran(Q3->dataBase[i].testType)<<" | "<<Q3->dataBase[i].testTime<<" | "<<testStatusTran(Q3->dataBase[i].testStatus)<<" |\n";
          }  
         }
         cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
        cout<<"| �� �� �� �� �� :"<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
        for(int i = 0; i < (Q4->rear-Q4->front);i ++)//��һ��Ԫ��ָ��list 
        {
         if(Q4->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Q4->dataBase[i].testID<<" "<<" | "<<Q4->dataBase[i].name<<" | "<<Q4->dataBase[i].identification<<" | "<<testTypeTran(Q4->dataBase[i].testType)<<" | "<<Q4->dataBase[i].testTime<<" | "<<testStatusTran(Q4->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Q4->dataBase[i].testID<<" "<<" | "<<Q4->dataBase[i].name<<" | "<<Q4->dataBase[i].identification<<" | "<<testTypeTran(Q4->dataBase[i].testType)<<" | "<<Q4->dataBase[i].testTime<<" | "<<testStatusTran(Q4->dataBase[i].testStatus)<<" |\n";
          }  
         }


        cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
        cout<<"| �� �� �� �� :"<<length<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
		cout<<endl<<endl;
	    }
    }
    
//��ӡ����ɼ����ܼ���Ա������Ϣ
    void coutTestedQue(QList Tested){
    int index = 0;
    int length = Tested->rear-Tested->front; //�ӳ�
	QNode *head;
        if(length == 0)//����Ϊ��   
            cout<<"��ǰû����Ա��ɺ�����!"<<endl;
        //���в�Ϊ���������ӡ��Ԫ�� 
        else 
        {
		    cout<<"����ɺ������ܼ���Ա��Ϣ����:\n";
        	 cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
             cout<<"|���| \t"<<"�� �� �� �� "<<" | �� �� "<<" |"<<"\t�� �� �� �� ֤ �� "<<" | ���� | "<<" �� �� ʱ ��\t|"<<"�����|\n";
             cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
		for(int i = 0; i < length;i ++)//��һ��Ԫ��ָ��list 
        {
         if(Tested->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Tested->dataBase[i].testID<<" "<<" | "<<Tested->dataBase[i].name<<" | "<<Tested->dataBase[i].identification<<" | "<<testTypeTran(Tested->dataBase[i].testType)<<" | "<<Tested->dataBase[i].testTime<<" | "<<testStatusTran(Tested->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Tested->dataBase[i].testID<<" "<<" | "<<Tested->dataBase[i].name<<" | "<<Tested->dataBase[i].identification<<" | "<<testTypeTran(Tested->dataBase[i].testType)<<" | "<<Tested->dataBase[i].testTime<<" | "<<testStatusTran(Tested->dataBase[i].testStatus)<<" |\n";
          }  
         }
        cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
        cout<<"| �� �� �� �� :"<<length<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
		cout<<endl<<endl;
	    }
    }

//��ӡ��ѯ�ĺ���������¼
      void coutQueryRes(QList Tested){
        cout<<Tested->dataBase[0].name;
        int index = 0;
        int length = Tested->rear-Tested->front; //�ӳ�
        QNode *head;
            if(length == 0)//����Ϊ��   
                cout<<"���ܼ���Աû�к�������ʷ��¼!"<<endl;
            //���в�Ϊ���������ӡ��Ԫ�� 
            else 
            {
		    cout<<"��ѯ���ܼ���Ա����ʷ������Ϣ����:\n";
        	 cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
             cout<<"|���| \t"<<"�� �� �� �� "<<" | �� �� "<<" |"<<"\t�� �� �� �� ֤ �� "<<" | ���� | "<<" �� �� ʱ ��\t|"<<"�����|\n";
             cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
		for(int i = 0; i < length;i ++)//��һ��Ԫ��ָ��list 
        {
         if(Tested->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Tested->dataBase[i].testID<<" "<<" | "<<Tested->dataBase[i].name<<" | "<<Tested->dataBase[i].identification<<" | "<<testTypeTran(Tested->dataBase[i].testType)<<" | "<<Tested->dataBase[i].testTime<<" | "<<testStatusTran(Tested->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Tested->dataBase[i].testID<<" "<<" | "<<Tested->dataBase[i].name<<" | "<<Tested->dataBase[i].identification<<" | "<<testTypeTran(Tested->dataBase[i].testType)<<" | "<<Tested->dataBase[i].testTime<<" | "<<testStatusTran(Tested->dataBase[i].testStatus)<<" |\n";
          }  
         }
        cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
        cout<<"| �� �� �� �� :"<<length<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ������������������������������������������������������������������������������������������������������������������������������������������������������������������������������*\n";
		cout<<endl<<endl;
	    }
    }


//���˵��ܺ��������
    void singleTest(QList Que,QList Q1,QList Q2,QList Q3,QList Q4){
        dataType item;
        dataType *p = new dataType;
        getHead(Que,p);
        item = *p;
        if(Q1->front == Q1->rear){
            cout<<"����1�ż����"<<endl;
            item.testType = '1';
            item.testStatus = '1';
            PopQue(Que);
            PushQue(Q1,item);
        }
        else {
            if(Q2->front == Q2->rear){
            cout<<"����2�ż����"<<endl;
             item.testType = '1';
            item.testStatus = '1';
            PopQue(Que);
            PushQue(Q2,item);
            }else {
                if(Q3->front == Q3->rear){
                     cout<<"����3�ż����"<<endl;
                      item.testType = '1';
                    item.testStatus = '1';
                    PopQue(Que);
                    PushQue(Q3,item);
                    }else {
                            if(Q4->front == Q4->rear){
                            cout<<"����4�ż����"<<endl;
                             item.testType = '1';
                            item.testStatus = '1';
                            PopQue(Que);
                            PushQue(Q4,item);
                            }
                            else{
                                cout<<"��ǰ���к������߾�ռ��!��ȴ�!\n"<<endl;
                            }
                    }
                }
        }
    }
//ʮ�˻�ܺ��������
    void multiTest(QList Que,QList Q1,QList Q2,QList Q3,QList Q4){
        
        if(Q1->front == Q1->rear){
            cout<<"����1�ż����"<<endl;
            for(int i = 0; i < 10; i++){
                dataType *p = (dataType*)malloc(sizeof(dataType)*2);
               getHead(Que,p);
               PopQue(Que);
               PushQue(Q1,*p);
               free(p);
            }
            for(int i = 0; i < 10; i++){
                                Q1->dataBase[i].testStatus = '1';
                                Q1->dataBase[i].testType = '2';
            }
        }
        else {
            if(Q2->front == Q2->rear){
            cout<<"����2�ż����"<<endl;
            for(int i = 0; i < 10; i++){
                dataType *p = (dataType*)malloc(sizeof(dataType)*2);
                getHead(Que,p);
                PopQue(Que);
                PushQue(Q2,*p);
                 free(p);
            }
            for(int i = 0; i < 10; i++){
                                Q2->dataBase[i].testStatus = '1';
                                Q2->dataBase[i].testType = '2';
                            }
            }else {
                if(Q3->front == Q3->rear){
                     cout<<"����3�ż����"<<endl;
                      for(int i = 0; i < 10; i++){
                        dataType *p = (dataType*)malloc(sizeof(dataType)*2);
                        getHead(Que,p);
                        PopQue(Que);
                        PushQue(Q3,*p);
                         free(p);
                     }
                     for(int i = 0; i < 10; i++){
                        Q3->dataBase[i].testStatus = '1';
                        Q3->dataBase[i].testType = '2';
                     }
                    }else {
                            if(Q4->front == Q4->rear){
                            cout<<"����4�ż����"<<endl;
                            for(int i = 0; i < 10; i++){
                                dataType *p = (dataType*)malloc(sizeof(dataType)*2);
                                getHead(Que,p);
                                PopQue(Que);
                                PushQue(Q4,*p);
                                free(p);
                            }
                             for(int i = 0; i < 10; i++){
                                Q4->dataBase[i].testStatus = '1';
                                Q4->dataBase[i].testType = '2';
                            }
                            
                            }
                            else{
                                cout<<"��ǰ���к������߾�ռ��!��ȴ�!\n"<<endl;
                            }
                    }
                }
        }
        //ȡ����ͷԪ�� �ж��ĸ��ֶ���Ϊ�� Ϊ�������
    }

//�����ɴӼ��̨�뿪һ��
    void testOver(QList Q,QList Tested){
        dataType item;
        dataType *p = new dataType;
        getHead(Q,p);
        item = *p;
        item.testStatus = '2';
        PopQue(Q);
        PushQue(Tested,item);
    }

//��װһ����ѯ�������ô���
    string queryQueRes(QList Q,dataType item,int *index){
         int tmp = *index;
        while(Q->dataBase[tmp].identification != NULL && strcmp(Q->dataBase[tmp].identification,item.identification)!=0)
            {  
                tmp++;
            }
            //�����ǲο�web����������ӿڵ�д�� ��Ϊ���Լ���webǰ��˿��� �Ƚ�ϰ������д��
        if(strcmp(Q->dataBase[tmp].identification,item.identification) == 0){
            *index = tmp;
               if(Q->dataBase[tmp].testStatus != NULL){
                return "200";
               }
               else if(Q->dataBase[tmp].testStatus == NULL){
                return "404";
               }
        }   
        else 
            return "501";
    }

//��������֤�Ų�ѯ����һ������״̬
    QList queryTestRes(QList Pool,QList Q1,QList Q2,QList Q3,QList Q4,QList Tested)
    {   dataType item;
        QList p = (QList)malloc(sizeof(QList));
        loopQuery:cout<<"�������ѯ�ܼ���Ա��18λ��������֤����:\n";
        cin>>item.identification;
        int len = 0;
            while(item.identification[len]!='\0')
                ++len;
            if(len == 18){
                int index = 0,list = 0;
                string res = queryQueRes(Pool,item,&index);
                if(res == "200"){
                    cout<<"��ѯ���ݿ�ɹ�,���ܼ���Ա��ǰ���ڻ�������!\n"<<endl;
                    strcpy(p->dataBase[list].testID,Pool->dataBase[index].testID);
                    strcpy(p->dataBase[list].identification,Pool->dataBase[index].identification);
                    strcpy(p->dataBase[list].name,Pool->dataBase[index].name);
                    strcpy(p->dataBase[list].testTime,Pool->dataBase[index].testTime);
                    p->dataBase[list].testType = Pool->dataBase[index].testType;
                    p->dataBase[list].testStatus = Pool->dataBase[index].testStatus;
                    list++;
                    // return p;
                }
                else if(res == "404"){
                    cout<<"��ѯ���ݿ�ɹ�,���ܼ���Ա��ǰ���ڻ�������!\n";
                    cout<<"�������¼�쳣,����Ϊ��!\n"<<endl;
                    strcpy(p->dataBase[list].testID,Pool->dataBase[index].testID);
                    strcpy(p->dataBase[list].identification,Pool->dataBase[index].identification);
                    strcpy(p->dataBase[list].name,Pool->dataBase[index].name);
                    strcpy(p->dataBase[list].testTime,Pool->dataBase[index].testTime);
                    p->dataBase[list].testType = Pool->dataBase[index].testType;
                    p->dataBase[list].testStatus = Pool->dataBase[index].testStatus;
                    list++;
                    // return p;
                }
            cout<<"q1\n";   
                index = 0;
                string res = queryQueRes(Q1,item,&index);
                if(res == "200"){
                        cout<<"��ѯ���ݿ�ɹ�,���ܼ���Ա��ǰ���ڼ����һ��!\n"<<endl;
                            strcpy(p->dataBase[list].testID,Q1->dataBase[index].testID);
                            strcpy(p->dataBase[list].identification,Q1->dataBase[index].identification);
                            strcpy(p->dataBase[list].name,Q1->dataBase[index].name);
                            strcpy(p->dataBase[list].testTime,Q1->dataBase[index].testTime);
                            p->dataBase[list].testType = Q1->dataBase[index].testType;
                            p->dataBase[list].testStatus = Q1->dataBase[index].testStatus;
                            cout<<p->dataBase[1].identification<<endl;
                            list++;
                        //   return p;
                    }
                else if(res == "404"){
                        cout<<"��ѯ���ݿ�ɹ�,���ܼ���Ա��ǰ���ڼ����һ��!\n";
                        cout<<"�������¼�쳣,����Ϊ��!\n"<<endl;
                        strcpy(p->dataBase[list].testID,Q1->dataBase[index].testID);
                            strcpy(p->dataBase[list].identification,Q1->dataBase[index].identification);
                            strcpy(p->dataBase[list].name,Q1->dataBase[index].name);
                            strcpy(p->dataBase[list].testTime,Q1->dataBase[index].testTime);
                            p->dataBase[list].testType = Q1->dataBase[index].testType;
                            p->dataBase[list].testStatus = Q1->dataBase[index].testStatus;
                            list++;
                        //   return p;
                    }
             cout<<"q2\n";                  
                index = 0;
               string res = queryQueRes(Q2,item,&index);
                  if(res == "200"){
                            cout<<"��ѯ���ݿ�ɹ�,���ܼ���Ա��ǰ���ڼ���߶���!\n"<<endl;
                            strcpy(p->dataBase[list].testID,Q2->dataBase[index].testID);
                            strcpy(p->dataBase[list].identification,Q2->dataBase[index].identification);
                            strcpy(p->dataBase[list].name,Q2->dataBase[index].name);
                            strcpy(p->dataBase[list].testTime,Q2->dataBase[index].testTime);
                            p->dataBase[list].testType = Q2->dataBase[index].testType;
                            p->dataBase[list].testStatus = Q2->dataBase[index].testStatus;
                            list++;
                                //  return p;
                  }
                  else if(res == "404"){
                                cout<<"��ѯ���ݿ�ɹ�,���ܼ���Ա��ǰ���ڼ���߶���!\n";
                                cout<<"�������¼�쳣,����Ϊ��!\n"<<endl;
                                   strcpy(p->dataBase[list].testID,Q2->dataBase[index].testID);
                                    strcpy(p->dataBase[list].identification,Q2->dataBase[index].identification);
                                    strcpy(p->dataBase[list].name,Q2->dataBase[index].name);
                                    strcpy(p->dataBase[list].testTime,Q2->dataBase[index].testTime);
                                    p->dataBase[list].testType = Q2->dataBase[index].testType;
                                    p->dataBase[list].testStatus = Q2->dataBase[index].testStatus;
                                    list++;
                  }
             cout<<"q13\n";                   
                   index = 0;
                   res = queryQueRes(Q3,item,&index);
                  if(res == "200"){
                                            cout<<"��ѯ���ݿ�ɹ�,���ܼ���Ա��ǰ���ڼ��������!\n"<<endl;
                                                  strcpy(p->dataBase[list].testID,Q3->dataBase[index].testID);
                                                strcpy(p->dataBase[list].identification,Q3->dataBase[index].identification);
                                                strcpy(p->dataBase[list].name,Q3->dataBase[index].name);
                                                strcpy(p->dataBase[list].testTime,Q3->dataBase[index].testTime);
                                                p->dataBase[list].testType = Q3->dataBase[index].testType;
                                                p->dataBase[list].testStatus = Q3->dataBase[index].testStatus;
                                                list++;
                                                // return p;
                                        }
                   else if(res == "404"){
                                            cout<<"��ѯ���ݿ�ɹ�,���ܼ���Ա��ǰ���ڼ��������!\n";
                                            cout<<"�������¼�쳣,����Ϊ��!\n"<<endl;
                                                strcpy(p->dataBase[list].testID,Q3->dataBase[index].testID);
                                                strcpy(p->dataBase[list].identification,Q3->dataBase[index].identification);
                                                strcpy(p->dataBase[list].name,Q3->dataBase[index].name);
                                                strcpy(p->dataBase[list].testTime,Q3->dataBase[index].testTime);
                                                p->dataBase[list].testType = Q3->dataBase[index].testType;
                                                p->dataBase[list].testStatus = Q3->dataBase[index].testStatus;
                                                list++;
                                                // return p;
                                        }
              cout<<"q4\n";                             
                   index = 0;
                    string res = queryQueRes(Q4,item,&index);
                     if(res == "200"){
                                                    cout<<"��ѯ���ݿ�ɹ�,���ܼ���Ա��ǰ���ڼ��������!\n"<<endl;
                                                         strcpy(p->dataBase[list].testID,Q4->dataBase[index].testID);
                                                            strcpy(p->dataBase[list].identification,Q4->dataBase[index].identification);
                                                            strcpy(p->dataBase[list].name,Q4->dataBase[index].name);
                                                            strcpy(p->dataBase[list].testTime,Q4->dataBase[index].testTime);
                                                            p->dataBase[list].testType = Q4->dataBase[index].testType;
                                                            p->dataBase[list].testStatus = Q4->dataBase[index].testStatus;
                                                            list++;
                                                        // return p;  
                                                }
                       else if(res == "404"){
                                                    cout<<"��ѯ���ݿ�ɹ�,���ܼ���Ա��ǰ���ڼ��������!\n";
                                                    cout<<"�������¼�쳣,����Ϊ��!\n"<<endl;
                                                            strcpy(p->dataBase[list].testID,Q4->dataBase[index].testID);
                                                            strcpy(p->dataBase[list].identification,Q4->dataBase[index].identification);
                                                            strcpy(p->dataBase[list].name,Q4->dataBase[index].name);
                                                            strcpy(p->dataBase[list].testTime,Q4->dataBase[index].testTime);
                                                            p->dataBase[list].testType = Q4->dataBase[index].testType;
                                                            p->dataBase[list].testStatus = Q4->dataBase[index].testStatus;
                                                            list++;
                                                        // return p; 
                                                }
                                                
                        index = 0;
                        while(index<(Tested->rear-Tested->front)){
                                string res = queryQueRes(Tested,item,&index);
                                                                if(res == "200"){
                                                                    cout<<"��ѯ���ݿ�ɹ�,���ܼ���Ա����ɺ������뿪!\n"<<endl;
                                                                   strcpy(p->dataBase[list].testID,Tested->dataBase[index].testID);
                                                                    strcpy(p->dataBase[list].identification,Tested->dataBase[index].identification);
                                                                    strcpy(p->dataBase[list].name,Tested->dataBase[index].name);
                                                                    strcpy(p->dataBase[list].testTime,Tested->dataBase[index].testTime);
                                                                    p->dataBase[list].testType = Tested->dataBase[index].testType;
                                                                    p->dataBase[list].testStatus = Tested->dataBase[index].testStatus;
                                                                }
                                                                else if(res == "404"){
                                                                    cout<<"��ѯ���ݿ�ɹ�,���ܼ���Ա����ɺ������뿪!\n";
                                                                    cout<<"�������¼�쳣,����Ϊ��!\n"<<endl;
                                                                  strcpy(p->dataBase[list].testID,Tested->dataBase[index].testID);
                                                                    strcpy(p->dataBase[list].identification,Tested->dataBase[index].identification);
                                                                    strcpy(p->dataBase[list].name,Tested->dataBase[index].name);
                                                                    strcpy(p->dataBase[list].testTime,Tested->dataBase[index].testTime);
                                                                    p->dataBase[list].testType = Tested->dataBase[index].testType;
                                                                    p->dataBase[list].testStatus = Tested->dataBase[index].testStatus;
                                                                }
                                                                else {
                                                                    return p;
                                                                }
                                                                list++;
                                                           }
                                    cout<<"return"<<endl;
                                        return p;
            }   
            else{
                cout<<"�����������֤����Ƿ�,���������밴\"Y\"��,��������˳�!\n"<<endl;
                char cmd;
                cin>>cmd;
                if(cmd == 'Y')
                    goto loopQuery;
            }      
    }


//�����˵�����װ  
    char menu(char handle){
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"|**------����˳��洢�ṹ�ĺ�������й����������------**|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"|**---------------------ϵͳ�����˵�---------------------**|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"|**\t \t \t \t \t \t \t **|"<<"\n"; 
    cout<<"|**\t \t ��0���μ���Ա�������� \t \t \t **|"<<"\n"; 
    cout<<"|**\t \t ��1��ʮ��һ�ܺ����� \t \t \t **|"<<"\n"; 
    cout<<"|**\t \t ��2�����˵��ܺ����� \t \t \t **|"<<"\n"; 
    cout<<"|**\t \t ��3��һ��̨�����һ�� \t \t \t **|"<<"\n";
    cout<<"|**\t \t ��4������̨�����һ�� \t \t \t **|"<<"\n";
    cout<<"|**\t \t ��5������̨�����һ�� \t \t \t **|"<<"\n";
    cout<<"|**\t \t ��6���ĺ�̨�����һ�� \t \t \t **|"<<"\n";
    cout<<"|**\t \t ��7��������֤�Ų�ѯ�ܼ���Ա����״̬  \t **|"<<"\n";
    cout<<"|**\t \t ��8��������֤���޸��ܼ���Ա������Ϣ  \t **|"<<"\n"; 
    cout<<"|**\t \t ��9����ǰ��������������Ա��Ϣ \t \t **|"<<"\n";
    cout<<"|**\t \t ��10����ǰδ������������Ա��Ϣ\t \t **|"<<"\n";  
    cout<<"|**\t \t ��11��������ݿ� \t \t \t **|"<<"\n"; 
    cout<<"|**\t \t ��12���ر����ݿ� \t \t \t **|"<<"\n"; 
     cout<<"|**\t \t \t \t \t \t \t **|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"���������ָ��,Ĭ��Ϊ��0��:"<<"\n"<<endl; 
    cin>>handle;
    return handle;
    }
    int main(){
        dataListType handle;
        // �����ȡ�ļ��ͨ���Զ��������Ŷӽ���;
        QNode waitingPool,Que1,Que2,Que3,Que4,testedPool;
        cout<<"���ݿ���г�ʼ��!"<<endl;   //��ʼ��˳�����
        initial(&waitingPool,&Que1,&Que2,&Que3,&Que4,&testedPool);
        cout<<"���ݿ�������!"<<endl;   //��ʼ�����гɹ�
        loop:handle = menu(handle);
        switch(handle){
            case '0':{
                inputToDataBase(&waitingPool);
                coutWaitingPool(&waitingPool);
                goto loop;
            }
            case '1':{
                multiTest(&waitingPool,&Que1,&Que2,&Que3,&Que4);
                coutWaitingPool(&waitingPool);
                coutWaitingQue(&Que1,&Que2,&Que3,&Que4);
                goto loop;
            }
            case '2':{
                singleTest(&waitingPool,&Que1,&Que2,&Que3,&Que4);
                coutWaitingPool(&waitingPool);
                coutWaitingQue(&Que1,&Que2,&Que3,&Que4);
                goto loop;
            }
            case '3':{
                testOver(&Que1,&testedPool);
                coutWaitingQue(&Que1,&Que2,&Que3,&Que4);
                coutTestedQue(&testedPool);
                goto loop;
            }
            case '4':{
                testOver(&Que2,&testedPool);
                coutWaitingQue(&Que1,&Que2,&Que3,&Que4);
                coutTestedQue(&testedPool);
                goto loop;
            }
            case '5':{
                testOver(&Que3,&testedPool);
                coutWaitingQue(&Que1,&Que2,&Que3,&Que4);
                coutTestedQue(&testedPool);
                goto loop;
            }
            case '6':{
                testOver(&Que4,&testedPool);
                coutWaitingQue(&Que1,&Que2,&Que3,&Que4);
                coutTestedQue(&testedPool);
                goto loop;
            }
            case '7':{
                QList res;
                res = queryTestRes(&waitingPool,&Que1,&Que2,&Que3,&Que4,&testedPool);
                cout <<"res"<<res->dataBase->identification;
                if(res != NULL) coutQueryRes(res);
                else cout<<"���޴�����֤�����Ӧ�ĺ����¼";
                goto loop;
            }
            case '8':{
                
                goto loop;
            }
            case '9':{
                coutTestedQue(&testedPool);
                  goto loop;
            }
            case '10':{
                coutWaitingPool(&waitingPool);
                coutWaitingQue(&Que1,&Que2,&Que3,&Que4);
                goto loop;
            }
            case '11':{
                  initial(&waitingPool,&Que1,&Que2,&Que3,&Que4,&testedPool);
                  reset(&Que1);
                  reset(&Que2);
                  reset(&Que3);
                  reset(&Que4);
                  reset(&waitingPool);
                 cout<<"�������ݿ�ɹ�!"<<endl;   //��ʼ�����гɹ�
                goto loop;
            }
            case '12':{
                 cout<<"������ֹ"<<endl;
                 break;
            }
            default:{
                 cout<<"����ָ���������������룡"<<endl;
                 goto loop;
            }
        }
    }