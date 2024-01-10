#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
	int id;
	int set;
	int name[MAX_DATA];
	int email[MAX_DATA];
}; // struct closures have a semicolon

struct Database {
	struct Address rows[MAX_ROWS];
};

struct Connection {
	FILE *file;
	struct Database *db;
};

void die(const char *message) {
 
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}

	exit(1);

}

void Address_print(struct Address *addr) {
	printf("%d %s %s \n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn) {
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc != 1)
		die("Failed to load Database"); 
}

struct Connection *Database_open(const char *filename, char mode) 
{

	struct Connection *conn = malloc(sizeof(struct Connection));
	if (!conn)
		die("Memory error.");

	conn->db = malloc(sizeof(struct Database));
	if (!conn->db)
		die("Memory error.");
	
	if (mode == 'c') {
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");
		
		if (conn->file) {
			Database_load(conn);
		}
	}

	if (!conn->file) 
		die("Failed to open the file");


	return conn;
}

void Database_close(struct Connection *conn) {
	if (conn) {
		if (conn->file)
			fclose(conn->file);
		if (conn->db)
			free(conn->db);
		free(conn);
	}
}

void Database_write(struct Connection *conn) {

	rewind(conn->file);
	
	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
	if (rc != 1)
		die("Failed to write database.");
	rc = fflush(conn->file);
	if (rc == -1)
		die("Cannot flush database.");
}


void Database_create(struct Connection *conn) {

}

void Database_set(struct Connection *conn, int id, const char *name, const char *email) {
	
}

void Database_get(struct Connection *conn, int id) {

}

void Database_delete(struct Connection *conn, int id) {

}

void Database_list(struct Connection *conn) {

}

int main(int argc, char *argv[]) {
	if (argc < 3)
		die("USAGE: ex17 <dbfile> <action> [action params]");

	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn =  Database_open(filename, action);
	int id = 0; 

	if (argc > 3) id = atoi(argv[3]);
	if (id >= MAX_ROWS) die("There aren't that many records. Exiting.");

		switch(action) {
			case 'c':
      				Database_create(conn);
      				Database_write(conn);
      				break;
			case 'g':
				break;
			case 's':
				break;
			case 'd':
				break;
			case '1':
				break;
			default:
				die("Invalid action. Available actions: (c)reate (g)et, (s)et, (d)elete, (l)ist");
			}

		return 0;

}
