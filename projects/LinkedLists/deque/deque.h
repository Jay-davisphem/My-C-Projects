typedef struct deque Deque;

/* Deque direction, returns -1 if empty */
#define DEQUE_FRONT (0) 
#define DEQUE_BACK (1) 
#define DEQUE_EMPTY (-1)

/* return a new empty deque */ 
Deque *dequeCreate(void);

/* push new value onto direction side of deque d */ 
void dequePush(Deque *d, int direction, int value);

/* pop and return first value on direction side of deque d */ 
/* returns DEQUE_EMPTY if deque is empty */
int dequePop(Deque *d, int direction);

/* return 1 if deque contains no elements, 0 otherwise */ 
int dequeIsEmpty(const Deque *d);

/* free space used by a deque */ 
void dequeDestroy(Deque *d);
