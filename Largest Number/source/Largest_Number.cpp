#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool compare(int a,int b){
    return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}

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
    sort(nums.begin(),nums.end(),compare);
    string ans = "";
    for(int i = 0;i<nums.size();i++){
    ans+=to_string(nums[i]);
    }
    if(ans[0]=='0'){
        cout << "0" << endl;
    }
    cout << ans << endl;
    return 0;
    
}