#include <bits/stdc++.h>

using namespace std;

int memo[1<<20];

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
        int bitShift=converteChar(s[i]);
        at^=(1<<bitShift);
        h=1;
        for(j=0;j<20;j++){
            res+=memo[at^h];
            h=h<<1;
        }
        res+=memo[at]++;
    }
    printf("%lld\n",res);
    return 0;
}