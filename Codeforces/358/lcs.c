#include<stdio.h>

int lcs(char *a, char *b, int la, int lb,int i, int j)
{
   // printf("%d %d\n", i , j);

    if(i==la || j==lb) return;

    if(a[i] == b[j])
    {
        printf("%c", a[i]);
        lcs(a,b,la,lb,i+1, j+1);
    }
    else {
        lcs(a,b,la,lb,i+1,j);
        lcs(a,b,la,lb,i,j+1);
    }
}

int main()
{
    char a[] = "ABCDE", b[] = "DACACBE";

    int la = 5, lb = 7;

    lcs(a,b,la,lb,0,0);
}
