# CPlusPlusPlus
Personal playground for newer standards of C++

## shared_ptr use count (shared_ptr_use_count.cpp)

```
baris@box:~/workspace/c++$ g++ -o shared_ptr_use_count shared_ptr_use_count.cpp 
baris@box:~/workspace/c++$ ./shared_ptr_use_count 
Deleted.
Use count = 2
Use count = 3
Use count = 1
Deleted.
```

## std::move() (move.cpp)

```
baris@box:~/workspace/playground/c++$ g++ -O0 -o move move.cpp 
baris@box:~/workspace/playground/c++$ ./move 
Length: 2800000000
First operation took 1163 milliseconds
Length: 2800000000
Second operation took 68 milliseconds
```
