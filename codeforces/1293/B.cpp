#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
		int n;
		cin>>n;
		double ans=0;
		fab(1,n+1,i)
		ans+=1.0000/i;
		cout<<fixed<<setprecision(10)<<ans<<endl;
	

	return 0;
}