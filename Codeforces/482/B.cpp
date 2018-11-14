#include<iostream>
using namespace std;

int index(char c) {
    if(c>='A' && c<='Z') return c - 'A';
    else return c-'a';
}

int main()
{
    long n;
    cin>>n;
    string ku, sh, ka;
    cin>>ku>>sh>>ka;

    bool kur = false, shi = false, kat = false;

    int a[52], b[52], c[52];
    long ma=-1, mb=-1, mc=-1;
    for(int i=0; i<52; i++)
    {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }

    long len = ku.length();

    for(int i=0; i<len; i++)
    {
        a[index(ku[i])]++;
        if (a[index(ku[i])] > ma) ma = a[index(ku[i])];
        b[index(sh[i])]++;
        if (b[index(sh[i])] > mb) mb = b[index(sh[i])];
        c[index(ka[i])]++;
        if (c[index(ka[i])] > mc) mc = c[index(ka[i])];
    }

    //cout<<ma<<" "<<mb<<" "<<mc<<endl;
    long mx = max(max(ma, mb), mc);
    if (mx == ma) kur = true;
    if (mx == mb) shi = true;
    if (mx == mc) kat = true;

    if(len - ma <= n)
        kur = true;
    if(len - mb <= n)
        shi = true;
    if(len - mc <= n)
        kat = true;

    if (kur + shi + kat >= 2)
    {
        cout<<"Draw";
    }
    else
    {
        if(kur)
            cout<<"Kuro";
        else if(shi)
            cout<<"Shiro";
        else if(kat)
            cout<<"Katie";
    }
    return  0;
}
