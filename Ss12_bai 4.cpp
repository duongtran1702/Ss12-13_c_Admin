#include<stdio.h>

void max_arr(int a[],int n){
	int max=a[0];
	for(int i=0;i<n;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	printf("So lon nhat la :%d",max);
}

int main(){
	int a[5]={1,2,3,4,5};
	max_arr(a,5);
}