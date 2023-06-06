#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,at,ma=1;
    cin>>n>>m;
    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n;i++){
        at=1;
        for(int j=1;j<m;j++){
            if(abs(mat[i][j-1]-mat[i][j])<=1){
                at++;
                ma=max(ma,at);
            }else at=1;
        }
    }
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