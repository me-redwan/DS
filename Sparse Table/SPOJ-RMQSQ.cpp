#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll table[10001][17];

void precal(vector<ll>&vec){
    ll n=vec.size();
    for(int i=0;i<n;i++){
        table[i][0]=vec[i];
    }
    for(int j=1;j<17;j++){
        for(int i=0;i+(1<<j)-1 <n;i++){
            table[i][j]=min(table[i][j-1],table[i+(1<<(j-1))][j-1]);
        }
    }
}
ll query(ll l,ll r){
    ll pw = log2(r-l+1);
    return min(table[l][pw],table[r-(1<<pw)+1][pw]);
}

int main(){
    ll n;
    cin>>n;
    vector<ll>vec(n);

    for(int i=0;i<n;i++)cin>>vec[i];
    precal(vec);
    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
    return 0;
}
