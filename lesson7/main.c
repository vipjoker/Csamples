#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>
#include<string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];  
};

struct Database {
	struct Address rows[MAX_ROWS];
};

struct Connection {
	FILE *file;
	struct Database *db;
};

void die(const char *message){
	if(errno){
	perror(message);
	}else{
		printf("Error: %s\n",message);
	} 
	exit(1);
}

void address_print (struct Address *addr){
	printf("%d %s %s\n",addr->id,addr->name, addr->email);
}

void database_load(struct Connection *conn){
	int rc = fread(conn->db,sizeof(struct Database),1,conn->file);
	if(rc != 1) die("Failed to load database");
}

struct Connection *database_open(const char *filename, char mode){
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn)die ("Memory error");
	
	conn->db = malloc(sizeof(struct Database));
	if(!conn->db)die("Memory error");
	
	if(mode == 'c'){
		conn->file = fopen(filename,"w");	
	}else{
		conn->file = fopen(filename,"r");
		if(conn->file){
			database_load(conn);	
		}	
	}
	
	if(!conn->file){
		die("Failed to open the file");		
	}
	return conn;
}

void database_close(struct Connection *conn){
	if(conn){
		if(conn->file) fclose(conn->file);	
		if(conn->db)free(conn->db);
		free(conn);
	}
}

void database_write(struct Connection *conn){
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database),1,conn->file);
	if(rc != 1)die("Failed to write database.");

	rc = fflush(conn->file);
	if(rc == -1) die("Cannot flush database.");
}

void database_create(struct Connection *conn){
	int i = 0;
	for(i = 0; i < MAX_ROWS; i++){
		struct Address addr = {.id = 0, .set =0};
		conn->db->rows[i] = addr;	
	}
}

void database_set(struct Connection *conn, int id, const char *name,const char *email){
	struct Address *addr = &conn->db->rows[id];
	if(addr->set)die("Already set, delete it first");
	
	char *res = strncpy(addr->name,name,MAX_DATA);

	if(!res)die("Name copy failed");
	
	res = strncpy(addr->email,email,MAX_DATA);
	if(!res)die("Email copy failed");

}

void database_get(struct Connection *conn, int id){
	struct Address *addr = &conn->db->rows[id];

	if(addr->set){
		address_print(addr);	
	}else{
		die("ID is not set");
	}
}

void database_delete(struct Connection *conn,int id){
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void database_list(struct Connection *conn){
	int i = 0;
	struct Database *db = conn->db;

	for(i = 0; i < MAX_ROWS; i++){
		struct Address *curr = &db->rows[i];

		if(curr->set){
			address_print(curr);	
		}	
	}
}
int main(int argc, char *argv[]){
	if(argc < 3)die("USAGE: <dbfile> <action> [action params]");
	
	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = database_open(filename,action);
	int id =0;

	if(argc > 3) id =atoi(argv[3]);
	
	if(id >= MAX_ROWS)die("There's not that many records.");

	switch(action){
		case 'c':
			database_create(conn);
			database_write(conn);
			break;
		case 'g':
			database_get(conn,id);
			break;
		case 's':
			if(argc != 6)die("Need id, name, email to set");

			database_set(conn,id,argv[4],argv[5]);
			database_write(conn);
			break;
		case 'd':
			if(argc != 4)die("Need id to delete");
			
			database_delete(conn,id);
			database_write(conn);
			break;
		case 'l':
			database_list(conn);
			break;
		default:
			die("Invalid action, only: c=create, g=get, d=del, l=list");
	}
	database_close(conn);

	return 0;
}
