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
	int i, position, temp;
	
	temp = data[0];
	position = 0;

	if (data == NULL || length <= 1)
		return;

	for(i=1; i<length; i++)
	{
		if(data[i]<temp)
		{
			data[position] = data[i];
			position ++;
			data[i] = data[position];
			data[position] = temp;
		}
	}

	if(position > 1)
		sort(data, position);
	if(position < length - 2)
		sort(&data[position + 1], length - position - 1);
	return;
}

void main()
{
	int data[100];
	int i;

	for (i=0; i<100; i++)
		data[i]=rand() % 100;

	sort(data, 100);

	for (i=0; i<100; i++)
		printf("%i ", data[i]);
	printf("\n");

}
