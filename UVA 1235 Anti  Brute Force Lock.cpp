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

#define ll  long long
#define fastio 	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define for0 for(int i = 0 ; i < n ; i++)
#define for1  for(int j = 0; j < m ; j++)
#define memset() memset(visited,false,sizeof(visited))
#define endl "\n"
#define output ios::sync_with_stdio(0);cin.tie(0);
struct edge
{
    int u, v;
    int w;
};
int n;
int parent[10000],sze[10000];
void make_set()
{
    for0
    {
        parent[i] = i;
        sze[i] = 1;

    }
}
int find(int a)
{
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}
bool union1(int a, int b)
{
    a = find(a); b = find(b);
    if(a == b) return false;
    if(sze[b] > sze[a]) swap(a,b);
    parent[b] = a;
    sze[a] += sze[b];
    return true;
}
int cmp(edge a, edge b)
{
    return a.w < b.w;
}
vector<edge> dsc;
int ans;
void kruskal()
{
    ans = 0;
    vector<edge> mst;
    sort(dsc.begin(),dsc.end(),cmp);
    for(auto it : dsc)
    {
        if(mst.size() == n - 1) break;
        if(union1(it.u,it.v))
        {
            ans += it.w;
            mst.push_back(it);
        }
    }

}
int distance(string a,string b)
{
    int res = 0;
    for(int k = 0; k < 4 ; k ++)
    {
        int high = max(a[k],b[k]);
        int low = min(a[k],b[k]);
        res += min(high - low, low - high + 10);
    }
    return res;
}
int main()
{
     int tc; cin >> tc;
     while(tc--)
    {
        cin >> n;
        vector<string> a(n);
        int minn = INT_MAX;
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
            minn = min(distance(a[i],"0000"),minn);
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i ; j < n ; j++)
            {
                if(i != j)
                {
                    int w = distance(a[i],a[j]);
                    dsc.push_back({i,j,w});
                }
            }
        }
        make_set();
        kruskal();
        cout << ans + minn << endl;
        dsc.clear();
     }
}
