/* All definitions are declarations as well
 * So by defining functions in reverse order, all functions have been declared before they are called.
 */

int myfunc2 () {
  return 1;
}

int myfunc1 () {
  return myfunc2 ();
}

int main (int argc, char *argv[]) {
	return myfunc1();
}
