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
	cout<<"1.�������ѧ����Ϣ"<<endl;
	cout<<"2.ɾ��ָ��λ�õ�Ԫ��"<<endl;
	cout<<"3.�˳�����\n";
	cout<<"*************************************\n";
	cin>>x;
	char c='y';
	char d='y';
	switch (x) {
	case 1:
		while(c=='y'){
			cout<<"�����ѧ������\n";
			cin>>n;
			t+=n;
			cout<<"�������ѧ����Ϣ��ѧ��+������\n";
			for(end=temp;(end-temp)<n;end++){
				if((end-msxb)>=N){
					cout<<"�ṹ����������\n\n";
					break;
				}
				cin>>end->number;
				cin>>end->name;
			}
			temp=end;
			cout<<"˳�����������\n";
			for(end=msxb;end<temp;end++){
				printf("%s %s\n",end->number,end->name);
			}
			if((end-msxb)>=N)
				break;
			fflush(stdin);
			cout<<"�Ƿ�������루����y������\n";
			cin>>c;
			if(c!='y'||(end-msxb)>=N){
				goto loop;
			}
		}
		break;
	case 2:
		while(d=='y'){
				if(end==msxb){
					cout<<"˳���Ϊ��\n";
					break;	
				}
				else{
					cout<<"������Ҫɾ����Ԫ����˳����е�λ��\n";
					cin>>i;
					if(i<0||i>N){
						cout<<"˳������޸�Ԫ��\n";
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
					cout<<"ɾ���ɹ�\n";	
					if(end==msxb){
						cout<<"˳���Ϊ��\n";
						break;
					}
					cout<<"˳�����������\n";
					for(end=msxb;end<temp;end++){
						printf("%s %s\n",end->number,end->name);
					}
					}
				}
				fflush(stdin);
				cout<<"�Ƿ����ɾ��������y������"<<endl;
				cin>>d;		
		}
		break;
	case 3:
		break;
	default:
		cout<<"�������";
		break;	
		}
}
