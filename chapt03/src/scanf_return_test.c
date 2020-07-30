#include<stdio.h> 

int main() 
{ 
    int t, m; 
    printf("enter the two int value\n"); 
    while(scanf("%d %d" ,&t,&m)==1) 
        printf("the scanf read only one value "); 
    while(scanf("%d %d" ,&t,&m)==2) 
        printf("scanf read two values\n"); 
    return 0; 
}