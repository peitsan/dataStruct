#include<iostream>
#define N 10
#define maxContain 256
    using namespace std;
    typedef struct sortedList{
        char stuNum[12];
        char stuName[20];
        char stuPhone[14];
    }sortList; //�������ݿ��нṹ ��¼�������ֶ����ڴ洢��Ϣ

   void SortListDel(sortList* obj,sortList *end,sortList *temp,int length){
        char d = 'y';
        int target;
        while(d = 'y'){
            if(obj == end){
                cout<<"˳���Ϊ��!"<<endl;
                break;
            }
            else{
                cout<<"����ɾ��Ԫ�ص�λ����:\n";
                cin>>target;
                if(0<target<=N){
                    for(end = obj; end<temp; end++){
                        	if(end-obj==target){
								for(int i=target;i<length;i++){
									obj[i-1]=obj[i];
								}
							}
                            temp -= 1;
                            if(obj == end){
						    cout<<"˳��������\n";
						    break;
					        }
					        cout<<"ɾ��Ԫ�غ��˳���\n";
					        for(end = obj;end < temp;end++){
					        	printf("%s %s %s\n",end->stuNum,end->stuName,end->stuPhone);
					        }
                    }
                    cout<<"�Ƿ����ɾ��(������'y'):\n";
                    cin>>d;
                }
                else{
                cout<<"˳�����û�и�Ԫ��(�ṹ�����):"<<endl;    
                }
            }
        }

 }
  
    void SortListPrint(sortList* obj,sortList *end,sortList *temp){
    temp = end;
    for(end=obj;end!=temp;end++){
            printf("%s%s%s",end->stuNum,end->stuName,end->stuPhone);
        }
    }
int main(){
    sortedList msxb[N]={{"2021212961","�����","18025597877"},
                        {"2021212961","�����","13364063027"},
                        {"2021212961","�����","15816750104"}};
    sortedList *end=msxb,*tmp=msxb;
    int Len = 3;
    SortListDel(msxb,end,tmp,Len);
    SortListPrint(msxb,end,tmp);
	return 0;
}
