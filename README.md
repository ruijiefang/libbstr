# libbstr

`libbstr` is a C string library designed to be more useable than null terminated strings. Its memory layout is inspired by andirez's `sds`: https://github.com/antirez/sds, but it uses only heap memory and does not require the use of manual alignment. Everything is written in straightforward, vanilla C, and guaranteed to work.
