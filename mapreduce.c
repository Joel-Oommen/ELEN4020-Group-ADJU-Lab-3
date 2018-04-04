#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>



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



void mapPhase (int* line, int* emit)
{

    


}


int main()
{
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
	}*/
	
	int keyValuePairs[6][4];
	int keyValuePairs2[6][4];
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
			
			//printf("k= %d, p= %d ,count= %d\n",k,p,count);	
					
			count++;
		}

	}
	/*
	printf("after thing \n");
	for (int j = 0 ; j< 12;j++)
	{
		printf("%d,%d  %d,%d \n",keyValuePairs[j][0],keyValuePairs[j][1],keyValuePairs[j][2],
			keyValuePairs[j][3]);
	}
	*/

	
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
	

	/*
	printf("after N \n");
	for (int j = 0 ; j< 12;j++)
	{
		printf("%d,%d  %d,%d \n",keyValuePairs[j][0],keyValuePairs[j][1],keyValuePairs[j][2],
			keyValuePairs[j][3]);
	}
	printf("heeeeeey \n");
	printf("after thing \n");
	for (int j = 0 ; j< 12;j++)
	{
		printf("%d,%d  %d,%d \n",keyValuePairs2[j][0],keyValuePairs2[j][1],keyValuePairs2[j][2],
			keyValuePairs2[j][3]);
	}
 
	*/

	 

	


	return 0;

}






