#include <stdio.h>
#include <string.h>
#include <math.h>
char F[40][7][41], Num[41];
int N, k;
void cpy_num(char s[], char d[], int s_s, int s_e, int d_s, int d_len)
{	//copy number s[s_e...s_e] to d[d_s...]
	int i, j;
	for(i = s_s, j = d_s; i <= s_e && j < d_len; i++, j++)
		d[j] = s[i];
	d[j] = '\0';
}
int s_to_num(int d[], char s[])
{	//translate the number from string s[] to int d[], and 3 chars to 1 int
	int len_s, len_d, i, j;
	len_s = strlen(s);
	len_d = len_s / 3 + (((len_s % 3) == 0) ? 0 : 1);
	for(i = len_d - 1, j = len_s - 1; j >= 2; i--, j -= 3)
		d[i] = s[j] - '0' + (s[j - 1] - '0') * 10 + (s[j - 2] - '0') * 100;
	if(j >= 0)
		d[i] = s[j] - '0' + ((j == 1) ? (s[j - 1] - '0') * 10 : 0);
	return len_d;
}
int max(int a, int b, int c)
{
	int d = (a > b) ? a : b;
	return ((d > c) ? d : c);
}
void Mul(char F_uj[], int start, int end, char result[])
{	//Multiplied number F_uj with Num[start...end], save in result, all number is in the strings
	char temp[41];
	int a[40 / 3 + 1], b[40 / 3 + 1], la, lb, rs[80 / 3 + 2], lrs;
	int p, q, t, c, d, i, j, ma, mi;
	long e;
	cpy_num(Num, temp, start, end, 0, sizeof(temp));
	/*
	printf("1: %s * %s", F_uj, temp);
//	*/
	la = s_to_num(a, F_uj);
	lb = s_to_num(b, temp);
	/*
	for(i = 0; i < la; i++)
		printf("%d", a[i]);
	printf(" * ");
	for(i = 0; i < lb; i++)
		printf("%d", b[i]);
	printf("\n");
	printf("la = %d, lb = %d\n", la, lb);
//	*/
	if(la < lb)
	{
		p = lb;
		for(q = 0; q < p; q++)
		{
			t = a[q];
			a[q] = b[q];
			b[q] = t;
		}
		t = la;
		la = lb;
		lb = t;
	}
	/*
	for(i = 0; i < la; i++)
		printf("%d", a[i]);
	printf(" * ");
	for(i = 0; i < lb; i++)
		printf("%d", b[i]);
	printf("\n");
	printf("la = %d, lb = %d\n", la, lb);
//	*/
	c = d = 0;
		/*
		printf("i     c     d\n");
//		*/
	for(i = la + lb - 2; i >= 0; i--)
	{
		c = d;
		ma = max(0, i - la + 1, i - lb + 1);
		mi = (la - 1 > i) ? i : (la - 1);
		/*
		printf("\n\nma: %d, mi: %d\n", ma, mi);
//		*/		
		for(j = ma; j <= mi; j++)
		{
			c += a[j] * b[i - j];
			/*
			printf("%-5d %-5d %-5d\n", c, a[j], b[i - j]);
//			*/
		}
		d = c / 1000;
		c = c % 1000;
		rs[i] = c;
		/*
		printf("%-5d %-5d %-5d\n", i, c, d);
//		*/
	}
	/*
	printf("rs: ");
	if(d != 0)
		printf("%d", d);
	for(i = 0; i <= la + lb - 2; i++)
		printf("%d ", rs[i]);
	printf("\n");
//	*/
	/*
	d = 0;
	rs[0] = 1;
	rs[1] = 0;
	la = lb = 1;
	la = 2;
//	*/
	e = rs[0] + 1000 * d;
	j = 0;
	if(e > 0)
	{
		for(i = 9; i >= 0 && e < (int)pow(10, i); i--)
			;
		for( ; i >= 0; i--, j++)
		{
			result[j] = e / (int)pow(10, i) % 10 + '0';
			e %= (long)pow(10, i);
			/*
			printf("%c", result[j]);
//			*/
		}			
	}
	result[j] = '\0';
	/*
	printf("\n");
	puts(result);
	printf("*\n");
//	*/
	for(i = 1; i <= la + lb - 2; i++, j += 3)
	{
		result[j] = rs[i] / 100 + '0';
		result[j + 1] = (rs[i] % 100) / 10 + '0';
		result[j + 2] = rs[i] % 10 + '0';
	}
	if(i != 1 && j >= 2)
		result[j] = '\0';
	else if(i == 1 && d == 0 && c == 0 && rs[0] == 0)
		strcpy(result, "0");
	/*
//	printf("\n%d, %d, %d, %d, %d\n", i, j, d, c, rs[0]);
	printf(" = %s\n\n", result);
//	*/
}
int numcmp(char a[], char b[])
{	//compare number a with number b, both number is in the strings
	int lena, lenb, i;
	lena = strlen(a);
	lenb = strlen(b);
	if(lena < lenb)
		return -1;
	else if(lena > lenb)
		return 1;
	else{
		for(i = 0; i < lena; i++)
		{
			if(a[i] > b[i])
				return 1;
			else if(b[i] > a[i])
				return -1;
		}
	}
}
int main()
{
	int i, K, u, j;
	char max[100], temp[100], t[100];
//	scanf("%d%d", &N, &k);
//	scanf("%s", Num);
//	/*
	strcpy(Num, "7777777777");
	N = 10;
	k = 5;
//	*/
	for(i = 0; i < N; i++)
		cpy_num(Num, F[i][1], 0, i, 0, sizeof(F[i][1]));
	/*
	for(i = 0; i < N; i++)
		puts(F[i][1]);
	printf("%s\n\n\n", F[1][1]);
//	*/
	/*
	strcpy(Num, "1");
	strcpy(F[1][1], "1000");
	Mul(F[1][1], 0, strlen(Num) - 1, temp);
	printf("\n\n%s * %s = %s\n", Num, F[1][1], temp);
//	*/
	for(K = 2; K <= k + 1; K++)
	{
//		/*
		printf("F: ");
		for(j = 0; j < N; j++)
			printf("%s, ", F[j][K - 1]);
		putchar('\n');
//		*/
		for(i = K - 1; i < N; i++)
		{
			max[0] = '0';
			max[1] = '\0';
			for(u = K - 2; u <= i - 1; u++)
			{
				Mul(F[u][K - 1], u+1, i, temp);
//				/*
				printf("%s * ", F[u][K - 1]);
				for(j = u + 1; j <= i; j++)
					printf("%c", Num[j]);
				printf(" = %s\n", temp);
//				*/
				if(1 == numcmp(temp, max))
				{
					strcpy(t, temp);
					strcpy(temp, max);
					strcpy(max, t);
				}
			}
			strcpy(F[i][K], max);
//			/*
			printf("\n***********\n");
			printf("F[%d][%d]: %s", i, K, max);
			printf("\n***********\n");
//			*/
		}
	}
	printf("%s", F[N - 1][k + 1]);
	return 0;
}
