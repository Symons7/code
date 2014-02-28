/*************************************************************************
	> File Name: bag.c
	> Author: simon_5s
	> Mail:  simon_5s@gmail.com
	> Created Time: Mon 10 Feb 2014 03:56:14 PM HKT
 ************************************************************************/

#include<stdio.h>

void main()
{
	int bagMaxWeight=5;
	int itemNumber=4;
	int weightOfItem[4]={2, 1, 3, 2};
	int valueOfItem[4]={12, 10, 20, 15};
	int maxValue;

	int i, j;
	int value[5][6];
	int temp;

	for(i=0; i<itemNumber+1; i++)
	{
		for(j=0; j<bagMaxWeight+1; j++)
		{
			if(i == 0 || j == 0)
				value[i][j] = 0;
			else
				
			if(j < weightOfItem[i-1])
				value[i][j] = value[i-1][j];
			else
			{
				temp = value[i-1][j-weightOfItem[i-1]]+valueOfItem[i-1];
				if(temp > value[i-1][j])
					value[i][j]=temp;
				else
					value[i][j]=value[i-1][j];
			}
		}
	}

	for(i=0; i<=itemNumber; i++)
	{
		for(j=0; j<=bagMaxWeight; j++)
			printf("%4d ", value[i][j]);
		printf("\n");
	}
}

