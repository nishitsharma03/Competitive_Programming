#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int main()
{ quick;

	int t;
	cin>>t;
	while(t--)
	
	{
		int n,s,k;
		cin>>n>>s>>k;
		vector<int> a;
		int closed[k];
		fab(0,k,i)
		{
			cin>>closed[i];
			a.push_back(closed[i]);
		}
		//sort(closed,closed+k);
		int i=0;
		
		

		//cout<<"i="<<i<<" ";
		
		for (int i=0; i<=k; i++) {
		if (s-i >= 1 && find(a.begin(), a.end(), s-i) == a.end()) {cout << i << endl; break;}
		if (s+i <= n && find(a.begin(), a.end(), s+i) == a.end()) {cout << i << endl;break; }
	
	}
}

	return 0;
}