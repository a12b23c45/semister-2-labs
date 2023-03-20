 //max min element in array 
 #include<stdio.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
        
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
   
     printf("The minimum array element is %d\n.",a[n-1]);
    printf("The maximum array element is %d.",a[0]);
}