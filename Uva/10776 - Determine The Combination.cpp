#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

/***
The biggest with this problem is how to handle duplicates
To handle duplicates I need to keep track of what character I've already taken
Suppose the original string is:   "abcdde"
Now I've taken  "abcd"
Next I will try to take "abcd" again because there's 2 d's
But then I will end up with duplicate values
So I can't take 2 d's
The most important part of this is whenever I am trying to take a value which will make the combination
duplicate, the prefix of these combination will be exactly same.
This is what it looks when I see it from the backtrack view:

abc     <- prefix
    d   <- adding a new char to make it "abcd"
    ... <- other chars that don't make a duplicate combination
    ... <-  ""
    d   <- this makes a duplicate combination

So in the backtracking stack I have to find if I have taken "d" in terms of "abc"

This can be achieved by keeping a flag to mark the characters in every level of the backtrack
So when I'm in "abc" level and have taken "d" i will set "d" to taken for the level "abc"
So if I try to take it again in the same level I will know that I have already taken it
The most important part of the flag is that it must be LOCAL.
In this way each level of the backtrack (each prefix) will have it's own set of markers
and will be able to detect if a char has already been taken

**/


string s;
int r, n;
char comb[50];
bool taken[50];

void gen_comb(int id, int pos)
{
    if(id==r) {
        cout<<comb<<"\n";
        return;
    }

    bool alreadyTaken[30];

    for(int i=0; i<30; i++) {
        alreadyTaken[i] = false;
    }

    for(int i=pos; i<n; i++) {
        if(alreadyTaken[s[i]-'a']) continue;

        if (taken[i]==false) {
            taken[i] = true;
            comb[id] = s[i];
            alreadyTaken[s[i]-'a'] = true;
            gen_comb(id+1, i+1);
            taken[i] = false;
        }
    }
}

int main()
{
    while(cin>>s>>r)
    {
        for(int i=0; i<50; i++) {
            taken[i] = false;
        }

        sort(s.begin(), s.end());
        comb[r] = '\0';
        n = s.length();
        gen_comb(0, 0);
    }
    return 0;
}
