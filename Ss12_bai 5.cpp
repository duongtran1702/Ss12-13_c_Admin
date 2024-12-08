#include<stdio.h>
#include<math.h>

int prime_num(int n){
	if(n<2){
		return 0;
	}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int a,b;
	printf("Nhap vao so thu nhat:");
	scanf("%d",&a);
	if(prime_num(a)==1){
		printf("Day la so nguyen to");
	}
	else{
		printf("Day khong phai la so nguyen to");
	}
	printf("\nNhap vao so thu hai:");
	scanf("%d",&b);
	if(prime_num(b)==1){
		printf("Day la so nguyen to");
	}
	else{
		printf("Day khong phai la so nguyen to");
	}
}






