#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *x, int *y)
{
   int temp = *x;    /* save the value at address x */
   *x = *y;      /* put y into x */
   *y = temp;    /* put temp into y */
}

void print(int arr[])
{
    int i;
    for(i=0;i<1000;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int partition(int arr[],int p,int r)
{
    int pivot = arr[r]; // last item is the pivot
    int i,j;
    i=p-1 ;
    for(j=p;j<=r-1;j++)
    {
       if(arr[j] <= pivot)
       {
          i++;
 	  swap(&arr[i],&arr[j]);
       }
    }
     swap(&arr[i+1],&arr[r]);
    return(i+1);
}

void quicksort(int arr[],int p,int r) // arr[p...r]
{
  print(arr);
  if(p<r)
  {
	int q = partition(arr,p,r);
    quicksort(arr,p,q-1);
  	quicksort(arr,q+1,r);
  }
}
int main(int argc, char const *argv[])
{
    srand(time(0));
    int arr[1000],i,j,q;
    for(i=0;i<1000;i++)
    {
	arr[i] = rand()%(1000);
    }
    quicksort(arr,0,999);
    print(arr);
    return 0;
}
