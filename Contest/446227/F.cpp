#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,at,ma=1;//o minimo possivel e sempre 1
    cin>>n>>m;
    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    //caminha nas linhas
    for(int i=0;i<n;i++){
        at=1;//o minimo possivel e sempre 1
        for(int j=1;j<m;j++){
            if(abs(mat[i][j-1]-mat[i][j])<=1){//caso a diferenca for menor ou igual a 1
                at++;//aumenta a linha atual
                ma=max(ma,at);//e se for maior que a maior atualiza a maior, tem que ser aqui para evitar apagar quando mudar de linha
            }else at=1;
        }
    }
    //caminha de forma analoga nas colunas
    for(int i=0;i<m;i++){
        at=1;
        for(int j=1;j<n;j++){
            if(abs(mat[j-1][i]-mat[j][i])<=1){
                at++;
                ma=max(ma,at);
            }else at=1;
        }
    }
    cout<<ma<<"\n";
    return 0;
}
