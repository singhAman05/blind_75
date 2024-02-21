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
        ll n,m,x,y,l;cin>>n>>m>>x>>y>>l;
        
        ll a = floor(((double)m-y)/(double)l);
        ll b = floor(((double)y-1)/(double)l);
        
        ll c = floor(((double)n-x)/(double)l);
        ll d = floor(((double)x-1)/(double)l);
        
        
        
        cout<< c*b + c*a + d*a + d*b + 1 + a + b + c + d<<endl;
        
    }
    return 0;
}
