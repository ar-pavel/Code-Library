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

long long lcm(long long a, long long b){
    return a/__gcd(a,b) * b;
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

        cout<<"Case "<<t<<": ";

        long long n,m;
        cin>>n>>m;

        vector<long long>lst(m);    
        for(int i=0; i<m; cin>>lst[i++]);
        
        long long cnt(0);

        for(int i=1; i<(1<<m); ++i){
            vector<long long>tmp;
            for(int j=0; j<15; ++j)
                if(isSet(i,j))
                    // cout<<lst[j]<<" ";
            // cout<<endl;
                    tmp.push_back(lst[j]);
            long long ab=tmp[0];
            for(auto x: tmp)
                ab = lcm(ab,x);

            // deb1(lst.size());

            (tmp.size()%2?cnt+= (n/ab): cnt-=(n/ab));

            // deb(ab,cnt);
                
        }  
        cout<<n-cnt<<endl;

    }      
    return 0;
}
