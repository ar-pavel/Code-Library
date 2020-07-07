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
            vector<int> white;
            vector<int> black;
            cin>>n;
            for(int i=0,t; i<n; ++i)
                cin>>t, white.push_back(t);
     
            for(int i=0,t,p; i<n; ++i)
                cin>>t, black.push_back(t);
     
            for(int i=0; i<n; ++i)
                sum ^= (black[i]-white[i]-1);
     
            // cout<<sum<<endl;
           
     
            cout<<"Case "<<cas<<": ";
            cout<<(!sum?"black wins":"white wins")<<endl;
        }
        return 0;
    }
