#include<iostream>
#define N 10
#define maxContain 256
    using namespace std;
    typedef struct sortedList{
        char stuNum[12];
        char stuName[20];
        char stuPhone[14];
    }sortList; //�������ݿ��нṹ ��¼�������ֶ����ڴ洢��Ϣ
   static int Length = 0;
    void SortListPrint(sortList obj[N],sortList *end,sortList *temp){
    temp = end;
    for(end=obj;end!=temp;end++){
            printf("%s %s %s \n",end->stuNum,end->stuName,end->stuPhone);
        }
    }
   void SortListInput(sortList obj[N],sortList *end,sortList *temp){
                int n;
                char c = 'y';
                while(c=='y'){
                     cout<<"������ѧ������:\n";
                     cin>>n;
                     Length += n;
                     if((end-obj+n)<=N){
                            while(n>0){
                                cout<<"������ѧ�š��������ֻ���(�м��ÿո����):\n";
                                scanf("%s %s %s",end->stuNum,end->stuName,end->stuPhone);
                                end++;
                                n--;
                                }
		                }    
                    SortListPrint(obj,end,temp);
			        fflush(stdin);
                    cout<<"�Ƿ����ִ��(��������y):\n";
			        cin>>c;
		}
		       
 }
   
int main(){
    sortedList msxb[N];
    sortedList *end=msxb,*tmp;
    SortListInput(msxb,end,tmp);
	return 0;
}
