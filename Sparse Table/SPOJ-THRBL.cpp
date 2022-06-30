#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll table[50001][17];

void precal(vector<ll>&vec){
    ll n=vec.size();
    for(int i=0;i<n;i++){
        table[i][0]=vec[i];
    }
    for(int j=1;j<17;j++){
        for(int i=0;i+(1<<j)-1 <n;i++){
            table[i][j]=max(table[i][j-1],table[i+(1<<(j-1))+1][j-1]);
        }
    }
}
ll query(vector<ll>&vec,ll l,ll r){
    ll pw = log2(r-l);
    l--;r--;
    r--;
    //cout<<vec[l]<<" - "<<table[l][pw]<<" "<<table[r-(1<<pw)+1][pw]<<" "<<pw<<endl;
    return vec[l]>=max(table[l][pw],table[r-(1<<pw)+1][pw])?1:0;
}

int main(){
    ll n,m,res=0;
    cin>>n>>m;
    vector<ll>vec(n);

    for(int i=0;i<n;i++)cin>>vec[i];
    precal(vec);
    while(m--){
        ll l,r;
        cin>>l>>r;
        if(r<l)swap(l,r);
        if(l==r)res++;
        else res+=query(vec,l,r);
    }
    cout<<res<<endl;
    return 0;
}
