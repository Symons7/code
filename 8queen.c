/*************************************************************************
	> File Name: 8queen.c
	> Author: simon_5s
	> Mail:  simon_5s@gmail.com
	> Created Time: Sat 08 Feb 2014 03:01:25 PM HKT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool valid(int p[], int i, int j, int number)
{
	int c;

	for(c=0; c<number; c++)
	{
		if(p[c] == j || abs(c - i) == abs(p[c] - j))
			return false;
	}

	return true;
}

void print_result(int p[], int number)
{
	int i;
	for (i=0; i<number; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}

int queen(int number)
{
	int pQueen[number];
	int count;
	int i, j;

	memset(pQueen, -1000, sizeof(pQueen));

	i=j=0;
	count = 0;

	while(i < number && i >= 0)
	{
		while(j < number)
		{
			if(valid(pQueen, i, j, number))
			{
				pQueen[i] = j;
				if(i == number -1)
				{
					print_result(pQueen, number);
					count ++;
					pQueen[i] = -1000;
				}
				else
					break;
			}
			j ++;
		}
		if(j != number)
		{
			i ++;
			j = 0;
		}
		else
		{
			i --;
			if(i >= 0)
			{
				j = pQueen[i] + 1;
				pQueen[i] = -1000;
			}
		}
	}

	return count;
}

void main()
{
	int number=0, result;

	while (number < 4 || number > 10)
	{
		printf("\nHow many queens?(4-10)");
		scanf("%d", &number);
	}

	result = queen(number);
	printf("There're %d results in total for %d queens.\n", result, number);
}

