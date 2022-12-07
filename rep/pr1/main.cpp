#include<iostream>
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


//数据打印输出函数
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

// 2021212961 林培灿 13364063027
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