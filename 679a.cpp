#include<iostream>
#include<string>
using namespace std;

int main(){
    int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    int count=0;
    for(int i=0;i<15;){
        if(count==2)break;
        cout<<primes[i]<<endl;
        fflush(stdout);
        string s;

        cin>>s;
        if(s=="yes"){
            count++;
            if(primes[i]<10)
            primes[i]=primes[i]*primes[i];
            else i++;
        }
        else ++i;
    }
    if(count<2)cout<<"prime"<<endl;
    else cout<<"composite"<<endl;
}