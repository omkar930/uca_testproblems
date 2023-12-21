#include<stdio.h>



int bitAnd(int a,int b){
    return ~(~a | ~b);
}
int bitXor(int a, int b){
   // return (((a&b))&((~a&~b)));
   return ((a&b)&((~a&b)));
}
int sign(int n){
    int s = (((1<<30)|n)>>30)&(~(!n));
    return s;
}
int getByte(int x,int n){
    return ((x>>(n<<3))&255)>>4;
}
int logicalShift(int x,int n){
    return (x>>n) & ~((-1>>n)<<1);
}
int conditional(int x,int y,int z){
    int m = (!x<<31)>>31;
    return (y^z)^(m&y)^(~m&z);
}
int bang(int n){
    return 1&((n>>31)|((~n+1)>>31)) ;
}
int invert(int x,int p,int n){
    return x^((-1<<p)^(((-1<<n)<<p)));
}
int main(){
    
    printf("%d \n",conditional(0,6,4));
    return 0;
}
