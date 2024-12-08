#include<stdio.h>
#include<stdlib.h>
void Enter_array(int *n,int**a){
	printf("Enter the number of elements :");
	scanf("%d",n);
	*a=(int *)malloc(*n*sizeof(int));
	for(int i=0;i<*n;i++){
		printf("Enter the %d-th element :",i+1);
		scanf("%d",&(*a)[i]);
	}
}

void Print_array(int n,int *a){
	printf("Print out the current managed array element :\n");
	for(int i=0;i<n;i++){
		printf("%3d",a[i]);
	}
	printf("\n");
}
void Add_element(int *n,int *a){
	printf("Enter the location you want to add (0-%d):",*n+1);
	int pos;
	scanf("%d",&pos);
	if(pos==0){
		pos=1;
	}
	if(pos<1||pos>*n+1){
		printf("Invalid location !\n");
		return;
	}
	printf("Enter the value you want to enter :");
	int value;
	scanf("%d",&value);
	for(int i=*n;i>=pos;i--){
		a[i]=a[i-1];
	}
	a[pos-1]=value;
	*n+=1;
	printf("Add elements successfull!\n");
}
void Fix_element(int n,int *a){
	printf("Enter the location you want to fix (1-%d) :",n);
	int pos;
	scanf("%d",&pos);
	if(pos<1||pos>n){
		printf("Invalid location !\n");
		return;
	}
	printf("Enter the value you want to edit :");
	int value;
	scanf("%d",&value);
	a[pos-1]=value;
	printf("Fix elements successfull!\n");
}
void Delete_element(int *n,int *a){
	printf("Enter the location you want to delete (1-%d):",*n);
	int pos;
	scanf("%d",&pos);
	if(pos==0){
		pos=1;
	}
	if(pos<1||pos>*n){
		printf("Invalid location !\n");
		return;
	}
	for(int i=pos-1;i<*n;i++){
		a[i]=a[i+1];
	}
	*n-=1;
	printf("Delete elements successfull!\n");
}
void Arrange_elements(int n,int *a){
	printf("a.Sort descending\n");
	printf("b.Sort ascending\n");
	char option;
	do{
		printf("Please enter option a or b :");
		scanf(" %c",&option);	
	}while(option!='a'&&option!='b');
	if(option=='a'){
		printf("Sorting in descending order... \n");
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				if(a[j]<a[j+1]){
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
	}
	if(option=='b'){
		printf("Sorting in ascending order...\n");
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				if(a[j]>a[j+1]){
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
	}
	printf("Arranged successfully!\n");
}
void Search_element(int n,int *a){
	int is_descending=1;
	int is_ascending =1;
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			is_ascending=0;
		}
		if(a[i]<a[i+1]){
			is_descending=0;
		}
	}
	if(is_ascending==1){
		printf("The array is sorted in ascending order.\n");
	}
	else if(is_descending==1){
		printf("The array is sorted in descending order.\n");
	}
	else{
		printf("The array is not sorted.\n");
	}
	printf("Enter the number you want to search :");
	int number;
	int pos=-1;
	scanf("%d",&number);
	if(is_ascending==1){
		int l=0;
		int r=n-1;
		while(l<=r){
			int m=(l+r)/2;
			if(a[m]==number){
				pos=m;
				break;
			}
			else if(a[m]<number){
				l=m+1;
			}
			else{
				r=m-1;
			}
		}
	}
	else if(is_descending==1){
		int l=0;
		int r=n-1;
		while(l<=r){
			int m=(l+r)/2;
			if(a[m]==number){
				pos=m;
				break;
			}
			else if(a[m]<number){
				r=m-1;
			}
			else{
				l=m+1;
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(a[i]==number){
				pos=i;
				break;
			}
		}	
	}
	if(pos==-1){
		printf("This element not found !\n");
	}
	else{
		printf("Element %d at index %d.\n",number,pos);
	}
}



int main(){
	int *a;
	int n=0;
	do{
		printf("1.Enter array.\n");
		printf("2.Print array.\n");
		printf("3.Add a element.\n");
		printf("4.Fix a element.\n");
		printf("5.Delete a element.\n");
		printf("6.Arrange array.\n");
		printf("7.Search a element.\n");
		printf("8.Exit.\n");
		int choice;
		printf("Enter your choice :");
		scanf("%d",&choice);
		if(choice==1){
			Enter_array(&n,&a);
		}
		else if(choice==2){
			Print_array(n,a);	
		}
		else if(choice==3){
			Add_element(&n,a);	
		}
		else if(choice==4){
			Fix_element(n,a);	
		}
		else if(choice==5){
			Delete_element(&n,a);		
		}
		else if(choice==6){
			Arrange_elements(n,a);
		}
		else if(choice==7){
			Search_element(n,a);
	
		}
		else {
			printf("Invalid choice !\n");
		}
	}while(true);
}
