#include <stdio.h>
#include <time.h>
long long fib_naiv(int n){
  if (n<=1){
      return n;
  }else {
      return fib_naiv(n-1)+ fib_naiv(n-2);
        }
}
long long fib_dynamic(int n){
    if (n<=1){
        return 1;
    }
    long long fib[n+1];
    fib[0]=0;
    fib[1]=1;
    for (int i=2; i<=n; i++){
        fib[i]=fib[i-1] + fib[i-2];
    }
    return  fib[n] ;
}
int main(){
    int n;
    printf("entrer n: ");
    scanf("%d",&n);
     clock_t start, end;              
    double time_naive, time_dynamic;   

    start = clock();                   
    long long result_naive = fib_naive(n); 
    end = clock();                     
    time_naive = ((double)(end - start)) / CLOCKS_PER_SEC; 

    start = clock();                   
    long long result_dynamic = fib_dynamic(n); 
    end = clock();                     
    time_dynamic = ((double)(end - start)) / CLOCKS_PER_SEC; 

    printf("\nNaive Fibonacci result: %lld\n", result_naive);
    printf("Naive Fibonacci runtime: %.6f seconds\n", time_naive);
    printf("\nDynamic Fibonacci result: %lld\n", result_dynamic);
