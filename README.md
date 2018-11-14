## Abstract VM - Simple typed virtual machine in C++

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
