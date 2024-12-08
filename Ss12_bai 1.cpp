#include<stdio.h>
int sum(int a,int b){
	int sum=a+b;
	return sum;
}


int main(){
	int a=3,b=4;
	printf("Tong la :%d",sum(a,b));
}