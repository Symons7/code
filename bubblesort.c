/*************************************************************************
	> File Name: sort.c
	> Author: simon_5s
	> Mail:  simon_5s@gmail.com
	> Created Time: Fri 07 Feb 2014 02:42:21 PM HKT
 ************************************************************************/

#include<stdio.h>
#include<stdbool.h>

void sort(int data[], int length)
{
	bool change;
	int i, j, temp;
	
	for(j=length; j>0; j--)
	{
		change = false;
		for(i=0; i<j-1; i++)
		{
			if(data[i]>data[i+1])
			{
				temp = data[i];
				data[i] = data[i+1];
				data[i+1] = temp;
				change = true;
			}
		}
		if(change == false)
			break;
	}

	return;
}

void main()
{
	int data[10]={4, 25, 2, 13, 11, 18, 20, 10, 11, 3};
	int i;

	sort(data, 10);

	for (i=0; i<10; i++)
		printf("%i ", data[i]);
	printf("\n");

}
