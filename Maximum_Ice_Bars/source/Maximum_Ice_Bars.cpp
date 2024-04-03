#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream cin("input3.txt");
    ofstream cout("../output/output3.txt"); 
    ll n;
    cin >> n;
    vector<ll> a;
    for(int i=0;i<n;i++){
        ll k;
        cin >> k;
        a.push_back(k);
    }
    ll amount;
    cin >> amount;
    sort(a.begin(),a.end());
    ll ct = 0;
    ll i = 0;
    while(amount>0 && i<a.size()){
        if(amount>=a[i]){
            amount = amount - a[i];
            i++;
            ct++;
        }else{
            break;
        }
    }
    cout << ct << endl;
    return 0;
}