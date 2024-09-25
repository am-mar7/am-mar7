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
int GCD (int x,int y)
{
    if(x <y) swap(x,y);
    int rem = 0; int ans = y;
    while (true)
    {
        rem =  x%y;
        x = y; y = rem;
        if(rem == 0)
        break;
        ans = rem;
    }
    return ans ;
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
