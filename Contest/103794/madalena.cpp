#include <iostream>
 
using namespace std;
 
unsigned int mat[501][501];
int x,y;
 
bool moved(int c){
    if(y<c-1) return 1;
    return 0;
}
bool movee(int c){
    if(y>0) return 1;
    return 0;
}
bool movec(int l){
    if(x>0) return 1;
    return 0;
}
bool moveb(int l){
    if(x<l-1) return 1;
    return 0;
}
 
void movimento(int l,int c){
    unsigned int possibilidades=0,maior=0;
    if(moved(c)) possibilidades++;
    if(movee(c)) possibilidades++;
    if(movec(l)) possibilidades++;
    if(moveb(l)) possibilidades++;
    if(movec(l)&&movee(c)) possibilidades++;
    if(movec(l)&&moved(c)) possibilidades++;
    if(moveb(l)&&movee(c)) possibilidades++;
    if(moveb(l)&&moved(c)) possibilidades++;
    if(moved(c)){mat[x][y+1]+=mat[x][y]/possibilidades;if(maior<mat[x][y+1]) maior=mat[x][y+1];}
    if(movee(c)){mat[x][y-1]+=mat[x][y]/possibilidades;if(maior<mat[x][y-1]) maior=mat[x][y-1];}
    if(movec(l)){mat[x-1][y]+=mat[x][y]/possibilidades;if(maior<mat[x-1][y]) maior=mat[x-1][y];}
    if(moveb(l)){mat[x+1][y]+=mat[x][y]/possibilidades;if(maior<mat[x+1][y]) maior=mat[x+1][y];}
    if(movec(l)&&movee(c)){mat[x-1][y-1]+=mat[x][y]/possibilidades;if(maior<mat[x-1][y-1]) maior=mat[x-1][y-1];}
    if(movec(l)&&moved(c)){mat[x-1][y+1]+=mat[x][y]/possibilidades;if(maior<mat[x-1][y+1]) maior=mat[x-1][y+1];}
    if(moveb(l)&&movee(c)){mat[x+1][y-1]+=mat[x][y]/possibilidades;if(maior<mat[x+1][y-1]) maior=mat[x+1][y-1];}
    if(moveb(l)&&moved(c)){mat[x+1][y+1]+=mat[x][y]/possibilidades;if(maior<mat[x+1][y+1]) maior=mat[x+1][y+1];}
    mat[x][y]=mat[x][y]%possibilidades;
    if(movee(c)){
        if(mat[x][y-1]==maior){
            y--;
            return;
        }
    }
    if(movee(c)&&movec(l)){
        if(mat[x-1][y-1]==maior){
            x--;
            y--;
            return;
        }
    }
    if(movec(l)){
        if(mat[x-1][y]==maior){
            x--;
            return;
        }
    }
    if(movec(l)&&moved(c)){
        if(mat[x-1][y+1]==maior){
            x--;
            y++;
            return;
        }
    }
    if(moved(c)){
        if(mat[x][y+1]==maior){
            y++;
            return;
        }
    }
    if(moved(c)&&moveb(l)){
        if(mat[x+1][y+1]==maior){
            x++;
            y++;
            return;
        }
    }
    if(moveb(l)){
        if(mat[x+1][y]==maior){
            x++;
            return;
        }
    }
    if(moveb(l)&&movee(c)){
        if(mat[x+1][y-1]==maior){
            x++;
            y--;
            return;
        }
    }
    return;
}
 
int main(){
    unsigned int ma=0;
    int l,c,mov=1;
    int i,j;
    cin>>l>>c;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            cin>>mat[i][j];
        }
    }
    cin>>x>>y;
    if(l==1&&c==1){
        cout<<mat[0][0]<<endl;
    }else{
        x--;
        y--;
        while(mov<l+c+1){
            mov++;
            movimento(l,c);
        }
        for(i=0;i<l;i++){
            for(j=0;j<c;j++){
                if(ma<mat[i][j]) ma=mat[i][j];
            }
        }
        cout<<ma<<endl;
    }
    return 0;
}