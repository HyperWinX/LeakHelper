<div align="center">
    <h1>LeakHelper</h1>
    <p>Small library for removing all unwanted memory leaks, caused by forgetting to deallocate memory.</p>
    <p>
        <a href="https://github.com/HyperWinX/CTeatify/graphs/contributors">
            <img src="https://img.shields.io/github/contributors/HyperWinX/LeakHelper" alt="contributors"/>
        </a>
        <a href="https://github.com/HyperWinX/LeakHelper/commits/master">
            <img src="https://img.shields.io/github/last-commit/HyperWinX/LeakHelper" alt="last commit"/>
        </a>
        <a href="https://github.com/HyperWinX/LeakHelper/network/members">
            <img src="https://img.shields.io/github/forks/HyperWinX/LeakHelper" alt="forks"/>
        </a>
        <a href="https://github.com/HyperWinX/LeakHelper/stargazers">
            <img src="https://img.shields.io/github/stars/HyperWinX/LeakHelper" alt="contributors"/>
        </a>
        <a href="https://github.com/HyperWinX/LeakHelper/issues">
            <img src="https://img.shields.io/github/issues/HyperWinX/LeakHelper" alt="contributors"/>
        </a>
    </p>
</div>
<br/>

# Contents
- [About LeakHelper](#about-leakhelper)
- [Installation](#installation)
- [Usage](#usage)
    - [Initialize listing](#initialize-listing)
    - [Allocating memory](#allocating-memory)
    - [Freeing memory](#freeing-memory)
    - [Finishing program](#finish-program)
    - [Example](#example)

## About LeakHelper
Small library for removing all unwanted memory leaks, caused by memory allocators/deallocators.

## Installation
1. Download [header](leakhelper.h) and [source file](leakhelper.c).
2. Include header into your source file when you want to use it.
3. Use!

## Usage

### Initialize listing
First, you need to initialize listing. To do so, execute function and pass maximum count of pointers program will use.
```c
init_listing(4); // Allocate memory for 4 pointers
```

### Allocating memory
You have two functions for allocating memory: lmalloc() and lcalloc(). All of them take exactly one argument - memory size, and return pointer. Don't forget to check if it's valid!
```c
void* ptr1 = lmalloc(32); // Allocate raw memory block 32 bytes size
void* ptr2 = lcalloc(64); // Allocate zero'ed out memory block 64 bytes size
```

### Freeing memory
There is one function to free pointer: lfree(). Works only with pointers created using lmalloc() or lcalloc().
```c
lfree(ptr1);
```

### Finish program
At the end of program (or function) you can put free_all() function to free all pointers created with library, and prevent memory leaks.
```c
free_all();
```

### Example
[This](main.c) is an example.