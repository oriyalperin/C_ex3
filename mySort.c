
#ifndef _MY_SORT_
#define _MY_SORT_
#include <stdio.h>
#define l 50


void shift_element(int* arr, int i)
{
while(arr+i>arr)
{
    *(arr+i)=*(arr+(i-1));
    i--;

}

}

void insertion_sort(int* arr , int len)
{
    for(int i=1;i<len;i++)
    {
        int j=i-1;
        
        if(*(arr+i)<*(arr+j))
        {
            while(*(arr+i)<*(arr+j)&&j>=0)
                {
                    j--;
                }
            int temp=*(arr+i);   
            shift_element((arr+j+1),i-(j+1));
            *(arr+j+1)=temp;

        }

    
    }

}

int main()
{
    int t=0;
    int nums[l];

    while (t<l)
    {
    scanf("%d",nums+t);
    t++;
    }

    insertion_sort(nums,l);
    for(int i=0;i<l-1;i++)
    {
        printf("%d,",*(nums+i));
    }
	printf("%d\n",*(nums+(l-1)));

    return 0;
}
#endif
