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

### [Exercise 6.17](ex_6_17.cpp)

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

## Return Expression

NOTE: Return Stetament have two forms, `return;` `return expression;`

### Exercise 6.30

Error (Clang):
> Non-void function 'str_subrange' should return a value. // error #1
>
> Control may reach end of non-void function. // error #2

### Exercise 6.31
Never return a reference to a local object.
If the function return type is a reference, do not return constants and the references of local temporary variables, because literal constants will be  converted to a local temporary variable and returned, which is an undefined behavior. It's `UB`.

### Exercise 6.32

legal, `ia` is a array with the size of 10, use `get()` function to give the values(0-9) to `ia`.

### [Exercise 6.33](ex_6_33.cpp)

### Exercise 6.34

When the recursion termination condition becomes var != 0, two situations can happen : case 1 : If the argument is positive, recursion stops at 0. This is exactly what @shbling pointed out. case 2 : if the argument is negative, recursion would never stop. As a result,a stack overflow would occur.

### Exercise 6.35

the recursive function will always use `val` as the parameter. *a recursion loop* would happen.

### Exercise 6.36

```cpp
string (&func(string (&arrStr)[10]))[10]
```

### Exercise 6.37

```cpp
using ArrT = string[10];
ArrT& func1(ArrT& arr);

auto func2(ArrT& arr) -> string(&)[10];

string arrS[10];
decltype(arrS)& func3(ArrT& arr);
```

I pefer the first one. Because it looks more intuitive.
[TestCode](ex_6_36_37.cpp)
## Exercise 6.38

```cpp
decltype(odd)& arrPtr(int i)
{
          return (i % 2) ? odd : even;
}
```

## Fuction Overloaded

### Exercise 6.39

(a) illegal top-level const,so it's repeat statement.

(b) illegal parameter is the same.

(c) legal

### Exercise 6.40

(a) no error

(b) ERROR: missing default argument on parameter 'wd', 'background'

### Exercise 6.41

(a) illegal. No matching function for call to 'init'.

(b) legal, and match.

(c) legal, but not match. `wd` would be setting to '*'.

### Exercise 6.43

Both two should put in a header. (a) is an inline function. (b) is the declaration of useful function. we always put them in the header.

### Exercise 6.44

```cpp
inline bool isShorter(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}
```

### Exercise 6.45

For example, the function `arrPtr` in [Exercise 6.38](#exercise-638) and `make_plural` in [Exercise 6.42](#exercise-642) should be defined as `inline`. But the function `func` in [Exercise 6.4](#exercise-64) shouldn't. Cause it just being call once and too many codes in the function.


> Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.

No.

> A constexpr function is defined like any other function but must meet certain restrictions: The **return type** and **the type of each parameter** in a must be a literal type

But `std::string`(parameter of `isShorter`) is not a literal type.

more discusses: [#22](https://github.com/ReadingLab/Discussion-for-Cpp/issues/22)


### Exercise 6.46

> Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.

No.

> A constexpr function is defined like any other function but must meet certain restrictions: The **return type** and **the type of each parameter** in a must be a literal type

But `std::string`(parameter of `isShorter`) is not a literal type.

more discusses: [#22](https://github.com/ReadingLab/Discussion-for-Cpp/issues/22)

### [Exercise 6.47](ex6_47.cpp)

### Exercise 6.48

This loop let user input a word all the way until the word is sought or input is `EOF`.

It isn't a good use of `assert`. The `assert` macro is often used to check for conditions that “**cannot happen**”. But the `assert` would always happen when users input `EOF` directly. The behavior is very natural, so the check is meaningless. using `assert(!cin || s != sought)` is more better.

### Exercise 6.49

candidate function:
>Set of functions that are considered when resolving a function call. (all the functions
>with the name used in the call for which a declaration is in scope at the time of the call.)

viable function:
>Subset of the candidate functions that could match a given call.
>It have the same number of parameters as arguments to the call,
>and each argument type can be converted to the corresponding parameter type.

### Exercise 6.50

(a) illegal. 2.56 match the `double`, but 42 match the `int`.

(b) match `void f(int)`.

(c) match `void f(int, int)`.

(d) match `void f(double, double = 3.14)`.

### [Exercise 6.51](ex6_51.cpp)

### Exercise 6.52

(a) Match through a promotion

(b) Arithmetic type conversion

### Exercise 6.53
p208 chinese edition
(a)

```cpp
int calc(int&, int&); // calls lookup(int&)
int calc(const int&, const int&); // calls lookup(const int&) 底层const
```

(b)

```cpp
int calc(char*, char*); // calls lookup(char*)
int calc(const char*, const char*); //calls lookup(const char *)
```

(c)

illegal. both calls lookup(char*) top-level parameters, and non top-level const parameterscan't be differentiate。

### Exercise 6.54

@Mooophy's or @pezy's ?
```cpp
int func(int a, int b);

using pFunc1 = decltype(func) *;
typedef decltype(func) *pFunc2;
using pFunc3 = int (*)(int a, int b);
using pFunc4 = int(int a, int b);
typedef int(*pFunc5)(int a, int b);
using pFunc6 = decltype(func);

std::vector<pFunc1> vec1;
std::vector<pFunc2> vec2;
std::vector<pFunc3> vec3;
std::vector<pFunc4*> vec4;
std::vector<pFunc5> vec5;
std::vector<pFunc6*> vec6;
```

## Exercise 6.55

```cpp
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }
```

## Exercise 6.56

```cpp
std::vector<decltype(func) *> vec{add, subtract, multiply, divide};
for (auto f : vec)
          std::cout << f(2, 2) << std::endl;
```

----

[my_complete codes](ex_6_54_55_56.cpp).
