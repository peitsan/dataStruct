#include<iostream>
#include<string.h>
    using namespace std;
//数据可移植化
    typedef char dataListType;
//数据库字段定义
    typedef struct dataType{
        dataListType stuNum[11];
        dataListType stuName[7];
        dataListType stuPhone[12];
    }dataType;
//数据库循环链表节点定义
    typedef struct Node{
        dataType dataBase;
        struct Node *next;
    }Node,*linkList;
    int length;
//定义循环链表的头节点 作为循环链表的标志位
    Node *h;
    
//手动更新数据库链表表长
     int getlen(linkList list){
        int count = 0;
        linkList p = list;
        while(p!=list)
        {	
            count++;//计数器累加 
            p = p->next; //指针p指向下一个链结点 
        }
        return count;
    }

     bool checkDuplication(dataType item,linkList list){
        Node *head;
         for(head=list->next;head!=h;head=head->next)//第一个元素指向list 
        {
         if(strcmp(head->dataBase.stuNum,item.stuNum)== 0) {
           return true;
          } 
        }
         return false;
    }
//数据库遍历打印
     void coutlist(linkList list){
    int index = 0;
	Node *head;
	if(length == 0)//链表为空   
		cout<<"学生信息数据库为空!"<<endl;
	//链表不为空则输出打印出元素 
	else 
	{
		cout<<"学生信息如下(学号/姓名/手机号):\n";
        	cout<<"* ————————————————————————————————————— *\n";
             cout<<"|序号| \t "<<"学 号\t "<<"| 姓 名 "<<" | "<<" 手 机 号\t|\n";
             cout<<"* ————————————————————————————————————— *\n";
		for(head=list->next;head!=h;head=head->next)//第一个元素指向list 
        {
         if(head->dataBase.stuPhone!="") {
            cout<<"| "<< ++index<<" "<<" | "<<head->dataBase.stuNum<<"| "<<head->dataBase.stuName<<" | "<<head->dataBase.stuPhone<<" |\n";
          } 
         }
         
        cout<<"* ————————————————————————————————————— *\n";
          cout<<"| 总数据数:"<<length<<"\t\t\t\t|\n";
        cout<<"* ————————————————————————————————————— *\n";
		cout<<endl<<endl;
	}
}
       
//数据库初始化(循环链表初始化)
     linkList initial() //初始化头结点
    {
        Node *p;
        p = (Node*)malloc(sizeof(Node)); //申请头结点空间
        if(p == NULL)
            cout<<"申请内存空间失败!"<<endl;
        else
        {
            p->next = p;
            length = 0;
            cout<<"初始化成功!"<<endl; 
        }
        return p;
    }

//数据输入(循环链表多值节点输入)
     linkList inputDataList(linkList list)
    {  
        Node *p,*q;
        p = list;   
        int n;
        while(p!=list)
		p = p->next;//找到链表标志位结点的地址               
        cout<<"请输入待导入学生信息条数n:";
        cin>>n;
        int i = 0,tmp[n];
        cout<<"请输入这n条学生信息(格式:\"学号 姓名 手机号\"):\n";                        
        while(n--)
        {   
            q=(Node*)malloc(sizeof(Node));
            cin>>q->dataBase.stuNum>>q->dataBase.stuName>>q->dataBase.stuPhone; //按顺序输入学生信息列表
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
             cout<<"第"<<i+1<<"条数据已经在数据库中重复,禁止输入!\n"<<endl;
        return list;
}

//根据定位在数据库中插入子节点链表 
     linkList insertNode(linkList list,int x,dataType item)
        {
            linkList p,q = list;
            int j=1;
            while(j<x&&q!=h)
            {
                q = q ->next;
                j++; 
            }//寻找第i个链结点
            if(j!=x||q==h)
                cout<<"链表中不存在第i个链结点"<<endl;
            p = (linkList)malloc(sizeof(linkList));//申请一个新的链结点
            p ->dataBase = item;//将item送新结点的数据域
            p ->next = q ->next;
            q ->next = p;//将新结点插入第i个链结点之后
            length += 1;
         return q;
        }

//根据学生的学号定位在数据库中的序号和数据
    dataType findIndexByStuNum(linkList list)
    {   dataType item;
        Node *p = list;
        int place = 0;
        cout<<"请输入查询学生对象的学号:\n";
        cin>>item.stuNum;
            while(p->next !=h && strcmp(p->dataBase.stuNum,item.stuNum)!=0)
            {  
                place++;
                p = p->next;
            }
             if(strcmp(p->dataBase.stuNum,item.stuNum)==0){
                 cout<<"学号为:"<<item.stuNum<<"的学生序号为:#"<<place<<"\n";
                cout<<"* ————————————————————————————————————— *\n";
                cout<<"|序号| \t "<<"学 号\t "<<"| 姓 名 "<<" | "<<" 手 机 号\t|\n";
                cout<<"* ————————————————————————————————————— *\n";
                cout<<"| "<< place <<" "<<" | "<<p->dataBase.stuNum<<"| "<<p->dataBase.stuName<<" | "<<p->dataBase.stuPhone<<" |\n";
                cout<<"* ————————————————————————————————————— *\n"<<endl;
                return p->dataBase;
                }
            else {
                cout<<"没有查询到学号为:"<<item.stuNum<<"的学生信息!\n"<<endl;
                return list->dataBase;
            }
    }

//根据定位插入数据操作程序
     void insertBySort(linkList list){
    int x;
    loopInsert:cout<<"请输入插入数据的目标位置序号:\n";
    cin>>x;
    char cmd;
    if(typeid(x) != typeid(int)){
        cout<<"输入数据非法! 重新输入请按\"Y\"键,结束按任意键!\n"<<endl;
        cin>>cmd;
        if(cmd == 'Y') goto loopInsert;
    }
    else if(x>length){
        cout<<"数据库在该位置没有相应数据,不能超过数据库长度!\n";
        cout<<"输入数据非法! 重新输入请按\"Y\"键,退出指令按任意键!\n"<<endl;
         cin>>cmd;
        if(cmd == 'Y') goto loopInsert;
    }
    else{
        dataType item;
          loopInsertInput:cout<<"请按格式输入待插入的学生信息(格式:\"学号 姓名 手机号\"):\n"<<endl; 
          cin>>item.stuNum>>item.stuName>>item.stuPhone; //按顺序输入学生信息列表
          if(!checkDuplication(item,list)){
             insertNode(list,x,item);
             coutlist(list);
          }
          else {
            cout<<"输入的学生信息已在数据库中重复!\n"; 
            cmd = ' ';
            cout<<"重新输入请按\"Y\"键,退出指令按任意键!\n"<<endl;
            cin >> cmd;
            if(cmd == 'Y') goto loopInsertInput;
          }
    }   
}

//根据序号字段删除数据库中的指定链表节点
     void deleteBySort(linkList list){
        int index;
        linkList p = list;
        loopDelBySort:cout<<"请输入删除目标的序号\n";
        cin>>index;
        if(p != h){
            if(typeid(index)!=typeid(int)||index>length||index<0){
                cout<<"输入学生序号非法!重新输入请按\"Y\",结束按任意键!\n"<<endl;
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
            cout<<"数据库为空,向下溢出!\n"<<endl;
        }
    }

//根据学号字段删除数据库中的指定链表节点
     void deleteByStuNum(linkList list){
        dataListType stuNum[11];
        linkList p = list;
        loopdeleteByStuNum:cout<<"请输入删除目标的学号\n";
        cin>>stuNum;
        if(p != h){
            int i= 0,place= 0;
            while(stuNum[i]!= '\0'){
                i ++;
            };
            if(i!=10){
                cout<<"输入学生学号非法!重新输入请按\"Y\",结束按任意键!\n"<<endl;
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
            cout<<"数据库为空,向下溢出!\n"<<endl;
        }
    }

//删除指定数据操作面板
     void deletePanel(linkList list){
    dataType item;
    char cmd;
    loopDelete:char x;
     cout<<"|**********************************************************|"<<"\n"; 
     cout<<"|**----------------------操 作 菜 单---------------------**|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"|**\t \t \t \t \t \t \t **|"<<"\n"; 
     cout<<"|**\t \t 【0】按照序号删除学生信息 \t \t **|"<<"\n"; 
      cout<<"|**\t \t 【1】按照学号删除学生信息 \t \t **|"<<"\n"; 
     cout<<"|**\t \t \t \t \t \t \t **|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"请输入删除指令:\n";
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
               cout<<"输入指令非法! 重新输入请按\"Y\"键,退出指令按任意键!\n"<<endl;
                cin>>cmd;
                if(cmd == 'Y') goto loopDelete;     
            }  
        }
}

//根据学生的学号更新其数据
     void updateByStuNum(linkList list)
    {   dataType item;
        linkList p = list,q,head = list;
        int place = 0, index = getlen(list);
        cout<<"请输入修改学生对象的学号:\n";
        cin>>item.stuNum;
            while(p->next !=h && strcmp(p->dataBase.stuNum,item.stuNum)!=0)
            {  
                place++;
                p = p->next;
            }
             if(strcmp(p->dataBase.stuNum,item.stuNum)==0){
                cout<<"学号为:"<<item.stuNum<<"的学生序号为:#"<<place<<"\n";
                cout<<"请依次输入更新后的姓名与手机号（格式:\"姓名 手机号\"）:"<<"\n"; //有bug
                q=(Node*)malloc(sizeof(Node));
                cin>>q->dataBase.stuName>>q->dataBase.stuPhone;
                strcpy(q->dataBase.stuNum,item.stuNum);
                q->next = p->next;
                p->dataBase = q->dataBase;
                }
            else {
               cout<<"没有查询到学号为:"<<item.stuNum<<"的学生信息!\n"<<endl;
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
    cout<<"|**------------基于循环链表的学生名册管理系统------------**|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"|**---------------------系统操作菜单---------------------**|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"|**\t \t \t \t \t \t \t **|"<<"\n"; 
     cout<<"|**\t \t 【0】学生信息批量导入 \t \t \t **|"<<"\n"; 
      cout<<"|**\t \t 【1】指定位置键入学生信息 \t \t **|"<<"\n"; 
       cout<<"|**\t \t 【2】删除指定学生信息数据 \t \t **|"<<"\n"; 
        cout<<"|**\t \t 【3】按学号查询学生基本信息 \t \t **|"<<"\n"; 
        cout<<"|**\t \t 【4】按学号修改学生基本信息 \t \t **|"<<"\n"; 
         cout<<"|**\t \t 【5】当前数据库所有学生信息 \t \t **|"<<"\n"; 
         cout<<"|**\t \t 【6】清空数据库 \t \t \t **|"<<"\n"; 
         cout<<"|**\t \t 【7】关闭数据库 \t \t \t **|"<<"\n"; 
     cout<<"|**\t \t \t \t \t \t \t **|"<<"\n"; 
    cout<<"|**********************************************************|"<<"\n"; 
    cout<<"请输入操作指令,默认为【0】:"<<"\n"<<endl; 
    cin>>handle;
    return handle;
    }

    int main(){
        linkList list;
        dataListType handle = 0;  
	    dataType item; 
	    cout<<"数据库链表初始化!"<<endl;   //初始化循环链表
	    list = initial();  
        cout<<"创建数据库!"<<endl;     //首次启动需要进行数据导入
        list->next = h;
        list->dataBase = item; 
	    cout<<"数据库已启动,请按照菜单进行数据操作!"<<endl;     //首次启动需要进行数据导入
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
                    cout<<"程序终止"<<endl;
                    break;
                }
                default :{
                    cout<<"输入指令有误！请重新输入！"<<endl;
                    goto loop;
                }
            }   
        return 0;
    }   