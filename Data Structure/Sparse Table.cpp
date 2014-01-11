/** !-D Range Queries **/

const int MX = 1e5 + 7 ;
const int MXLG = 17;
int dp[MX][MXLG];
int a[MX] , N ;
int preprocess() {
    for( int i = 0 ; i < N ; i++ ) dp[i][0] = a[i]; // init the 0th level s = 1 , k = 0
    for( int s = 2 , k = 1 ; s <= N ; k++ ) { // powering up each level with s *= 2 , and k ++
        for( int i = 0 ; i + s <= N ; i++ )
            dp[i][k] = min( dp[i][k-1] , dp[i+s/2][k-1] );
        s *= 2 ;
    }
}
int rmq(int i , int j ) {
    int range = j - i + 1 , s = 1, k = 0 ;
    for( s = 1 , k = 0 ; s * 2 <= range ; k++ , s *= 2 );
    int ans = min( dp[i][k] , dp[i+range-s][k]);
    return ans;
}


/** 2-D Square Queries **/

//  top left corner is (I, J) and whose bottom right corner is (I+S-1, J+S-1)

const int MX = 507 ;
const int MXLG = 9 ;
int dp[MX][MX][MXLG];
int a[MX][MX] , N ;
int preprocess() {
    for( int i = 0 ; i < N ; i++ )
        for( int j = 0 ; j < N ; j++ )  dp[i][j][0] = a[i][j];
    for( int s = 2 , k = 1 ; s <= N ; k++ ){
        for( int i = 0 ; i + s <= N ; i++ )
            for( int j = 0 ; j + s <= N ; j++ ){
                int mx = dp[i][j][k-1];
                mx = max( mx , dp[i+s/2][j][k-1]);
                mx = max( mx , dp[i][j+s/2][k-1]);
                mx = max( mx , dp[i+s/2][j+s/2][k-1]);
                dp[i][j][k] = mx ;
            }
        s *= 2 ;
    }
}
int rmq(int i , int j , int range ){
    int s = 1 , k = 0 ;
    for( s = 1 , k = 0 ; s * 2 <= range ; s *= 2 , k++ );
    int ans = dp[i][j][k];
    ans = max( ans , dp[i+range-s][j][k] );
    ans = max( ans , dp[i][j+range-s][k] );
    ans = max( ans , dp[i+range-s][j+range-s][k]);
    return ans;
}
