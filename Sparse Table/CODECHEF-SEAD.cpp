#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll table[100001][17];

void precal(vector<ll>&vec){
    ll n=vec.size();
    for(int i=0;i<n;i++){
        table[i][0]=vec[i];
    }
    for(int j=1;j<17;j++){
        for(int i=0;i+(1<<j)-1 <n;i++){
            table[i][j]=max(table[i][j-1],table[i+(1<<(j-1))][j-1]);
        }
    }
}
ll query(ll l,ll r,ll d){
    ll ub=r;
    ll res=ub+1;
    while(l<=r){
       ll mid=(l+r)/2;
       ll pw = log2(ub-mid+1);
       ll mx=max(table[mid][pw],table[ub-(1<<pw)+1][pw]);
       //cout<<l<<" "<<r<<" "<<mid<<" "<<mx<<endl;
       if(mx>d){
        l=mid+1;
       }
       else {  res=min(mid,res);
       r=mid-1;}
    }
    return res+1;
}

int main(){
    ll n;
    cin>>n;
    vector<ll>vec(n);

    for(int i=0;i<n;i++)cin>>vec[i];
    vector<ll>dif;
    for(int i=1;i<n;i++){
        dif.push_back(vec[i]-vec[i-1]);
    }
     dif.push_back(0);
   // for(auto x:dif)cout<<x<<" ";
   // cout<<endl;
    precal(dif);
    ll q;
    cin>>q;
    while(q--){
        ll t,d;
        cin>>t>>d;
        ll ub=upper_bound(vec.begin(),vec.end(),t)-vec.begin();
        ub--;
     //   cout<<"UB"<<ub<<endl;
        cout<<query(0,ub-1,d)<<endl;
    }
    return 0;
}
