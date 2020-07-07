

    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main(){
        #ifndef ONLINE_JUDGE
            freopen("in.txt","r",stdin);
            freopen("out.txt","w",stdout);
        #endif
       
        int tc,t(1);
        for(scanf("%d",&tc); tc; ++t,--tc){
            vector<long long>X,Y;
            int n;
            long long p,q,cnt(0);
            scanf("%d",&n);
            for(int i=0; i<n; ++i){
                scanf("%lld%lld",&p,&q);
                X.push_back(p), Y.push_back(q);
            }
            X.push_back(X[0]), Y.push_back(Y[0]);
     
            double area = 0;
            for(int i=0,j=n-1; i<n; ++i)
                area = area + (X[j]+X[i])*(Y[j]-Y[i]), j = i,
                cnt += __gcd(abs(X[i]-X[i+1]), abs(Y[i]-Y[i+1]));
     
            //cnt += n;
            //cnt = (cnt)/2.0;
            long long inner = fabs(area);
            // inner -= ();
            //inner ++;
            // cout<<inner<<endl;
            // cout<<cnt<<endl;
            printf("Case %d: %lld\n",t,(inner-cnt+2)>>1);
            // cout<<area/2<<endl;
            // cout<<area<<endl;
            // long long laticePoint = (long long)(abs(area/2.0))- (cnt/2) +1;
            // printf("Case %d: %lld\n", t,laticePoint);
        }
     
        return 0;
    }  
