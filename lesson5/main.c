#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

struct Person{
	char *name;
	int age;
	int weight;
	int height;
};

struct Person *person_create(char *name,int age, int height,int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);
	who->name = strdup(name);
	who->age = age;
	who->height= height;
	who->weight = weight;
	return who;
}

void person_destroy(struct Person *who){
	assert(who != NULL);
	free(who->name);
	free(who);

}

void person_print(struct Person *who){
	printf("Name: %s \n",who->name);
	printf("\tAge: %d\n",who->age);
	printf("\tHeight: %d\n",who->height);
	printf("\tWeight: %d\n",who->weight);
}

int main (int argc, char *argv[]){
	struct Person *joe = person_create("Joe",32,54,140);
	struct Person *ivan = person_create("Bod",33,66,170);
	printf("Joe is location %p\n",joe);
	person_print(joe);
	printf("Ivan is location %p\n",ivan);
	person_print(ivan);
	
	joe->age += 20;
	joe->height -=2;
	joe->weight +=30;
	person_print(joe);
	
	ivan->age +=10;
	ivan->height -=5;
	ivan->weight +=10;
	person_print(ivan);

	person_destroy(joe);
	person_destroy(ivan);
	return 0;
}
