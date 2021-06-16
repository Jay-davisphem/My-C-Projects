#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
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

void die(const char *message, struct Connection *conn) {
  if (conn){
    if (conn->file)
      fclose(conn->file);
    if (conn->db)
      free(conn->db);
  }
  free(conn);
  if (errno) perror(message);
  else printf("ERROR: %s\n", message);

  exit(1);
}

void Address_print(struct Address *addr){
  printf("%d  %s  %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn){
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1)
    die("Failed to load Database", conn);
}

struct Connection *Database_open(const char *filename, char mode){
  struct Connection *conn = malloc(sizeof(struct Connection));
  if (!conn)
    die("Memory Error", conn);

  conn->db = malloc(sizeof(struct Database));
  if (!conn->db)
    die("Memory Error", conn);

  if (mode == 'c'){
    conn->file = fopen(filename, "w");
  }
  else{
    conn->file = fopen(filename, "r+");

    if (conn->file)
      Database_load(conn);
  }
  if (!conn->file)
    die("Failed to open the file", conn);


  return conn;
}

void Database_close(struct Connection *conn){
  if (conn){
    if (conn->file)
      fclose(conn->file);
    if (conn->db)
      free(conn->db);
  }
  free(conn);
}

void Database_write(struct Connection *conn){
  rewind(conn->file);
  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1)
    die("Failed to write database.", conn);
  
  rc = fflush(conn->file);
  if (rc == -1)
    die("Cannot flush database.", conn);
}
void Database_create(struct Connection *conn, unsigned int max_rows){
  int i = 0;
  for (i = 0; i < max_rows; i++){
    struct Address addr = {.id = i, .set = 0};
    conn->db->rows[i] = addr;
  }
}

void Database_set(struct Connection *conn, int id,
    const char *name, const char *email,
    unsigned int max_data){
  struct Address *addr = &conn->db->rows[id];
  if (addr->set)
    die("Already set, delete it first!", conn);

  addr->set = 1;
  char *res = strncpy(addr->name, name, max_data);
  res[sizeof(addr->name) - 1] = '\0';
  if (!res)
    die("Name copy failed!", conn);

  res = strncpy(addr->email, email, max_data);
  res[sizeof(addr->email) - 1] = '\0';
  if (!res)
    die("Email copy failed!", conn);
}

void Database_get(struct Connection *conn, int id){
  struct Address *addr = &conn->db->rows[id];
  if (addr->set){
    Address_print(addr);
  }
  else{
    die("ID is not set!", conn);
  }
}

void Database_delete(struct Connection *conn, int id){
  struct Address addr = {.id = id, .set = 0};
  conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn, unsigned int max_rows){
  int i = 0;
  struct Database *db = conn->db;

  for (i = 0; i < max_rows; i++){
    struct Address *cur = &db->rows[i];

    if (cur->set){
      Address_print(cur);
    }
  }
}

int main(int argc, char *argv[]){
  struct Connection *conn = NULL;
  if (argc < 3){
    char *l = "Usage: <filename.dat> <dbfile> <action> [action params]";
    /*strcat(l, argv[0]);
    strcat(l, " <dbfile> <action> [action params]");*/
    die(l, conn);
  }
  unsigned int max_rows = 100, max_data = 512;
  char *filename = argv[1];
  char action = argv[2][0];
  conn = Database_open(filename, action);
  int id = 0;
  if (argc > 3) id = atoi(argv[3]);
  if (id >= MAX_ROWS) die("There is not that many records!", conn);
  switch (action){
    case 'c':
      max_rows = atoi(argv[3]);
      Database_create(conn, max_rows);
      Database_write(conn);
      break;
    case 'g':
      if (argc != 4)
        die("Need an id to get!", conn);
      Database_get(conn, id);
      break;
    case 's':
      if (argc != 7)
        die("Need id, name, email and database max data to set!", conn);
      max_data = atoi(argv[6]);
      Database_set(conn, id, argv[4], argv[5], max_data);
      printf("Address id=%d, name=%s and %s filled in the database %s\n", id, argv[4], argv[5], filename);;
      Database_write(conn);
      break;
    case 'd':
      if (argc != 4)
        die("Need ID to delete.", conn);
      Database_delete(conn, id);
      Database_write(conn);
      break;
    case 'l':
      printf("id   name       email\n---------------------------------\n");
      max_data = atoi(argv[3]);
      Database_list(conn, max_rows);
      break;
    default:
      die("Invalid action: c=create, g=get, s=set, d=del, l=list", conn);
  }
  Database_close(conn);

  return 0;
}
