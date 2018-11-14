#include<iostream>
using namespace std;
int main()
{
    unsigned long number,i, count=0,max=0,startMax=0;
    for(i=999999; i>2; i--) {
        number=i;
        while(number!=1) {
            count++;
            if(number%2==0) {
                number=number/2;
            }
            else {
                number= (number*3)+1;
            }
        }
        count++;
        if(count>max) {
            max=count;
            startMax=i;
        }
        count=0;
    }
    cout<<max<<" starting with "<<startMax<<endl;
}
