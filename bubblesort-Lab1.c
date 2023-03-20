 
// bubble sort (arranginf elements either in ascending or descending order)
 #include<stdio.h>
 int main(void)
 {
    int a[]={1,4,5,6,7,24,5,3,43,56};
    int length=10;
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<(length-1);j++){
            if (a[j]>a[j+1]){
                int temp =a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<length;i++)
    printf("%d ",a[i]);
 }
 