//#pragma GCC optimize "trapv"
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
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
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;
bool findPartiion (vector<int> &arr, int n)  
{  
    int sum = 0;  
    int i, j;  
      
    // Calculate sum of all elements  
    for (i = 0; i < n; i++)  
    sum += arr[i];  
      
    if (sum % 2 != 0)  
    return false;  
      
    bool part[sum / 2 + 1][n + 1];  
      
    // initialize top row as true  
    for (i = 0; i <= n; i++)  
    part[0][i] = true;  
          
    // initialize leftmost column,  
    // except part[0][0], as 0  
    for (i = 1; i <= sum / 2; i++)  
    part[i][0] = false;  
      
    // Fill the partition table in bottom up manner  
    for (i = 1; i <= sum / 2; i++)  
    {  
        for (j = 1; j <= n; j++)  
        {  
            part[i][j] = part[i][j - 1];  
            if (i >= arr[j - 1])  
            part[i][j] = part[i][j] ||  
                         part[i - arr[j - 1]][j - 1];  
        }      
    }  
      
    /* // uncomment this part to print table  
    for (i = 0; i <= sum/2; i++)  
    {  
    for (j = 0; j <= n; j++)  
        cout<<part[i][j];  
    cout<<endl;  
    } */
      
    return part[sum / 2][n];  
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
		int n;
		cin>>n;
		vector<int> a(2*n), part;
		fab(0,2*n,i)
		cin>>a[i];
		
		fab(0,2*n,i)
		{
			int cnt=0;
			int uptil=a[i];
			while(i<2*n and a[i]<=uptil)
			{
				i++;
				cnt++;
			}
			i--;
			part.pb(cnt);


		}
		if(findPartiion(part,part.size()))
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}
	
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}