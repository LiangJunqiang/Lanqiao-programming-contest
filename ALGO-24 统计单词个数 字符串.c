#include <stdio.h>
#include <string.h>
#define WORD_LEN	10
#define CHAR_INT	(1 << ((int)sizeof(char)*8 - 2))
typedef struct
{
	int s;						//�ֵ��������ʸ���
	char word[6][WORD_LEN];
}dictionary;
typedef struct
{
	char str[202];
	char s_flag[200];	//��������Ƿ���������Ϊ���ʿ�ʼ 
	char used[202];		//�������������ĸ��ռ�õĵ��ʸ��� 
}m_string;				//ͳ�������ұ�ռ�����ٵ� k ����ĸ��Ϊ�ָ� 
void word_sort(dictionary *zd);
void change_str(char *x, char *y);
int Index_KMP(char S[], char T[], int next[], int pos);
void get_nextval(char *T, int nextval[]);
void statistic(m_string *s, dictionary *zd);
int main()
{
	char sub_str[22];
	m_string s;
	dictionary zd;
	int p, k;
	int i;
	scanf("%d%d", &p, &k);
	s.str[0] = '\0';
	getchar();
	while(p--)
	{
		fgets(sub_str, 22, stdin);
		sub_str[20] = '\0';
		strcat(s.str, sub_str);
	}
	scanf("%d", &(zd.s));
	getchar();
	for(i = 0; i < zd.s; i++)
		gets(zd.word[i]);
	word_sort(&zd);
	memset(s.s_flag, 0, (int)sizeof(s.s_flag));
	memset(s.used, 0, (int)sizeof(s.used));
	statistic(&s, &zd);
	i = analysis_disconnect(&s, k);
	printf("%d\n", i);
	return 0;
}
int analysis_disconnect(m_string *s, int k)
{	//��s->str[k] ��  s->str[k - 1] ��Ͽ�������� (s->used[k] �� s->s_flag[k]) ������
	//�� k - 1 ����С�� (s->used[k] �� s->s_flag[k]) ֵ����ÿ�ҵ�һ���� s->used[k]��Ϊ������Ӷ��ֳ� k �ݣ���ʹ���ٵ��ʵĴ�����С 
	int i, j, min_u_f;
	int len = strlen(s->str);
	int word_count = 0;
	for(i = 0; i < len; i++)
		if(s->s_flag[i] == 1)
			word_count++;
	k = k - 1;
	for(i = 1; i <= k; i++)
	{
		min_u_f = 1;
		for(j = 2; j < len; j++)
			if(s->used != 0 && ((s->used[min_u_f] - s->s_flag[min_u_f]) > (s->used[j] - s->s_flag[j])))
				min_u_f = j;
		word_count -= (s->used[min_u_f] - s->s_flag[min_u_f]);
		s->used[min_u_f] = CHAR_INT;
	}
	return word_count;
}
void statistic(m_string *s, dictionary *zd)
{
	int i, j;
	int next[6][WORD_LEN];
	int len[6];
	int pos;
	for(i = 0; i < zd->s; i++)
	{
		get_nextval(zd->word[i], next[i]);
		len[i] = strlen(zd->word[i]);
		for(pos = 0; pos != -1; )
		{
			pos = Index_KMP(s->str, zd->word[i], next[i], pos);
			if(pos != -1){
				if(s->s_flag[pos] == 0){
					s->s_flag[pos] = 1;
					for(j = pos; j < pos + len[i]; j++)
						s->used[j]++;
				}
				pos++;
			}
		}
	}
}
void change_str(char *x, char *y)
{
	char z[WORD_LEN];
	strcpy(z, x);
	strcpy(x, y);
	strcpy(y, z);
}
void word_sort(dictionary *zd)
{
	int i, j, k;
	for(i = 0; i < zd->s; i++)
	{
		k = i;
		for(j = i + 1; j < zd->s; j++)
			if(strlen(zd->word[k]) > strlen(zd->word[j]))
				k = j;
		if(i != k)
			change_str(zd->word[i], zd->word[k]);
	}
}
int Index_KMP(char S[], char T[], int next[], int pos)
{
	int i = pos;
	int j = 0;
	int len_s;
	int len_t;
	len_s = strlen(S);
	len_t = strlen(T);
	while(i < len_s && j < len_t)
	{
		if(j == -1 || S[i] == T[j]){
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if(j >= len_t)
		return i - len_t;
	else
		return -1;
}
void get_nextval(char *T, int nextval[])
{
	int i = 0;
	int j = -1;
	int len;
	len = strlen(T);
	nextval[0] = -1;
	while(i < len - 1)
	{
		if(j == -1 || T[i] == T[j]){
			++i;
			++j;
			nextval[i] = j;
		}
		else{
			j = nextval[j];
		}
	}
}
