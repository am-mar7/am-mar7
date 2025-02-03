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
int get_log (int base , int num){
    int x = 1;int ret = 0;
    while(x < num){
        x *= base;
        ret ++;
    }
    if(x > num)ret--;
    return ret;
}
/*******************************/
int XORtoN(int n)
{
    int mod = n % 4;
    if (mod == 0) return n;
    else if (mod == 1) return 1;
    else if (mod == 2) return n + 1;
    return 0;

}
/*******************************/
