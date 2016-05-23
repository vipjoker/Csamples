#include<stdio.h>
#include<stdlib.h>

struct User {
	int age;
	char *name;
	char *surname;	
};

void print_user(struct User *user){
	printf("User name %s surname %s age %d\n",user->name,user->surname,user->age);
}

int main (int argc, char *argv[])
	struct User *myself = malloc(sizeof(struct User)); 
	myself->age = 88;
	myself->name = "Oleh";
	myself->surname = "Makhobei";
	print_user(myself);
	
}
