#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

long long func(vector<ll> &nums){
    ll sum = 0;
    ll f1 = 0;
    ll ans = 0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        f1 += i*nums[i];
    }
    ans = f1;
    int k = nums.size();
    int j = k-1;
    for(int i=1;i<nums.size();i++){
        ll f2 = f1 + sum - (k)*nums[j--];
        ans = max(ans,f2);
        f1 = f2;
    }
    return ans;
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
        ll k;
        cin >> k;
        nums.push_back(k);
    }
    ll ans = func(nums);
    cout << ans << endl;
    return 0;
}