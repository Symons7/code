/*************************************************************************
	> File Name: katalan.c
	> Author: simon_5s
	> Mail:  simon_5s@gmail.com
	> Created Time: Mon 10 Feb 2014 02:15:22 PM HKT
 ************************************************************************/

#include<stdio.h>

long int katalan(int n)
{
	int i, j, r;
	long int c[n+1];

	if(n < 3)
		return n;

	c[0] = 1;
	c[1] = 1;
	c[2] = 2;

	for(i = 3; i < n+1; i ++)
	{
		r = 0;
		for(j = 0; j < i; j ++)
		{
			r = r + c[j]*c[i-1-j];
		}
		c[i] = r;
	}

	return c[n];
}

void main()
{
	int n=-1;
	long int result;

	while (n < 0 || n > 20)
	{
		printf("\nInput the number:(1-20)");
		scanf("%d", &n);
	}

	result = katalan(n);
	printf("Katalan C(%d)=%ld\n", n, result);
}
