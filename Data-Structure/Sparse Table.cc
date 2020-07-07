// Problem link: https://www.spoj.com/problems/RMQSQ/

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

const int mx=500000, k=25;
int n;
int sparseTable[k][mx];
vector<int>lst;

void buildST(){

	for(int i=0; (1<<i)<=n; ++i){
		for(int j=0; j<n; ++j){
			if(i==0)
				sparseTable[i][j]=lst[j];
			else
				sparseTable[i][j]=min(sparseTable[i-1][j], sparseTable[i-1][j+(1<<(i-1))]);
		}  
	}  


	// for(int i=0; (1<<i)<=n; ++i)
	// 	for(int j=0; j<n; ++j)
	// 		cout<<sparseTable[i][j]<<" \n"[j==n-1];    

}


int findMin(int l, int r) {
    return min(sparseTable[__lg(r-l+1)][l], sparseTable[__lg(r-l+1)][r-(1<<__lg(r-l+1))+1]); 
}

 
int main(){
	#ifndef ONLINE_JUDGE
	    freopen("in.txt","r",stdin);
	    freopen("out.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	read(n);
	for(int i=1,_val; i<=n; ++i)
		read(_val), lst.push_back(_val);

	buildST();

	int q,l,r;
	read(q);

	while(q--){
		read(l,r);
		cout<<findMin(l,r)<<endl;
	}

    return 0;
}
