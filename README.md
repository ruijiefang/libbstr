# libbstr

`libbstr` is a C string library designed to be more useable than null terminated strings. Its memory layout is inspired by andirez's `sds`: https://github.com/antirez/sds, but it uses only heap memory and does not require the use of manual alignment. Everything is written in straightforward, vanilla C, and guaranteed to work.

## Features
 * Minimal storage - `libbstr` stores only 8 bytes of extra information (a pointer to the end of the string) before the pointer to each object
 * Backwards compatible - Casting a `bstr` object to `char *` yields your everyday null-terminated string (char array).
 * Fast `bstrcmp` implementation using SIMD in words.
 * Constant-time `bstrlen` call.

## Anti-features
 * Base library does not provide complex functions - Most utilities provided by `<string.h>` can fill in the void.
