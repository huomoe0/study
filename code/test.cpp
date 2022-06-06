#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXM 500005
const int INF = 2147483647;
int n,m,head[MAXN],cnt,vis[MAXN],s,dis[MAXN];

struct edge
{
    int v,w,next;
}e[MAXM];
struct node
{
    int dis,pos;
    bool operator<(const node &x) const
    {
        return x.dis < this->dis;
    }
};
void add(int u,int v,int w)
{
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
void dijkstra()
{
    for(int i = 1;i <= n;i++)    dis[i] = INF;
    dis[s] = 0;
    priority_queue<node> q;
    q.push((node){0,s});
    while(!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos,d = tmp.dis;
        if(vis[x])  continue;
        vis[x] = 1;
        for(int i = head[x];i;i = e[i].next)
        {
            dis[e[i].v] = min(dis[e[i].v],dis[x]+e[i].w);
            if(!vis[e[i].v])    q.push((node){dis[e[i].v],e[i].v});
        }

    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&s);
    for(int i = 0;i < m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
    }
    dijkstra();
    for(int i = 1;i <= n;i++)   printf("%d ",dis[i]);


    return 0;
}