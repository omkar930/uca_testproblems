int longestValidParentheses(char* s) {
    int l=0,r=0;
    int max = 0;
    int n = strlen(s);
    for(int i = 0;i<n;i++){
        char c = s[i];
      
        (c=='(') ? l++ : r++;

        if(l==r){
            max = (max>l*2)? max : l*2;
        }else if(r>l){
            l = 0;
            r = 0;
        }
    }
    l = 0,r = 0;
    for(int i = 0;i<n;i++){
        char c = s[n-i-1];
      
        (c==')') ? r++ : l++;
        
        if(l==r){
            max = (max>l*2)? max : l*2;
        }else if(l>r){
            l = 0;
            r = 0;
        }
    }
    return max;
}
