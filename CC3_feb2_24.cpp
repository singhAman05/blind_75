#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<int, int> mpi;
typedef set<int> seti;
typedef unordered_map<int,int> uom;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;cin>>n;
        ll l=0;
        ll position = 0;
        for(int i=31;i>=0;i--){
        	if(n&(1ll<<i)){
        		if(position==0){position=i;}
        		if(l==0 || l==2) l++;
        	}
        	else{
        		if(l==1) l=2;
        	}
        }
        if(l!=3) {cout<<"0\n";continue;}
        ll sum = 0;
        ll res = 1e18;
        for(int i=position;i>=0;i--){
        	sum+=pow(2,i);
        	if(sum<n)continue;
        	
        	res = min(res, sum-n);
        }
        cout<<res<<endl;
    }
    return 0;
}
