#include<iostream>
#define N 10
#define maxContain 256
    using namespace std;
    typedef struct sortedList{
        char stuNum[12];
        char stuName[20];
        char stuPhone[14];
    }sortList; //定义数据库行结构 记录下三个字段用于存储信息

   void SortListDel(sortList* obj,sortList *end,sortList *temp,int length){
        char d = 'y';
        int target;
        while(d = 'y'){
            if(obj == end){
                cout<<"顺序表为空!"<<endl;
                break;
            }
            else{
                cout<<"你想删除元素的位置在:\n";
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
						    cout<<"顺序表已清空\n";
						    break;
					        }
					        cout<<"删除元素后的顺序表\n";
					        for(end = obj;end < temp;end++){
					        	printf("%s %s %s\n",end->stuNum,end->stuName,end->stuPhone);
					        }
                    }
                    cout<<"是否继续删除(是输入'y'):\n";
                    cin>>d;
                }
                else{
                cout<<"顺序表中没有该元素(结构体溢出):"<<endl;    
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
    sortedList msxb[N]={{"2021212961","林培灿","18025597877"},
                        {"2021212961","林培灿","13364063027"},
                        {"2021212961","林培灿","15816750104"}};
    sortedList *end=msxb,*tmp=msxb;
    int Len = 3;
    SortListDel(msxb,end,tmp,Len);
    SortListPrint(msxb,end,tmp);
	return 0;
}
