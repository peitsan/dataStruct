#include<iostream>
#define N 10
#define maxContain 256
    using namespace std;
    typedef struct sortedList{
        char stuNum[12];
        char stuName[20];
        char stuPhone[14];
    }sortList; //�������ݿ��нṹ ��¼�������ֶ����ڴ洢��Ϣ
  void SortListPrint(sortList obj[N],sortList *end,sortList *temp){//ɾ��λ�ú� �������Ԫ��������ǰ�ƶ�һλ
    temp = end;
    for(end=obj;end!=temp;end++){
            printf("%s %s %s\n",end->stuNum,end->stuName,end->stuPhone);
        }
    }
   void SortListDel(sortList obj[N],sortList *end,sortList *temp,int length){
        char d = 'y';
        int target;
        cout<<"ԭʼ��������:\n";
        SortListPrint(obj,end,temp);//���ô�ӡ����
        while(d == 'y'){
            if(obj == end){ //�ж����Ա��Ƿ�Ϊ��
                cout<<"˳���Ϊ��!"<<endl;
                break;
            }
            else{
                cout<<"����ɾ��Ԫ�ص�λ����:\n";
                cin>>target;
                if(0<= target <=N+1){
                    for(end = obj; end-temp<length; end++){
                        //ɾ��Ԫ���߼�
                        	if(end-obj==target){
								for(int i=target;i<=length;i++){
									obj[i-1]=obj[i];//ɾ��λ�ú� �������Ԫ��������ǰ�ƶ�һλ
                                }
                            }
                        }
                      temp -= 1;
                    if(obj == end){
					    cout<<"˳��������\n";
						break;
					    }
					cout<<"ɾ��Ԫ�غ��˳���\n";
					SortListPrint(obj,end,temp);
                          
                    cout<<"�Ƿ����ɾ��(������'y'):\n";
                    cin>>d;
                }
                else{
                cout<<"˳�����û�и�Ԫ��(�ṹ�����):"<<endl;    
                }
            }
        }

 }
  
    
int main(){
    sortedList msxb[N]={{"2021212961","�����","18025597877"},
                        {"2021212961","�����","13364063027"},
                        {"2021212961","�����","15816750104"}};
    sortedList *end=&msxb[3],*tmp=msxb;
    int Len = 3;
    SortListDel(msxb,end,tmp,Len);
	return 0;
}
