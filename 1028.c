#include <stdio.h>
 
int mdc (int a, int b){
    if (b==0)
        return a;
    else
        return mdc(b, a % b);
}

int main (){
    int n, f1, f2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &f1, &f2);
        printf("%d\n", mdc(f1, f2));
    }
    return 0;
}
