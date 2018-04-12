# Chapter 6. Functions
## Chapter 6.1 Function basics
### Exercise 6.1

>**Parameters**: Local variable declared inside the function parameter list.
they are initialized by the **arguments** provided in the each function call.
>**Arguments**: Values supplied in a function call that are used to initialize the function's **parameters**.

### Exercise 6.2

```cpp
(a) string f() {
          string s;
          // ...
          return s;
    } //function type wrong
(b) void f2(int i) { /* ... */ }//function type wrong
(c) int calc(int v1, int v2) { /* ... */ } //parameters' name can't be the same
(d) double square (double x) { return x * x; } // { } 
```

### Exercise 6.3

```cpp
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
int fact(int i);
int factRecursive(int i);
int main(int argc, char const *argv[])
{
    cout << fact(5) <<endl;
    cout << factRecursive(6) <<endl;
}

int fact(int i){
    if(i == 0 | i ==1) return 1;
    int ret = 1;
    ++i;
    while(i > 1){
        ret *= (--i);
    }
    return ret;
}
 
int factRecursive(int i){
    if(i == 0 | i ==1) return 1;
    else return i * factRecursive(i-1);
}
```

### [Exercise 6.4](ex_6_4.cpp)

### [Exercise 6.5](ex_6_5.cpp)

### Exercise 6.6

>**local variable**: Variables defined inside a **block**;
>**parameter**: **Local variables** declared inside the **function parameter list**
>**local static variable**: **local static variable（object）** is initialized before the first time execution passes through the object’s definition.**Local statics** are not destroyed when a function ends; they are **destroyed when the program terminates.**

for example:

```cpp
int fun_counter(int val){
    static int counter;
    int local_var = 0;
    ++counter;
    cout << val <<endl;
    cout << val + local_var <<endl;
}
```

### Exercise 6.7

```cpp
int fun_cnt(){
    static int cnt;
    /* do something*/
    return cnt++; 
}
```

### [Exercise 6.8](Chapter6.h)

### Exercise 6.9 [fact.cc](fact.cc)|[factMain.cc](factMain.cc)
Tips: on Mac osX, you should use:
`CC factMain.o fact.o -lstdc++ ` to link these .o files.

### [Exercise 6.10](ex_6_10.cpp)

### [Exercise 6.11](ex_6_11.cpp)

### [Exercise 6.12](ex_6_12.cpp)

I think useing reference is more convenient. no more '*', just use agruments' another name 'refrence'.

### Exercise 6.13

`void f(T)` pass the argument by value. **nothing the function does to the parameter can affect the argument**.
`void f(T&)` pass a reference, will be **bound to** whatever T object we pass.

### Exercise 6.14
a parameter should be a reference type:

```cpp
void reset(int &i)
{
        i = 0;
}
```

a parameter should not be a reference:
we want to use the iterator to print values but keep it unchanged. If it's a refrence, the begin iterator will be changed.

```cpp
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
        for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
                std::cout << *iter << std::endl;
}
```

### Exercise 6.15

>why is `s` a reference to const but `occurs` is a plain reference?

cause the `s` should not be changed by this function. but `occurs`'s result must be calculated by the function.

>Why are these parameters references, but the char parameter `c` is not?

It's OK to use const reference here but copying a `char` directly would be more memory-efficient.
use reference can avoid copying, so it's more memory-efficient for string using reference.
and cause `occurs` would be changed in function body, so it should be a reference.

>What would happen if we made `s` a plain reference? What if we made `occurs` a reference to const?

`s` could be changed in the function, and `occurs` would not be changed. so `occurs = 0;` is an error.

### Exercise 6.16

```cpp
bool is_empty(const string& s) { return s.empty(); }
```

Since this function doesn't change the argument,"const" shoud be added
before string&s,otherwise this function is misleading and can't be used
with const string or in a const function.

## [Exercise 6.17](ex_6_17.cpp)

Not the same.
For the first one "const" was used, since no change need to do for the argument.
For the second function,"const" can't be used,because the content of the agument should be changed.

### Exercise 6.18

(a)

```cpp
bool compare(const matrix &m1, const matrix &m2);
```
to compare tow matrixs is equal or not.
(b)

```cpp
vector<int>::iterator change_val(int, vector<int>::iterator);
```

### Exercise 6.19

(a) illegal, only one parameter.
(b) legal.
(c) legal.
(d) legal.

### Exercise 6.20

If we can use `const`, just use it. If we make a parameter a plain reference when it could be a reference to `const`,
the reference value maybe changed.

### [Exercise 6.21](ex_6_21.cpp)

### [Exercise 6.22](ex_6_22.cpp)

### [Exercise 6.23](ex_6_23.cpp)

### Exercise 6.24

>Arrays have two special properties that affect how we define and use functions that operate on arrays: We cannot copy an array, and when we use an array it is (usually) **converted to a pointer**.

So we cannot pass an array by value, and when we pass an array to a function, we are actually passing a pointer
to the array's first element.

In this question, `const int ia[10]` is actually same as `const int*`, and the size of the array is **irrelevant**.
we can pass `const int ia[3]` or `const int ia[255]`, there are no differences. If we want to pass an array which size is ten, we should use reference like that:

```cpp
void print10(const int (&ia)[10]) { /*...*/ }
```

see more discusses at <http://stackoverflow.com/questions/26530659/confused-about-array-parameters>

### [Exercise 6.25](ex_6_25.cpp)

### [Exercise 6.26](ex_6_26.cpp)

### [Exercise 6.27](ex_6_27.cpp)

### Exercise 6.28

The type of `elem` in the `for` loop is `const std::string&`.

### Exercise 6.29

Depends on the type of elements of `initializer_list`. When the type is [PODType](http://en.cppreference.com/w/cpp/concept/PODType), reference is unnecessary. Because `POD` is **cheap to copy**(such as `int`). Otherwise, Using reference(`const`) is the better choice.