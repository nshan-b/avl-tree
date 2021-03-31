# avl-tree
This is a basic implementation of an AVL Tree.

## Installation
Configure your CMake properly and build it however you want. It should spit out in a build directory as an .exe / .out file for both main.cpp & AVLTreeSanityCheck.cpp.  

## Usage
Filler code (at the moment) --> src/main.cpp 
Tests --> tests/AVLTreeSanityCheck.cpp 

Both create separate executables: AVL.exe & AVL_test.exe.

AVL_test uses GoogleTest as a dependency (see CMakeLists.txt) and runs different tests to see if we're getting accurate results. Basically through random insertion, random deletion, in-order traversals, etc.

## License
[MIT](https://choosealicense.com/licenses/mit/)
