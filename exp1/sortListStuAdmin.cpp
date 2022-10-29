#include<iostream>
#define N 3
#define maxContain 256
int maxRow =maxContain / sizeof(sortedList);

    using namespace std;
    typedef struct sortedList{
        char stuNum[12];
        char stuName[20];
        int stuPhone[14];
    }sortList; //定义数据库行结构 记录下三个字段用于存储信息

    typedef struct sortedList{
        sortList db[maxContain];
        int length;
    }dataBase; //定义数据库结构


    void SortListInput(dataBase* &,sortedList *end,int n){
        int t;
        L = length
        if(n < (maxContain/sizeof(obj))){
                char c = 'y';
                while(c=='y'){
                    t++;
                    printf("请输入学号\n");
                    scanf("%d", &L->obj[n - 1].stuNum, 250);
                    printf("请输入姓名\n");
                    scanf("%s", &L->obj[n - 1].stuName, 250);
                    printf("请输入手机号\n");
                    scanf("%s", &L->obj[n - 1].stuPhone, 250);
                    end ++;
                    if(!n){
                       fflush(stdin);   
                        c = 'n';
                    }
            }
        }
        else{
              cout<<"Input List Times Oversize!";
            }   
        
    }

    void SortListFind(sortedList* &obj){
        
    }

    void SortListDelete(sortedList* &obj,int n,int sel){
        
    }

    void SortListDisplay(sortedList* &obj){

    }
    void SortListDestroy(sortedList* &obj){

    }
    void SortListInitial(sortedList* &obj){
        obj = (sortedList*)malloc(sizeof(obj));//动态开辟一个单位为结构体所占长度的内存区  进行初始化
        obj->length = 0;   //将数据库清空且标记长为0
    }

int main(){
    dataBase* Data;
    sortedList msxb[N];
    sortedList *end=msxb,*tmp;
    int n;
    cout<<"请输入录入数据条数:";
    cin>>n;
    SortListInitial(Data);
    SortListInput(Data,end,n);
    cout<<msxb<<endl;
}