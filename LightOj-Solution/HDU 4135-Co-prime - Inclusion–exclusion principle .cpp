#include "bits/stdc++.h"

using namespace std;

// template<typename... T>
// void read(T&... args) {
//     ((cin >> args), ...);
// }

// template<typename... T>
// void write(T&&... args) {  
//     ((cout << args << " "), ...);
// }

#define deb(x,y) cerr << #x << " " << x << " " << #y << " " << y <<endl;
#define deb1(x) cerr << #x << " " << x <<endl;
#define isSet(x,i) (bool)(x & (1<<i)) 

vector<long long> getFact(long long n){
    vector<long long>lst;
    for(long long i=2; i*i<=n; ++i)  {
        if(n%i==0){
            lst.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) lst.push_back(n);
    return lst;
}   

int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int tc,t(1);
    for(cin>>tc; tc; ++t,--tc){

        cout<<"Case #"<<t<<": ";

        long long a,b,n;
        cin>>a>>b>>n;

        vector<long long>factors=getFact(n);
        // for(auto x: factors)
        //     cout<<x<<" ";
        // cout<<endl;

        int sz=factors.size();
        // deb1(sz);
        --a;
        long long cnta(0),cntb(0);
        for(int i=1; i<(1<<sz); ++i){
            long long ab = 1,cnt(0);
            for(int j=0; j<sz; ++j)
                if(isSet(i,j))
                    ab *= factors[j],++cnt;           
            if(cnt%2)
                cnta += (a/ab), cntb += (b/ab);
            else
                cnta -= (a/ab), cntb -= (b/ab);

            // deb(cnta,cntb);
        }  
        cout<<b-cntb+cnta-a<<endl;
    }      
    return 0;
}
