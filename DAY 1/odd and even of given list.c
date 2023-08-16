#include<stdio.h>
int main(){
	int i;
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	printf("Even numbers: \n");
	for(i=0; i<10; i++){
		if(a[i]%2==0){
			printf("%d ", a[i]);
		}
	}
	printf("\n");
	printf("Odd numbers: \n");
	for(i=0; i<10; i++){
		if(a[i]%2!=0){
			printf("%d ", a[i]);
		}
	}
	return 0;
}
