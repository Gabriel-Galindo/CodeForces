#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int g,i,min=0,max=0,ok,atual=0;
    char frase[100010];
    cin>>g;
    cin>>frase;
    i=0;
    ok=0;
    while(i<strlen(frase)&&!ok){
        if(frase[i]=='D') atual+=g;
        else atual-=g;
        if(max<atual) max=atual;
        if(min>atual) min=atual;
        if(max-min>=360) ok=1;
        i++;
    }
    if(ok) cout<<"S"<<endl;
    else cout<<"N"<<endl;
    return 0;
}