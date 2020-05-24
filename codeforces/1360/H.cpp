//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
vector<ll > v;
ll n,m;

void bintodec(string s)
{
	reverse(all(s));
	ll val=0;
	for(int i=0;i<s.size();i++)
	{
		val+=(1LL<<i)*(s[i]-'0');
	}
	v.pb(val);

}
string dectobin(ll tot)
{
	if(tot==0)
		return string(m,'0');
	string ans="";
	while(tot>0)
	{
		if(tot%2)
			ans='1'+ans;
		else
			ans='0'+ans;
		tot/=2;
	}

	while(ans.size()<m)
	{
		ans='0'+ans;
	}

	return ans;
}

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
		
		cin>>n>>m;
		fab(0,n,i)
		{
			string s;
			cin>>s;
			bintodec(s);
		}
		sort(all(v));
		ll tot=(1LL<<m)-n-1;
		//cout<<"tot:"<<tot<<endl;
		tot=(tot)/2;

		auto l=lower_bound(all(v),tot);
		int ind=l-v.begin();
		if(l!=v.end() and *l==tot)
			{ind++;
				l++;}
			//	cout<<"l:"<<*l<<endl;
		fab(0,ind,i)
		{

			tot++;
			if(l!=v.end() and *l==tot)
			{
				i--;
				l++;
			}
		}		
		cout<<dectobin(tot)<<endl;
		v.clear();




	}
	

	return 0;
}