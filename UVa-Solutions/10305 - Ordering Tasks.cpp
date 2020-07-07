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
#define FF first
#define SS second

const int mx = 1000;
vector<int>graph[mx];
vector<int>visited(mx,0);
stack<int>data;

void topoutil(int i){
	visited[i]=1;
	for(auto e:graph[i])
		if(!visited[e])
			topoutil(e);
	data.push(i);
}

void toposort(int n){
	for(int i=1; i<=n; ++i)
		if(!visited[i])
			topoutil(i);
}

void init(){
	for(int i=1; i<mx; ++i){
		graph[i].clear();
		visited[i]=0;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int n,m;
	while(cin>>n>>m and n ){
		init();

		for(int i=0,u,v; i<m; ++i){
			cin>>u>>v;
			graph[u].push_back(v);
		}

		toposort(n);
		

		while(data.size()){
			cout<<data.top()<<" ";
			data.pop();
		}
		
		cout<<endl;
	}
return 0;
}
