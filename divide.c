/*************************************************************************
	> File Name: divide.c
	> Author: simon_5s
	> Mail:  simon_5s@gmail.com
	> Created Time: Thu 13 Feb 2014 04:54:20 PM HKT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int a=0, b=0;
	int i, count, flag;
	int result[256], *hash;

	while(a <= 0 || b <= 0)
	{
		printf("\nInput a and b:");
		scanf("%d %d", &a, &b);
	}
	
	hash = (int *)malloc(sizeof(int)*b);
	memset(hash, 0, sizeof(hash));

	result[0] = a / b;
	i = a % b;
	count = 1;
	flag = 0;
	while(i != 0 && !flag)
	{
		if(hash[i] == 0)
		{
			hash[i] = count;
			i = i * 10;
			result[count] = i / b;
			i = i % b;
		}
		else
		{
			result[hash[i]] += 10;
			flag = 1;
		}
		count ++;
	}

	printf("Result is: %d", result[0]);
	if(a % b != 0)
	{
		printf(".");
		for(i = 1; i < count - 1; i ++)
		{
			if(result[i] >= 10)
				printf("(%d", result[i]-10);
			else
				printf("%d", result[i]);
		}
		if(flag)
			printf(")");
		else
			printf("%d", result[count - 1]);
	}
	printf("\n");
	free(hash);
}
