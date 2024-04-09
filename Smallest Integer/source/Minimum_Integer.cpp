#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input2.txt");
    ofstream cout("../output/output2.txt"); 
    string num;
    cin >> num;
    ll k;
    cin >> k;
    string ans="";
    for(char &c:num)
    {
        while(ans.size() && ans.back()>c &&k)
        {
            ans.pop_back();
            k--;
        }
        if(ans.size()||c!='0')ans.push_back(c);
    }
    while(ans.size()&&k--)           
    {
        ans.pop_back();
    }
    if(ans==""){
        ans = "0";
    }
    ll nans = stoi(ans);
    cout << nans << endl;
    return 0;
}