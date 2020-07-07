#include <bits/stdc++.h>
 
using namespace std;
// #define deb(x) cout << #x << " " << x << endl;
 
// template<typename... T>
// void read(T&... args) {
//     ((cin >> args), ...);
// }
 
// template<typename... T>
// void write(T&&... args) { 
//     ((cout << args << " "), ...);
// }
 
#define M 5000000

int phi[M+2];

unsigned long long phiSum[M+2];

void calculatePhi(){
    for(int i=2; i<=M; i++)
        phi[i] = i;

    for(int i =2; i<=M; i++){
        if(phi[i]==i){
            for(int j=i; j<=M; j+=i)
                phi[j]-=phi[j]/i;
        }
    }
}

 
 
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif
 
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
 
	calculatePhi();
	phiSum[1] = 0;

    for(int i=2; i<=M; i++)
    	phiSum[i]= ((unsigned long long)phi[i]* (unsigned long long)phi[i])+phiSum[i-1];

   
	// for(int i=1; i<10; ++i)
	// 	cout<<phi[i]<<" "<<phiSum[i]<<endl;
	// deb(phi[2]);
	// deb(phiSum[20]);	
 
 
	int tc,t(1);
	for(scanf("%d",&tc); tc; ++t,--tc){
		int a,b;
		scanf("%d%d",&a,&b);
		// printf("%d\n",phiSum[a-1]);
		unsigned long long x = phiSum[b]-phiSum[a-1];
		// x *= x;
		printf("Case %d: %llu\n",t,x);
 
	}
 
	return 0;
}
