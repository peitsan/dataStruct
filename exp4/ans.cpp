//将中缀表达式转为后缀表达式
#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 20
 
struct Stack
{
    int top;
    char arr[MAXSIZE];
}stack1,stack2,temp;          //stack1为符号栈，stack2为存放结果的栈,temp是临时使用的栈
 
void Push_stack(struct Stack* stack,char c)          //入栈
{
    if(stack->top < MAXSIZE)
    {
        stack->top++;
        stack->arr[stack->top] = c;
    }
    else
        printf("stack over flow!\n");
}
 
void Pop_stack(struct Stack* stack)      //出栈
{
    if(stack->top != -1)
    {
        stack->top--;
    }
    else 
        printf("stack under flow!\n");
 
}
 
bool Isempty(struct Stack* stack)    //判断栈是否为空
{
    if(stack->top == -1)
        return true;   //空
    else
        return false;  //非空
}
 
void Reverse_print(struct Stack* stack)        //逆序输出栈，需要使用另外一个临时栈
{
    temp.top = -1;
    while(stack->top != -1)
    { 
        Push_stack(&temp,stack->arr[stack->top]);
        Pop_stack(stack);
    }
    while(temp.top != -1)
    {
        printf("%c",temp.arr[temp.top]);
        Pop_stack(&temp);
    }
}
 
bool Isnum(char ch)         //判断是否是数字
{
    if(ch >= '0' && ch <= '9')
        return true;
    else
        return false;
 
}
 
int Cmp_level(char mark1,char mark2)            //比较两个运算符的优先级,mark1>mark2 返回正数,mark1==mark2 返回0,mark1<mark2,返回负数
{
    char mark_table[]={'+','-','*','/','(',')'};         //运算符集
    int mark_level_table[]={1,1,2,2,3,3};               //将对应运算符的优先级存储
    int table_len = sizeof(mark_table)/sizeof(mark_table[0]);       //运算符集的长度
    int mark_index,mark1_index,mark2_index;
    for(mark_index = 0; mark_index < table_len; mark_index++)      //找出需要比较的两个运算符的下标
    {
        if(mark1 == mark_table[mark_index])
            mark1_index = mark_index;
        if(mark2 == mark_table[mark_index])
            mark2_index = mark_index;
    }
    return mark_level_table[mark1_index] - mark_level_table[mark2_index];    //返回两个运算符的优先级差值
}
 
bool Ispush(char mark, struct Stack* stack)       //判断运算符是否能入栈
{
    if(Isempty(stack))             //栈为空就进栈
        return true;  
    else if(stack->arr[stack->top] == '(')           //栈顶是'('就进栈
        return true;  
    else if(Cmp_level(mark,stack->arr[stack->top]) > 0 && mark != ')')       //优先级大于并且不是')'栈顶也进栈
        return true;
    else 
        return false;
 
}
 
void Right_ope(struct Stack* stack)                 //右括号的操作
{
    while(stack->arr[stack->top] != '(')           //一直取出运算符栈顶元素到结果栈中，直到遇到'('为止
    {
        Push_stack(&stack2,stack->arr[stack->top]);
        Pop_stack(stack);
    }
    Pop_stack(stack);                   //将'('也出栈
}
 
void Switch(const char *exp, int  len)                //将中缀表达式转换为后缀表达式
{
    stack1.top = stack2.top = -1;
    for(int i = 0; i < len-1;  i++)
    {
        if(Isnum(exp[i]))     //如果是数字就如栈到结果栈中
        {
            Push_stack(&stack2,exp[i]);
        }
        else if(!Isnum(exp[i]))       //如果是运算符
        {
          
             if(Ispush(exp[i],&stack1))   //先判断是否满足运算符如栈条件
            {
                Push_stack(&stack1,exp[i]);
                printf("%c   %d\n",stack1.arr[stack1.top],stack1.top);
            }
             else if(exp[i] == ')')       //判断是否遇到了')'
            {
                Right_ope(&stack1);
            }
            else if(Cmp_level(exp[i],stack1.arr[stack1.top]) == 0) //表达式与符号栈顶元素如果是相同的优先级，那么就将符号栈顶元素出栈并入栈到结果中，且再将表达式如栈到符号栈
            {
                Push_stack(&stack2,stack1.arr[stack1.top]);
                Pop_stack(&stack1);
                Push_stack(&stack1,exp[i]);
            }
        }
    }
    while(stack1.top != -1)         //当遍历完表达式后，还需要将运算符栈中的内容全部导入结果栈中
    {
        Push_stack(&stack2,stack1.arr[stack1.top]);
        Pop_stack(&stack1);
    }
    Reverse_print(&stack2);        //逆序输出结果
}
 
int main(int argc, char *argv[])
{ 
    char str[]="(a+b)*(c-d)";
    int len = sizeof(str)/sizeof(str[1]);
    Switch(str,len);
    return 0;
} 