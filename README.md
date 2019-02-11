# CPlusPlusPlus
Personal playground for newer standards of C++

## std::shared_ptr reference count (shared_ptr_use_count.cpp)

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
baris@box:~/workspace/c++$ g++ -O0 -o move move.cpp 
baris@box:~/workspace/c++$ ./move 
Length: 2800000000
First operation took 1163 milliseconds
Length of the string after the call is 2800000000
Length: 2800000000
Second operation took 68 milliseconds
Length of the string after the call is 0
```

## std::unique_ptr (

```
baris@box:~/workspace/c++$ g++ -o unique_ptr unique_ptr.cpp -pthread
baris@box:~/workspace/c++$ ./unique_ptr 
task is valid
task is NOT valid
Name: foo Count: 5
Name: foo Count: 5
Name: foo Count: 5
^C
```

