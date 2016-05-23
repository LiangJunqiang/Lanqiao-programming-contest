#include <stdio.h>
#include <string.h>
#define MAXMbit	20
void change(char m[], int style)
{	//各位字符与数字互换 
	int i, go = style * '0';
	for(i = 0; (style == -1 && m[i] != '\0') || (style == 1 && m[i] != (-1*'0')); i++)
		m[i] += go;
	m[i] += go;
}
void reduceHex(char m[])
{	//把 A ~ F 转换为 '0'+10 ~ '0'+15 
	int i = strlen(m) - 1;
	for(; i >= 0; i--)
		if(m[i] >= 'A' && m[i] <= 'F')
			m[i] = m[i] - 'A' + 10 + '0';
}
int IsHW(char m[])
{	//判断是否回文串 
	int i, len = strlen(m);
	for(i = 0; i < len / 2; i++)
		if(m[i] != m[len - i - 1])
			return 0;
	return 1;
}
int testStep(int n, char m[])
{
	int len, step = 0, i, d;
	char temp[MAXMbit];
	if(n == 16)
		reduceHex(m);
	while(1){
		if(IsHW(m))
			break;
		if(step >= 30)
			return -1; 
		strcpy(temp, m);
		len = strlen(m);
		change(m, -1);
		change(temp, -1);
		step++;
		d = 0;
		for(i = len; i > 0; i--)
		{
			m[i] = temp[i - 1] + temp[len - i] + d;
			d = m[i] / n;
			m[i] %= n;
		}
		if(d == 0){
			for(i = 0; i < len; i++)
				m[i] = m[i + 1];
			m[i] = -1 * '0';
		}else{
			m[0] = d;
			m[len + 1] = -1 * '0';
		}
		change(m, 1);
	}
	return step;
}
int main()
{
	int N, step;
	char M[10];
	scanf("%d", &N);
	getchar();
	scanf("%s", M);
	step = testStep(N, M);
	if(step != -1)
		printf("STEP=%d\n", step);
	else
		printf("Impossible!\n");
	return 0;
}
