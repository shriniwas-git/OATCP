#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input2.txt");
    ofstream cout("../output/output2.txt"); 

    vector<ll> nums;
    ll num;
     while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n')  // Break loop if Enter key is pressed
            break;
    }
    ll n;
    cin >> n;
    ll miss = 1, added = 0, i = 0;
    while (miss <= n) {
        if (i < nums.size() && nums[i] <= miss) {
            miss += nums[i++];
        } else {
            miss += miss;
            added++;
        }
    }
    cout << added << "\n";
    return 0;
}