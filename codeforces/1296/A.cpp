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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		//vector<int> v;
		int k;
		int cnt=0;
		string ans;
		fab(0,n,i)
		{
			cin>>k;
			if(k%2)
				cnt++;
		}
		if((cnt==n)&&(n%2==0))
			ans="NO";
		else if(cnt==0)
			ans="NO";
		else
			ans="YES";
		cout<<ans<<endl;
	}
	

	return 0;
}