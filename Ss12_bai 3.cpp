#include<stdio.h>
int factorial(int n){
	int factorial=1;
	for(int i=1;i<=n;i++){
		factorial*=i;
	}
	return factorial;
}
int main(){
	int n=3;
	printf("Giai thua cua %d la :%d",n,factorial(n));
}