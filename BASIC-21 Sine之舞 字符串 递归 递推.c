#include <stdio.h>
#include "string.h"
#define MAXLEN 10000
//中文
int CatNum(char *p, int n)
{
	int i, j = 0;
	int len = strlen(p);
	for(i = 100; i > 0 && !(n / i); i /= 10)
		;
	if(i > 0){
		while(i > 0){
			j++;
			p[len] = (n / i) + '0';
			len++;
			n %= i; 
			i /= 10;
		}
		p[len] = '\0';
	}
	return j;
}
int NewAn(int n, char An[], int insertposition)
{
	int numbit, i, j;
	int repair_brackets = strlen(An) - insertposition;//待会要补上的右括号数
	An[insertposition] = '\0';
	if(n == 1){
		strcpy(An, "sin(1)");
		return 5;
	}
	else{
		if(n % 2 == 0)
			strcat(An, "-sin(");
		else
			strcat(An, "+sin(");
		numbit = CatNum(An, n);
		strcat(An, ")");
		for(i = strlen(An), j = 0; j < repair_brackets; i++, j++)
			An[i] = ')';	//补上右括号
		An[i] = '\0';
		return (numbit + 5);
	}
}
void CreatSn(int n, char Sn[])
{	
	char An[MAXLEN] = {'\0'};
	int insertposition = 0, i, j, len;
	if(n == 0){
		Sn[0] = '0';
		return;
	}
	insertposition += NewAn(1, An, insertposition);
	strcpy(Sn, An);
	strcat(Sn, "+");
	CatNum(Sn, n);
	for(i = 2; i <= n; i++){
		insertposition += NewAn(i, An, insertposition);
		len = strlen(Sn);
		for(j = len; j > 0; j--)
			Sn[j] = Sn[j - 1];
		Sn[0] = '(';
		strcpy(&Sn[len + 1], ")");
		strcat(Sn, An);
		strcat(Sn, "+");
		CatNum(Sn, n - i + 1);
	}
}
int main(int argc, char const *argv[])
{
	char Sn[MAXLEN] = {'\0'};
	
	int n;
	scanf("%d", &n);
	CreatSn(n, Sn);
	printf("%s\n", Sn);
	return 0;
}
