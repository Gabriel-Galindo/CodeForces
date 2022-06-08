#include <iostream>
#include <cstring>

using namespace std;

unsigned long long int vet[100001];
unsigned long long int res[100001];

unsigned long long int f(int i,int tam){
    if(tam-i==1){
        return vet[i];
    }
    if(tam-i==2){
        if(vet[i]>vet[i+1]) return vet[i];
        else return vet[i+1];
    }
    if(tam-i==3){
        if(vet[i]+vet[i+2]>vet[i+1]) return vet[i]+vet[i+2];
        else return vet[i+1];
    }
    if(res[i]==-1){
        unsigned long long int a=0,b=0;
        a=vet[i]+f(i+2,tam);
        b=vet[i+1]+f(i+3,tam);
        if(a>b) res[i]=a;
        else res[i]=b;
    }
    return res[i];
}

int main(){
    int tam,i;
    cin>>tam;
    memset(res,-1,sizeof(res));
    for(i=0;i<tam;i++){
        cin>>vet[i];
    }
    cout<<f(0,tam)<<endl;
    return 0;
}