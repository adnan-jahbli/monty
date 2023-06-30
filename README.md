# Monty Interpreter

The `monty interpreter` is designed to execute Monty ByteCodes files, which provide a scripting language similar to Python.

## Overview of Monty Language
Monty language is specifically created for manipulating data information, such as stacks or queues. Each instruction, known as an opcode, is sent per line. Monty byte code files typically have the .m extension.

Here's an example of a Monty byte code file (`file.m`):
```bash
$ cat file.m
# Pushing element to the stack
push 0
push 1
push 2
# Printing all elements
pall
push 3
push 4
pop
# Rotating the stack to the bottom
rotr
pall
rotl
# Setting FIFO
queue
push 5
# Setting LIFO
stack
push 5
$
```

## Technologies Used
* The interpreter is implemented in the C programming language.
* C files are compiled using `gcc compiler`.
* The C files follow the C90 standard.
* Tested on Ubuntu 20.04 LTS.

## Usage
To compile all the files, use the following command::

```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$
```

The **synopsis** for running the interpreter is as follows:

```bash
$ ./monty [filename]
$
```

To execute the interpreter with a Monty byte code file:

```bash
$ ./monty file.m
2
1
0
0
3
2
1
$
```

## Features
### Opcodes
The `monty` interpreter supports the execution of various opcodes:

| Opcode | Description |
| -------- | ----------- |
| `push` | Pushes an element to the stack |
| `pall` | Prints all the values on the stack |
| `pint` | Prints the value at the top of the stack |
| `pop` | Removes the top element of the stack |
| `swap` | Swaps the top two elements of the stack |
| `queue` | Sets the format of the data to a queue (FIFO) |
| `stack` | Sets the format of the data to a stack (LIFO) |
| `nop` | Doesn't do anything |
| `add` | Adds the top two elements of the stack |
| `sub` | Subtracts the top element of the stack from the second top element of the stack |
| `mul` | Multiplies the second top element of the stack with the top element of the stack |
| `div` | Divides the second top element of the stack by the top element of the stack |
| `mod` | Computes the rest of the division of the second top element of the stack by the top element of the stack |
| `pchar` | Prints the char at the top of the stack |
| `pstr` | Prints the string starting at the top of the stack |
| `rotl` | Rotates the stack to the top |
| `rotr` | Rotates the stack to the bottom |

Any line starting with `#` is treated as a comment and is not executed by the interpreter.

If an **unknown opcode** is encountered, the interpreter displays an error message and stops:

```bash
$ cat errorfile.m
push 1
pint
pcx
$ ./monty errorfile.m
1
L3: unknown instruction pcx
```

### Return Value
The `monty` interpreter returns `0` when no errors occur. Otherwise, it returns `1`.

## Authors
* Adnane Jahbli: [Twitter](https://twitter.com/AdnaneJahbli) - [GitHub](https://github.com/adnan-jahbli)
