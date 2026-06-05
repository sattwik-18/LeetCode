#include<stdio.h>
#include<limits.h>
int reverse(int x){
  int r=0;
  while(x!=0)
  {
    int d=x%10;
    if(r>INT_MAX /10 || (r==INT_MAX && d>7)){
      return 0;
    }
    if(r<INT_MIN /10 || (r==INT_MIN && d<-8)){
      return 0;
    }
    r=r*10+d;
    x=x/10;
  }
  return r;
}
  void main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("%d",reverse(n));
  }
