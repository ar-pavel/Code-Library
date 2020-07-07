    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main(){
        #ifndef ONLINE_JUDGE
            freopen("in.txt","r",stdin);
            freopen("out.txt","w",stdout);
        #endif
     
     
        int tc,t(1);
        for(scanf("%d",&tc); tc; ++t,--tc){
            long long piaju,left;
            vector<long long> lst;
           
            scanf("%lld%lld", &piaju,&left);
            // cin>>piaju>>left;
            // cout<<piaju<<" "<<left<<endl;
     
            if(left*2>=piaju){
                printf("Case %d: impossible\n",t);
                continue;
            }
            printf("Case %d:",t);
           
       
            piaju = piaju-left;
            // cout<<piaju<<endl;
           
     
            for(long long i=1; i*i<=piaju; ++i)
                if(piaju%i==0){
                    lst.push_back(i);
                   
                    // printf("%lld ",i);
                if(piaju/i!=i)
                    lst.push_back(piaju/i);
                }
     
            sort(lst.begin(), lst.end());
     
            for(auto x: lst)
                if(x>left)
                    printf(" %lld",x);
           
           
            printf("\n");
        }
     
        return 0;
    }
