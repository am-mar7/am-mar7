//to control the number of digits after the decimal dot we use
//  fixed<<setprecision(9)<<d;

/***************************************/
bool isPrime (int n)
{
    if (n == 2) return true;
    if (n < 2 || n%2 == 0) return false;
    for (int i = 3; i*i <= n; i+=2)
        if(n%i == 0) return false;
    return true;
}  
/***************************************/
int countDivisors (int n)
{
    int sum = 0;
    for (int i = 1; i*i <= n; i++)
    {
        if(n % i == 0)
            sum += i;
        if(n%i ==0 && i*i <n)
            sum += n/i;    
    }
    return sum;         
}

/***************************************/
int gcd (int a, int b) { // non recursive approch
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int GCD (int a, int b) { // recursive approach
    return b ? GCD (b, a % b) : a;
}
int LCM(int x,int y)
{
    return x /GCD(x,y)*y;
}

/***************************************/
vector<int> primefactors (int n)
{
    vector<int> v;
    while (n%2 ==0)
    {
        v.push_back(2);
        n/=2;
    }
    for (int i = 3; i*i <= n; i+=2)
    {
        while (n%i ==0)
        {
            v.push_back(i);
            n/=i;
        }       
    }
    if(n > 1) v.push_back(n);
    return v;   
}
/***************************************/
bool almostprime (int n)
{
    int dpd = 0;
    if(n%2 ==0) dpd++;    
    for(int i = 3; i < n;i+=2)
        if(isPrime(i) && n%i == 0) dpd++;
    return dpd == 2;  
}
/***************************************/
vector<int> Divisors (int n)
{
    vector<int> v;
    for (int i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            v.push_back(i);
            if(i*i != n)
                v.push_back(n/i);
        }
    }
    return v;   
}
/***************************************/
int greatestDiv (int n)
{
    for (int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return n/i;
    }       
    return 1;   
}
/***************************************/
int sumBettwen_A_B(int a, int b){
    if(a < b)swap(a,b);
    return (a * (a+1) / 2 ) - (b * (b-1) / 2);
}
int sumEvens(int x , int y){
    if(x>y) swap(x,y);
    return (y/2) * (y/2 +1) - ((x-1)/2) * ((x-1)/2 +1);
}
int sumOdds(int x , int y){
    if(x>y) swap(x,y);
    return ((y+1)/2) * ((y+1)/2)  -  (x/2) * (x/2);
}
/***************************************/
int comb (int n ,int r){
    vector<int> facn , facr;// factorial n , r
    for(int i = n ; i > n-r ; i--)
        facn.push_back(i);
    for(int i = 1; i <= r; i++)
        facr.push_back(i);
    int ret = 1;map<int,int> vis;
    for(int i = 0 ; i< facn.size() ; i++){
        ret *= facn[i];
        int div = 0;
        for(int j= 0 ; j < facr.size();j++){
            if(ret%facr[j] == 0 && !vis[facr[j]])
                div = facr[j];
        }
        if(div){
            vis[div]++;
            ret/= div;
        }
        else break;
    }    
    return ret;
}
int perm (int n ,int r){
    int ret = 1;
    for(int i = n; i > n-r ;i--)ret *= i;
    return ret;
}
/***************************************/
int fastPower (int base , int power){
    if(power == 0)return 1;
    if(power == 1)return base;

    int result = fastPower(base,power/2);
    result *= result;
    
    if(power%2)result *= base;
    return result;
}
/***************************************/
vector<pair<int,int>> primeFactors (int n){ 
    vector<pair<int,int>> ret;
    int b  = 2, pw = 0;
    while(n % 2 == 0){
        pw ++;
        n /= 2;
    } 
    if(pw) 
        ret.push_back({b,pw});
    for (int i = 3 ; i*i <=n ; i+= 2){
        pw = 0 , b = i; 
        while(n % i == 0){
            n /= i;
            pw ++;
        }    
        if(pw)
            ret.push_back({b,pw});
        if (n == 1)break;
    }
    if (n > 1) ret.push_back({n,1});
    return ret;
}
/***************************************/
vector<int> primesToN (int n){ // sieve approch
    vector<int> isprime(n+1 , 1);
    vector<int> ret;
    for(int i = 2 ; i <= n; i++)    if(isprime[i]){
        ret.push_back(i);
        for(int j = i+i ; j <= n ; j+= i)
            isprime[j] = 0;
    }   
    return ret;
} 
/***************************************/
int extended_euclid(int a , int b , int& x , int& y){
    if(b == 0){
        x =  1, y = 0;
        return a;
    }
    int g =  extended_euclid(b , a%b , y , x);
    y -=  (a / b) * x;
    return g;
}
/***************************************/
int modInverse (int a , int m){
    int x, y;
    int g = extended_euclid(a , m , x, y) ;
    if(g == 1)
        return (x + m)%m;
    return -1;    
}
