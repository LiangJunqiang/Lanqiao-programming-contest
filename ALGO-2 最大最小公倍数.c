#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//中文 
#define MAXBit	20
int multiply(int a[], int b[], int la, int lb);
int GetN(int N[]);
void printNum(int a[], int l);
int expressedThree(int a[], int la);
int main(int argc, char const *argv[])
{
	int N[MAXBit] = {0}, la = 0, faciend[MAXBit - 12] = {0}, i, lb;
	la = GetN(N);
	for (i = 0; i < la; i++)
		faciend[i] = N[i];
	lb = la;
	if(N[la - 1] & 1){
		faciend[lb - 1]--;
		la = multiply(N, faciend, la, lb);
		faciend[lb - 1]--;
		la = multiply(N, faciend, la, lb);
	}
	else{
		if(!expressedThree(N, la)){
			faciend[lb - 1]--;
			la = multiply(N, faciend, la, lb);
			faciend[lb - 1] -= 2;
			la = multiply(N, faciend, la, lb);
		}
		else if(N[la - 1] >= 6){
			N[la - 1]--;
			faciend[lb - 1] -= 2;
			la = multiply(N, faciend, la, lb);
			faciend[lb - 1]--;
			la = multiply(N, faciend, la, lb);
		}
		else{
			faciend[lb - 1]--;
			la = multiply(N, faciend, la, lb);
			faciend[lb - 1]--;
			la = multiply(N, faciend, la, lb);
			
		}
	}
	printNum(N, la);
	return 0;
}
int expressedThree(int a[], int la)
{
	long sum = 0;
	int i;
	for(i = 0; i < la; i++)
		sum += a[i];
	if(sum % 3 == 0)
		return 1;
	else
		return 0;
}//expressedThree
void printNum(int a[], int l)  
{  	
	int i;   
	char string[10];  
	for(i=0;i<l;i++) {   
		itoa(a[i],string,10);  
		if (strlen(string)==1)  
			printf("00");  
		if (strlen(string)==2)  
			printf("0");  
		printf("%s",string);
	}  
}
int multiply(int a[], int b[], int la, int lb)
{
	int p, q, t, ma, mi, i, j;
	unsigned int c, d;
	int k[MAXBit] = {0};
	if(la<lb) 								//如果被乘数长度小于乘数，则交换被乘数与乘数 
	{  
		p=lb;   
		for (q=0;q<p;q++) 					//交换被乘数与乘数 
		t=a[q],a[q]=b[q],b[q]=t;   
		t=la,la=lb,lb=t; 					//交换被乘数的长度与乘数的长度 
	}
	c=d=0; 									//清空累加变量，其中 C 用于累加斜线间的数，d 用作进位标志 
	for(i=la+lb-2;i>=0;i--) 				//累加斜线间的数，i为横纵坐标之和 
	{  
		c=d; 								//将前一位的进位标志存入累加变量 c 
		ma=max(0,i-la+1,i-lb+1);		 	//求累加的下限 
		mi=(i>la-1)?(la-1):i; 				//求累加的上限  
		for(j=ma;j<=mi;j++)					//计算出横纵坐标之和为i的单元内的数,并累加到 C 中 
			c+=(long)a[j]*b[i-j];
		d=c/1000; 							//求进位标志 
		if(c>999)  
			c%=1000; 						//取 c 的末三位 
		k[i+2]=c; 							//保存至表示乘积的数组 k[] 
	}
	k[i + 2] = d % 1000;
	k[i + 1] = d / 1000;
	i = 0;
	while(k[i] == 0)
		i++;
	c = i;
	for(j = 0; i <= la + lb; i++, j++)
		a[j] = k[i];
	return (la + lb + 1 - c);
}//multiply
int GetN(int N[])
{	//input a number, end of a '\n'
	//把输入的整型数从低位起，每三位为一份存于数组（高位在前），
	//最后不足三位也算一份，返回份数
	int i = 0, j, k, bit, len;
	char ch;
	while((ch = getchar()) != '\n')
	{
		N[i] = ch - '0';
		i++;
	}
	bit = i;
	ch = bit % 3;
	if(ch == 0){
		len = bit / 3;
		i = 0;
		j = 0;
	}
	else{
		len = bit / 3 + 1;
		if(ch == 2){
			N[0] = N[0] * 10 + N[1];
			i = 1;
			j = 2;
		}
		else
			i = j = 1;
	}
	for(; i < len && j < bit; i++){
		N[i] = N[j] * 100 + N[j + 1] * 10 + N[j + 2];
		j += 3;
	}
	return len;
}//GetN
int max(int a,int b,int c)
{  
	int d;  
	d=(a>b)?a:b;  
	return (d>c)?d:c;  
} 