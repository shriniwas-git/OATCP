#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll func(int ind1, int ind2, vector<vector<char>>& mat, int n,vector<vector<int>> &dp) {
    if (ind1 < 0 || ind2 < 0 || ind1 >= n || ind2 >= n) {
        return 0;
    }
    if (mat[ind1][ind2]=='*') {
        return 0; 
    }
    if (ind1 == n-1 && ind2 == n-1) {
        return 1; 
    }
    if(dp[ind1][ind2]!=-1){
        return dp[ind1][ind2];
    }
    ll down = func(ind1 + 1,ind2,mat,n,dp)%mod;
    ll right = func(ind1,ind2 + 1,mat,n,dp)%mod;
    return dp[ind1][ind2] = (down+right)%mod;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input1.txt");
    ofstream cout("../output/output1.txt"); 
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<vector<char>> mat(n,vector<char> (n,'0'));
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char c;
                cin >> c;
                mat[i][j] =c;
            }
        }
        ll ans = func(0,0,mat,n,dp);
        cout << ans << endl;

    }
    return 0;
}