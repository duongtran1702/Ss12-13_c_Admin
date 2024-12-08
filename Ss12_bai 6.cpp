#include<stdio.h>
#include<stdbool.h>
bool perfect_num(int n){
	if(n<1){
		return false;
	}
	int temp=0;
	for(int i=1;i<=n/2;i++){
		if(n%i==0) {
			temp+=i;
		}
		
	}
	if(temp==n){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	printf("Enter number 1st :");
	int a;
	scanf("%d",&a);
	if(perfect_num(a)){
		printf("This is a perfect number !\n");
	}
	else {	
		printf("This is a not perfect number !\n");
	}
	printf("Enter number 2nd :");
	int b;
	scanf("%d",&b);
	if(perfect_num(b)){
		printf("This is a perfect number !\n");
	}
	else {	
		printf("This is not a perfect number !\n");
	}
}