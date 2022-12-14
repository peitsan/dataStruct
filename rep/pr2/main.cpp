#include <iostream>
#include <cstring>
#include <assert.h>
    #define MAX 100
    #define MULTITEST 10
    #define SINGTEST 1
    using namespace std;
    
//数据可移植化
    typedef char dataListType;
//数据库字段定义
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
//打印顺序队列中的元素
    void coutQueue(QList Que)
    {
        //遍历队头到队尾中的每个元素，并将其打印输出
        for(int i=Que->front; i<Que->rear; ++i)
        {
            cout<<"|"<<Que->dataBase[i].testID<<"|"<<Que->dataBase[i].name<<"|"<<Que->dataBase[i].identification<<"|"<<Que->dataBase[i].testStatus<<"|\n";
        }
        cout<<endl<<endl;
    }

//入队操作
    void PushQue(QList Que, dataType item)
    {
        //判断队列是否还有存储空间
        if(Que->rear >= MAX)
            return;
        //如果还有存储空间，将数据入队
        Que->dataBase[Que->rear++] = item;
    }

//出队
    void PopQue(QList Que)
    {
        //判断队列中的元素是否为空
        if(Que->front == Que->rear)
            return;
        //如果队列中的元素不为空，进行出队操作
        Que->front++;
    }

//获取队头元素
    void getHead(QList Que, dataType *item)
    {
        //判断队列中的元素是否为空
        if(Que->front == Que->rear)
            return;
        //如果队列中的元素不为空，取出队头元素
        *item = Que->dataBase[Que->front];
    }

//获取队列元素个数
    int getlen(QList Que)
    {
        //将尾指针位置减去头指针的位置就是队列中元素的个数
        return (Que->rear - Que->front);
    }

//清空队列
    void reset(QList Que)
    {
        //将队头指针和队尾指针都重置为0
        Que->front = Que->rear = 0;
    }

//销毁队列
    void destroyQue(QList Que)
    {
        //释放队列的存储空间
        free(Que->dataBase);
        //将队列空间的位置指针置空
        Que->dataBase = NULL;
    }

    void initial(QList Que,QList Q1,QList Q2,QList Q3,QList Q4,QList Tested)
    {
        //为顺序队列开辟存储空间S
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
        //初始化时，队头和队尾都在0位置
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
             s  += to_string(ptm->tm_hour); //此处的时间为零时区时间 由于进制在c++转换难度较大 此处不转换时间戳
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
             s  += to_string(ptm->tm_hour); //此处的时间为零时区时间 由于进制在c++转换难度较大 此处不转换时间戳
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
  
//批量输入缓存区中的待检测人员基本信息  
    void inputToDataBase(QList Que){
         dataType item;
         int n,i= 0 ;
         cout<<"请输入缓冲池中待检测人员数量n:\n";
         cin>>n; 
         cout<<"请输入这n位受检病人的基本信息(格式:\" 姓名 身份证号\"):\n";
         i = n;
         while(n--){
            cin>>item.name>>item.identification;
            strcpy(item.testTime,testTimeGenerator());
            strcpy(item.testID,testIDGenerator());                      //字段testStatus中状态码含义: '0'在缓冲池中 '1'在队列中待检测 '2'检测完成出队 '3'阴性 '4'阳性 
            item.testStatus= '0';
            item.testType= '0';                          //字段testType中状态码含义: '0'未检 '1'混检 '2'单检 
            int len = 0;
            while(item.identification[len]!='\0')
                ++len;
            if(len == 18){
              PushQue(Que,item);
              testSumTimes++;
            }
            else{
                cout<<"第"<<i - n<<"条输入信息身份证号码非法,已跳过!\n";
            }
        }
        cout<<endl<<endl;
    }
//状态码转换器
    dataListType* testTypeTran(dataListType status){
      dataListType *s;
        switch(status){
            case '0':{
               s =  "未检";
               break;}
            case '1':{
                s = "单检";
                break;}
            case '2':{
                s = "混检";
                break;}
        }
        return s;
    }
    dataListType* testStatusTran(dataListType status){
        dataListType *s;
        switch(status){
            case '0':{
               s =  "缓冲区";
               break;}
            case '1':{
                s = "待检测";
                break;}
            case '2':{
                s = "已检测";
                break;}
            case '3':{
                s = "阴性";
                break;}
            case '4':{
                s = "阳性";
                break;}
        }
        return s;
    }
//打印缓存区中的待检测人员基本信息
    void coutWaitingPool(QList Que){
    int index = 0;
    int length = Que->rear-Que->front; //队长
	QNode *head;
        if(length == 0)//队列为空   
            cout<<"当前没有人员处于核酸检测缓冲带内!"<<endl;
        //队列不为空则输出打印出元素 
        else 
        {
		    cout<<"核酸检测缓冲带内受检人员信息如下:\n";
        	 cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
             cout<<"|序号| \t"<<"检 测 编 号 "<<" | 姓 名 "<<" |"<<"\t公 民 身 份 证 号 "<<" | 类型 | "<<" 检 测 时 间\t|"<<"检测结果|\n";
             cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
		for(int i = 0; i < length;i ++)//第一个元素指向list 
        {
         if(Que->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Que->dataBase[i].testID<<" "<<" | "<<Que->dataBase[i].name<<" | "<<Que->dataBase[i].identification<<" | "<<testTypeTran(Que->dataBase[i].testType)<<" | "<<Que->dataBase[i].testTime<<" | "<<testStatusTran(Que->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Que->dataBase[i].testID<<" "<<" | "<<Que->dataBase[i].name<<" | "<<Que->dataBase[i].identification<<" | "<<testTypeTran(Que->dataBase[i].testType)<<" | "<<Que->dataBase[i].testTime<<" | "<<testStatusTran(Que->dataBase[i].testStatus)<<" |\n";
          }  
         }
        cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
        cout<<"| 数 据 总 数 :"<<length<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
		cout<<endl<<endl;
	    }
    }
    
//打印四支队列中的受检人员基本信息
    void coutWaitingQue(QList Q1,QList Q2,QList Q3,QList Q4){
        int index = 0;
        int length = (Q1->rear-Q1->front)+(Q2->rear-Q2->front)+(Q3->rear-Q3->front)+(Q4->rear-Q4->front); //队长
	    QNode *head;
        if(length == 0)//队列为空   
            cout<<"当前没有人员处于检测线上!"<<endl;
        //队列不为空则输出打印出元素 
        else 
        {
		    cout<<"核酸台检测线上受检人员信息如下:\n";
        	 cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
             cout<<"|序号| \t"<<"检 测 编 号 "<<" | 姓 名 "<<" |"<<"\t公 民 身 份 证 号 "<<" | 类型 | "<<" 检 测 时 间\t|"<<"检测结果|\n";
             cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
	    cout<<"| 检 测 线 一 上 :"<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
        for(int i = 0; i < (Q1->rear-Q1->front);i ++)//第一个元素指向list 
        {
         if(Q1->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Q1->dataBase[i].testID<<" "<<" | "<<Q1->dataBase[i].name<<" | "<<Q1->dataBase[i].identification<<" | "<<testTypeTran(Q1->dataBase[i].testType)<<" | "<<Q1->dataBase[i].testTime<<" | "<<testStatusTran(Q1->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Q1->dataBase[i].testID<<" "<<" | "<<Q1->dataBase[i].name<<" | "<<Q1->dataBase[i].identification<<" | "<<testTypeTran(Q1->dataBase[i].testType)<<" | "<<Q1->dataBase[i].testTime<<" | "<<testStatusTran(Q1->dataBase[i].testStatus)<<" |\n";
          }  
         }
           cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
        cout<<"| 检 测 线 二 上 :"<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
        for(int i = 0; i < (Q2->rear-Q2->front);i ++)//第一个元素指向list 
        {
         if(Q2->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Q2->dataBase[i].testID<<" "<<" | "<<Q2->dataBase[i].name<<" | "<<Q2->dataBase[i].identification<<" | "<<testTypeTran(Q2->dataBase[i].testType)<<" | "<<Q2->dataBase[i].testTime<<" | "<<testStatusTran(Q2->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Q2->dataBase[i].testID<<" "<<" | "<<Q2->dataBase[i].name<<" | "<<Q2->dataBase[i].identification<<" | "<<testTypeTran(Q2->dataBase[i].testType)<<" | "<<Q2->dataBase[i].testTime<<" | "<<testStatusTran(Q2->dataBase[i].testStatus)<<" |\n";
          }  
         }
           cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
        cout<<"| 检 测 线 三 上 :"<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
        for(int i = 0; i < (Q3->rear-Q3->front);i ++)//第一个元素指向list 
        {
         if(Q3->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Q3->dataBase[i].testID<<" "<<" | "<<Q3->dataBase[i].name<<" | "<<Q3->dataBase[i].identification<<" | "<<testTypeTran(Q3->dataBase[i].testType)<<" | "<<Q3->dataBase[i].testTime<<" | "<<testStatusTran(Q3->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Q3->dataBase[i].testID<<" "<<" | "<<Q3->dataBase[i].name<<" | "<<Q3->dataBase[i].identification<<" | "<<testTypeTran(Q3->dataBase[i].testType)<<" | "<<Q3->dataBase[i].testTime<<" | "<<testStatusTran(Q3->dataBase[i].testStatus)<<" |\n";
          }  
         }
         cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
        cout<<"| 检 测 线 四 上 :"<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
        for(int i = 0; i < (Q4->rear-Q4->front);i ++)//第一个元素指向list 
        {
         if(Q4->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Q4->dataBase[i].testID<<" "<<" | "<<Q4->dataBase[i].name<<" | "<<Q4->dataBase[i].identification<<" | "<<testTypeTran(Q4->dataBase[i].testType)<<" | "<<Q4->dataBase[i].testTime<<" | "<<testStatusTran(Q4->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Q4->dataBase[i].testID<<" "<<" | "<<Q4->dataBase[i].name<<" | "<<Q4->dataBase[i].identification<<" | "<<testTypeTran(Q4->dataBase[i].testType)<<" | "<<Q4->dataBase[i].testTime<<" | "<<testStatusTran(Q4->dataBase[i].testStatus)<<" |\n";
          }  
         }


        cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
        cout<<"| 数 据 总 数 :"<<length<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
		cout<<endl<<endl;
	    }
    }
    
//打印已完成检测的受检人员基本信息
    void coutTestedQue(QList Tested){
    int index = 0;
    int length = Tested->rear-Tested->front; //队长
	QNode *head;
        if(length == 0)//队列为空   
            cout<<"当前没有人员完成核酸检测!"<<endl;
        //队列不为空则输出打印出元素 
        else 
        {
		    cout<<"已完成核酸检测受检人员信息如下:\n";
        	 cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
             cout<<"|序号| \t"<<"检 测 编 号 "<<" | 姓 名 "<<" |"<<"\t公 民 身 份 证 号 "<<" | 类型 | "<<" 检 测 时 间\t|"<<"检测结果|\n";
             cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
		for(int i = 0; i < length;i ++)//第一个元素指向list 
        {
         if(Tested->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Tested->dataBase[i].testID<<" "<<" | "<<Tested->dataBase[i].name<<" | "<<Tested->dataBase[i].identification<<" | "<<testTypeTran(Tested->dataBase[i].testType)<<" | "<<Tested->dataBase[i].testTime<<" | "<<testStatusTran(Tested->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Tested->dataBase[i].testID<<" "<<" | "<<Tested->dataBase[i].name<<" | "<<Tested->dataBase[i].identification<<" | "<<testTypeTran(Tested->dataBase[i].testType)<<" | "<<Tested->dataBase[i].testTime<<" | "<<testStatusTran(Tested->dataBase[i].testStatus)<<" |\n";
          }  
         }
        cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
        cout<<"| 数 据 总 数 :"<<length<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
		cout<<endl<<endl;
	    }
    }

//打印查询的核酸检测核酸记录
      void coutQueryRes(QList Tested){
        cout<<Tested->dataBase[0].name;
        int index = 0;
        int length = Tested->rear-Tested->front; //队长
        QNode *head;
            if(length == 0)//队列为空   
                cout<<"该受检人员没有核酸检测历史记录!"<<endl;
            //队列不为空则输出打印出元素 
            else 
            {
		    cout<<"查询到受检人员的历史核酸信息如下:\n";
        	 cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
             cout<<"|序号| \t"<<"检 测 编 号 "<<" | 姓 名 "<<" |"<<"\t公 民 身 份 证 号 "<<" | 类型 | "<<" 检 测 时 间\t|"<<"检测结果|\n";
             cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
		for(int i = 0; i < length;i ++)//第一个元素指向list 
        {
         if(Tested->dataBase[i].name!="") {
            if(index<9)
             cout<<"| "<< ++index<<" "<<" | "<<" "<<Tested->dataBase[i].testID<<" "<<" | "<<Tested->dataBase[i].name<<" | "<<Tested->dataBase[i].identification<<" | "<<testTypeTran(Tested->dataBase[i].testType)<<" | "<<Tested->dataBase[i].testTime<<" | "<<testStatusTran(Tested->dataBase[i].testStatus)<<" |\n";
            else
             cout<<"| "<< ++index <<" | "<<" "<<Tested->dataBase[i].testID<<" "<<" | "<<Tested->dataBase[i].name<<" | "<<Tested->dataBase[i].identification<<" | "<<testTypeTran(Tested->dataBase[i].testType)<<" | "<<Tested->dataBase[i].testTime<<" | "<<testStatusTran(Tested->dataBase[i].testStatus)<<" |\n";
          }  
         }
        cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
        cout<<"| 数 据 总 数 :"<<length<<"\t\t\t\t\t\t\t\t\t |\n";
        cout<<"* ———————————————————————————————————————————————————————————————————————————————————————*\n";
		cout<<endl<<endl;
	    }
    }


//单人单管核酸检测入队
    void singleTest(QList Que,QList Q1,QList Q2,QList Q3,QList Q4){
        dataType item;
        dataType *p = new dataType;
        getHead(Que,p);
        item = *p;
        if(Q1->front == Q1->rear){
            cout<<"请走1号检测线"<<endl;
            item.testType = '1';
            item.testStatus = '1';
            PopQue(Que);
            PushQue(Q1,item);
        }
        else {
            if(Q2->front == Q2->rear){
            cout<<"请走2号检测线"<<endl;
             item.testType = '1';
            item.testStatus = '1';
            PopQue(Que);
            PushQue(Q2,item);
            }else {
                if(Q3->front == Q3->rear){
                     cout<<"请走3号检测线"<<endl;
                      item.testType = '1';
                    item.testStatus = '1';
                    PopQue(Que);
                    PushQue(Q3,item);
                    }else {
                            if(Q4->front == Q4->rear){
                            cout<<"请走4号检测线"<<endl;
                             item.testType = '1';
                            item.testStatus = '1';
                            PopQue(Que);
                            PushQue(Q4,item);
                            }
                            else{
                                cout<<"当前所有核酸检测线均占用!请等待!\n"<<endl;
                            }
                    }
                }
        }
    }
//十人混管核酸检测入队
    void multiTest(QList Que,QList Q1,QList Q2,QList Q3,QList Q4){
        
        if(Q1->front == Q1->rear){
            cout<<"请走1号检测线"<<endl;
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
            cout<<"请走2号检测线"<<endl;
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
                     cout<<"请走3号检测线"<<endl;
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
                            cout<<"请走4号检测线"<<endl;
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
                                cout<<"当前所有核酸检测线均占用!请等待!\n"<<endl;
                            }
                    }
                }
        }
        //取出队头元素 判断哪个分队列为空 为空则插入
    }

//检测完成从检测台离开一人
    void testOver(QList Q,QList Tested){
        dataType item;
        dataType *p = new dataType;
        getHead(Q,p);
        item = *p;
        item.testStatus = '2';
        PopQue(Q);
        PushQue(Tested,item);
    }

//封装一个查询函数复用代码
    string queryQueRes(QList Q,dataType item,int *index){
         int tmp = *index;
        while(Q->dataBase[tmp].identification != NULL && strcmp(Q->dataBase[tmp].identification,item.identification)!=0)
            {  
                tmp++;
            }
            //这里是参考web网络编程请求接口的写法 因为我自己是web前后端开发 比较习惯这种写法
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

//根据身份证号查询最新一条核酸状态
    QList queryTestRes(QList Pool,QList Q1,QList Q2,QList Q3,QList Q4,QList Tested)
    {   dataType item;
        QList p = (QList)malloc(sizeof(QList));
        loopQuery:cout<<"请输入查询受检人员的18位公民身份证号码:\n";
        cin>>item.identification;
        int len = 0;
            while(item.identification[len]!='\0')
                ++len;
            if(len == 18){
                int index = 0,list = 0;
                string res = queryQueRes(Pool,item,&index);
                if(res == "200"){
                    cout<<"查询数据库成功,该受检人员当前处于缓冲区内!\n"<<endl;
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
                    cout<<"查询数据库成功,该受检人员当前处于缓冲区内!\n";
                    cout<<"但核酸记录异常,数据为空!\n"<<endl;
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
                        cout<<"查询数据库成功,该受检人员当前处于检测线一上!\n"<<endl;
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
                        cout<<"查询数据库成功,该受检人员当前处于检测线一上!\n";
                        cout<<"但核酸记录异常,数据为空!\n"<<endl;
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
                            cout<<"查询数据库成功,该受检人员当前处于检测线二上!\n"<<endl;
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
                                cout<<"查询数据库成功,该受检人员当前处于检测线二上!\n";
                                cout<<"但核酸记录异常,数据为空!\n"<<endl;
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
                                            cout<<"查询数据库成功,该受检人员当前处于检测线三上!\n"<<endl;
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
                                            cout<<"查询数据库成功,该受检人员当前处于检测线三上!\n";
                                            cout<<"但核酸记录异常,数据为空!\n"<<endl;
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
                                                    cout<<"查询数据库成功,该受检人员当前处于检测线四上!\n"<<endl;
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
                                                    cout<<"查询数据库成功,该受检人员当前处于检测线四上!\n";
                                                    cout<<"但核酸记录异常,数据为空!\n"<<endl;
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
                                                                    cout<<"查询数据库成功,该受检人员已完成核酸检测离开!\n"<<endl;
                                                                   strcpy(p->dataBase[list].testID,Tested->dataBase[index].testID);
                                                                    strcpy(p->dataBase[list].identification,Tested->dataBase[index].identification);
                                                                    strcpy(p->dataBase[list].name,Tested->dataBase[index].name);
                                                                    strcpy(p->dataBase[list].testTime,Tested->dataBase[index].testTime);
                                                                    p->dataBase[list].testType = Tested->dataBase[index].testType;
                                                                    p->dataBase[list].testStatus = Tested->dataBase[index].testStatus;
                                                                }
                                                                else if(res == "404"){
                                                                    cout<<"查询数据库成功,该受检人员已完成核酸检测离开!\n";
                                                                    cout<<"但核酸记录异常,数据为空!\n"<<endl;
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
                cout<<"您输入的身份证号码非法,重新输入请按\"Y\"键,或按任意键退出!\n"<<endl;
                char cmd;
                cin>>cmd;
                if(cmd == 'Y')
                    goto loopQuery;
            }      
    }


//操作菜单面板封装  
    char menu(char handle){
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"|**------基于顺序存储结构的核酸检测队列管理程序设计------**|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"|**---------------------系统操作菜单---------------------**|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"|**\t \t \t \t \t \t \t **|"<<"\n"; 
    cout<<"|**\t \t 【0】参检人员批量导入 \t \t \t **|"<<"\n"; 
    cout<<"|**\t \t 【1】十人一管核酸混检 \t \t \t **|"<<"\n"; 
    cout<<"|**\t \t 【2】单人单管核酸检测 \t \t \t **|"<<"\n"; 
    cout<<"|**\t \t 【3】一号台检测完一名 \t \t \t **|"<<"\n";
    cout<<"|**\t \t 【4】二号台检测完一名 \t \t \t **|"<<"\n";
    cout<<"|**\t \t 【5】三号台检测完一名 \t \t \t **|"<<"\n";
    cout<<"|**\t \t 【6】四号台检测完一名 \t \t \t **|"<<"\n";
    cout<<"|**\t \t 【7】按身份证号查询受检人员核酸状态  \t **|"<<"\n";
    cout<<"|**\t \t 【8】按身份证号修改受检人员基本信息  \t **|"<<"\n"; 
    cout<<"|**\t \t 【9】当前已做核酸所有人员信息 \t \t **|"<<"\n";
    cout<<"|**\t \t 【10】当前未做核酸所有人员信息\t \t **|"<<"\n";  
    cout<<"|**\t \t 【11】清空数据库 \t \t \t **|"<<"\n"; 
    cout<<"|**\t \t 【12】关闭数据库 \t \t \t **|"<<"\n"; 
     cout<<"|**\t \t \t \t \t \t \t **|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"请输入操作指令,默认为【0】:"<<"\n"<<endl; 
    cin>>handle;
    return handle;
    }
    int main(){
        dataListType handle;
        // 核酸采取四检测通道以二级缓冲排队进行;
        QNode waitingPool,Que1,Que2,Que3,Que4,testedPool;
        cout<<"数据库队列初始化!"<<endl;   //初始化顺序队列
        initial(&waitingPool,&Que1,&Que2,&Que3,&Que4,&testedPool);
        cout<<"数据库已启动!"<<endl;   //初始化队列成功
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
                else cout<<"查无此身份证号码对应的核酸记录";
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
                 cout<<"重置数据库成功!"<<endl;   //初始化队列成功
                goto loop;
            }
            case '12':{
                 cout<<"程序终止"<<endl;
                 break;
            }
            default:{
                 cout<<"输入指令有误！请重新输入！"<<endl;
                 goto loop;
            }
        }
    }