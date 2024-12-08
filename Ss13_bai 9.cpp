#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int prime_is(int n){
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
void enter_matrix(int *n,int *m,int ***a){
	printf("Enter n:");
	scanf("%d",n);
	printf("Enter m:");
	scanf("%d",m);
	*a=(int **)malloc((*n)*sizeof(int *));
	for(int i=0;i<*n;i++){
		(*a)[i]=(int*)malloc(*m*sizeof(int));
	}
	for(int i=0;i<*n;i++){
		for(int j=0;j<*m;j++){
			printf("Enter the element at the row %d column %d:",i+1,j+1);
			scanf("%d",&(*a)[i][j]);
		}
	}
}
void print_matrix(int n,int m,int **a){
	printf("Print the elements based on the matrix :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
}
void elements_at_the_corner_of_matrix(int n,int m,int**a){
	printf("Print the elements at the corner of the matrix :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0&&j==0||i==0&&j==m-1||j==0&&i==n-1||i==n-1&&j==m-1){	
				printf("%3d",a[i][j]);
			}
			else{
				printf("   ");
			}
		}
		printf("\n");	
	}
}
void elements_on_the_border_of_matrix(int n,int m,int **a){
	printf("Print the elements on the border of the matrix :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0||j==0||i==n-1||j==m-1){
				printf("%3d",a[i][j]);
			}
			else{
				printf("   ");
			}						
		}
		printf("\n");
	}
}

void diagonals_of_matrix(int n,int m,int **a){
	if(m!=n){
		printf("Error:Cannot print diagonal lines due to inconsistent rows and columns.Please check!");
		return;
	}
	printf("Print the main diagonal of the matrix :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j==i){
				printf("%3d",a[i][j]);
			}
			else{
				printf("   ");
			}						
		}
		printf("\n");
	}
	printf("Print the secondary diagonal of the matrix :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j==n-i-1){
				printf("%3d",a[i][j]);
			}
			else{
				printf("   ");
			}						
		}
		printf("\n");
	}
}
void print_prime_number_in_the_matrix(int n,int m,int **a){
	printf("Print the prime elements in the matrix :\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(prime_is(a[i][j])==1){
				printf("%3d",a[i][j]);
			}
			else{
				printf("   ");
			}						
		}
		printf("\n");
	}
}
int main() {
	int **a;
	int n,m;
	do{
		printf("1.Enter n and m.\n");
		printf("2.Print matrix.\n");
		printf("3.Print the elements at the corner of the matrix.\n");
		printf("4.Print the elements on the border of the matrix.\n");
		printf("5.Print the diagonals of the matrix.\n");
		printf("6.Printf the prime number elements of the matrix.\n");
		printf("7.Exit.\n");
		int choice;
		printf("Enter your choice :");
		scanf("%d",&choice);
		if(choice==1){
			enter_matrix(&n,&m,&a);
		}
		else if(choice==2){
			print_matrix(n,m,a);	
		}
		else if(choice==3){
			elements_at_the_corner_of_matrix(n,m,a);	
		}
		else if(choice==4){
			elements_on_the_border_of_matrix(n,m,a);	
		}
		else if(choice==5){
			diagonals_of_matrix(n,m,a);	
		}
		else if(choice==6){
			print_prime_number_in_the_matrix(n,m,a);
		}
		else if(choice==7){
			printf("Exit.");
			return 0;
		}
		else {
			printf("Invalid choice !\n");
		}
	}while(true);
	for(int i=0;i<n;i++){
		free(a[i]);
	}
	free(a);
}













