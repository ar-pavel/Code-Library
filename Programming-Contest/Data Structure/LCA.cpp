const int MX = 1e5 + 7 ;
const int MXLG = 22 ;
const int INF = 1e8 + 7;
vector<pii>edge[MX] ;
int N , P[MX][MXLG] , L[MX] , T[MX];
int minE[MX][MXLG] , maxE[MX][MXLG] , dist[MX];
pii res;
bool Vis[MX];
void dfs(int u , int p , int d){
    Vis[u] = true ;
    T[u] = p ; /** T holds only the parent of node , make sure T is initialized **/
    L[u] = d ; /** L denotes nodes are in which Level ? **/
    forstl(i,edge[u]){
        int v = i->ff , w = i->ss;
        if( Vis[v] ) continue;
        P[v][0] = u ; /** make sure P[v][0] is initialized , it is the 2^0 means 1st parent of v **/
        minE[v][0] = maxE[v][0] = w ;
        dist[v] = dist[u] + w ;
        dfs(v,u,d+1);
    }
}
void preprocess() {
    for( int i = 1 ; i <= N ; i++ ) {
        for( int j = 0 ; (1 << j) < N ; j++ ) {
            P[i][j] = -1 ;
            maxE[i][j] = -INF;
            minE[i][j] = +INF;
        }
    }
    dfs(1,-1,0); /** if input tree contains 0 as root call u = 0 else 1 **/
    for( int j = 1 ; (1 << j) < N ; j++ ) {
        for( int i = 1 ; i <= N ; i++ ) {
            if( P[i][j - 1] == -1 ) continue ;
            P[i][j] = P[ P[i][j - 1] ][j - 1];
            maxE[i][j] = max( maxE[i][j - 1] , maxE[ P[i][j - 1] ][j - 1] );
            minE[i][j] = min( minE[i][j - 1] , minE[ P[i][j - 1] ][j - 1] );
        }
    }
}
void Reset(){
    for( int i = 0 ; i <=  N ; i++ ){
        edge[i].clear();
        Vis[i] = false ;
        dist[i] = -1;
    }
    dist[0] = 0 ;/** 0 is root of  the tree **/
}
int lca(int p , int q) {
    if(L[p] < L[q] ) swap(p,q);
    res.ff = +INF , res.ss = -INF ; int lg ;
    for( lg = 1 ; (1 << lg) <= L[p] ; ++lg ); lg--;
    for( int i = lg ; i >= 0 ; i--){
        if( L[p] - (1 << i) >= L[q] ){
            res.ff = min( res.ff , minE[p][i] );
            res.ss = max( res.ss , maxE[p][i] );
            p = P[p][i];
        }
    }
    if( p == q ) return p ;
    for( int i = lg ; i >= 0 ; i-- ){
        if( P[p][i] != -1 && P[p][i] != P[q][i]){
            res.ff = min(res.ff , min( minE[p][i] , minE[q][i]));
            res.ss = max(res.ss , max( maxE[p][i] , maxE[q][i]));
            p = P[p][i];
            q = P[q][i];
        }
    }
    res.ff = min(res.ff , min( minE[p][0] , minE[q][0]));
    res.ss = max(res.ss , max( maxE[p][0] , maxE[q][0]));
    return P[p][0]; // T[p] 
}
void Input(){
    Reset();
    For(i,N-1) {
        int u , v , w ;
        read(u) , read(v) , read(w);
        edge[u].pb(mp(v,w));
        edge[v].pb(mp(u,w));
    }
}
int getDistance(int x , int y){ /** find distance of path x to y **/
    int a = lca(x,y);
    int Ans = dist[x] + dist[y] - 2 * dist[a] ;
    return Ans;
}
int query(int r , int u , int v ){ /** If r is root of the tree , find lca of (u,v) */
    pii p[7];
    p[0].second = u ;
    p[1].second = v ;
    p[2].second = r ;
    p[3].second = lca(r,u);
    p[4].second = lca(r,v);
    p[5].second = lca(u,v);
    for( int i = 0 ; i < 6 ; i++ ){
        int x = p[i].second ;
        p[i].first = getDistance(x,r) + getDistance(x,u) + getDistance(x,v);
    }
    sort(p,p+6);
    return p[0].second ;
}
int getMinRoad(int x , int y){ /** find maximum road which is used in path x to y **/
    lca(x,y);
    return res.ff;
}
int getMaxRoad(int x , int y){ /** find minimum road which is used in path x to y **/
    lca(x,y);
    return res.ss;
}
int getKth(int p , int q , int k){ // find Kth node walking from p to q
    int a = lca(p,q) , d ;
    if( a == p ){ // ans lies on the q side
        d = L[q] - L[p] + 1 ;
        swap(p,q);
        k = d - k + 1 ;
    }
    else if( a == q ) ; // do nothing as ans lies on p side
    else {
        if( k > L[p] - L[a] + 1 ) { // if k lies form p to lca + lca to ... means ans is on the q side so substact the k from p to lca dist
            d = L[p] + L[q] - 2 * L[a] + 1 ;
            k = d - k + 1 ;
            swap(p,q);
        }
        else ; // do nothing as k lies from p to under the lca means it is in p side
    }
    int lg ; for( lg = 1 ; (1 << lg) <= L[p] ; ++lg ); lg--;
    k--;
    for( int i = lg ; i >= 0 ; i-- ){
        if( (1 << i ) <= k ) {
            p = P[p][i];
            k -= ( 1 << i );
        }
    }
    return p;
}
int main(){
#ifdef LOCAL
         FI ;
#endif
    while( scanf("%d",&N) && N ) {
        Input();
        preprocess();
    }
}
