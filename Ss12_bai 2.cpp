#include<stdio.h>

void print_array(int a[],int n){
	printf("In mang :");
	for(int i=0;i<n;i++){
		printf("%2d",a[i]);
	}
}

int main(){
	int a[]={1,2,3,4,5,6};
	int n=sizeof(a)/4;
	print_array(a,n);
}