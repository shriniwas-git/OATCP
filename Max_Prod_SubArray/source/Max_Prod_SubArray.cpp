#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

long long func(vector<ll> &nums){
    if(nums.size()==0){
        return 0;
    }
    long long p1 = nums[0];
    ll p2 = nums[0];
    ll res = nums[0];
    for(int i=1;i<nums.size();i++){
        ll temp = max({nums[i],p1*nums[i],p2*nums[i]})%mod;
        p2 = min({nums[i],p1*nums[i],p2*nums[i]})%mod;
        p1 = temp%mod;
        res = max(res,p1);
    }
    return res%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input3.txt");
    ofstream cout("../output/output3.txt"); 
    ll n;
    cin >> n;
    vector<ll> nums;
    for(int i=0;i<n;i++){
        int k;
        cin >> k; 
        nums.push_back(k);
    }
    ll ans = func(nums);
    cout << ans << endl;
    return 0;
}