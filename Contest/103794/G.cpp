#include <bits/stdc++.h>

using namespace std;

int main(){
    int qnt=0,n,puloMax,pulando;
    char s[500005];
    cin>>n;
    cin>>s;
    puloMax=1;
    pulando=0;
    if(s[0]=='.') qnt=-1;//se comecar com buraco a fase sempre vai ser impossivel
    for(int i=1;i<n;i++){
        if(qnt!=-1){//se for impossivel nao adianta mais calcular
            if(pulando){//ve se o bario esta pulando ou nao
                if(s[i]=='x'){//caso seja possivel aterissar aterissa e ajusta as variaveis
                    pulando=0;
                    puloMax=1;
                }else{
                    puloMax--;//ajusta a distancia do pulo
                    if(puloMax<0) qnt=-1;//classifica como impossivel quando o pulo e maior do que o pulo maximo
                }
            }
            else{
                if(s[i]=='.'){
                    pulando=1;//ajusta para pulo
                    puloMax--;//ja tira um de carga
                    qnt++;//aumenta a quantidade de pulos dados
                }else puloMax++;//ajusta o pulo maximo enquanto for bloco solido
            }
        }
    }
    cout<<qnt<<"\n";
    return 0;
}