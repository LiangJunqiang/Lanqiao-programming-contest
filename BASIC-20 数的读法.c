#include "stdio.h"
#include <string.h>
#define MAXLEN 12
int IsDigit(char x)
{	//判断字符表示的是否数字，是返回1，否则返回零
	if(x >= '0' && x <= '9')
		return 1;
	else
		return 0;
}
void InsertDigitInCN(char a, char spell[])
{	//把指定数字的拼音插入到spell的前面
	char t[300];
	switch(a){
		case '0': strcpy(t, "ling ");	strcat(t, spell); strcpy(spell, t); break;
		case '1': strcpy(t, "yi ");		strcat(t, spell); strcpy(spell, t); break;
		case '2': strcpy(t, "er ");		strcat(t, spell); strcpy(spell, t); break;
		case '3': strcpy(t, "san ");	strcat(t, spell); strcpy(spell, t); break;
		case '4': strcpy(t, "si "); 	strcat(t, spell); strcpy(spell, t); break;
		case '5': strcpy(t, "wu "); 	strcat(t, spell); strcpy(spell, t); break;
		case '6': strcpy(t, "liu "); 	strcat(t, spell); strcpy(spell, t); break;
		case '7': strcpy(t, "qi "); 	strcat(t, spell); strcpy(spell, t); break;
		case '8': strcpy(t, "ba "); 	strcat(t, spell); strcpy(spell, t); break;
		case '9': strcpy(t, "jiu "); 	strcat(t, spell); strcpy(spell, t); break;
		default: break;
	}
}
void InsertUnit(int bit, char spell[])
{
	char t[300];
	switch(bit){
		case 2: strcpy(t, "shi ");	strcat(t, spell); strcpy(spell, t); break;
		case 3: strcpy(t, "bai ");	strcat(t, spell); strcpy(spell, t); break;
		case 4: strcpy(t, "qian "); strcat(t, spell); strcpy(spell, t); break;
		case 5: strcpy(t, "wan "); 	strcat(t, spell); strcpy(spell, t); break;
		case 6: strcpy(t, "shi "); 	strcat(t, spell); strcpy(spell, t); break;
		case 7: strcpy(t, "bai "); 	strcat(t, spell); strcpy(spell, t); break;
		case 8: strcpy(t, "qian "); strcat(t, spell); strcpy(spell, t); break;
		case 9: strcpy(t, "yi "); 	strcat(t, spell); strcpy(spell, t); break;
		case 10: strcpy(t, "shi "); strcat(t, spell); strcpy(spell, t); break;
		default: break;
	}
}
void ReadDigit(char num[], char spell[])
{	//把num[]里的数字转换为拼音存放在spell中
	int j; 
	int i = strlen(num) - 1;
	if(num[i] != '0')
		InsertDigitInCN(num[i], spell);
	i--;
	for (j = 2; i >= 0; i--, j++)
	{
		if(num[i] != '0'){
			InsertUnit(j, spell);
			if(num[i] != '1' || j % 4 != 2)
				InsertDigitInCN(num[i], spell);
		}
		else{
			if((j == 5 && (num[i-1] != '0' || num[i-2] != '0' || num[i-3] != '0')) || ( j == 9 && num[i-1] != '0'))
				InsertUnit(j, spell);
			if(num[i+1] != '0' && !((j == 5 && (num[i-1] != '0' || num[i-2] != '0' || num[i-3] != '0')) || ( j == 9 && num[i-1] != '0')))
				InsertDigitInCN(num[i], spell);
		}
	}
}
int main(int argc, char const *argv[])
{
	int i;
	char num[11] = {'\0'};
	char spell[300] = {'\0'};
	for (i = 0; i < 10 && IsDigit(num[i] = getchar()); ++i)
		;
	num[i] = '\0';
	ReadDigit(num, spell);
	printf("%s", spell);
	return 0;
}
