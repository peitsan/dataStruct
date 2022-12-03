#include<iostream>
#include<string.h>
#include<malloc.h>
    using namespace std;
    typedef char dataListType;
    typedef struct dataType{
        dataListType stuNum[10];
        dataListType stuName[10];
        dataListType stuPhone[11];
    }dataType;

    typedef struct Node{
        dataType dataBase;
        struct Node *next;
    }Node,*linkList;

    linkList initial() //初始化头结点
    {
        Node *p;
        p = (Node*)malloc(sizeof(Node)); //申请头结点空间
        if(p == NULL)
            cout<<"申请内存空间失败!"<<endl;
        else
        {
            p->next = NULL;
            cout<<"初始化成功!"<<endl; 
        }
    }

    linkList inputDataList(linkList list)
    {
        Node *p,*q;
        p = list;   
        int n;                       	  
        dataType tmp;
        cout<<"输入长度:";
        cin>>n;
        cout<<"输入元素:";                        
        while(n--)
        {
            q=(Node*)malloc(sizeof(Node));
            scanf("%d",&q->dataBase);
            q->next = NULL;
            p->next = q;
            p = q;
        } 
        return list;
    } 