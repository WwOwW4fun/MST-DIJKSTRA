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
    for(int i = 0 ; i < n; i ++)
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
int main()
{
    int tc; cin >> tc;
    int k = 0;
    output;
    while(tc--)
    {
        int r; cin >> n >> r;
        int a[n] , b[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j < n ; j++)
            {
                if(i != j)
                {
                    int dis = (a[i] - a[j])*(a[i] - a[j]) + (b[i] - b[j])*(b[i] - b[j]);
                    dsc.push_back({i,j,dis});
                }
            }
        }
        sort(dsc.begin(),dsc.end(),cmp);
        double  walk = 0, railway = 0;
        int mst = 0;
        int res = 0;
        make_set();
        for(auto it : dsc)
        {
            if(mst == n + 1) break;
             if(union1(it.u,it.v))
            {

                if(it.w <= r*r)
                {
                    walk += sqrt(it.w);

                }
                else
                {
                    railway += sqrt(it.w);
                    res++;
                }
                mst ++;

            }

        }
        cout << "Case #" << ++k << ": ";
        cout << res+1 << " " << round(walk) << " " << round(railway);
        cout << endl;
        dsc.clear();
    }
}