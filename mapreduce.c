#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 

void write2(int i, int j, float num)
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



void mapPhase(map_container out)
{
	int rows,columns,rows2,columns2;
	

	// Read Files.................................................................................
	
	char filename[] = "File1ForLab3.txt";
	FILE* readFile = fopen(filename, "r");

	char filename2[] = "File2ForLab3.txt";
	FILE* readFile2 = fopen(filename2, "r");

		
	
	int i = 0;
    	
	fscanf(readFile, "%d", &rows);
	fscanf(readFile, "%d", &columns); 
	
	fscanf(readFile2, "%d", &rows2);
	fscanf(readFile2, "%d", &columns2); 

	int lines[rows*columns][3];
	int lines2[rows2*columns2][3];

	int numOfLines =i;
	while (1)
	{  
			
		if (fscanf(readFile, "%d", &lines[i][0])<1) break; 
		if (fscanf(readFile, "%d", &lines[i][1])<1) break;
		if (fscanf(readFile, "%d", &lines[i][2])<1) break;
		
		i++;
		numOfLines=i;
	}

	fclose(readFile); 

	int i2=0;
	int numOfLines2 =i;
    	while (1)
	{  
		
		if (fscanf(readFile2, "%d", &lines2[i2][0])<1) break;
		if (fscanf(readFile2, "%d", &lines2[i2][1])<1) break;
		if (fscanf(readFile2, "%d", &lines2[i2][2])<1) break;   
		i2++;
		numOfLines2=i2;
	}

	fclose(readFile2); 

	//------------------------------------done reading --------------------------------------------
	

	int keys[numOfLines*columns2][2];
	int keys2[numOfLines2*rows][2];
	int Values[numOfLines*columns2][2];
	int Values2[numOfLines2*rows][2];
	int count=0;
	

	//.................................... For M .............................................

	for (int k = 0 ; k < columns2; k++)
	{

		for (int p = 0; p< numOfLines;p++)
		{
			keys[count][0] = lines[p][0];
			keys[count][1] = k;
			Values[count][0] = lines[p][1];
			Values[count][1] = lines[p][2];		
			count++;	
			emit_intermediate(out,keys,Values);
		}

	}

	
	//...................................... For N ................................................


	int count2=0;

	for (int i = 0 ; i < rows; i++)
	{

		for (int p = 0; p< numOfLines;p++)
		{
			keys2[count2][0] = i;
			keys2[count2][1] = lines2[p][1];
			Values2[count2][0] = lines2[p][0];
			Values2[count2][1] = lines2[p][2];	
			count2++;
			emit_intermediate(out,keys2,Values2);
		}

	}
	
	 


}


int main()
{
	/*
	int rows,columns,rows2,columns2;
	

	// Read Files.................................................................................
	
	char filename[] = "File1ForLab3.txt";
	FILE* readFile = fopen(filename, "r");

	char filename2[] = "File2ForLab3.txt";
	FILE* readFile2 = fopen(filename2, "r");

	int i = 0;
    	int lines[6][3];
	int lines2[6][3];
	fscanf(readFile, "%d", &rows);
	fscanf(readFile, "%d", &columns); 
	
	fscanf(readFile2, "%d", &rows2);
	fscanf(readFile2, "%d", &columns2); 
	int numOfLines =i;
	while (1)
	{  
			
		if (fscanf(readFile, "%d", &lines[i][0])<1) break; 
		if (fscanf(readFile, "%d", &lines[i][1])<1) break;
		if (fscanf(readFile, "%d", &lines[i][2])<1) break;
		
		if (fscanf(readFile2, "%d", &lines2[i][0])<1) break;
		if (fscanf(readFile2, "%d", &lines2[i][1])<1) break;
		if (fscanf(readFile2, "%d", &lines2[i][2])<1) break;   
		i++;
		numOfLines=i;
	}
	fclose(readFile); 
	
	/*for (int j = 0 ; j< i;j++)
	{
		printf("%d %d %d \n", lines[j][0],lines[j][1],lines[j][2]); 
	}
	
	printf("\n");

	for (int j = 0 ; j< i;j++)
	{
		printf("%d %d %d \n", lines2[j][0],lines2[j][1],lines2[j][2]); 
	}
	
	int keyValuePairs[12][4];
	int keyValuePairs2[12][4];
	int count=0;


	// For M .....................................................................

	for (int k = 0 ; k < columns2; k++)
	{

		for (int p = 0; p< numOfLines;p++)
		{
			keyValuePairs[count][0] = lines[p][0];
			keyValuePairs[count][1] = k;
			keyValuePairs[count][2] = lines[p][1];
			keyValuePairs[count][3] = lines[p][2];
			
			//printf("i= %d, k= %d ,j= %d, njk= %d\n",lines[p][0],k,lines[p][1],lines[p][2]);		
					
			count++;
		}

	}

	//int[12][4]
	/*
	printf("after thing \n");
	for (int j = 0 ; j< 12;j++)
	{
		printf("%d,%d  %d,%d \n",keyValuePairs[j][0],keyValuePairs[j][1],keyValuePairs[j][2],
			keyValuePairs[j][3]);
	}
	

	
	// For N .....................................................................


	int count2=0;

	for (int i = 0 ; i < rows; i++)
	{

		for (int p = 0; p< numOfLines;p++)
		{
			keyValuePairs2[count2][0] = i;
			keyValuePairs2[count2][1] = lines2[p][1];
			keyValuePairs2[count2][2] = lines2[p][0];
			keyValuePairs2[count2][3] = lines2[p][2];
			
			//printf("i= %d, k= %d ,j= %d, njk= %d\n",i,lines2[p][1],lines2[p][0],lines2[p][2]);	
					
			count2++;
		}

	}
	

	
	printf("From M: \n");
	for (int j = 0 ; j< 12;j++)
	{
		printf("%d,%d  %d,%d \n",keyValuePairs[j][0],keyValuePairs[j][1],keyValuePairs[j][2],
			keyValuePairs[j][3]);
	}
	
	printf("From N \n");
	for (int j = 0 ; j< 12;j++)
	{
		printf("%d,%d  %d,%d \n",keyValuePairs2[j][0],keyValuePairs2[j][1],keyValuePairs2[j][2],
			keyValuePairs2[j][3]);
	}
 	


	// Sort By j
	for (int i = 0; i < 12-1; i++)      
	{
		for (int j = 0; j < 12-i-1; j++) 
		{
           		if (keyValuePairs[j][2] > keyValuePairs[j+1][2])
              		swap(&keyValuePairs[j][2], &keyValuePairs[j+1][2]);

			if (keyValuePairs2[j][2] > keyValuePairs2[j+1][2])
              		swap(&keyValuePairs2[j][2], &keyValuePairs2[j+1][2]);
		}
	}
	
	/*
	printf("From M (sorted): \n");
	for (int j = 0 ; j< 12;j++)
	{
		printf("%d,%d  %d,%d \n",keyValuePairs[j][0],keyValuePairs[j][1],keyValuePairs[j][2],
			keyValuePairs[j][3]);
	}
	
	printf("From N (sorted): \n");
	for (int j = 0 ; j< 12;j++)
	{
		printf("%d,%d  %d,%d \n",keyValuePairs2[j][0],keyValuePairs2[j][1],keyValuePairs2[j][2],
			keyValuePairs2[j][3]);
	}
	
	emit_intermediate(

	*/
	
	mapPhase();
	
	return 0;

}






