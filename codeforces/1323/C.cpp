#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
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
		string s;
		cin>>s;
		int cnto=0,cntc=0;
		bool flag=true;
		int ans=0;
		fab(0,n,i)
		{
			if(s[i]=='(')
				cnto++;
			else
				cntc++;

		}
		if(cnto!=cntc)
		{
			cout<<-1<<endl;

		}
		else
		{
		fab(0,n,i)
		{
			if(s[i]=='(')
				cnto++;
			else
				cntc++;


			if(cntc>cnto)
			{
			
				ans++;
				while(i<n&&cntc>cnto)
				{	i++;
					ans++;
					if(s[i]=='(')
				cnto++;
			else
				cntc++;
			
				}
				if(i==n&&cntc!=cnto)
				{
					flag=false;
					break;
				}
			}}
			if(!flag)
				cout<<-1<<endl;
			else
				cout<<ans<<endl;
}

	
	
	

	return 0;
}