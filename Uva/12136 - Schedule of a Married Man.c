#include<stdio.h>
int main()
{
    int t, cs = 0;
    scanf("%d", &t);
    getchar();
    while( t-- )
    {
        char s1[20], s2[20];
        fgets(s1, 18, stdin);
        fgets(s2, 18, stdin);
        int wsh,wsm, weh,wem;
        int msh,msm, meh,mem;

        sscanf(s1,"%d:%d %d:%d",&wsh,&wsm, &weh,&wem);
        sscanf(s2,"%d:%d %d:%d",&msh,&msm, &meh,&mem);

        if( meh < wsh || (meh==wsh && mem < wsm)  ) printf("Case %d: Hits Meeting\n", ++cs);
        else if( msh > weh || (msh==weh && msm>wem) ) printf("Case %d: Hits Meeting\n", ++cs);
        else printf("Case %d: Mrs Meeting\n", ++cs);
    }
    return 0;
}
