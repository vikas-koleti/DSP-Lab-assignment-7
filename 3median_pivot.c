#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int arr[100000000];
int medianThree(int a, int b, int c) {
    if ((a > b) ^ (a > c)) 
        return a;
    else if ((b < a) ^ (b < c)) 
        return b;
    else
        return c;
}
int partition ( int arr[],int l ,int r) {
    int i = l + 1;
    int m=l+r/2;
    int swap;
    int val=medianThree(arr[l],arr[m],arr[r]);
    //printf("\nelements are %d  %d  %d\n",arr[l],arr[m],arr[r]);
    if(val==arr[l])
    swap=l;
    else if(val==arr[m])
    swap=m;
    else
    swap=r;
    int temp=arr[swap];
    arr[swap]=arr[l];
    arr[l]=temp;
    int piv = arr[l] ;  
	int j;          //make the first element as pivot element.
    for(j =l + 1; j <= r ; j++ )  {
    /*rearrange the array by putting elements which are less than pivot
       on one side and which are greater that on other. */
          if ( arr[ j ] < piv) {
                 int temp=arr[i];
   				arr[i]=arr[j];
   				arr[j]=temp;
            	i += 1;
        }
   }
   temp=arr[l];
   arr[l]=arr[i-1];
   arr[i-1]=temp;
   		 //put the pivot element in its proper place.
   return i-1;                      //return the position of the pivot
}
void quick_sort ( int arr[ ] ,int l , int r ) {
   if( l < r ) {
        //stores the position of pivot element
         int piv_pos = partition (arr,l , r ) ;     
         quick_sort (arr,l , piv_pos -1);    //sorts the left side of pivot.
         quick_sort ( arr,piv_pos +1 , r) ; //sorts the right side of pivot.
   }
}
void display(int arr[],int s){
	quick_sort(arr, 0,s-1);
}
int main(){ 
	int s;
  	printf("Enter the size: ");
  	if(scanf("%d",&s)==1){
  	if(s<=0){
  		printf("\nInvalid size given\n\n");
  		exit(0);
	  }
  //int arr[s];
  	int i=0;
  	int max=s;
  	int temp;
  	for(i=0;i<s;i++){
  	arr[i]=i+1;
  	}
  //using rand() function,making a array contains random integers and calculating the time taken.
  	for (i = 0; i < s; i++)  
    {  
    int j=i+rand()%(s-i);
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t; 
	}
	printf("\nGiven random integers are: \n");
	for(i=0;i<s;i++){	
	printf("%d ",arr[i]);
    }
  	clock_t t;
    t = clock();
    display(arr,s);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nRandom elements after sorted : \n");
    for(i=0;i<s;i++)
    printf("%d ",arr[i]);
    printf("\ntime taken for random numbers is %f\n\n", time_taken); 
    //inserting sorted numbers in to the array and calculating the time taken
    printf("\nGiven sorted numbers are: \n");
    for(i=0;i<s;i++){
    	arr[i]=i+1;
    	printf("%d ",arr[i]);
	}
	printf("\n");
    t = clock();
    display(arr,s);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Sorted array is: \n");
    for(i=0;i<s;i++){
    	printf("%d ",arr[i]);
	}
    printf("\ntime taken for sorted numbers  is %f\n\n", time_taken);
    
    //making an array as almost sorted and calculating time taken to sort.
    int num=s/100;
    for (i = 0; i < num; i++)  
    {  
    int j=i+rand()%(s-i);
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t; 
	}
	printf("Given almost sorted elements are:\n");
    for(i=0;i<s;i++)
    printf("%d ",arr[i]);
    printf("\n");
    t = clock();
    display(arr,s);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Elements after sorted:\n");
    for(i=0;i<s;i++)
    printf("%d ",arr[i]);
    printf("\ntime taken for almost sorted numbers  is %f\n\n", time_taken);
  	}
  	else{
  	printf("\nInvalid size given\n\n");
  	exit(0);
  
  	}	
}
