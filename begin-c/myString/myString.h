/* make a struct string * that holds a copy of s */ 
/* returns 0 if malloc fails */
struct string *makeString(const char *s);

/* destroy a struct string * */
void destroyString(struct string *s);

/* return the length of a struct string * */
int stringLength(struct string *s);

/* return the character at position index in the struct string * */
/* or returns -1 if index is out of bounds */
int stringCharAt(struct string *s, int index);
