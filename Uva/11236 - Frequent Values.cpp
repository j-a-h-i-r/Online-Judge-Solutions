#include<bits/stdc++.h>
using namespace std;

struct data {
    int numL, countL, numR, countR, numM, countM;
    int count;
    data() {
        numL=0; countL=0; numR=0; countR=0; numM=0; countM=0;
    }
    data(int a, int b, int c, int d, int e, int f) {
        numL=a; countL=b; numR=c; countR=d; numM=e; countM=f;
    }
};

const int sz = 100001;
int arr[sz];
data tree[sz*3];

data better(int node, data a, data b) {
    data ans = data(a.numL, a.countL, b.numR, b.countR, 0, 0);
    if (a.numR == b.numL) {
        int sumTwo = a.countR + b.countL;
        // maximum of left node is greater than right node
        // and sum of edge values of two nodes
        if (a.countM > max(sumTwo, b.countM)) {
            ans.numM = a.numM;
            ans.countM = a.countM;
        }
        else if (b.countM > max(sumTwo, a.countM)) {
            ans.numM = b.numM;
            ans.countM = b.countM;
        }
        else {
            ans.numM = a.numR;
            ans.countM = sumTwo;
        }

        if (a.numL == b.numL) {
            ans.countL += b.countL;
        }
        if (a.numR == b.numR) {
            ans.countR += a.countR;
        }
    }
    else {
        if (a.countM > b.countM) {
            ans.numM = a.numM;
            ans.countM = a.countM;
        }
        else {
            ans.numM = b.numM;
            ans.countM = b.countM;
        }
    }
    return ans;
}
void build(int node, int l, int r) {
    if (l==r) {
        tree[node] = data(arr[l], 1, arr[l], 1, arr[l], 1);
        //cout<<l<<"-- "<<tree[node].numM<<"- "<<tree[node].countM<<endl;
        return;
    }
    int left = node * 2;
    int right = left + 1;
    int mid = (l+r)/2;

    build(left, l, mid);
    build(right, mid+1, r);

    int cnt = 0;

    tree[node] = better(node, tree[left], tree[right]);
    //cout<<l<<"-"<<r<<"- "<<tree[node].numM<<"- "<<tree[node].countM<<endl;
    //if (tree[node].count < cnt) tree[node] = data(arr[mid], cnt);
    //cout<<l<<"-"<<r<<"- "<<tree[node].num<<"- "<<tree[node].count<<endl;
    return;
}

data query(int node, int l, int r, int a, int b)
{
    if (a>r || b<l) {
        // irrelevent segment
        return data(100001, -100, 100001, -100, 100001, -100);
    }
    if (l>=a && r<=b) {
        // totally relevant
        return tree[node];
    }
    int left = node*2;
    int right = left + 1;
    int mid = (l+r)/2;

    data d1 = query(left, l, mid, a, b);
    data d2 = query(right, mid+1, r, a, b);
    //cout<<d1.countM<<" = "<<d2.countM<<endl;
    return better(node, d1, d2);
}

int main()
{
    int n, q, a, b;
    data ans;
    while(cin>>n) {
        if (n==0) break;
        cin>>q;

        for (int i=1; i<=n; i++) {
            cin>>arr[i];
            //cout<<"~"<<arr[i]<<endl;
        }
        build(1, 1, n);
        //cout<<"Build Passed";

        for (int i=0; i<q; i++) {
            cin>>a>>b;

            ans = query(1, 1, n, a, b);
            //cout<<ans.numM<<" "<<ans.countM<<"\n";
            cout<<ans.countM<<"\n";
        }
    }
    return 0;
}
