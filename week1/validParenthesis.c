bool isValid(char* s) {
    char arr[10000];
    int top = 0;
    int n = strlen(s);
    for(int i = 0;i<n;i++){
        char c = s[i];

        if(c == '(' || c == '{' || c == '['){
            arr[top++] = c;
        }else if((c=='}' || c==')' || c==']')&&top>0){
              if(c=='}' && arr[top-1]=='{'){
                    top--;
                }else if(c==']' && arr[top-1]=='['){
                    top--;
                }else if(c==')' && arr[top-1]=='('){
                    top--;
                }else{
                    return false;
                }
        }else{
            return false;
        }
       printf("%d",top);
    }
    printf("%s",arr);
    printf("%d",top);
    if(top < 1){
        return true;
    }else{
        return false;
        }
}
