/* This example embeds the README of our library. Pretty cool, right? */

#include "embed99.h"
#include <stdio.h>

embedtxt(readme, "README.md");

int main(void) {
  fputs((const char *)edata(&readme), stdout);
  return 0;
}
