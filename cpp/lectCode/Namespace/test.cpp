#include <iostream>
#include "foo.h"
#include "bar.h"

int main (int argc, char **argv) {
  foo::myfunc();
  bar::myfunc();
  return 0;
}