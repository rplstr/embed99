## Quine

> A quine is a computer program that takes no input and produces a copy of its own source code as its only output.

This example embeds its own binary into the data section and then prints the source at runtime.

Build and run:
```sh
cc -I.. -o quine quine.c
./quine
```

## Print README

This example embeds and prints the project’s README file.

Build and run:
```sh
cc --I.. -o print_readme print_readme.c
./print_readme
```
