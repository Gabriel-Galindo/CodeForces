#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int mat[1001][1001];

int MMC(int a,int b){
    int r;
    while(a%b){
        r=a%b;
        a=b;
        b=r;
    }
    return r;
}

int alcanca(int x,int y,int n,int m,int tempo){
    queue<tuple<int,int,int>> fila;
    int quant=0;
    mat[x][y]=1;
    fila.push(make_tuple(x,y,0));
    while(!fila.empty()){
        if(get<2>(fila.front())>tempo) break;
        if(get<0>(fila.front())>0){
            if(!mat[get<0>(fila.front())-1][get<1>(fila.front())]){
                mat[get<0>(fila.front())-1][get<1>(fila.front())]=1;
                fila.push(make_tuple(get<0>(fila.front())-1,get<1>(fila.front()),get<2>(fila.front())+1));
            }
        }
        if(get<0>(fila.front())<n-1){
            if(!mat[get<0>(fila.front())+1][get<1>(fila.front())]){
                mat[get<0>(fila.front())+1][get<1>(fila.front())]=1;
                fila.push(make_tuple(get<0>(fila.front())+1,get<1>(fila.front()),get<2>(fila.front())+1));
            }
        }
        if(get<1>(fila.front())>0){
            if(!mat[get<0>(fila.front())][get<1>(fila.front())-1]){
                mat[get<0>(fila.front())][get<1>(fila.front())-1]=1;
                fila.push(make_tuple(get<0>(fila.front()),get<1>(fila.front())-1,get<2>(fila.front())+1));
            }
        }
        if(get<1>(fila.front())<m-1){
            if(!mat[get<0>(fila.front())][get<1>(fila.front())+1]){
                mat[get<0>(fila.front())][get<1>(fila.front())+1]=1;
                fila.push(make_tuple(get<0>(fila.front()),get<1>(fila.front())+1,get<2>(fila.front())+1));
            }
        }
        quant++;
        fila.pop();
    }
    return quant;
}

int main(){
    int i,j,n,m,tempo,vazio=0,alc,div,x,y;
    char temp;
    memset(mat,0,sizeof(mat));
    cin>>n>>m>>tempo>>x>>y;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>temp;
            if(temp=='.'){
                vazio++;
                mat[i][j]=0;
            }
            else mat[i][j]=1;
        }
    }
    alc=alcanca(x-1,y-1,n,m,tempo);
    div=MMC(alc,vazio);
    cout<<alc/div<<" "<<vazio/div<<endl;
    return 0;
}