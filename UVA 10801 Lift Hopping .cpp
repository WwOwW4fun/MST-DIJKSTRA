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

#define for0 for(int i = 0 ; i < n ; i++)
#define for1  for(int i = 0; i < m ; i++)

#define output ios::sync_with_stdio(0);cin.tie(0);
#define for0(l,r) for(int i = (l); i < (r); i++)
#define for1(l,r) for(int j = (l); j < (r); j++)
#define vi vector<int>
#define pair<int,int> pii;
#define output ios::sync_with_stdio(0);cin.tie(0);
struct elevator{
    int from,to,w,id;
    bool operator>(const elevator &e) const{
        return this->w > e.w;
    }
};
int n,m;
int time1[10000];

void dijktra(vector<elevator> adj[1000])
{
    vector<int> d(1000,INT_MAX);
    vector<int> pos(1000,-1);
    priority_queue<elevator,vector<elevator>,greater<elevator>> pq;
    pq.push({0,0,0,0});
    d[0] = 0;
    while(!pq.empty())
    {
        elevator e = pq.top();
        pq.pop();
        if(e.w > d[e.to]) continue;
        for(auto it : adj[e.to])
        {
            int tim = d[it.from] + abs(it.to - it.from)*time1[it.id];
            if(it.id != pos[it.from] and pos[it.from] != -1) tim += 60;
            if(tim < d[it.to])
            {
                d[it.to] = tim;
                it.w = tim;
                pos[it.to] = it.id;
                pq.push(it);
            }
        }
    }
    if(d[m] == INT_MAX) cout << "IMPOSSIBLE" << endl;
    else cout  << d[m] <<endl;
}
int main()
{
    output;
    while(cin >> n >> m)
    {
        vector<elevator> adj[1000];
        for(int i = 0; i < n ; i++) cin >> time1[i];
        cin.ignore();
        for(int i = 0; i < n; i++)
        {
            string str; getline(cin ,str);
            int u;
            stringstream ss (str);
            vector<int> v;
            while(ss >> u)
            {
                v.push_back(u);
            }
            for(int j = 0; j < v.size() ; j++)
            {
                for(int k = j + 1; k < v.size() ; k++)
                {

                        adj[v[k]].push_back({v[k],v[j],0,i});
                        adj[v[j]].push_back({v[j],v[k],0,i});
                }
            }
        }
        dijktra(adj);

    }
}