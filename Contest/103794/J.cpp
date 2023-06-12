#include <bits/stdc++.h>

using namespace std;

struct Ponto{
    int x;
    int y;
};

int intersec(Ponto iniparede,Ponto fimparede,Ponto camera,Ponto ponto){
    double det=(ponto.x-camera.x)*(fimparede.y-iniparede.y)-(ponto.y-camera.y)*(fimparede.x-iniparede.x);
    if(det==0) return 0;
    double s,t;
    s=((ponto.x-camera.x)*(camera.y-iniparede.y)-(ponto.y-camera.y)*(camera.x-iniparede.x))/det;
    t=((fimparede.x-iniparede.x)*(camera.y-iniparede.y)-(fimparede.y-iniparede.y)*(camera.x-iniparede.x))/det;
    if(s<=1&&s>=0&&t<=1&&t>=0) return 1;//se a interseccao ocorrer nos segmentos da parede e camera pros pontos mais proximos retorna 1
    return 0;
}

int main(){
    int qntpontos,ok=1;
    cin>>qntpontos;
    Ponto paredes[qntpontos],camera;
    for(int i=0;i<qntpontos;i++){
        cin>>paredes[i].x>>paredes[i].y;
    }
    cin>>camera.x>>camera.y;
    if(qntpontos==3) ok=1;//trinagulo sempre da certo
    else{
        //analisa todos os que nao sao possiveis botar no for
        if(intersec(paredes[qntpontos-2],paredes[qntpontos-1],camera,paredes[qntpontos-3])) ok=0;
        if(intersec(paredes[qntpontos-2],paredes[qntpontos-1],camera,paredes[0])) ok=0;
        if(intersec(paredes[qntpontos-1],paredes[0],camera,paredes[qntpontos-2])) ok=0;
        if(intersec(paredes[qntpontos-1],paredes[0],camera,paredes[1])) ok=0;
        if(intersec(paredes[0],paredes[1],camera,paredes[qntpontos-1])) ok=0;
        if(intersec(paredes[0],paredes[1],camera,paredes[2])) ok=0;
        for(int i=2;i<qntpontos-1;i++){
            //analisa um por um, a parede e os pontos mais proximos da parede
            if(intersec(paredes[i-1],paredes[i],camera,paredes[i-2])) ok=0;
            if(intersec(paredes[i-1],paredes[i],camera,paredes[i+1])) ok=0;
        }
    }
    if(ok) cout<<"S\n";
    else cout<<"N\n";
    return 0;
}