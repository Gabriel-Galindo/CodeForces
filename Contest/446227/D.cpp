#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,aux,total=0;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>aux;
        total+=aux;//guarda todos os resultados anteriores para descobrir em quem cairia
    }
    for(int i=0;i<n;i++){
        int res=(n-(total%n)+i)%n;//calcula quanto tem que ser o valor posto para chegar em i
        if(res>20) cout<<"-1\n";//se for impossivel imprime impossivel
        else cout<<res<<"\n";//se for possivel imprime o numero
    }
    return 0;
}
