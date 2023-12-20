typedef struct {
    int size;
    int f;
    int r;
    int *arr;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
    q->size = 1000;
    q->f = -1;
    q->r = -1;
    q->arr = (int*)malloc(sizeof(int) * q->size);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    
    obj->r++;
    obj->arr[obj->r] = x;
    
}

int myQueuePop(MyQueue* obj) {
    int a = -1;
    if(!(obj->f==obj->r)){
        obj->f++;
        a = obj->arr[obj->f];
    }
    return a;
}

int myQueuePeek(MyQueue* obj) {
     
    return obj->arr[obj->f+1];
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->r==obj->f){
        return true;
    }
    return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj->arr);
    obj->r=-1;
    obj->f=-1;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
