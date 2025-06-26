#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
       int g;
        for(int i=0;i<2;i++){
            cout<<"digit"<<endl;
            fflush(stdout);
            cin>>g;
        }
        int jury1,jury2,jury3,jury4;

        cout<<"add -8"<<endl;
        fflush(stdout);
        cin>>jury1;

        cout<<"add -4"<<endl;
        fflush(stdout);
        cin>>jury2;

        cout<<"add -2"<<endl;
        fflush(stdout);
        cin>>jury3;

        cout<<"add -1"<<endl;
        fflush(stdout);
        cin>>jury4;
        
        int x,y;
            cout<<"add "<<n-1<<endl;
            fflush(stdout);
        cin>>x;
        
        cout<<"!"<<endl;
        fflush(stdout);
        cin>>y;
    }
}