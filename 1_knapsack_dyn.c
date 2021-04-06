#include<stdio.h>
int max(int, int);

int main()
{
    int p[500] = {0}, wt[500] = {0};
    int m, n;
    int k[500][500];

    printf("\nenter the size of bag: ");
    scanf("%d",&m);
    printf("\nenter the number of items: ");
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        printf("\nenter profit of item %d: ",i);
        scanf("%d",&p[i]);
        printf("\nenter weight of item %d: ",i);
        scanf("%d",&wt[i]);
    }

    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=m; w++)
        {
            if(i==0||w==0)
             k[i][w] = 0;
            else if(wt[i]<=w)
             k[i][w] = max(p[i]+k[i-1][w-wt[i]], k[i-1][w]);
            else
             k[i][w] = k[i-1][w];
            
        }
    }

    printf("\n%d",k[n][m]);
    int i=n, j=m;
   
    while(i>0)
    {
        if(k[i][j]==k[i-1][j])
        {
            printf("\nitem %d = not selected",i);
            i=i-1;
        }
        else
        {
            printf("\nitem %d = selected",i);
            j=j-wt[i];
            i=i-1;

        }
        
    }

}
int max(int a, int b)
{
    if(a>b)
     return a;
    else
     return b;
    
}