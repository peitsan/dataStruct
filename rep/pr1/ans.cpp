#include<iostream>
#include<malloc.h>
using namespace std;
typedef int elemtype; //定义结点类型 
 
//定义一个线性链表的类型
typedef struct node
{
	elemtype data; //数据域
	struct node *next; //指针域 
}node,*linklist;
 
//初始化链表 
linklist initlist()
{
	node *p;
	p = (node*)malloc(sizeof(node));
	if(p == NULL)
		cout<<"申请内存空间失败!"<<endl<<endl;
	else
	{
		p->next = NULL;
		cout<<"初始化成功!"<<endl<<endl; 
	}
}
 
//知晓长度创建链表
linklist creat(linklist list)
{
	node *p,*q;
    p = list;                          	  
	elemtype a,n; 
	cout<<"输入长度:";
	cin>>n;
	cout<<"输入元素:";                        
    while(n--)
    {
    	q=(node*)malloc(sizeof(node));
        scanf("%d",&q->data);
        q->next = NULL;
        p->next = q;
        p = q;
    } 
    return list;
} 
 
//不知晓长度创建链表
linklist creat1(linklist list)
{
	node *p,*q;
    p = list;                          	  
	elemtype a; 
	//以0为结束的标记 
	cout<<"输入元素:";                        
    while(cin>>a)
    {
    	if(a == 0)
    		break;
    	q=(node*)malloc(sizeof(node));
        q->data = a;
        q->next = NULL;
        p->next = q;
        p = q;
    } 
    return list;
} 
//求线性链表的长度
int length1(linklist list)
{
	linklist p = list;
	int n = 0;
	while(p!=NULL)
	{	
		n++;//计数器累加 
		p = p->next; //指针p指向下一个链结点 
	}
	return n;//返回链表的长度 
} 
 
//求线性链表的长度(递归)
int length2(linklist list)
{
	if(list!=NULL)
		return 1+length2(list->next);
	else
		return 0; 
} 
 
//确定元素item在线性链表中的位置
linklist find(linklist list,elemtype item)
{
	linklist p = list;
	int place = 1;
	while(p !=NULL && p->data != item)
	{
		place++;
		p = p->next;
	}
	if(p !=NULL && p->data == item)
		cout<<"item的位置为:"<<place<<endl;
	else
		cout<<"item不存在!"<<endl;
}
 
//非空线性链表的末尾插入一个数据信息为item的链接点
void insert1(linklist list,elemtype item)
{
	//list存放链表的首地址
	linklist p,r;
	r = list;
	while(r->next!=NULL)
		r = r->next;//找到链表末尾结点的地址 
	p = (linklist)malloc(sizeof(node));//申请一个新的链接点
	p ->data = item;//将item送新结点的数据域
	p ->next = NULL;//新结点的指针域置为NULL 
	r ->next =p;//插入链表的末尾 
}
 
 
//在线性链表中的第i个链结点后面插入一个数据信息为item的链接点
void insert2(linklist list,int i,elemtype item)
{
	linklist p,q = list;
	int j=1;
	while(j<i&&q!=NULL)
	{
		q = q ->next;
		j++; 
	}//寻找第i个链结点
	if(j!=i||q==NULL)
		printf("链表中不存在第i个链结点");
	p = (linklist)malloc(sizeof(node));//申请一个新的链结点
	p ->data = item;//将item送新结点的数据域
	p ->next = q ->next;
	q ->next = p;//将新结点插入第i个链结点之后
}
 
//在按值有序链接的线性链表中插入一个数据信息为item的链结点
linklist insert3(linklist &list,elemtype item)
{
	linklist p,q,r;
	p = (linklist)malloc(sizeof(node));
	p ->data = item;
	if(list==NULL||item<list->data)//若链表为空或者item小于第1个链结点 
	{
		p ->next = list;//将新的链结点插在链表最前面 
		list = p;//list指向被插入的新结点 
	}	
	else
	{
		q = list;
		while(q!=NULL&&item>=q->data)//寻找插入位置 
		{
			r = q;
			q = q->next;
		}
		p->next = q;
		r->next = p;//将新的链结点插在q指示的链结点后面 
	} 
	return list;
}
 
//逆转一个线性链表
void invert(linklist &list)
{
	linklist p,q,r;
	p = list;
	q = NULL;
	while(p!=NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	list = q;
} 
 
node* getelem(linklist list,int k)
{
    node* s=list;
    while(k)
    {
        s=s->next;
        k--;
    }
    return s;
}
 
void deletelist3(linklist list,int k)
{
    node* p=list;
    node* q=NULL;
    p=getelem(list,k-1);
    q=p->next;
    p->next=q->next;
    free(q);
 
}
 
//销毁一个线性链表
void deletelist(linklist &list)
{
	linklist p = list;
	while(p!=NULL)
	{
		list = p->next;//保存下一个链结点的位置
		free(p);//删除并释放当前的链结点
		p = list;//下一个链结点成为当前链结点
	}
} 
 
//打印链表元素,遍历链表 
void printinfo(linklist list)
{
	node *head;
	if(head == NULL)//链表为空   
		cout<<"链表为空!"<<endl;
	//链表不为空则输出打印出元素 
	else 
	{
		cout<<"链表元素为:";
		for(head=list;head!=NULL;head=head->next)//第一个元素指向list  
			cout<<head->data<<" ";
		cout<<endl<<endl;
	}
}
 
int main()
{
	linklist list;
	elemtype n,item,i;
	
	//初始化链表
	cout<<"初始化链表!"<<endl; 
	list = initlist();
	
	//创建头结点
	list = (node*)malloc(sizeof(node));
    list->next = NULL;
    list->data = -1; 
	
	//创建链表(知晓长度) 
	cout<<"创建链表!"<<endl;
	list = creat(list); 
	printinfo(list);
	
	//创建链表(不知晓长度) 
	cout<<"创建链表,以0为结束标志!"<<endl; 
	list = creat1(list); 
	printinfo(list);
	
	//求链表的长度
	cout<<"链表的长度!"<<endl<<"链表长度为:"<<length1(list)<<endl;
	
	//求链表的长度
	cout<<"链表的长度!"<<endl<<"链表长度为:"<<length2(list)<<endl;
	
	//确定元素item在线性链表中的位置
	cout<<endl<<"元素item的位置!"<<endl;
	cout<<"输入元素item:";
	cin>>item; 
	find(list,item); 
	
	//非空线性链表的末尾插入一个数据信息为item的链接点	
	cout<<endl<<"末尾插入item结点!"<<endl;
	cout<<"输入元素item:";
	cin>>item; 
	insert1(list,item); 
	printinfo(list); 
	
	//在线性链表中的第i个链结点后面插入一个数据信息为item的链接点
	cout<<endl<<"第i个链结点后面插入item!"<<endl;
	cout<<"输入结点i:";
	cin>>i; 
	cout<<"输入元素item:";
	cin>>item; 
	insert2(list,i,item);
	printinfo(list);
	
	//在按值有序链接的线性链表中插入一个数据信息为item的链结点
	cout<<endl<<"按值有序在链表中插入item!"<<endl;
	cout<<"输入元素item:";
	cin>>item; 
	insert3(list,item);
	printinfo(list);
	
	//逆转一个线性链表
	cout<<endl<<"逆序链表!"<<endl; 
	invert(list);
	printinfo(list);
	invert(list);
	printinfo(list);
	
	//删除第i个结点
	cout<<endl<<"删除第i个结点!"<<endl; 
	cout<<"输入结点i:";
	cin>>i; 
	deletelist3(list,i);
	printinfo(list); 
	
	//销毁一个线性链表
	cout<<endl<<"销毁链表!"<<endl; 
	deletelist(list);
	printinfo(list);
	return 0;
}