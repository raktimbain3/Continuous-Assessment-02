#include<stdio.h>
float CelsiusToFahrenheit(float c);
int main()
{   int n;
    char cond;
    do
    {
       while(1)
       {
           printf("Enter number of temperatures (1-10):");
           scanf("%d",&n);
           if( n<1 || n>10 )
           {
            printf("Invalid Operation!\n");
            continue;
           }
           else { break; }
       }
        
       float temp[n];
       for( int i=0; i<n; i++ )
       {
           printf("Enter temperature %d (Celsius):",i+1);
           scanf("%f",&temp[i]);
       }
   
       printf("\n=== Temperature Conversions === \n");
       printf("\nCelsius\tFahrenheit\n");
   
       for( int i=0; i<n; i++)
       {
           printf("%.2f\t%.2f\n",temp[i],CelsiusToFahrenheit( temp[i] ));
       }

       printf("Convert more? (y/n):");
       scanf(" %c",&cond);
    } while (cond=='Y' || cond=='y');
    
    
}
float CelsiusToFahrenheit ( float c )
{
    return c*9/5 + 32;
}