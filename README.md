# embed99

Single-header C/C++ library under 200 LoC for embedding arbitrary files into your binary.

## Usage

1. Copy `embed99.h` into your project.
2. Include and embed files:
   ```c
   #include "embed99.h"
   embed(bin, "cool.bin");
   ```
3. Access data:
   ```c
   const void *data = edata(&bin);
   size_t len = elen(&bin);
   ```

## Example: Quine

Build and run the provided quine example:
```sh
cc -std=c99 -Wall -I. -o examples/quine examples/quine.c
./examples/quine
```

## License

Public-domain (0BSD). See header in `embed99.h` for full text.
