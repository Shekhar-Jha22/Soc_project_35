#include<bits/stdc++.h>
using namespace std;

class segtree{
    int n;
    vector<int>v;
    vector<int>arr;
    public:
    segtree(int n,vector<int>v1){
        n=n;
        int i=0;
        while((1<<i)<n)i++;

        v=new vector<int>(2*(1<<i),0);
        arr=v1;
    }

    void set(int i,int val){
        set(i,val,1,0,n-1);
    }

    void set(int i, int val, int k, int x, int y) {
        if (x == y) {
            v[k] = val;
            arr[i] = val;
        } else {
            int mid = (x + y) / 2;
            if (i <= mid)
                set(i, val, 2 * k, x, mid);
            else
                set(i, val, 2 * k + 1, mid + 1, y);
            v[k] = v[2 * k] + v[2 * k + 1];
        }
    }

    int sum(int l,int r){
        return sum(int l,int r,int k,int x,int y);
    }
    int sum(int l,int r,int k,int x,int y){
        if(r<x || y<l)return 0;
        else if(r>=x && y>=l)return v[k];
        else return sum(l,r,2*k,x,(x+y)/2)+sum(l,r,2*k+1,(x+y)/2+1,y);
    }
}