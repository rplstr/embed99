# embed.c

Single-header C/C++ library under 100 LoC for embedding arbitrary files into your binary.

## Usage

1. Copy `embed99.h` into your project.
2. Include and embed files:
   ```c
   #include "embed99.h"
   e99_embed(bin, "cool.bin");
   ```
3. Access data:
   ```c
   const void *data = e99_edata(&bin);
   size_t len = e99_elen(&bin);
   ```

## License

This project is licensed under the 0BSD license. See [LICENSE](LICENSE) for full text.
