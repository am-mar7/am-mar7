bool knowBit (int n , int i){
    return 1LL&(n>>i);
}
int setBit(int n, int i){
    return n|(1LL<<i);
}
int resetBit(int n,int i){
    return n&(-1LL^(1LL<<i));
}
int ResetBit(int n , int i){
    return n&(~(1LL<<i));
}
int flibBit (int n, int i){
    return n^(1LL<<i);
}
bool isPowerofTwo(int n){
    return !(n&(n-1));
}
/*******************************/
string convert_to_binary(int n){
    if(n == 0)return "0";
    string ret = "";
    while(n > 0){
        ret = to_string(n%2) + ret;
        n /=2;
    }
    return ret;
} 
/*******************************/
