#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll func(vector<ll> &boys,vector<ll> &girls){
    sort(boys.begin(),boys.end());
    sort(girls.begin(),girls.end());
    ll pairs = 0;
    ll i=0;
    ll j=0;
    ll n = boys.size(),m=girls.size();
    while(i<n && j<m){
        if(abs(boys[i]-girls[j])<=1){
            pairs+=1%mod;
            i++;
            j++;
        }else if(boys[i]>girls[j]){
            j++;
        }else{
            i++;
        }
    }
    return pairs%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input3.txt");
    ofstream cout("../output/output3.txt"); 
    ll n;
    cin >> n;
    vector<ll> boys;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        boys.push_back(k);
    }
    ll m;
    cin >> m;
    vector<ll> girls;
    for(int i=0;i<m;i++){
        int k;
        cin >> k;
        girls.push_back(k);
    }
    ll ans = func(boys,girls);
    cout << ans << endl;
    return 0;
}