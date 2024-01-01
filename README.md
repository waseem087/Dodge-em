# Installation
## Prerequisites:
- cmake
- C++ compiler
  
Without the compiler, `cmake` won't be able to work.
You can clone the project using command
```
git clone https://github.com/waseem087/Dodge-em.git
```
Then to make the build files
```
cmake -S . -B build
```
And finally, compiling it for your hardware
```
cmake --build build --config Release
```
