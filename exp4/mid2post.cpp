#include<iostream>
#define MAX 20  
    using namespace std;
    typedef struct Stack
    {
        int top;
        char s[MAX];
    }StackType;
StackType stack1,stack2,tmp;
void Push(StackType* stack,char c)          //��ջ
{
    if(stack->top < MAX)
    {
        stack->top++;
        stack->s[stack->top] = c;
    }
    else
        printf("stack over flow!\n");
} 

 
void Pop(StackType* stack)      //��ջ
{
    if(stack->top != -1)
    {
        stack->top--;
    }
    else 
        printf("stack under flow!\n");
}

void Reverse_print(StackType* stack)        //�������ջ����Ҫʹ������һ����ʱջ
{
    tmp.top = -1;
    while(stack->top != -1)
    { 
        Push(&tmp,stack->s[stack->top]);
        Pop(stack);
    }
    while(tmp.top != -1)
    {
        printf("%c",tmp.s[tmp.top]);
        Pop(&tmp);
    }
}
void Right_ope(StackType* stack)                 //�����ŵĲ���
{
    while(stack->s[stack->top] != '(')           //һֱȡ�������ջ��Ԫ�ص����ջ�У�ֱ������'('Ϊֹ
    {
        Push(&stack2,stack->s[stack->top]);
        Pop(stack);
    }
    Pop(stack);                   //��'('Ҳ��ջ
}
int NumberCheck(char ch)         //�ж��Ƿ�������
{
    if(ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}
int Cmp_level(char mark1,char mark2)            //�Ƚ���������������ȼ�,mark1>mark2 ��������,mark1==mark2 ����0,mark1<mark2,���ظ���
{
    char mark_table[]={'+','-','*','/','(',')'};         //�������
    int mark_level_table[]={1,1,2,2,3,3};               //����Ӧ����������ȼ��洢
    int table_len = sizeof(mark_table)/sizeof(mark_table[0]);       //��������ĳ���
    int mark_index,mark1_index,mark2_index;
    for(mark_index = 0; mark_index < table_len; mark_index++)      //�ҳ���Ҫ�Ƚϵ�������������±�
    {
        if(mark1 == mark_table[mark_index])
            mark1_index = mark_index;
        if(mark2 == mark_table[mark_index])
            mark2_index = mark_index;
    }
    return mark_level_table[mark1_index] - mark_level_table[mark2_index];    //������������������ȼ���ֵ
}
int Ispush(char mark, StackType* stack)       //�ж�������Ƿ�����ջ
{
    if(stack->top == -1)             //ջΪ�վͽ�ջ
        return 1;  
    else if(stack->s[stack->top] == '(')           //ջ����'('�ͽ�ջ
        return 1;  
    else if(Cmp_level(mark,stack->s[stack->top]) > 0 && mark != ')')       //���ȼ����ڲ��Ҳ���')'ջ��Ҳ��ջ
        return 1;
    else 
        return 0;
}
void Switch(const char *exp, int  len)                //����׺���ʽת��Ϊ��׺���ʽ
{
    stack1.top = stack2.top = -1;
    for(int i = 0; i < len-1;  i++)
    {
        if(NumberCheck(exp[i]))     //��������־���ջ�����ջ��
        {
            Push(&stack2,exp[i]);
        }
        else if(!NumberCheck(exp[i]))       //����������
        {
          
             if(Ispush(exp[i],&stack1))   //���ж��Ƿ������������ջ����
            {
                Push(&stack1,exp[i]);
                printf("%c   %d\n",stack1.s[stack1.top],stack1.top);
            }
             else if(exp[i] == ')')       //�ж��Ƿ�������')'
            {
                Right_ope(&stack1);
            }
            else if(Cmp_level(exp[i],stack1.s[stack1.top]) == 0) //���ʽ�����ջ��Ԫ���������ͬ�����ȼ�����ô�ͽ�����ջ��Ԫ�س�ջ����ջ������У����ٽ����ʽ��ջ������ջ
            {
                Push(&stack2,stack1.s[stack1.top]);
                Pop(&stack1);
                Push(&stack1,exp[i]);
            }
        }
    }
    while(stack1.top != -1)         //����������ʽ�󣬻���Ҫ�������ջ�е�����ȫ��������ջ��
    {
        Push(&stack2,stack1.s[stack1.top]);
        Pop(&stack1);
    }
    Reverse_print(&stack2);        //����������
}
 


int main()
{ 
    char str[]="((a+b)*(c-d))";
    int len = sizeof(str)/sizeof(str[1]);
    Switch(str,len);
    return 0;
} 