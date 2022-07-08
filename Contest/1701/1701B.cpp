#include <iostream>
#include <cstring>

using namespace std;

int vet[200000];

int main(){
    int casos,n,ini=0,i,d,j;
    memset(vet,0,sizeof(vet));
    cin>>casos;
    while(casos--){
        cin>>n;
        d=1;
        i=3;
        cout<<"2"<<endl;
        while(d<=n){
            if(d!=1) cout<<" ";
            cout<<d;
            vet[d+ini-1]=1;
            d=d*2;
            if(d>n){
                while(i<=n){
                    if(!vet[i+ini-1]){d=i;break;}
                    i+=2;
                }
                if(i>n) break;
            }
        }
        ini+=n;
        cout<<endl;
    }
    return 0;
}