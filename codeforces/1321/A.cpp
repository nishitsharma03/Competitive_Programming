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
	int r[n],b[n];
	fab(0,n,i)
	cin>>r[i];
	fab(0,n,i)
	cin>>b[i];
	int cntr=0,cntb=0;
	fab(0,n,i)
	{
		if(r[i]&&!b[i])
			cntr++;
		else if(!r[i]&&b[i])
			cntb++;
	}
	if(!cntr)
		cout<<-1<<endl;
	

	else
	{
		if(cntr>cntb)
			cout<<1<<endl;
		else if(cntr==cntb)
			cout<<2<<endl;
		else
		{
			cout<<ceil(cntb/cntr)+1<<endl;
		}
	}

	return 0;
}