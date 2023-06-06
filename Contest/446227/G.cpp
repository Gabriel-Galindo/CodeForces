#include <bits/stdc++.h>

using namespace std;

int main(){
    int v[3],n,aux,a,b;
    v[0]=0,v[1]=1,v[2]=0;
    cin>>n;
    while(n--){
        cin>>a>>b;
        aux=v[a-1];
        v[a-1]=v[b-1];
        v[b-1]=aux;
    }
    for(int i=0;i<3;i++){
        if(v[i]) cout<<i+1<<"\n";
    }
    return 0;
}