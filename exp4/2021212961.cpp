#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;
#define MAX 20
typedef struct
{
    int top;
	char stack[MAX];
}Stack;

int checkPriority(char str)
{
	switch (str)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '(':
		return 0;
	case ')':
		return 0;
	default:
		break;
	}
}

int stack_full(Stack s)
{
	if (s.top == MAX-1)
		return 1;//stack_full
	else
		return 0;
}

int stack_empty(Stack s)
{
	if (s.top == -1)
		return 1;//stack empty
	else
		return 0;

}

int Push(Stack *s,char str)
{
	if (stack_full(*s))
	{
		printf("stack full\n");
		return 0;
	}
	else
	{
		s->top++;
		s->stack[s->top] = str;
		return 1;
	}

}

int Pop(Stack *s)
{
	if (stack_empty(*s))
	{
		printf("stack empty\n");
		return 0;
	}
	else
	{
		char str = s->stack[s->top];
		s->top--;
		return str;
	}
}

int getTop(Stack s)
{
	if (stack_empty(s))
	{
		return 0;
	}
	else
	{
		return s.stack[s.top];
	}
}
void Mid2Post(Stack *s1, Stack *s2,char* str)
{
	int priority = 0;
	for (int i = 0; i < strlen(str) ; i++)
	{
		if (str[i] == '(')
			Push(s1, str[i]);
		else if (str[i] == ')')
		{
			while (1)
			{
				char ele = Pop(s1);
				if (ele == '(')
					break;
				else {
					Push(s2, ele);
				}
			}
		}
		else if (str[i] > 'A' && str[i] < 'Z' || str[i] > 'a' && str[i] < 'z' || str[i] >= '0')
		{
			Push(s2, str[i]);
		}
		else
		{
			if (stack_empty(*s1))
			{
				Push(s1, str[i]);
			}
			else
			{
			
				if (checkPriority(str[i]) >= checkPriority(getTop(*s1)))
				{
					Push(s1, str[i]);
				}
				else
				{
					while (1)
					{
					

						if (checkPriority(getTop(*s1)) <= checkPriority(str[i]) || getTop(*s1) == '(')
						{
							Push(s1, str[i]);
							break;
						}
						Push(s2, Pop(s1));
					
					}
				}
			}
		}

	}

	while (stack_empty(*s1) == 0)
	{
		char elem = Pop(s1);
		if (elem != '(') {
			Push(s2, elem);
		}

	}
	int index = 0;
	int opt[50];
	while (stack_empty(*s2) == 0)
	{
		opt[index] = Pop(s2);
		index++;
	}

	cout<<"后缀表达式为: ";
	for (int i = index-1; i >= 0; i--)
	{
		printf("%c", opt[i]);
	}

	printf("\n");
}

int main()
{
	char str[MAX];
    cout<<"请输入中缀表达式!\n";
    scanf("%s",str);
	cout<<"中缀表达式为:"<<str<<"\n";
	Stack s1,s2;           //定义左右子树 并初始化顺序栈
	s1.top =s2.top = -1;
	Mid2Post(&s1, &s2, str);
    return 0;
}
