#include <bits/stdc++.h>

#define lli long long int

using namespace std;

vector<pair<int,int>> kpeias[505];

lli knapSack(int W, int i)
{
    // Making and initializing dp array
    vector<pair<int,int>>::iterator it;
    lli dp[W + 1];
    memset(dp, 0, sizeof(dp));
 
    for (it=kpeias[i].begin();it!=kpeias[i].end();++it) {
        for (int w = W; w >= 0; w--) {
 
            if (it->first<= w)
                 
                // Finding the maximum value
                dp[w] = max(dp[w],
                            dp[w - it->first] + it->second);
        }
    }
    // Returning the maximum value of knapsack
    return dp[W];
}

int main(){
    int n,t,a,b,majestosidade;
    lli res=0;
    cin>>n>>t;
    while(n--){
        cin>>a>>b>>majestosidade;
        kpeias[b-1].push_back(make_pair(a/2,majestosidade));
    }
    for(int i=0;i<t;i++){
        cin>>a>>b;
        res+=knapSack(min(a,b),i);
    }
    cout<<res<<"\n";
    return 0;
}