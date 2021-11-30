#include<stdio.h>
int main(){
    int a=1,b=3,c=2;
    if(a>b)
        if(b>c)
            printf("a>b and b>c");

    else
        printf("Something else");

    return 0;
}

/*
-_Solution--!
sizeof(int) =4
but 
it will give output: false
because:- 
1)whenever we have comparison operator operand will be of same  data type
    and in case sizeof() it return signed  data
2) sizeof() is evaluate at compile time, not evalutes at run time.


*/