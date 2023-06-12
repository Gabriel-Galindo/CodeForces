#include <bits/stdc++.h>

#define INF 0x3F3F3F3F

using namespace std;

int main(){
    int n,m,k,q,a,b,tempo,ma,res;
    cin>>n>>m>>k>>q;
    int mat[n][m];
    int tempoMax[n][m];
    memset(mat,INF,sizeof(mat));
    while(q--){
        cin>>a>>b>>tempo;
        mat[a-1][b-1]=tempo;
    }
    //por ser entradas relativamente pequenas forca bruta funciona
    for(int i=0;i<n;i++){//passa por cada linha
        for(int j=0;j+k<=m;j++){
            ma=0;
            for(int crise=j;crise<k+j;crise++){
                ma=max(ma,mat[i][crise]);//calcula o valor maximo para cada "linha do quadrado" 
            }
            tempoMax[i][j]=ma;//guarda o valor da "linha do quadrado"
        }
    }
    res=INF;
    for(int j=0;j+k<=m;j++){//para cada "linha do quadrado"
        for(int i=0;i+k<=n;i++){
            ma=0;
            for(int crise=i;crise<i+k;crise++){
                ma=max(ma,tempoMax[crise][j]);//verifica o maior valor das colunas das "linhas do quadrado"
            }
            res=min(res,ma);//atualiza a resposta
        }
    }
    if(res==INF) cout<<"-1\n";//se a resposta nao mudou o pais nao entra em colapso
    else cout<<res<<"\n";//imprime a resposta
    return 0;
}