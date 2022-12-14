/*@function:统计输入中的所有单词出现的次数
 * @method: 使用二叉查找树。对输入的单词建立一颗二叉查找树，新输入的单词若存在于树中，则增加该节点的计数值；否则，新增一个节点
 */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
 
#define MAXWORD 	100
 
typedef struct tnode
{
	char 	word[MAXWORD];
	int 	count;
	struct tnode *left;
	struct tnode *right;
}tnode_t;
 
tnode_t *addtree(tnode_t *, char *);
void treeprint(tnode_t *);
int getword(char *, int);
 
 
 
int main(void)
{
		tnode_t *root;
		char word[MAXWORD];
		
		root = NULL;
		while(getword(word, MAXWORD) != EOF)
			if(isalpha(word[0]))
				root = addtree(root, word);
		treeprint(root);
		return 0;
}
 
/* add a node to the tree by using non-recursive method */
/*
tnode_t *addtree(tnode_t *p, char *w)
{
	int cond;
	tnode_t *s, *temp1, *temp2;//s为待插入的node，temp2为temp1的父节点
	s = (tnode_t *)malloc(sizeof(tnode_t));
	if(s == NULL)
	{
		printf("error: malloc\n");
		exit(0);
	}
	strcpy(s->word, w);
	s->count = 1;
	s->left = s->right = NULL;
	if(p == NULL) //if tree is empty
	{
		p = s;
		return p;
	}
	temp1 = p;
	while(temp1 != NULL) //find the place to insert
	{
		temp2 = temp1;
		if((cond = strcmp(w, temp1->word)) < 0)
			temp1 = temp1->left;
		else if(cond == 0) //if the node is existed, count increases, and free memory of s
		{
			temp1->count++;
			free(s);
			return p;
		}
		else
			temp1 = temp1->right;
	}
	if((cond = ~(w, temp2->word)) < 0)
		temp2->left = s;
	else
		temp2->right = s;
	return p;
}
**/
 
/* add a node to the tree by using recursive method */
tnode_t *addtree(tnode_t *p, char *w)
{
	int cond;
	tnode_t *s;
	
	if(p == NULL) //基准
	{
	    s = (tnode_t *)malloc(sizeof(tnode_t));
		if(s == NULL)
		{
			printf("error: malloc\n");
			exit(0);
		}
		strcpy(s->word, w);
		s->count = 1;
		s->left = s->right = NULL;
		p = s;
		return p;
	}
	else if((cond = strcmp(w, p->word)) < 0)
		p->left = addtree(p->left, w);//note
	else if(cond == 0)
		p->count++;
	else 
		p->right = addtree(p->right, w);
	return p;
}
 
/***********************************/
/* inorder print */
void treeprint(tnode_t *p)
{
	if(p != NULL)
	{
		treeprint(p->left);
		printf("%s\t%d\n", p->word, p->count);
		treeprint(p->right);
	}
}
 
/***********************************/
int getword(char *word, int lim)
{
	int c;
	char *w = word;
	
	while(isspace(c = getchar())) //检查参数c是否为空格字符,即为下一个字母的开始
		;
	if(c != EOF)
		*w++ = c;
	if(!isalpha(c)) //判断字符变量c是否为字母
	{
		*w = '\0';
		return c;
	}
	for(; --lim > 0; w++)
		if(!isalnum(*w = getchar())) //判断字符变量c是否为字母或数字
			break;
 
	*w = '\0';
	return word[0];
}