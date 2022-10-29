#include<iostream>
#define N 10
#define maxContain 256
    using namespace std;
    typedef struct sortedList{
        char stuNum[12];
        char stuName[20];
        char stuPhone[14];
    }sortList; //定义数据库行结构 记录下三个字段用于存储信息
  void SortListPrint(sortList obj[N],sortList *end,sortList *temp){//删除位置后 将后面的元素依次向前移动一位
    temp = end;
    for(end=obj;end!=temp;end++){
            printf("%s %s %s\n",end->stuNum,end->stuName,end->stuPhone);
        }
    }
   void SortListDel(sortList obj[N],sortList *end,sortList *temp,int length){
        char d = 'y';
        int target;
        cout<<"原始数据如下:\n";
        SortListPrint(obj,end,temp);//调用打印函数
        while(d == 'y'){
            if(obj == end){ //判断线性表是否为空
                cout<<"顺序表为空!"<<endl;
                break;
            }
            else{
                cout<<"你想删除元素的位置在:\n";
                cin>>target;
                if(0<= target <=N+1){
                    for(end = obj; end-temp<length; end++){
                        //删除元素逻辑
                        	if(end-obj==target){
								for(int i=target;i<=length;i++){
									obj[i-1]=obj[i];//删除位置后 将后面的元素依次向前移动一位
                                }
                            }
                        }
                      temp -= 1;
                    if(obj == end){
					    cout<<"顺序表已清空\n";
						break;
					    }
					cout<<"删除元素后的顺序表\n";
					SortListPrint(obj,end,temp);
                          
                    cout<<"是否继续删除(是输入'y'):\n";
                    cin>>d;
                }
                else{
                cout<<"顺序表中没有该元素(结构体溢出):"<<endl;    
                }
            }
        }

 }
  
    
int main(){
    sortedList msxb[N]={{"2021212961","林培灿","18025597877"},
                        {"2021212961","林培灿","13364063027"},
                        {"2021212961","林培灿","15816750104"}};
    sortedList *end=&msxb[3],*tmp=msxb;
    int Len = 3;
    SortListDel(msxb,end,tmp,Len);
	return 0;
}
