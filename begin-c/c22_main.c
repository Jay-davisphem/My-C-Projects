#include "c22.h"
#include "dbg.h"

const char *MY_NAME = "David O. Joshua";

void scope_demo(int count){
  log_info("count is %d", count);

  if (count > 10){
    int count = 100;

    log_info("count in this scope is %d.", count);
  }

  log_info("count is at the exit: %d", count);

  count = 3000;

  log_info("count after assign: %d", count);
}

int main(int argc, char *argv[]){
  log_info("My name: %s, age: %d", MY_NAME, get_age());

  set_age(100);

  log_info("The age is now %d.", get_age());

  log_info("THE_SIZE is %d", THE_SIZE);
  print_size();

  THE_SIZE = 9;

  log_info("THE_SIZE is now %d", THE_SIZE);
  print_size();

  // test the ratio function static
  log_info("Ratio at first: %f", update_ratio(2.0));
  log_info("Ratio again: %f", update_ratio(10.0));
  log_info("Ratio once more: %f", update_ratio(300.0));

  // The the scope demo
  int count = 74;
  scope_demo(count);
  log_info("count after calling scope_demo: %i", count);
  int ptr = count *20;
  scope_demo(ptr);

  log_info("count after calling scope_demo: %i", count);

  return 0;
}
