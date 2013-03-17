#include <stdio.h>

/* Create a simple structure with three members.
 * Members appear one after another in memory
 */
struct Time {
  int hour;
  int minute;
  int second;
};

/* And a shorted version */
struct Date {
  int d, m, y;
};

int main (int argc, char* argv[]) {
  /* Create a variable of type 'struct Date' and initialise it
   * Notice that the initialiser is like that for an array:
   * Comma separated, with {} surrounding.
   */
  struct Date dob = { 01, 04, 1990 };
  /* Print the values of the members, using the . operator */
  printf( "DOB: %02d/%02d/%04d\n", dob.d, dob.m, dob.y);
  /* We can also assign to a member using the . operator */
  dob.d = 2;

  return 0;
}
