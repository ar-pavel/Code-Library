    #include<bits/stdc++.h>
     
    using namespace std;
     
    #define ll long long
    #define pb push_back
    #define rep(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
    #define all(v) (v).begin(),(v).end()
    #define S(x) scanf("%d",&(x))
    #define S2(x,y) scanf("%d%d",&(x),&(y))
    #define SL(x) scanf("%lld",&(x))
    #define SL2(x) scanf("%lld%lld",&(x),&(y))
    #define P(x) printf("%d\n",(x))
    #define SS second
    #define FF first
    #define mx 100007
    #define INF INT_MAX
    #define pii pair<int,int>
     
    //vector<vector<pii> > graph;
    vector<int> graph[mx];
    vector<int>dis(mx,INF);
    vector<bool>vis(mx,0);
    vector<int>cost[mx];
     
     
    void Clear(int n){
        for(int i=0; i<n+5; ++i){
            graph[i].clear();
            cost[i].clear();
            vis[i]=0;
            dis[i]=INF;
        }
        //fill(vis.begin(),vis.end(),0);
        //fill(dis.begin(),dis.end(),INF);
       
    }
     
    void search(int s){
        queue<int>q;
        q.push(s);
        dis[s]=0;
        while(q.size()){
            int t = q.front();
            q.pop();
            for(int i=0; i<graph[t].size(); ++i){
                int x=graph[t][i];
                int  tmp=max(dis[t], cost[t][i]);
                    if(tmp<dis[x]){
                        dis[x]=tmp;
                        q.push(x);
                    }
            }
        }
    }
     
     
    int main(){
        ios::sync_with_stdio(false);cin.tie(0);
        int q,t(1);
        for(cin>>q; q; --q){
            int n,m,s;
            cin>>n>>m;
            for(int i=0,u,v,w; i<m; ++i){
                cin>>u>>v>>w;
                graph[u].push_back(v);
                graph[v].push_back(u);
                cost[u].push_back(w);
                cost[v].push_back(w);
            }
            fill(dis.begin(),dis.begin()+n+1,INF);
            cin>>s;
            search(s);
            cout<<"Case "<<t++<<":"<<endl;
     
            for(int i=0; i<n; ++i)
                if(dis[i]==INF)
                    cout<<"Impossible"<<endl;
                else
                    cout<<dis[i]<<endl;
            Clear(n);
        }
       
        return 0;
    }
