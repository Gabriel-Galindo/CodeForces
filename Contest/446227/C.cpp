#include <bits/stdc++.h>

using namespace std;

set<int> s;
int fprimos[100005];

void crivo(){
    fprimos[0]=fprimos[1]=1;
    for(int i=2;i<100005;i++){
        if(fprimos[i]==0){
            fprimos[i]=i;
            if((long long)i*i<100005){
                for(int j=i*i;j<100005;j+=i) fprimos[j]=i;
            }
        }
    }
}

void fatores(int num){
    if(num==1) return;
    s.insert(fprimos[num]);//guarda todos os fatores primos dos denominadores
    fatores(num/fprimos[num]);
    return;
}

int main(){
    int n,a,b;
    cin>>n;
    memset(fprimos,0,sizeof(fprimos));
    crivo();
    while(n--){
        int aux;
        cin>>a>>b;
        //o numerador nao importa, a unica coisa que importa e o denominador na sua forma mais basica
        aux=b/__gcd(b%a,a);
        fatores(aux);
    }
    if(s.empty()){//se todos os denominadores forem 1 nao importa a base logo imprime a menor aceitada
        cout<<"2\n";
    }else{
        set<int>::iterator it;
        long long res=1;
        for(it=s.begin();it!=s.end();it++){
            res=(res*(*it))%998244353;//multiplica todos os fatores primos diferentes de todos os denominadores
        }
        cout<<res<<"\n";
    }
    return 0;
}
