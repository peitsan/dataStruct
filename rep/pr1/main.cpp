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
    //更新数据库链表表长
    int getlen(linkList list){
        int count = 0;
        linkList p = list;
        while(p!=NULL)
        {	
            count++;//计数器累加 
            p = p->next; //指针p指向下一个链结点 
        }
        return count;
    }

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
		for(head=list->next;head!=NULL;head=head->next)//第一个元素指向list 
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
    
    void linkListPop(linkList* pphead)
    {
        if (*pphead == NULL)
        {
            return;
        }
        else if ((*pphead)->next == NULL)
        {
            free(*pphead); //把pList指向的那块内存空间释放
            *pphead = NULL;//把pList指针置为空
        }
        else
        {
            linkList tail = *pphead; //尾删 需要知道尾和尾前的结构体(置为空)
            linkList prev = NULL;
            while (tail->next != NULL)
            {
                prev = tail;   //小跟班指针
                tail = tail->next;
            }
            free(tail);
            prev->next = NULL;
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
            p->next = NULL;
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
        while(p->next!=NULL)
		p = p->next;//找到链表末尾结点的地址               
        cout<<"请输入导入学生信息条数n:";
        cin>>n;
        cout<<"请输入这n条学生信息(格式:\"学号 姓名 手机号\"):\n";                        
        while(n--)
        {
            q=(Node*)malloc(sizeof(Node));
            cin>>q->dataBase.stuNum>>q->dataBase.stuName>>q->dataBase.stuPhone; //按顺序输入学生信息列表
            length += 1;
            q->next = NULL;
            p->next = q;
            p = q;
        } 
        return list;
    } 

//根据定位在数据库中插入子节点链表 
      linkList insertNode(linkList list,int x,dataType item)
        {
            linkList p,q = list;
            int j=1;
            while(j<x&&q!=NULL)
            {
                q = q ->next;
                j++; 
            }//寻找第i个链结点
            if(j!=x||q==NULL)
                printf("链表中不存在第i个链结点");
            p = (linkList)malloc(sizeof(linkList));//申请一个新的链结点
            p ->dataBase = item;//将item送新结点的数据域
            p ->next = q ->next;
            q ->next = p;//将新结点插入第i个链结点之后
            return p;
        }


//根据学生的学号定位在数据库中的序号和数据
    dataType findIndexByStuNum(linkList list)
    {   dataType item;
        Node *p = list;
        int place = 0;
        cout<<"请输入查询学生对象的学号:\n";
        cin>>item.stuNum;
            while(p->next !=NULL && strcmp(p->dataBase.stuNum,item.stuNum)!=0)
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
            else cout<<"没有查询到学号为:"<<item.stuNum<<"的学生信息!\n"<<endl;
          
    }
    
//根据学生的学号更新其数据
    linkList updateByStuNum(linkList list)
    {   dataType item;
        linkList p = list,q,head = list;
        int place = 0, index = getlen(list);;
        cout<<"请输入修改学生对象的学号:\n";
        cin>>item.stuNum;
            while(p->next !=NULL && strcmp(p->dataBase.stuNum,item.stuNum)!=0)
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
                while(index>place && head->next!=NULL)
                {
                    linkListPop(&head);
                    index--; 
                }
                head->next = q;
                return q;
                }

            else {
               cout<<"没有查询到学号为:"<<item.stuNum<<"的学生信息!\n"<<endl;
               return list;
            }
          
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
        dataListType n,i,handle;  
	    dataType item; 
	    cout<<"数据库链表初始化!"<<endl;   //初始化循环链表
	    list = initial();  
        cout<<"创建数据库!"<<endl;     //首次启动需要进行数据导入
        list = (Node*)malloc(sizeof(Node)); 
        list->next = NULL;
        list->dataBase = item; 
	    cout<<"数据库已启动,请按照菜单进行数据操作!"<<endl;     //首次启动需要进行数据导入
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