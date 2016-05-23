#include<stdio.h>
#include<stdlib.h>

struct User {
	int age;
	char *name;
	char *lastName;
};

void printUser(struct User *user){
	printf("User age %d \nname %s\nlastName %s\n",user->age,user->name,user->lastName); 
}

char *readStrinag(){
	char array[20] ;
	int counter = 0;
	char letter = '0';
	while(letter != '\n'){
		letter = getchar();
		array[counter] = letter;
		counter++;
	}
	return &array;
//	char *namePointer = &array;
//	return  namePointer;
}

int main(int argc,char *argv[]){
	
	struct User *u = malloc(sizeof(struct User));
	
	u->age = 77;
	printf("Enter your name \n");
	u->name = readStrinag();
	printf("Enter your lastName\n");
	u->lastName = readStrinag();

	printUser(u);
	free(u); 

}


