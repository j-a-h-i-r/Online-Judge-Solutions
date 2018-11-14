#include<stdio.h>

char grade(float n) {
    if(n>=90.0) return 'A';
    else if(n>=80.0) return 'B';
    else if(n>=70.0) return 'C';
    else if(n>=60.0) return 'D';
    else return 'F';
}

int main()
{
    int t, c = 0;
    scanf("%d", &t);
    while(t--) {
        int fr, se, fi, at, ct[3], i;
        scanf("%d%d%d%d", &fr, &se, &fi, &at);
        for(i=0; i<3; i++) {
            scanf("%d", &ct[i]);
        }
        int min = ct[0];

        for(i=1; i<3; i++) {
            if(ct[i] < min) min = ct[i];
        }
        float total = (float)fr+se+fi+at+((ct[0]+ct[1]+ct[2]-min)/2.0);

        printf("Case %d: %c\n", ++c, grade(total));
    }
    return 0;
}
