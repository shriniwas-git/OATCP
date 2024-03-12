#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


ll func(ll target,ll sum,vector<int> &dp){
    if(target==sum){
        return 1;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    ll ways = 0;
    for(int i=1;i<=6;i++){
        if((sum+i)<=target){
            ways+= func(target,sum+i,dp)%mod;
        }else{
            break;
        }
    }
    return dp[sum] = ways%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input.txt");
    ofstream cout("../output/output.txt"); 
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<int> dp(n+1,-1);
        if(n>0){
        ll ans = func(n,0,dp);
        cout << ans << endl;
        }else{
        cout << 0 << endl;
        }
    }
    return 0;
}