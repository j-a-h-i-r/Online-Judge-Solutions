#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    while( scanf("%d",&n) && n!=0 )
    {
        getchar();

        int totDol = 0, totCent = 0;
        int dollar[n+1], cent[n+1];
        int i;

        for(i=0; i<n; i++) {
            char s[20];
            fgets(s, 18, stdin);
            sscanf(s,"%d.%d", &dollar[i], &cent[i]);

            totDol += dollar[i];
            totCent += totCent[i];
        }

        int dAvg = (totDol+(totCent/100))/n;
        int cAvg = (totCent%100)/n;

        double exch = 0;

        for(i=0; i<n; i++)
        {
            if ( spend[i] < avg ) exch += avg-spend[i];
        }

        printf("$%f\n", floorf(exch*100)/100 );
    }
    return 0;
}
