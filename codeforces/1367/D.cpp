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
		string s;
		cin>>s;
		int m;
		cin>>m;
		ll b[m];
		fab(0,m,i)
		cin>>b[i];
		sort(all(s));
		reverse(all(s));
		int j=25;
		char lp=s[j];
		int y=0;
		string ans="";
		fab(0,m,i)
		ans+='a';
		vector<bool > done(m);
		fab(0,m,i)
		done[i]=0;
		int freq[26]={0};
		fab(0,s.size(),i)
		freq[s[i]-'a']++;
			
			while(1)
				{vector<int> req;
				fab(0,m,k)
				{if(b[k]==0 and !done[k])
					req.pb(k);}
					//cout<<"Siz:"<<req.size()<<endl;
				if(!req.size())
					break;
				while(j>0 and freq[j]<req.size())
					j--;
				char op='a';
						fab(0,j,oo)
						op++;
						j--;
				for(auto k:req)
				{
					//cout<<k<<" ";
					if(!done[k])
					{
						
						ans[k]=op;
						fab(0,m,kt)
						{
							if(b[kt]!=0)
							b[kt]-=abs(kt-k);


						}
						done[k]=1;

					}

				}
				//cout<<endl;



			}
			
				
			
				for(auto i:ans)
				cout<<i;
			cout<<endl;
			}
		
	
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}