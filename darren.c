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

void write(int i, int j, float num)
{
	

	FILE *writeFile = fopen("File3ForLab3.txt", "w");
	if (writeFile == NULL)
	{
	    printf("Can't open File\n");
	    exit(1);
	}

	fseek(writeFile, 0, SEEK_END); // goto end of file
	if (ftell(writeFile) == 0)
 	{
      		fprintf(writeFile, "%d %d %f",i,j);
 	}
	fseek(writeFile, 0, SEEK_SET);
	
	fprintf(writeFile, "%d %d %f",i,j, num);


}


int** read (const char* filename)
{
 	FILE* readFile = fopen(filename, "r");
	int i = 0;
    	int lines[6][3];
	while (!feof(readFile))
	{  
				
		fscanf(readFile, "%d", &lines[i][0]); 
		fscanf(readFile, "%d", &lines[i][1]); 
		fscanf(readFile, "%d", &lines[i][2]);  		
		//printf("%d %d %d \n", lines[i][0],lines[i][1],lines[i][2]);
		   
		i++;
	}
	fclose(readFile); 
	return lines;       
}


void mapPhase (int* line, int* emit)
{

    i = line[0];
    j = line[1];
    value  = line[2];
    

    if(matrix == 'A')
        emit(i, {j, value, 'A'})
    else
        emit(j, {i, value, 'B'})


}


int main()
{
	int rows = 2;
	int columns=3;
	float* line = malloc(3*sizeof(float));
	line[0] = 0;
	line[1] = 0;
	line[2] = 2;

	
	

}






