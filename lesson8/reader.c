#include<stdio.h>

int main (int argc, char *argv[]){
	char buffer[200];
	if(argc != 2){
		printf("Wrong num of arguments\n");
	}else{
		FILE *f = fopen(argv[1],"r");	
		int result =fscanf(f,"%s",buffer);
		int result2 =fscanf(f,"%s",buffer);
		printf("Result is %d\n",result);
		printf("Result is %d\n",result2);
		printf("File read %s",buffer);
		fclose(f);	
	}
}
