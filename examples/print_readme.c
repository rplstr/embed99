/* This example embeds the README of this directory. Pretty cool, right? */

#include "embed99.h"
#include <stdio.h>

e99_embed(readme, "README.md");

int main(void) {
  fputs((const char *)e99_edata(&readme), stdout);
  return 0;
}
