    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main(){
        #ifndef ONLINE_JUDGE
            freopen("in.txt","r",stdin);
            freopen("out.txt","w",stdout);
        #endif
     
        int tc;
        cin>>tc;
        for(int cas = 1; cas<=tc; ++cas){
            vector<int> lst;
            int n,m,sum(0),chk(0);
            cin>>n>>m;
     
            for(int i=0,t,p; i<n; ++i){
                p=0;
                for(int j=0; j<m; ++j)
                    cin>>t, p+= t;
                sum ^= p,
                chk += (t!=1);
            }
            cout<<"Case "<<cas<<": ";
            (chk)?cout<<(sum?"Alice":"Bob")<<endl:cout<<(n&1?"Bob":"Alice")<<endl;
        }
        return 0;
    }
