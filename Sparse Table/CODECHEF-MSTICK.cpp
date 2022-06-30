#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mintable[100005][17];
ll maxtable[100005][17];
void precal(vector<ll>&vec){
    ll n=vec.size();
    for(int i=0;i<n;i++){
        mintable[i][0]=vec[i];
        maxtable[i][0]=vec[i];
    }
    for(int j=1;j<17;j++){
        for(int i=0;i+(1<<j)-1 <n;i++){
            mintable[i][j]=min(mintable[i][j-1],mintable[i+(1<<(j-1))][j-1]);
            maxtable[i][j]=max(maxtable[i][j-1],maxtable[i+(1<<(j-1))][j-1]);
        }
    }
}
ll n;
double query(ll l,ll r){
    ll pw = log2(r-l+1);
    ll inside =true;
    ll mini=min(mintable[l][pw],mintable[r-(1<<pw)+1][pw]);
    ll maxi=max(maxtable[l][pw],maxtable[r-(1<<pw)+1][pw]);

    ll maxR,maxL;
    if(l==0)maxL=-1000000;
    else{
    ll pwl=log2(l);
    maxL=max(maxtable[0][pwl],maxtable[l-(1<<pwl)][pwl]);
    }
    if(r==n-1)maxR=-1000000;
    else{
        ll pwr=log2(n-r-1);
        maxR=max(maxtable[r+1][pwr],maxtable[(n-1)-(1<<pwr)+1][pwr]);
    }
    return max({mini+(maxi-mini)/2.0,(double)maxL+mini,(double)maxR+mini});
}

int main(){
    cin>>n;
    vector<ll>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    precal(vec);
    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        printf("%.1lf\n",query(l,r));
    }
    return 0;
}
