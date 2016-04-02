#include "stdio.h"
#include "string.h"
#define MAXLEN 12
void TimeInEnglish(int num, int ish, char c1[], char c2[])
{
	if(num <= 20)
		switch(num){
			case 0: strcpy(c2, "zero "); break;
			case 1: strcpy(c2, "one "); break;
			case 2: strcpy(c2, "two "); break;
			case 3: strcpy(c2, "three "); break;
			case 4: strcpy(c2, "four "); break;
			case 5: strcpy(c2, "five "); break;
			case 6: strcpy(c2, "six "); break;
			case 7: strcpy(c2, "seven "); break;
			case 8: strcpy(c2, "eight "); break;
			case 9: strcpy(c2, "nine "); break;
			case 10: strcpy(c2, "ten "); break;
			case 11: strcpy(c2, "eleven "); break;
			case 12: strcpy(c2, "twelve "); break;
			case 13: strcpy(c2, "thirteen "); break;
			case 14: strcpy(c2, "fourteen "); break;
			case 15: strcpy(c2, "fifteen "); break;
			case 16: strcpy(c2, "sixteen "); break;
			case 17: strcpy(c2, "seventeen "); break;
			case 18: strcpy(c2, "eighteen "); break;
			case 19: strcpy(c2, "nineteen "); break;
			case 20: strcpy(c2, "twenty "); break;
			default: break;
		}
	else if((ish && num < 24) || (!ish && num < 60)){
		switch(num / 10){
			case 2: strcpy(c1, "twenty "); break;
			case 3: strcpy(c1, "thirty "); break;
			case 4: strcpy(c1, "forty "); break;
			case 5: strcpy(c1, "fifty "); break;
			default: break;
		}
		switch(num % 10){
			case 0: break;
			case 1: strcpy(c2, "one "); break;
			case 2: strcpy(c2, "two "); break;
			case 3: strcpy(c2, "three "); break;
			case 4: strcpy(c2, "four "); break;
			case 5: strcpy(c2, "five "); break;
			case 6: strcpy(c2, "six "); break;
			case 7: strcpy(c2, "seven "); break;
			case 8: strcpy(c2, "eight "); break;
			case 9: strcpy(c2, "nine "); break;
			default: break;
		}
	}
	if(ish == 0 && num == 0)
		strcpy(c2, "o'clock");
	else if(ish == 0 && num != 0)
		c2[strlen(c2) - 1] = '\0';
}
int main(int argc, char const *argv[])
{
	int h, m;
	char h1[MAXLEN] = {'\0'}, h2[MAXLEN] = {'\0'}, m1[MAXLEN] = {'\0'}, m2[MAXLEN] = {'\0'};
	scanf("%d%d", &h, &m);
	TimeInEnglish(h, 1, h1, h2);
	TimeInEnglish(m, 0, m1, m2);
	printf("%s%s%s%s", h1, h2, m1, m2);
	return 0;
}
