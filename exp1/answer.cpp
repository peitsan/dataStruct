#include<iostream>
using namespace std;
#define N 3
typedef struct Slist{
	char number[12];
	char name[20];
}Slist;
int main(){
	Slist msxb[N];
	Slist*end = msxb,*temp = msxb;
	int n,x,i,t=0;
	loop:cout<<"*************************************\n";
	cout<<"1.多次输入学生信息"<<endl;
	cout<<"2.删除指定位置的元素"<<endl;
	cout<<"3.退出操作\n";
	cout<<"*************************************\n";
	cin>>x;
	char c='y';
	char d='y';
	switch (x) {
	case 1:
		while(c=='y'){
			cout<<"输入的学生人数\n";
			cin>>n;
			t+=n;
			cout<<"待输入的学生信息（学号+姓名）\n";
			for(end=temp;(end-temp)<n;end++){
				if((end-msxb)>=N){
					cout<<"结构体数组已满\n\n";
					break;
				}
				cin>>end->number;
				cin>>end->name;
			}
			temp=end;
			cout<<"顺序表内容如下\n";
			for(end=msxb;end<temp;end++){
				printf("%s %s\n",end->number,end->name);
			}
			if((end-msxb)>=N)
				break;
			fflush(stdin);
			cout<<"是否继续输入（输入y继续）\n";
			cin>>c;
			if(c!='y'||(end-msxb)>=N){
				goto loop;
			}
		}
		break;
	case 2:
		while(d=='y'){
				if(end==msxb){
					cout<<"顺序表为空\n";
					break;	
				}
				else{
					cout<<"请输入要删除的元素在顺序表中的位置\n";
					cin>>i;
					if(i<0||i>N){
						cout<<"顺序表中无该元素\n";
					}
					else{
						for(end=msxb;end<temp;end++){
							if(end-msxb==i){
								for(int j=i;j<t;j++){
									msxb[j-1]=msxb[j];
								}
							}
						}
						temp-=1;
					cout<<"删除成功\n";	
					if(end==msxb){
						cout<<"顺序表为空\n";
						break;
					}
					cout<<"顺序表内容如下\n";
					for(end=msxb;end<temp;end++){
						printf("%s %s\n",end->number,end->name);
					}
					}
				}
				fflush(stdin);
				cout<<"是否继续删除（输入y继续）"<<endl;
				cin>>d;		
		}
		break;
	case 3:
		break;
	default:
		cout<<"输入错误";
		break;	
		}
}
