#include <iostream>

using namespace std;

int mat[2][2];

int main(){
    int casos,i,j,quant;
    cin>>casos;
    while(casos--){
        quant=0;
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                cin>>mat[i][j];
                if(mat[i][j]) quant++;
            }
        }
        if(!quant) cout<<"0"<<endl;
        else{
            if(quant==4) cout<<"2"<<endl;
            else cout<<"1"<<endl;
        }
    }
}