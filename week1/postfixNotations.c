int toInt(char* str){
    int i = 0, res = 0,sign = 1;
    if(str[0] == '-'){
        sign = -1;;
        i++;
    }
    for(;i<strlen(str);i++){
        
        res = res*10 + (str[i] - '0');
    }
    return res*sign;
}
int evalRPN(char** tokens, int n) {
    int arr[10000];
    int top  = -1;
    for(int i = 0;i<n;i++){
        if(strcmp(tokens[i],"+")==0){
            arr[top-1] = arr[top-1] + arr[top];
            top--;
        }else if(strcmp(tokens[i],"-")==0){
            arr[top-1] = arr[top-1] - arr[top];
            top--;
        }else if(strcmp(tokens[i],"*")==0){
            arr[top-1] = arr[top-1] * arr[top];
            top--;
        }else if(strcmp(tokens[i],"/")==0){
            arr[top-1] = arr[top-1] / arr[top];
            top--;
        }else{
            arr[++top] = toInt(tokens[i]);
            printf("%d\n",arr[top]);
        }
    }
    return arr[0];
}
