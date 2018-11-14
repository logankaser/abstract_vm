## Abstract VM - Simple typed virtual machine in C++

Implements five number types: three integer types or 1, 2, and 4 byte widths, and two floating point types of
4 and 8 byte widths.
Features a simple precision promotion model, if an `float` and a `double` are added the result will be a `double`.
Implemented in C++11 making use of..  
 *class templates*, *class specialization*, *abstract virtual classes* and *custom exceptions*.

### Grammar
Type           | Regular expression
---------------|------------
**Int**        | `(int8\|int16\|int32)((-?[\d]+)))`
**Float**      | `(float\|double)((-?[\d]+.[\d]+)))`
**Operation**  | `(pop\|dump\|add\|sub\|mul\|div\|mod\|print\|exit)(?: *;.*)?`
**Function**   | `(push\|assert\|loop) (\w+(\S+))(?: *;.*)?`
**Termination**| `;([^;]+)`

### Dependencies
`make`  
`clang++`  
### Building
```
git clone https://github.com/logankaser/abstract_vm.git
cd abstract_vm
make
```
### Usage
```
./avm # enter interpreted mode / repl
# or
./avm file.avm # interpret file of instructions
```
