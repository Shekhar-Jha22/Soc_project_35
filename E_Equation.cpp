#include<bits/stdc++.h>
using namespace std;

int main(){
    double c;
    cin>>c;

    double l=0,r=1e5;
    
    while(r-l>=1e-6){
        double mid=(l+r)/2;

        if(mid*mid+sqrt(mid)>=c)r=mid;
        else l=mid;
    }
    cout << fixed << setprecision(10) << l << endl;

}