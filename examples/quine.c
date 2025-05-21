/* This is not really a quine since we're basically cheating by embeding the
 * source file. But works as an example, so what do you want? */
#include "embed99.h"
#include <stdio.h>

embed(quine_source, "examples/quine.c");

int main(void) {
  fwrite(edata(&quine_source), 1, elen(&quine_source), stdout);
  return 0;
}
