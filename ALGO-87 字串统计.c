#include <stdio.h>
#define MAXLEN	60
typedef struct{
	int start;
	int len;
}best;
typedef struct strings{
	char str[MAXLEN];
	int len;
	char message[MAXLEN][MAXLEN];	//message[i][j]:i是子串开始的下标，j = 子串长度 - 1； message[i][j]的值是此子串出现的次数 
	int maxcount;
	int maxlen;
}strings;
void init(strings *strs, int l, best *bestzc)
{
	int i, j;
	bestzc->start = bestzc->len = 0;
	strs->maxcount = strs->maxlen = 1;
	strs->len = strlen(strs->str);
	for(i = 0; i < l; i++)
		for(j = l - 1; j < l; j++)
			strs->message[i][j] = 1;
}
void Index_KMP(strings *strs, best *zc, int l, int next[])
{	
	int i = 0;
	int j = zc->start;
	int end = zc->start + zc->len - 1;
	int first = -1;
	while(i < strs->len){
		if(j == zc->start - 1 || strs->str[i] == strs->str[j]){
			++i;
			++j;
		}
		else
			j = next[j];
		if(j > end){
			if(first == -1){
				
			}
		}
	}
	if(j > end)
		return i - zc->len;
	else
		return 0;
}//Index_KMP
void get_nextval(strings *strs, best *zc, int nextval[])
{	//求模式串的nextval函数值并存入数组nextval。
	int i = zc->start;
	int j = i - 1;
	int end = zc->start + zc->len - 1;
	nextval[1] = 0;
	while(i < end){
		if(j == zc->start - 1 || strs->str[i] == strs->str[j]){
			++i;
			++j;
			nextval[i] = j;
		}
		else
			j = nextval[j];
	}
}//get_nextval
int main()
{
	int i, j;
	int l;
	int next[MAXLEN];
	strings strs;
	best bestzc;
	best zc;
	scanf("%d", &l);
	gets(strs.str);
	init(&strs, l, &bestzc);
	for(i = 0; i < strs->len; i++)
		for(j = l - 1; j < strs->len; j++)
		{	
			if(strs->message[i][j] != 0){
				get_nextval(&strs, &zc, next);
				Index_KMP(&strs, &zc, l, next);
			}
			
		}
	
	return 0;
}
