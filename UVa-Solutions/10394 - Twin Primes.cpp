#include <bits/stdc++.h>

using namespace std;

#define le 18409202

#define ON(x) (Mark[x/64] & (1<<((x%64)/2)))
#define mark(x) (Mark[x/64] |= (1<<((x%64)/2)))

vector<int> primes;

long long Mark[le >> 6];

void sieve(){
    int rt = sqrt(le);
    int t=2;
    for (int i = 3; i <= rt; i+=2)
        if (!ON(i)){
            // if(t+2==i) primes.push_back(t);
            for (int j = i * i; j < le; j += (i+i))
                mark(j);
            // t=i;
        }

    for(int i=3; i<le; i += 2)
        if(!ON(i)){
            
            if(t+2==i) 
                primes.push_back(t);

            t=i;
        }

            
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    sieve();

    int a;
    // for(auto x: primes)
    //         cout<<x<<"\t";
    // cout<<endl;
    
    while(scanf("%d", &a)!=EOF)
        a = primes[a-1], printf("(%d, %d)\n",a,a+2);

    #ifndef ONLINE_JUDGE
            cerr<<"Time:"<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
    #endif        

    return 0;
}
