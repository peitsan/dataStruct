#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct Link_list{
    int data;
    struct Link_list *next;
} Link_list;
void disp(Link_list *head){
	Link_list *temp=head;
	while(head!=NULL){
        temp=head->next;
		printf("%d",temp->data);
		printf("  ");
		free(head);
		head=temp;
	}
}
Link_list *crelist(int n,Link_list *head,int flag){
	Link_list *q,*temp,*p;
	p=head->next;
	if (flag==1){
		temp = head;
    for (int i=0; i<n; i++) {
        q = (Link_list*)malloc(sizeof(Link_list));
        scanf("%d", &q->data);
        temp->next = q;
        temp = q;}
	temp->next = NULL;}
	else{
	temp = head;
    for (int i=0; i<n; i++) {
        q = (Link_list*)malloc(sizeof(Link_list));
        scanf("%d", &q->data);
        temp->next = q;
        temp = q;}
	temp->next=p;}
	return head;
}
int main(){   
    int n=0,flag=1,m=1;
    Link_list *head=NULL,*temp;
    head = (Link_list*)malloc(sizeof(Link_list));
    head->next=NULL;
    while (m==1){
        printf("请输入你要输入的个数：");
        fflush(stdin);
        scanf("%d",&n);
        crelist(n,head,flag);
        printf("是否继续输入？输入1为继续，其他为退出\n");
        fflush(stdin);
        scanf("%d",&m);
        flag++;
    }
    printf("输出结果为：");
    disp(head);
    while(head!=NULL){
    	temp=head->next;
    	free(head);
    	temp=head;
	}
return 0;
}