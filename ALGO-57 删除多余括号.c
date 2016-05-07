#include<stdio.h>
#include <string.h>
#define MAXLEN 256
int main()
{
	char bds[MAXLEN];
	char len;
	char i, j;
	char n_flag, check_flag;
	gets(bds);
	len = strlen(bds);
	for(i = 0; i < len; i++)
	{
		while(bds[i] != '(' && i < len)	i++;
		if(i >= len)
			break;
		n_flag = 0;
		check_flag = 0;
		for(j = i + 1; check_flag >= 0; j++)
		{
			if(bds[j] == '(')
				check_flag++;
			else if(bds[j] == ')')
				check_flag--;
			else if(check_flag <= 0 && (bds[j] == '+' || bds[j] == '-'))
				n_flag = 1;
		}
		if(!(n_flag == 1
			&& (
					(i > 0 && (bds[i - 1] == '*' || bds[i - 1] == '/' || bds[i - 1] == '-'))	//要注意括号前为减号时直接去掉会出错 
					|| (j < len && (bds[j] == '*' || bds[j] == '/'))
				)))
		{
			bds[i] = 0;
			bds[j - 1] = 0;
		}
	}
	for(i = 0, j = 0; j < len; )
	{
		if(bds[j] != 0)
			bds[i++] = bds[j++];
		else
			j++;
	}
	bds[i] = '\0';
	puts(bds);
	return 0;
}
