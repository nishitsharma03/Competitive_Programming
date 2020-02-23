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
		int b[n];
		bool ch[2*n+1];
		fab(0,2*n+1,i)
		ch[i]=false;
		fab(0,n,i)
		{
			cin>>b[i];
			ch[b[i]]=true;
		}
		//cout<<ch[2*n]<<"__";

		if((!ch[1])||ch[2*n])
		{
			cout<<"-1"<<endl;
			continue;
		}
		vector<int> v;
		int flag=0;
		fab(0,n,i)
		{
			v.pb(b[i]);
			int k=b[i];
			k++;
			while(k<=2*n&&ch[k])
				k++;
			if(k==2*n+1)
				{flag=-1;
			break;}
			ch[k]=true;
			v.pb(k);
		}
		if(flag==-1)
			{cout<<"-1\n";
		continue;}
		fab(0,2*n,i)
		cout<<v[i]<<" ";
		cout<<endl;

	}
	

	return 0;
}