#include <bits/stdc++.h>

#define INF 0x3F3F3F3F

using namespace std;

int vr[25],vg[25],vb[25];

int main(){
    int r,g,b,ri,gi,bi,ma=0,mi,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>vr[i]>>vg[i]>>vb[i];
    }
    //caminha por todas cores existentes
    for(ri=0;ri<256;ri++){
        for(gi=0;gi<256;gi++){
            for(bi=0;bi<256;bi++){
                mi=INF;
                //para cada cor dado pelo problema calculaa distancia ate a cor atual e salva o valor minimo
                for(int i=0;i<n;i++){
                    mi=min(mi,abs(vr[i]-ri)+abs(vg[i]-gi)+abs(vb[i]-bi));
                }
                if(ma<mi){//caso o valor minimo seja maior que o valor minimo guardado atualiza a melhor cor e o valor minimo guardado
                    ma=mi;
                    r=ri;
                    g=gi;
                    b=bi;
                }
            }
        }
    }
    cout<<r<<" "<<g<<" "<<b<<"\n";
    return 0;
}
