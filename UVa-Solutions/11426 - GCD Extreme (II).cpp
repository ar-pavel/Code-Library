#include "bits/stdc++.h"
 
using namespace std;
 
template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}
 
template<typename... T>
void write(T&&... args) {  
    ((cout << args << " "), ...);
}
 
#define deb(x) cerr << #x << " " << x <<endl;
 
#define debs(args ...) cerr << __LINE__ << ": ", err(new istringstream(string(#args)), args), cerr << '\n'
void err(istringstream *iss) {}
template<typename T, typename ... Args> void err(istringstream *iss, const T &_val, const Args & ... args) {
    string _name;
    *iss >> _name;
    if (_name.back()==',') _name.pop_back();
    cerr << _name << " = " << _val << "; ", err(iss, args ...);
}

int mx =200001;
vector<long long>sum(mx+2,0);
vector<int>phi(mx+2,0);

void phi_cal(){
	for(int i=1; i<=mx; ++i)
		phi[i]=i;
	for(int i=2; i<=mx; ++i)
		if(phi[i]==i)
			for(int j=i; j<=mx; j+=i)
				phi[j] -= phi[j]/i;  

}

void gcd_sum(){
	for(int i=1; i<=mx; ++i)
		for(int j=i+i; j<=mx; j+=i)
			sum[j] += 1ll*i*phi[j/i];

	for(int i=1; i<=mx; ++i)
		sum[i]+=sum[i-1];  
}
 
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
  
 	phi_cal();
 	gcd_sum();

 	int n;
 	while(cin>>n and n)
 		cout<<sum[n]<<endl;

    return 0;
}
