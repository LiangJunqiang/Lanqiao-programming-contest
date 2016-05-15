#include <stdio.h>
#include <string.h>
#define MIN_INT	-2100000000
int p, k, s;
char str[10][21];
char word[6][16];
int Cnt[200][41];
int wn[201][201];

int getCnt(int a, int b)
{
	int i, j, u;
	int count;
	if(wn[a][b] <= 0)
	{
		count = 0;
		for(u = a; u <= b; u++)
		{
			for(i = 0; i < s; i++)
			{
				for(j = 0; word[i][j] != '\0' && u + j <= b && word[i][j] == str[(u + j) / 20][(u + j) % 20]; j++)
					;
				if(word[i][j] == '\0'){
					count++;
					break;
				}
			}
		}
		wn[a][b] = count;
	}
	return wn[a][b];
}

int main()
{
	
	int i, u, K, max, temp, j;
	p = 1;
	k = 3;
	/*
	strcpy(str[0], "thisisabookyouareaoh");
	s = 4;
	strcpy(word[0], "is");
	strcpy(word[1], "a");
	strcpy(word[2], "ok");
	strcpy(word[3], "sab");
//	*/
	scanf("%d%d", &p, &k);
	for(i = 0; i < p; i++)
		scanf("%s", str[i]);
	scanf("%d", &s);
	for(i = 0; i < s; i++)
		scanf("%s", word[i]);
	for(i = 0; i < p * 20; i++)
		Cnt[i][1] = getCnt(0, i);
	/*
	printf("Cnt: ");
	for(i = 0; i < p * 20; i++)
		printf("%d ", Cnt[i][1]);
	printf("\n");
//	*/
	for(K = 2; K <= k; K++)
	{
		for(i = K - 1; i < p * 20; i++)
		{
			max = MIN_INT;
			/*
			printf("temp: ");
//			*/
			for(u = K - 2; u < i; u++)
			{
				/*
				printf("%d ", temp);
//				*/
				temp = Cnt[u][K - 1] + getCnt(u + 1, i);
				max = (max < temp) ? temp : max;
			}
			Cnt[i][K] = max;
			/*
			printf("\nmax: %d\n", max);
//			*/
			/*
			printf("Cnt: ");
			for(j = 0; j < p * 20; j++)
				printf("%d ", Cnt[j][K]);
			printf("\n");
//			*/
		}
	}
	printf("%d\n", Cnt[p * 20 - 1][k]);
	return 0;
}
