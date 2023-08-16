#include<stdio.h>
int main()
{
	int a[10][10], b[10][10], m[10][10], r, c, i, j ,k;
	printf("Rows: ");
	scanf("%d", &r);
	printf("Columns: ");
	scanf("%d", &c);
	printf("First matrix element: ");
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("Second matrix element: ");
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			scanf("%d", &b[i][j]);
		}
	}
	printf("Result: \n");
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			m[i][j]=0;
			for(k=0; k<c; k++){
				m[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
	return 0;	
}
