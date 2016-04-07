#include <stdio.h>
#include <string.h>
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
int best_count;
void init(strings *strs, int l, best *bestzc)
{
	int i, j;
	bestzc->start = bestzc->len = 0;
	strs->maxcount = strs->maxlen = 1;
	strs->len = strlen(strs->str);
	for(i = 0; i < l; i++)
		for(j = l - 1; j < l; j++)
			strs->message[i][j] = 1;
	best_count = 0;
}
void count_KMP(strings *strs, best *zc, int next[], best *bestzc)
{	
	int i = zc->start + 1;
	int j = zc->start;
	int j_end = zc->start + zc->len - 1;
	while(i < strs->len){
		if(j == zc->start - 1 || strs->str[i] == strs->str[j]){
			++i;
			++j;
			if(j > j_end){
				strs->message[zc->start][zc->len - 1]++;
				strs->message[i - zc->len + 1][zc->len - 1] = 0;
				j = next[j];
				if(strs->message[zc->start][zc->len - 1] > strs->maxcount){
					strs->maxcount = strs->message[zc->start][zc->len - 1];
					best_count = 1;
					//记下出现次数最多的首个子串
					bestzc->start = zc->start;	
					bestzc->len = zc->len;
				}
				else if(strs->message[zc->start][zc->len - 1] == strs->maxcount){
					best_count++;
					//记下出现次数最多的子串中最长且最早出现的子串
					if(bestzc->len < zc->len){
						bestzc->start = zc->start;	
						bestzc->len = zc->len;
					}
				}
			}
		}
		else
			j = next[j];
	}
}//Index_KMP
void get_nextval(strings *strs, best *zc, int nextval[])
{	//求模式串的nextval函数值并存入数组nextval。
	int i = zc->start;
	int j = i - 1;
	int end = zc->start + zc->len - 1;
	nextval[zc->start] = zc->start - 1;
	while(i <= end){
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
	int l, i;
	int next[MAXLEN];
	int best_end;
	strings strs;
	best bestzc;
	best zc;
	scanf("%d", &l);
	fflush(stdin);
	gets(strs.str);
	init(&strs, l, &bestzc);
	//统计不同字符串出现的次数，记录在该字符串首次出现的strs.message[zc.start][zc.len - 1]里 
	//记录strs.message[zc.start][zc.len - 1]等于strs.maxcount的个数best_count, 
	for(zc.start = 0; zc.start < strs.len; zc.start++)
		for(zc.len = l; zc.len <= strs.len - zc.start + 1; zc.len++)
		{	
			if(strs.message[zc.start][strs.len - 1] != 0){
				get_nextval(&strs, &zc, next);
				count_KMP(&strs, &zc, next, &bestzc);
			}
		}
	best_end = bestzc.start + bestzc.len - 1;
	for(i = bestzc.start; i <= best_end; i++)
		putchar(strs.str[i]);
	putchar('\n');
	return 0;
}
