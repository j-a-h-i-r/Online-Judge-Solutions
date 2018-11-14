#include<cstdio>
#include<map>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);
    getchar();

    while(t--){

        map<char, int> paper;

        int c, money=0, s, line, cent ;
        char ch;

        scanf("%d", &c);
        //cout<<c<<"\n";
        getchar();

        while(c--){
            scanf("%c %d", &ch, &cent);
            getchar();
            paper[ch] = cent;
            //cout<<ch<<" "<<paper[ch]<<"\n";
        }

        scanf("%d", &line);
        getchar();
        //cout<<line<<"\n";

        while(line--){
            char l[10020];
            fgets(l, 10010, stdin);

            //cout<<l;

            for(int i=0; l[i]!='\n'&&l[i]!='\0'; i++)
            {
                if( paper.find(l[i])!=paper.end() )
                {
                    money+=paper[ l[i] ];
                }
            }
            //cout<<"sf";
        }

        int dollar = money/100;
        cent = money%100;
        printf("%d.", dollar);
        if(cent<10) printf("0%d$\n", cent);
        else printf("%d$\n", cent);
    }
    return 0;
}
