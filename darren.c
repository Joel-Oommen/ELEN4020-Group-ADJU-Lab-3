#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void populateArray(int A[3][3], int dimension)
{

	int ELEM = dimension;
	for(int i=0;i<ELEM;i++)
	{
		for(int j=0;j<ELEM;j++)
		{
			A[i][j]=0;
		}
	}
}


void printArray(int A[3][3], int dimension)
{

	int ELEM = dimension;
	for(int i=0;i<ELEM;i++)
	{
		for(int j=0;j<ELEM;j++)
		{
			printf("%d \t", A[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int row = 3;
	int col = 3;
	int A[row][col];
	int B[row][col];
	int C[row][col];
	int D[row][col];
	A[0][0] = 0;
	A[0][1] = -1;
	A[0][2] = -1;
	A[1][0] = 1;
	A[1][1] = 0;
	A[1][2] = 1;
	A[2][0] = 1;
	A[2][1] = -1;
	A[2][2] = 0;
	B[0][0] = 0;
	B[0][1] = 1;
	B[0][2] = 1;
	B[1][0] = -1;
	B[1][1] = 0;
	B[1][2] = -1;
	B[2][0] = -1;
	B[2][1] = 1;
	B[2][2] = 0;

	populateArray(C,row);
	populateArray(D,row);

	for (int i = 0 ; i < row; i++)
	{
  		for (int j = 0 ; j < col; j++)
		{
     			C[i][j]=0.0;
			
     			for (int k = 0 ; k < col; k++)
			{
        			C[i][j] = C[i][j]+A[i][k]*A[k][j];
				
			}
    			 
   		} 
	}


	for (int i = 0 ; i < row; i++)
	{
  		for (int j = 0 ; j < col; j++)
		{
     			D[i][j]=0.0;
			
     			for (int k = 0 ; k < col; k++)
			{
        			D[i][j] = D[i][j]+C[i][k]*C[k][j];
				
			}
    			 
   		} 
	}

		
	printArray(C,row);

	printf("\n");

	printArray(D,row);

}
