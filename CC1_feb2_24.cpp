#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int,int> mpi;
typedef set<int> seti;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vi v(n);
        int l=0;
        for(int i=0;i<n;i++) {cin>>v[i];if(v[i]<=4)l=1;}
        if(l)cout<<"NO\n";
        else cout<<"YES\n";
        
    }
    return 0;
}
