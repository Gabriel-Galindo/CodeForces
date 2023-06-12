#include <bits/stdc++.h>

using namespace std;

int main(){
    int linhas,colunas,resistencia;
    int qnt[3];
    memset(qnt,0,sizeof(qnt));
    cin>>linhas>>colunas>>resistencia;
    int mat[linhas][colunas];
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            cin>>mat[i][j];
            qnt[mat[i][j]-1]++;
        }
    }
    if(resistencia>=linhas*colunas) cout<<"-1\n";
    else if(linhas==1||colunas==1){
        if(resistencia<linhas*colunas/2) cout<<"-1\n";
        else{
            int res=0x3F3F3F3F,ok=1;
            for(int tipoAtual=1;tipoAtual<=3;tipoAtual++){
                ok=1;
                int respostaAtual=linhas*colunas-qnt[tipoAtual-1];
                if(linhas==1){
                    int resonanciaAtual[colunas],qntatual,pedraInicial,pedraFinal,i=0,j;
                    memset(resonanciaAtual,0,sizeof(resonanciaAtual));
                    while(i<colunas){
                        qntatual=0;
                        if(mat[0][i]==tipoAtual){
                            pedraInicial=i;
                            qntatual++;
                            j=i+1;
                            while(j<colunas&&mat[0][j]==tipoAtual){
                                qntatual++;
                                j++;
                            }
                            pedraFinal=j;
                            for(j=pedraInicial;j<pedraFinal;j++){
                                resonanciaAtual[j]=qntatual;
                            }
                            i=pedraFinal;
                        }else i++;
                    }
                    for(int i=0;i<colunas/2;i++){
                        if(resonanciaAtual[i]==0){
                            if(i>0) resonanciaAtual[i]=resonanciaAtual[i-1];
                            if(i<colunas/2) resonanciaAtual[i]+=resonanciaAtual[i+1];
                            if(resonanciaAtual[i]>=resistencia) ok=0;
                            resonanciaAtual[i]++;
                        }
                        //cout<<resonanciaAtual[i]<<" ";
                    }
                    for(int i=1+colunas/2;i<colunas;i++){
                        if(resonanciaAtual[i]==0){
                            if(i>1+colunas/2) resonanciaAtual[i]=resonanciaAtual[i-1];
                            if(i+1<colunas) resonanciaAtual[i]+=resonanciaAtual[i+1];
                            if(resonanciaAtual[i]>=resistencia) ok=0;
                            resonanciaAtual[i]++;
                        }
                        //cout<<resonanciaAtual[i]<<" ";
                    }
                }else{
                    int resonanciaAtual[linhas],qntatual,pedraInicial,pedraFinal,i=0,j;
                    memset(resonanciaAtual,0,sizeof(resonanciaAtual));
                    while(i<linhas){
                        qntatual=0;
                        if(mat[i][0]==tipoAtual){
                            pedraInicial=i;
                            qntatual++;
                            j=i+1;
                            while(j<linhas&&mat[j][0]==tipoAtual){
                                qntatual++;
                                j++;
                            }
                            pedraFinal=j;
                            for(j=pedraInicial;j<pedraFinal;j++){
                                resonanciaAtual[j]=qntatual;
                            }
                            i=pedraFinal;
                        }else i++;
                    }
                    for(int i=0;i<linhas/2;i++){
                        if(resonanciaAtual[i]==0){
                            if(i>0) resonanciaAtual[i]=resonanciaAtual[i-1];
                            if(i<linhas/2) resonanciaAtual[i]+=resonanciaAtual[i+1];
                            if(resonanciaAtual[i]>=resistencia) ok=0;
                            resonanciaAtual[i]++;
                        }
                    }
                    for(int i=1+linhas/2;i<linhas;i++){
                        if(resonanciaAtual[i]==0){
                            if(i>1+linhas/2) resonanciaAtual[i]=resonanciaAtual[i-1];
                            if(i+1<linhas) resonanciaAtual[i]+=resonanciaAtual[i+1];
                            if(resonanciaAtual[i]>=resistencia) ok=0;
                            resonanciaAtual[i]++;
                        }
                    }
                }
                if(ok) res=min(res,respostaAtual);
                else res=min(res,respostaAtual+2);
            }
            cout<<res<<"\n";
        }
    }else if(resistencia+1==linhas*colunas) cout<<linhas*colunas-max(qnt[0],max(qnt[1],qnt[2]))<<"\n";
    else{
        cout<<"-1\n";
    }
    return 0;
}