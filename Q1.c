#include<stdio.h>
#include<malloc.h>

void greaterThanTwo(int*,int);
int highest(int *,int,int*);

int main(int argc,char *argv[])		//get size of array by command line argument
{
	int no_elements=0,*arr=NULL,first_highest,second_highest,third_highest,flag=0,index=0;

	if(argc < 2)
		return -1;

	no_elements = atoi(argv[1]);
	arr = (int *)malloc(sizeof(int) * no_elements);
	
	while(index < no_elements)
	{
		scanf("%d",(arr+index));
		index++;
	}

	greaterThanTwo(arr,no_elements);

	return 0;
}

void greaterThanTwo(int *arr,int no_elements)
{
	int first_highest,second_highest,third_highest,index=0;

	if((no_elements < 3) || arr==NULL)
		return;
	
	first_highest = highest(arr,no_elements,NULL);
	second_highest = highest(arr,no_elements,&first_highest);
	
	while(index < no_elements)
	{
		if(arr[index] < second_highest)
		{
			printf(" %d",arr[index]);
		}
		index++;
	}
}

int highest(int *arr,int no_elements,int *no)
{
	int max=arr[0],index=1;

	while(index < no_elements)
	{
		if(no != NULL)			//find highest element smaller than *no
		{
			if((arr[index] > max) && (arr[index]< (*no)))
			{
				max = arr[index];
			}
		}
		else if(no == NULL)			//find highest element
		{
			if(arr[index] > max)
			{
				max = arr[index];
			}
		}

		index++;
	}

	return max;
}
