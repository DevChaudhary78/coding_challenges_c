> This repository is dedicated to [codingchallenges.fyi](https://codingchallenges.fyi), where I would try to solve a challenge every weekend. 📈

## Installation & Usage
- Clone this repository, and you need a C compiler like `gcc`, `clang`, etc.
- Locate any challenge you would like to run
- You'll find some helper c files and header files, you will need to compile all of them and link them together
```
gcc -c wc.c -o wc.o
gcc -c counting.c -o counting.o
gcc wc.o counting.o -o wc
```

## Structure
Every challenge is modularized in its sub-repository.
```
| wc
| --- wc.c
| --- wc.h
| --- counting.c
| --- counting.h
```
