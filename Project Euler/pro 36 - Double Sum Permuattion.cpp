#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

bool palin(char *s){
    int i,j;
    for (i=0, j=strlen(s)-1; i<j; i++, j-- ){
        if (s[i]!=s[j]) return false;
    }
    return true;
}

int main()
{
    int i;
    long int sum=0;

    char a[50], temp[10];

    for (i=1; i<1000000; i++) {

        itoa(i,temp,10);

        if (palin(temp)) {
            itoa(i,a,2);

            if (palin(a)) {
                cout<<i<<"  "<<a<<endl;
                sum += i;
            }
        }
    }

    cout<<sum;
}
