#include <stdio.h>
#include <string.h>

int a[6]={1,6,4,3,2,5};

void swap(int* x,int* y)
{
    int z;
    z=*x;
    *x=*y;
    *y=z;
}

void F(){
    swap(&a[0],&a[5]);
    swap(&a[5],&a[4]);
    swap(&a[5],&a[1]);
}
void L(){
    swap(&a[1],&a[3]);
    swap(&a[0],&a[1]);
    swap(&a[1],&a[2]);
}
int main() {
    char s[111];
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++){
        if(s[i]=='L')L();
        if(s[i]=='R'){L();L();L();}
        if(s[i]=='F')F();
        if(s[i]=='B'){F();F();F();}
    }
    for(int i=0;i<6;i++)
        printf("%d\n",a[i]);
    return 0;
}
