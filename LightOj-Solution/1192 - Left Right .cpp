

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
            int n,m,sum(0);
            cin>>n;
            for(int i=0,t,p; i<n; ++i)
                cin>>t>>p, sum ^= (p-t-1);
            cout<<"Case "<<cas<<": ";
            cout<<(sum?"Alice":"Bob")<<endl;
        }
        return 0;
    }
