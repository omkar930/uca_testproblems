int cComp(char a, char b){
    return a-b;
}
char* removeDuplicateLetters(char* s) {
    char* arr = (char*)malloc(10000);
    int top = -1;
    int occ[26];
    int visited[26];
    memset(occ,0,sizeof(occ));
    memset(visited,0,sizeof(visited));
    for(int i = 0;i<strlen(s);i++){
        occ[s[i]-'a']++;
    }
    for(int i = 0;i<strlen(s);i++){
        char c = s[i];
        if(visited[c-'a']){
            occ[c-'a']--;
            continue;
        }    
        while(top>=0 && cComp(arr[top],c) > 0 && occ[arr[top]-'a'] > 0){
            visited[arr[top]-'a']=0;
            top--;
        }
       
        arr[++top] = c;
        occ[c-'a']--;
        visited[c-'a']=1;
        
        
    }
    arr[top+1] = '\0';
    
    return arr;
}
