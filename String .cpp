//***********************Nah I would win*************************//
int to_int(string s){//2736548
    int x = 0;
    For(s.length()){
        int dig = s[i] - '0';
        x*=10;
        x+= dig; 
    }
    return x;
}
//***********************Nah I would win*************************//
bool is_a_sub_string (string sub , string x){
    if(sub.length() > x.length())return 0;
    if(sub == x)return 1;
    int i = 0 ,j =0;
    while(j < x.length()){
        if(i == sub.length())return 1;
        if(sub[i] == x[j])i++;
        else i = (sub[0] == x[j]);
        j++;
    }
    return i == sub.length();
}
