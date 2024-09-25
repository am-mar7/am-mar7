struct BigInteger
{
    string str;
    BigInteger(string s){
        str = s;
    }
    BigInteger operator+(const BigInteger& b){
        string a = str , c = b.str;
        int alen = a.size() , clen = c.size();
        int len = abs(alen-clen);
        if(alen > clen){
            reverse(c.begin(),c.end());
            while(len--){
                c.push_back('0');
            }
            reverse(c.begin(),c.end());
        }
        if(clen > alen){
            reverse(a.begin(),a.end());
            while(len--){
                a.push_back('0');
            }
            reverse(a.begin(),a.end());
        }
        int carry = 0;
        int n= max(alen,clen);
        string res (n +1, '0');
        for(int i =n-1; i >= 0; i--){
            int digit = a[i]-'0' + c[i] -'0'+ carry;
            carry = digit /10;
            res[i+1] = digit%10 + '0';
        }
        if(carry)res[0] = carry;
        else res = res.substr(1);
        return BigInteger(res);
    }
    BigInteger operator*(const BigInteger b){
        string a = str , c = b.str;
        int alen = a.size(), clen = c.size();
        if(min(alen,clen) == 0)
            return BigInteger("0");
        vector<int> res(alen+clen,0);
        int carry = 0, i1 = 0 , i2 = 0;
        for(int i = alen-1; i>= 0; i--){
            carry = 0, i2 = 0;
            int n1 = a[i] - '0';
            for(int j = clen -1; j>=0 ; j--){
                int n2 = c[j] - '0';
                int sum = n1*n2 + carry + res[i1+i2];
                carry = sum/10;
                res [i1+i2] = sum%10; 
                i2++;
            }
            if(carry){
                res[i1+i2] += carry;
            }
            i1++;
        }
        string ret = "";
        reverse(res.begin(),res.end());
        bool flag = 0;
        For(res.size()){
            if(res[i]||flag){
                flag =1;
                ret += '0'+res[i];
            }
        }
        if(ret.empty()) return BigInteger("0");
        return BigInteger (ret);
    }
    bool issmaller (string n1, string n2){
        if(n1.length()<n2.length()) 
            return 1;
        if(n1.length() > n2.length()) 
            return 0;
        for(int i = 0; i<n1.length(); i++)
            if(n1[i] < n2[i]) 
                return 1;
            else if(n1[i] > n2[i])
                return 0;
        return 0;        
    }
    BigInteger operator- (const BigInteger b){
        string a = str, c = b.str;
        if(a == c)return BigInteger("0");
        bool isnega = 0;
        if(issmaller(a,c)){
            swap(a,c);
            isnega = 1;
        }
        reverse(a.begin(),a.end());
        reverse(c.begin(),c.end());
        string res = "";
        int carry= 0;
        for(int i =0 ; i < c.size() ; i++){
            int diff = ((a[i]-'0') - (c[i] - '0')) -carry;
            if(diff < 0){
                diff += 10;
                carry =1;
            }
            else carry =0;
            res.push_back(diff+'0');
        }
        for(int i = c.size(); i < a.size(); i++){
            int diff = (a[i]-'0') - carry;
            if(diff<0){
                diff += 10;
                carry =1;
            }
            else carry= 0;
            res.push_back(diff+'0'); 
        }
        while(res.back() == '0')res.pop_back();
        if(isnega)
            res.push_back('-');
        reverse(res.begin(),res.end());
        return BigInteger(res);
    }    
};
