/* Declare the myfunc1() function, so we know how to use it */
int myfunc1 (int);

/* Declare the myfunc2() function, so we know how to use it */
int myfunc2 (int);

/* Main function - calls myfunc1() so needs to know about myfunc1() */
int main (int argc, char* argv[]) {
  return myfunc1 (argc);
}

/* myfunc1() calls myfunc2() so needs to know about myfunc2() */
int myfunc1 (int i1) {
  return myfunc2 (i1) + 1;
}

/* myfunc2() doesn't need to call anything else */
int myfunc2 (int i2) {
  return 1 + i2;
}
