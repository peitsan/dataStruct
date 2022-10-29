#include<iostream>
#define N 3
#define maxContain 256
    using namespace std;
    typedef struct sortedList{
        char stuNum[12];
        char stuName[20];
        int stuPhone[14];
    }sortList; //定义数据库行结构 记录下三个字段用于存储信息
    typedef struct dataList{
        sortList db[maxContain];
        int length;
    }dataBase; //定义数据库结构

   void SortListInput(sortList* obj,sortList *end,int n){
        if(n < (maxContain/sizeof(obj))){
                char c = 'y';
                while(c=='y'){
                    n --;
                    printf("请输入学号\n");
                    scanf("%d", &obj[n - 1].stuNum, 250);
                    printf("请输入姓名\n");
                    scanf("%s", &obj[n - 1].stuName, 250);
                    printf("请输入手机号\n");
                    scanf("%s", &obj[n - 1].stuPhone, 250);
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
void SortListPrint(sortedList* obj,int n){
    for(int i = 0; i < n; i++){
        cout<<obj->stuNum<<" "<<obj->stuName<<" "<<obj->stuPhone;
    }
}
int main(){
    sortedList msxb[N];
    sortedList *end=msxb,*tmp;
    int n;
    cout<<"Please Input Input Times:\n";
    cin>>n;
    SortListInput(msxb,end,n);
    SortListPrint(msxb,n);
}