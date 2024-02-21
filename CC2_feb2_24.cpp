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
        // int n;
        ll ans = INT_MIN;
        ll ind=1;
        for(int i=0;i<22;i++){
            long long a,b;cin>>a>>b;
            
            if(((long long)a + 1ll*20*b) > ans){
                ans = a + 20*b;
                ind = i+1;
            }
        }
        
        cout<<ind<<endl;
    }
    return 0;
}
