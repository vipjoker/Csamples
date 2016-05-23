#include<stdio.h>

int main(int argc, char *argv[]){
	int array[] = {2,4,6,8};
	int count = sizeof(array)/sizeof(int);

	int i =0;
	for (i = 0 ; i < count; i++){
		printf("Letter %d\n",*(array+i));
	}

	printf("-------\n");

	char *names[] = {
		"Oleh","Ivan","Petro","Danylo"	
	};
	 i = 0;
	int j = 0;	
	while(i < sizeof(names)/sizeof(*names)){
		char *word = *(names + i);
		j = 0;
		while(*(word + j) != '\0'){
			printf("%c",*(word + j));	
			j++;
		}	
		printf("\n");
		i++;
	}
}
