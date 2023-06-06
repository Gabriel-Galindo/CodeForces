#include <bits/stdc++.h>

using namespace std;

int memo[1<<20];//guarda todas a combinacoes existentes de quantidade impar(0 e par, 1 impar) de cada letra
//atualmente da TLE
int converteChar(char c){
    if(c>'y') return c-'b'-5;
    if(c>'u') return c-'b'-4;
    if(c>'o') return c-'b'-3;
    if(c>'i') return c-'b'-2;
    if(c>'e') return c-'b'-1;
    return c-'b';
}

int main(){
    int n,at=0,i,j,h;
    scanf("%d",&n);
    char s[n+5];
    scanf(" %s",s);
    memo[0]=1;
    long long res=0;
    for(i=0;i<strlen(s);i++){
        int bitShift=converteChar(s[i]);//calcula qual a string de bits correspondente com a letra
        at^=(1<<bitShift);//faz ou exclusivo com o atual para mudar a paridade da letra encontrada
        h=1;
        for(j=0;j<20;j++){
            res+=memo[at^h];//calcula se a letra j faz com que um estado encontrado previamente ocorre novamente, se sim daquele estado ao atual faz mais uma substring possivelmente palindroma
            h=h<<1;
        }
        res+=memo[at]++;//calcula se o estado atual ja ocorreu
    }
    printf("%lld\n",res);
    return 0;
}
