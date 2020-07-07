    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
     
    using namespace std;
    using namespace __gnu_pbds;
     
    typedef tree<long long, null_type, less<long long>, rb_tree_tag,
     tree_order_statistics_node_update> orderedset;
     
     
    int main(){
        #ifndef ONLINE_JUDGE
            freopen("in.txt","r",stdin);
            freopen("out.txt","w",stdout);
        #endif
        // ios::sync_with_stdio(false);
        // cin.tie(0);cout.tie(0);
       
     
        int tc,t(1);
        for(scanf("%d",&tc); tc; ++t,--tc){
            cout<<"Case "<<t<<":\n";
            //orderedset lst;
            vector<long long>lst;
            long long n,m;
            // cin>>n>>m;
            scanf("%lld%lld",&n,&m);
            for(long long i=0,t; i<n; ++i)
                 scanf("%lld",&t), lst.push_back(t);
     
            // for(auto x: lst)
            //         cout<<x<<"\t";
            // cout<<endl;
            for(long long i=0,l,r; i<m; ++i){
                 scanf("%lld%lld",&l,&r);
                l = ((long long)(lower_bound(lst.begin(), lst.end(), l) - lst.begin()));
                r = (long long)(upper_bound(lst.begin(), lst.end(), r) - lst.begin());
                printf("%lld\n",r-l );
                // cout<<r-l<<endl;
            }
       
        }
        return 0;
    }
