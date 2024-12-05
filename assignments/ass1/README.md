# Assignment 1

## Requirements

Write a program to manage integers according to the following requirements:

### Functional Requirements

When the program runs, it should display an introduction:
"Integer Array Management Program"
and instructions for using the program's features:

- Enter 'c' to create an integer array (if an array already exists, clear the old array data).
- Enter 'p' to print the array (if the array has no values, notify the user that the array is empty).
- Enter 'i' to insert an element at position k, as specified by the user.
- Enter 'd' to delete an element at position k (if position k does not contain a value, notify the user that element k does not exist).
- Enter 's' to sort the array in ascending order.
- Enter 'x' to sort the array in descending order.
- Enter 't' to search for a number x in the array (the user will input x via the keyboard).
- Enter 'e' to exit the program.

### Technical Requirements:

- The program must separate functionality into different files (though excessive splitting is unnecessary).
- Variables must not be shared between files. The purpose is to ensure that functional files can act as libraries and be integrated anywhere.
- The program should validate all input conditions because users may input invalid data at any point.

---

## How to run

- We will use a very simple Makefile, the command `make` will build all the necessary source code and put it into a `/.build` folder to hold the binary.

```bash
make # Build the entire program
./build/main # Run the program
make clean # Clean .build
```

