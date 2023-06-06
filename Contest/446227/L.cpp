/**/
#include <bits/stdc++.h>

using namespace std;

int pai[100005],estado[100005],vis[100005],cont[100005];
vector<int> filho[100005],adj[100005];

void bfs(){
    queue<int> q;
    int at;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        at=q.front();
        q.pop();
        for(auto c:adj[at]){
            if(!vis[c]){
                filho[at].push_back(c);
                pai[c]=at;
                vis[c]=1;
                q.push(c);
            }
        }
    }
}

int acende(int s,int b){
    int acendidos=0,t=1;
    if(estado[s]!=1){
        estado[s]=1;
        acendidos++;
        if(!filho[s].empty()){
            for(auto c:filho[s]){
                if(estado[c]!=1){
                    acendidos+=acende(c,0);
                }
            }
        }
        cont[s]+=acendidos;
        if(b){
            while(pai[s]!=-1){
                t=1;
                s=pai[s];
                cont[s]+=acendidos;
                if(estado[s]==0){
                    if(!filho[s].empty()){
                        for(auto c:filho[s]){
                            if(estado[c]==0) t=0;
                        }
                        if(t==1){
                            estado[s]=1;
                            acendidos++;
                            cont[s]++;
                        }
                    }
                }
            }
        }
    }
    return acendidos;
}

void apaga(int s,int b){
    int apagados=cont[s];
    if(cont[s]!=0){
        estado[s]=0;
        cont[s]=0;
        if(!filho[s].empty()){
            for(auto c:filho[s]){
                if(cont[c]!=0){
                    apaga(c,0);
                }
            }
        }
        if(b){
            while(pai[s]!=-1){
                s=pai[s];
                cont[s]-=apagados;
                if(estado[s]==1){
                    estado[s]=0;
                    cont[s]--;
                    apagados++;
                }
            }
        }
    }
}

int main(){
    int n,a,b;
    memset(pai,-1,sizeof(pai));
    memset(estado,0,sizeof(estado));
    memset(vis,0,sizeof(vis));
    memset(cont,0,sizeof(cont));
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();
    cin>>n;
    while(n--){
        cin>>a>>b;
        if(a==1){
            acende(b,1);
        }
        if(a==2){
            apaga(b,1);
        }
        if(a==3){
            cout<<cont[b]<<"\n";
        }
    }
    return 0;
}
