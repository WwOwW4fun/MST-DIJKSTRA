/* 
Author : Nguyen Xuan An 
Gmail : xuanan437@gmail.com
*/   
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define for0(i ,l ,r) for(int i = (l); i < (r); ++i)
#define for1(i, l, r) for(int i = (l); i >= (r); --i)
#define for2(v) for(auto it : v)
#define reset(a) memset(a,0,sizeof(a))
#define mem(a) memset(a,-1,sizeof(a))
#define membo(a) memset(a,false,sizeof(a))

#define vi vector<int>
#define vpi vector<pair<int, int>>
#define pii pair<int,int>
#define fi first
#define se second
#define prq priority_queue
#define pb push_back

#define output ios::sync_with_stdio(0);cin.tie(0);
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define PI 3.1415926535897932385
#define INF 10000000

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define for0(l,r) for(int i = (l); i < (r); i++)
#define for1(l,r) for(int j = (l); j < (r); j++)
#define vi vector<int>
#define pii pair<int,int>
#define output ios::sync_with_stdio(0);cin.tie(0);
int n;

vector<pii> adj[1000];
int parent[10000];
int main()
{
    int k = 0;
    while(cin >> n and n != 0)
    {


        for(int i = 1; i <= n; i++)
        {
            int x; cin >> x;
            for(int j = 0; j < x ; j++)
            {
                int y, z; cin >> y >> z;
                adj[i].push_back({z,y});
            }
        }
        int s, e; cin >> s >> e;
        cout << "Case " << ++k << ": ";
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        int d[n+2];
        for0(0,n+2) d[i] = INT_MAX;
        d[s] = 0;
        pq.push({0,s});
        while(!pq.empty())
        {
            pii top = pq.top();
            pq.pop();
            if(top.first > d[top.second]) continue;
            for(auto it : adj[top.second])
            {
                if(d[it.second] > d[top.second] + it.first)
                {
                    d[it.second] = d[top.second] + it.first;
                    pq.push({d[it.second],it.second});
                    parent[it.second] = top.second;
                }
            }
        }
        int  x = e;
        vi v;
        while(x != s)
        {
            v.push_back(x);
            x = parent[x];
        }
        v.push_back(s);
        reverse(v.begin(),v.end());
        cout << "Path =";
        for(int t : v) cout << " " << t;
        cout <<"; ";
        cout << d[e] << " second delay" << endl;
        for0(1,n+1) adj[i].clear();
        }

}