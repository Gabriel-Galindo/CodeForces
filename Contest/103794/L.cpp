#include <bits/stdc++.h>

using namespace std;

int main(){
    int linhas,linhaAtual=1,r=0,descendo=1;
    char s[2005];
    cin>>s;
    cin>>linhas;
    //essa questao e separada em tres casos
    if(linhas==1) cout<<s<<"\n";//quando so tem uma linha a matriz a solucao e a entrada
    else if(linhas==2){//quando tem duas linhas
        char resposta[strlen(s)+1];
        resposta[strlen(s)]='\0';
        for(int i=0;i<strlen(s);i++){
            if(linhaAtual==1){
                if(r>=strlen(s)) r=linhaAtual++;//guarda o final da primeira linha e onde botar as letras da segunda linha
                else{
                    resposta[r]=s[i];
                    r+=2;//sempre pula um espaco
                }
            }
            if(linhaAtual!=1){
                resposta[r]=s[i];
                r+=2;//sempre pula um espaco
            }
        }
        cout<<resposta<<"\n";
    }else{//todos os outros casos
        char resposta[strlen(s)+1];
        resposta[strlen(s)]='\0';
        for(int i=0;i<strlen(s);i++){
            if(linhaAtual==1){//a primeira e ultima linha tem espacamento igual sempre
                if(r>=strlen(s)){
                    r=linhaAtual++;//troca de linha e guarda onde da resposta botar as letras
                }else{
                    resposta[r]=s[i];
                    r+=2*(linhas-1);//calcula onde botar a proxima letra da linha
                }
            }
            if(linhaAtual!=1&&linhaAtual!=linhas){//linhas com espacamento variavel
                resposta[r]=s[i];
                if(descendo){
                    r+=2*(linhas-linhaAtual);//se for descendo calcula a distancia pra proxima letra baseando nisso
                    descendo=0;//agora esta subindo
                }else{
                    r+=2*(linhaAtual-1);//se for subindo calcula a distancia baseado nisso
                    descendo=1;//agora esta descendo
                }
                if(r>=strlen(s)){
                    descendo=1;//sempre comeca descendo
                    r=linhaAtual++;//muda de linha e ajusta onde botar a letra
                }
            }
            if(linhaAtual==linhas){//a primeira e ultima linha tem espacamento igual sempre separado para nao dar erro quando linhas for igual a dois
                if(r>=strlen(s)){
                    r=linhaAtual++;//troca de linha e guarda onde da resposta botar as letras
                }else{
                    resposta[r]=s[i];
                    r+=2*(linhas-1);//calcula onde botar a proxima letra da linha
                }
            }
        }
        cout<<resposta<<"\n";
    }
    return 0;
}