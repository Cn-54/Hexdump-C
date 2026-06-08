# hexdump-c
simple command line tool to print the contents of a file as hex with an ascii representation

## Output Format
each line consists of the offset followed by 16 bytes of hex then the ascii representation with all non printables displayed as "."

```
00000000  23 69 6e 63 6c 75 64 65 20 3c 73 74 64 69 6f 2e  | #include <stdio.
00000010  68 3e 0a 0a 69 6e 74 20 6d 61 69 6e 28 69 6e 74  | h>..int main(int
```
## Build

```bash
gcc src/hexdump.c -o hexdump
```

## Usage

```bash
./hexdump <file>
```
