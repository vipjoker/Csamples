#include<stdio.h>

int main (int argc, char *argv[]){
	
	if(argc == 2){
			FILE *f  = fopen(argv[1],"w+");
			fprintf(f,"This from code\n");
			fclose(f);
	}else{
		printf("Wrong number of arguments");	
	}

}
