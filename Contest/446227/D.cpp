#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,aux,total=0;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>aux;
        total+=aux;
    }
    for(int i=0;i<n;i++){
        int res=(n-(total%n)+i)%n;
        if(res>20) cout<<"-1\n";
        else cout<<res<<"\n";
    }
    return 0;
}