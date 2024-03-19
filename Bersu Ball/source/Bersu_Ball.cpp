#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll func(vector<ll> &boys, vector<ll> &girls) {
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    ll n = boys.size(), m = girls.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (abs(boys[i - 1] - girls[j - 1]) <= 1) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m] % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input1.txt");
    ofstream cout("../output/output1.txt"); 

    ll n;
    cin >> n;
    vector<ll> boys(n);
    for(int i = 0; i < n; i++) {
        cin >> boys[i];
    }

    ll m;
    cin >> m;
    vector<ll> girls(m);
    for(int i = 0; i < m; i++) {
        cin >> girls[i];
    }

    ll ans = func(boys, girls);
    cout << ans << endl;
    return 0;
}
