#include<iostream>
#define N 3
#define maxContain 256
    using namespace std;
    typedef struct sortedList{
        char stuNum[12];
        char stuName[20];
        int stuPhone[14];
    }sortList; //�������ݿ��нṹ ��¼�������ֶ����ڴ洢��Ϣ
    typedef struct dataList{
        sortList db[maxContain];
        int length;
    }dataBase; //�������ݿ�ṹ

   void SortListInput(sortList* obj,sortList *end,int n){
        if(n < (maxContain/sizeof(obj))){
                char c = 'y';
                while(c=='y'){
                    n --;
                    printf("������ѧ��\n");
                    scanf("%d", &obj[n - 1].stuNum, 250);
                    printf("����������\n");
                    scanf("%s", &obj[n - 1].stuName, 250);
                    printf("�������ֻ���\n");
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