#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

#define SIZE_N 1000
#define SIZE_P 1000

bool flag[SIZE_N+5];
int primes[SIZE_P+5];

int seive()
{
    int i,j,total=0,val;

    for(i=2; i<=SIZE_N; i++) flag[i]=1;

    val=sqrt(SIZE_N)+1;

    for(i=2; i<val; i++)
        if(flag[i])
            for(j=i; j*i<=SIZE_N; j++)
                flag[i*j]=0;

    for(i=2; i<=SIZE_N; i++)
        if(flag[i])
            primes[total++]=i;

    return total;
}
int factors_in_factorial(int N,int p)
{
    int sum=0;

    while(N)
    {
        sum+=N/p;
        N/=p;
    }
    return sum;
}
int Trailingzero_Base_B(int N,int B)
{
    int i,ans,freq,power;

    ans=1000000000;
    for(i=0; primes[i]<=B; i++)
    {
        if(B%primes[i]==0)
        {
            freq=0;
            while(B % primes[i]==0)
            {
                freq++;
                B/=primes[i];
            }
            power=factors_in_factorial(N, primes[i]);
            ans=min(ans, power/freq);
        }
    }
    return ans;
}

long digits(int b, int n)
{
    long dig = 0;
    for(int i=1; i<=n; i++)
    {
        dig+= log(i)/log(b);
    }
    return b;
}


int main()
{
    int total=seive();
    int i,N,B,zero;

    while(scanf("%d %d",&N,&B)==2)
    {
        zero=Trailingzero_Base_B(N,B);
        long d = digits(B, N);
        printf("%d %ld\n",zero, d);
    }
    return 0;
}
