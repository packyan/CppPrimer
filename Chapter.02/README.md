# Chapter 2. Variables and Basic Types

## Chapter 2.1
### Exerise 2.1
>What are the differences between int, long, long long, and short? Between an unsigned and a signed type? Between a float and a double?
in Cpp short and int **at least** 16 bits, long **at least** 32 bits. long long **at least** 64bits.
the `signed` can be represent positive negative and zero numbers, while `unsigned`  can only represent positive numbers or zero.
`float` type **at least** has six significant digits(**single-precision**) while `double`  **at least** (**double-precision**)has ten. In general a double has 15 decimal digits of precision, while float has 7.
>The C and C++ standards do not specify the representation of float, double and long double. It is possible that all three implemented as IEEE double-precision. Nevertheless, for most architectures (gcc, MSVC; x86, x64, ARM) float is indeed a IEEE single-precision floating point number (binary32), and double is a IEEE double-precision floating point number (binary64).

Usage:
- Use int for integer arithmetic. short is usually too small and, in practice, long often has the same size as int. If your data values are larger than the minimum guaranteed size of an int, then use long long. (In a word: `short` < `int` < `long` < `long long`)
- Use an unsigned type when you know that the values cannot be negative. (In a word: no negative, unsigned.)
- Use double for floating-point computations; float usually does not have enough precision, and the cost of double-precision calculations versus **single-precision** is negligible. In fact, on some machines, **double-precision** operations are faster than single. The precision offered by long double usually is unnecessary and often entails considerable run-time cost. (In a word: float < double < long double)

Reference

- [What are the criteria for choosing between short / int / long data types?](http://www.parashift.com/c++-faq/choosing-int-size.html)
- [Difference between float and double](http://stackoverflow.com/questions/2386772/difference-between-float-and-double)
- Advice: Deciding which Type to Use(This book.)

### Exerise 2.2

>To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.
using float or double, both meet the accuracy need of this occasion.

Reference:

- [mortgage-calculator](http://www.bankrate.com/calculators/mortgages/mortgage-calculator.aspx)
- [What's in a Mortgage Payment?](http://www.homeloanlearningcenter.com/mortgagebasics/whatsinamortgagepayment.htm)

### Exerise 2.3

> What output will the following code produce?
> ```c++
>unsigned u = 10, u2 = 42;
>std::cout << u2 - u << std::endl;
>std::cout << u - u2 << std::endl;
>int i = 10, i2 = 42;
>std::cout << i2 - i << std::endl;
>std::cout << i - i2 << std::endl;
>std::cout << i - u << std::endl;
>std::cout << u - i << std::endl;
>```

output(g++ (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609):

`
32
4294967264
32
-32
0
0
`

### Exercise 2.5

>Determine the type of each of the following literals. Explain the differences among the literals in each of the four exa123mples:
- (a) 'a', L'a', "a", L"a"
- (b) 10, 10u, 10L, 10uL, 012, 0xC
- (c) **3.14**, 3.14f, 3.14L
- (d) 10, 10u, 10., 10e-2

1. character literal, wide character literal, string literal, string wide character literal.
2. decimal, unsigned decimal, long decimal, unsigned long decimal, octal, hexadecimal.
3. **double**, float, long double.
4. decimal, unsigned decimal, double, double.

### Exercise 2.6

>What, if any, are the differences between the following definitions:

```c++
int month = 9, day = 7;
int month = 09, day = 07;
```

the first line define  int variables in decimal;
the second line define two int variables in octal, BUT month = 09 is wrong, cause in cotal the digits can't bigger than 8.

### Exercise 2.7

>What values do these literals represent? What type does each have?

- "Who goes with F\145rgus?\012"
- 3.14e1L
- 1024f
- 3.14L

1. Who goes with Fergus?(new line) "string" (\145 -> 'e', \012 -> "new line")
2. 31.4 "double"
3. 1024 "float"
4. 3.14 "long double"

ref:
[ASCII table](http://www.asciitable.com/)



## Chapter 2.2
### Exerise 2.9
> Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.
- std::cin >> int input_value;
- int i = { 3.14 };
- double salary = wage = 9999.99;
- int i = 3.14

(a):error: expected '(' for function-style cast or type construction.
```c
int input_value = 0;
std::cin >> input_value;
```
(b):when you compile the code without the argument "`-std=c++11`", you will get the warning below: warning: implicit conversion from 'double' to 'int' changes value from 3.14 to 3. ---when you compile the code using "-std=c+11", you will get a error below: error: type 'double' cannot be narrowed to 'int' in initializer list ---conclusion: Obviously, list initialization becomes strict in c++11.

`double i = { 3.14 }`;

(c): --if you declared 'wage' before, it's right. Otherwise, you'll get a error: error: use of undeclared identifier 'wage'
```c++
double wage;
double salary = wage = 9999.99;
```
(d): ok: but value will be truncated.

```c
double i = 3.14;
```


### Exercise 2.10

>What are the initial values, if any, of each of the following variables?

```c++
std::string global_str;
int global_int;
int main()
{
  int local_int;
  std::string local_str;
}
```

global_str is global variable, so the value is empty string. 
global_int is global variable, so the value is 0.
local_int is a local variable which is not uninitialized, so it has a undefined value. 
local_str is also a local variable which is not uninitialized, but it has a value that is defined by the class. So it is empty string.

> PS: please read P44 in the English version, P40 in Chinese version to get more.
> The note: Uninitialized objects of built-in type defined inside a function body have a undefined value. Objects of class type that we do not explicitly inititalize have a value that is **defined by class**.

### Exercise 2.11
Explain whether each of the following is a declaration or a definition:
- (a) extern int ix = 1024;
- (b) int iy;
- (c) extern int iz;

1. definition
2. definition
3. declaration

> Which, if any, of the following names are invalid?
- (a) int double = 3.14;
- (b) int _;
- (c) int catch-22;
- (d) int 1_or_2 = 1;
- (e) double Double = 3.14;

a, c, d are invalid.

### Exercise 2.13
> What is the value of j in the following program?

```c
int i = 42;
int main()
{
  int i = 100;
  int j = i;
}
```

100,because local object named reused hides global reused.

### Exercise 2.14
> Is the following program legal? If so, what values are printed?

```c
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
  sum += i;
std::cout << i << " " << sum << std::endl;
```

is legal,print:
100 45

## Chapter 2.3
Note:
compound type : reference and pointer
compound type declaration include two parts: **base type** and **declarator**

```c++
int ival = 1024;
int &refVal = ival; //correct refVal is ival's ""avatar"..
int &refVal; //incorrect reference must be initialized
```

### Exercise 2.15
>Which of the following definitions, if any, are invalid? Why?
- (a) int ival = 1.01;
- (b) int &rval1 = 1.01;
- (c) int &rval2 = ival;
- (d) int &rval3;

(a): valid.
(b): invalid. initializer must be an object.
(c): valid. if ival has benn declared
(d): invalid. a reference must be initialized.

### Exercise 2.16

>Which, if any, of the following assignments are invalid? If they are valid, explain what they do.

`int i = 0, &r1 = i; double d = 0, &r2 = d;`

>- (a) r2 = 3.14159;
>- (b) r2 = r1;
>- (c) i = r2;
>- (d) r1 = d;

- (a): valid. let d equal 3.14159.
- (b): valid. automatic convert will happen.
- (c): valid. but value will be truncated.
- (d): valid. but value will be truncated.

### Exercise 2.17

>What does the following code print?

```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

`10, 10`

**Note:**
**pointer**type exactly matches the object it points to.
> how to use pointer to access objects?
> use '*'

in c++ program use `nullptr` to represent a null pointer, `int *p = nullptr`,  when compiling need to use `-std=c++11` .

### Exercise 2.18

> Write code to change the value of a pointer. Write code to change the value to which the pointer points.

```cpp
int x = 666, y = 233;
int *p = nullptr;
int p = &x; //change the value of a pointer.
int *p = y; //change the value to which the pointer points
```


### Exercise 2.19

> Explain the key differences between pointers and references.

**definition**:

the pointer is "points to" any other type.

the reference is "another name" of an **object**.

**key difference**:

1. a reference is another name of an **already existing** object. a pointer is an object in its **own right**.
2. Once initialized, a reference remains **bound to** its initial object. There is **no way** to rebind a reference to refer to a different object. a pointer can be **assigned** and **copied**.
3. a reference always get the object to which the reference was initially bound. a single pointer can point to **several different objects** over its lifetime.
4. a reference must be initialized. a pointer need **not be** initialized at the time it is defined.

**Usage advise**:

check [here](http://www.parashift.com/c%2B%2B-faq-lite/refs-vs-ptrs.html)

### Exercise 2.20

> What does the following program do?
>
> ```cpp
> int i = 42;
> int *p1 = &i; *p1 = *p1 * *p1;
> ```

`p1` pointer to `i`, `i`'s value changed to 1764(42*42)

### Exercise 2.21

> Explain each of the following definitions. Indicate whether any are illegal and, if so, why.
>
> ```cpp
> int i = 0;
> ```
>
> - (a) `double* dp = &i;`
> - (b) `int *ip = i;`
> - (c) `int *p = &i;`

- (a): illegal, cannot initialize a variable of type `double *` with an rvalue of type `int *` ; `error: cannot convert ‘int*’ to ‘double*’ in initialization`
- (b): illegal, cannot initialize a variable of type `int *` with an rvalue of type `int` ; `error: invalid conversion from ‘int’ to ‘int*’ [-fpermissive]`
- (c): legal.

### Exercise 2.22

> Assuming p is a pointer to int, explain the following code:
>
> ```cpp
> if (p) // whether p is nullptr?
> if (*p) // whether the value pointed by p is zero?
> ```

### Exercise 2.23

> Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?

No. 
Because more information needed to determine whether the pointer is valid or not.

### Exercise 2.24

> Why is the initialization of `p` legal but that of `lp` illegal?
>
> ```cpp
> int i = 42;
> void *p = &i;
> long *lp = &i;
> ```

Because they have different types. `void*` is a special pointer type that can hold the address of any object. But we cannot initialize a variable of type `long *` with an rvalue of type `int *`

### Exercise 2.25

> Determine the types and values of each of the following variables.
>
> - (a) `int* ip, i, &r = i;`
> - (b) `int i, *ip = 0;`
> - (c) `int* ip, ip2;`

- (a) `ip`: a pointer points to a `int` type variable, `i` is an `int`, `r` is a reference to `int` `i`.
- (b): `ip` is a valid, null pointer, and `i` is an `int`.
- (c): `ip` is a pointer to `int`, and `ip2` is an `int`.


## 2.4 Const Qualifier

Usage:
`const int buffsize = 4096;`

## Chapter 2.4

### Exercise 2.26

> Which of the following are legal? For those that are illegal, explain why.
>
> ```cpp
> const int buf;      // illegal, buf is uninitialized const.
> int cnt = 0;        // legal.
> const int sz = cnt; // legal.
> ++cnt;              // legal.
> ++sz;               // illegal, attempt to write to const object(sz).
> ```

- (a) illegal, buf is uninitialized const.
- (b) legal.
- (c) legal.
- (d) legal.
- (e) illegal, attempt to write to const object(sz)

Note：chinese edtion book p55，56

### Exercise 2.27

> Which of the following initializations are legal? Explain why.
>
> ```cpp
> int i = -1, &r = 0;         // illegal, r must refer to an object.
> int *const p2 = &i2;        // legal.
> const int i = -1, &r = 0;   // legal.
> const int *const p3 = &i2;  // legal.
> const int *p1 = &i2;        // legal
> const int &const r2;        // illegal, r2 is a reference that cannot be const.
> const int i2 = i, &r = i;   // legal.
> ```

### Exercise 2.28

> Explain the following definitions. Identify any that are illegal.
>
> ```cpp
> int i, *const cp;       // illegal, cp must initialize.
> const int ic, &r = ic;  // illegal, ic must initialize.
> int *p1, *const p2;     // illegal, p2 must initialize.
> const int *const p3;    // illegal, **const pointer** (p3) must initialize.
> const int *p;           // legal. a pointer to const int.
> ```

NOTE: **pointer to const** and **const pointer** is different 

**pointer to const** or **reference to const **  will not change the value of the pointed(refer) object consciously, but the value can be changed by other ways.
e.g.:
**const pointer**: pointer can not be changed, **bounded** to a object

```cpp
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main(int argc, char const *argv[])
{
    int i = 1;
    const int &const_r = i, *p = &i;
    //r and *p can not changed i;
    cout << "const_r = "<<const_r<<" *p = " <<*p<<endl;
    i = 5;
    cout <<"i = "<<i<<endl;
    int &r = i;
    r = 10;
    cout << "&r = " <<r <<endl;
    // but can changed by other ways;
    return 0;
}
```


`Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 8.1.0 (clang-802.0.42)
Target: x86_64-apple-darwin16.6.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin`

```cpp
const_r = 1 *p = 1
i = 5
&r = 10
```


## Exercise 2.29

> Using the variables in the previous ## Exercise, which of the following assignments are legal? Explain why.
>
> ```cpp
> i = ic;     // legal.
> p1 = p3;    // illegal. p3 is a pointer to const int.
> p1 = &ic;   // illegal. ic is a const int.
> p3 = &ic;   // illegal. p3 is a const pointer.
> p2 = p1;    // illegal. p2 is a const pointer.
> ic = *p3;   // illegal. ic is a const int.
> ```

*for pointer*
**top-level const** means the pointer is a const object.
**low-level const** means the object that the pointer pointed to is const  .
a pointer can be **both** top-level const and low-level const.

*More general:*
**top-level const** means a const obj's value **can not** be changed.
**low-level const** means a const obj's value **can  be** changed.

e.g.：
```cpp
int i = 1; 
int *const p1 = &i; //**top-level const**
const int c1 = 42; //**top-level const**
const int *p2 = &i; //**low-level const**
const int const *p3 = p2; // the right const is a **top-level const** the left one is a **low-level const**
const int &r = i; // the const using to declare a refer is **low-level const**
```

**Non-constant can be converted to constants**


**Both** the copy in and copy out objects must have **low-level const**.

### Exercise 2.30

> For each of the following declarations indicate whether the object being declared has top-level or low-level `const`.
>
> ```cpp
> const int v2 = 0; int v1 = v2;
> int *p1 = &v1, &r1 = v1;
> const int *p2 = &v2, *const p3 = &i, &r2 = v2;
> ```

- v2 is top-level `const`, p2 is low-level `const`.
- p3: right-most `const` is top-level, left-most is low-level.
- r2 is low-level `const`.

### Exercise 2.31

> Given the declarations in the previous ## Exercise determine whether the following assignments are legal. Explain how the top-level or low-level `const` applies in each case.
>
> ```cpp
> r1 = v2; // legal, top-level const in v2 is ignored.
> p1 = p2; // illegal, p2 has a low-level const but p1 doesn't.
> p2 = p1; // legal, we can convert int* to const int*.
> p1 = p3; // illegal, p3 has a low-level const but p1 doesn't.
> p2 = p3; // legal, p2 has the same low-level const qualification as p3.
> ```

a variable declared by  `constexpr` must be a const variable.
`constexpr int mf = 20;`

## Exercise 2.32

> Is the following code legal or not? If not, how might you make it legal?

```cpp
int null = 0, *p = null;
```

illegal.

```cpp
int null = 0, *p = nullptr;
```

## Chapter 2.5

NOTE: type alias is a name. Two ways to rename a type.
1.  using **typedef**

e.g. `typedef double wages`

2.  using **using rename = name**

e.g. `using SI = sales_item;`

```cpp
typedef char *pstring;
const pstring cstr = 0;
const pstring *ps;
//Const is a modification of a given type 
//const pstring means a const pointer pointed to char type.
```


`auto` usually ignore the **top-level const**


### Exercise 2.33

> Using the variable definitions from this section, determine what happens in each of these assignments:
>
> ```cpp
> a = 42; // set 42 to int a.
> b = 42; // set 42 to int b.
> c = 42; // set 42 to int c.
> d = 42; // ERROR, d is an int *. correct: *d = 42;
> e = 42; // ERROR, e is an const int *. correct: e = &c;
> g = 42; // ERROR, g is a const int& that is bound to ci.
> ```

## Exercise 2.34

> Write a program containing the variables and assignments from the previous ## Exercise. Print the variables before and after the assignments to check whether your predictions in the previous ## Exercise were correct. If not, study the examples until you can convince yourself you know ￼￼what led you to the wrong conclusion.

check the [code](exercise2.34.cpp).

## Exercise 2.35

> Determine the types deduced in each of the following definitions. Once you’ve figured out the types, write a program to see whether you were correct.
>
> ```cpp
> const int i = 42;
> auto j = i;
> const auto &k = i;
> auto *p = &i;
> const auto j2 = i, &k2 = i;
> ```

- `i` is `const int`.
- `j` is `int`.
- `k` is `const int&`.
- `p` is `const int *`.
- `j2` is `const int`.
- `k2` is `const int&`.

check [code](exercise2.35.cpp).

### Exercise 2.36

> In the following code, determine the type of each variable and the value each variable has when the code finishes:
>
> ```cpp
> int a = 3, b = 4;
> decltype(a) c = a;
> decltype((b)) d = a;
> ++c;
> ++d;
> ```

`c` is an int, `d` is a reference of `a`. all their value are `4`.

### Exercise 2.37

> Assignment is an example of an expression that yields a reference type. The type is a reference to the type of the left-hand operand. That is, if i is an int, then the type of the expression `i = x` is `int&`. Using that knowledge, determine the type and value of each variable in this code:
>
> ```cpp
> int a = 3, b = 4;
> decltype(a) c = a;
> decltype(a = b) d = a;
> ```

- `c` is an int, `d` is a reference of int.
- the value: `a = 3, b = 4, c = 3, d = 3`

## Exercise 2.38

> Describe the differences in type deduction between `decltype` and auto. Give an example of an expression where auto and `decltype` will deduce the same type and an example where they will deduce differing types.

The way `decltype` handles top-level `const` and references differs **subtly** from the way `auto` does. Another important difference between `decltype` and `auto` is that the deduction done by `decltype` depends on the **form** of its given expression.

so the key of difference is **subtly** and **form**.

```cpp
int i = 0, &r = i;
// same
auto a = i;
decltype(i) b = i;
// different
auto c = r;
decltype(r) d = i;
```

More? check [here](http://stackoverflow.com/questions/21369113/what-is-the-difference-between-auto-and-decltypeauto-when-returning-from-a-fun) and [here](http://stackoverflow.com/questions/12084040/decltype-vs-auto)

## Exercise 2.6

NOTE: how to define a struct?
begin with **struct**, next with class name and body, the variables defined in class body must be unique.

e.g. 

```cpp
struct Sale_data{
    /* ...*/
} accum, trans, *salesptr;
```


the following one is better：

```cpp
//define a struct
struct Sale_data{
    // ....data member
}; //remeber the ';'
//define variables
Sale_data accum, trans, *salesptr;
```

in c++11 standard, we can provide a in-class initializer to data member.

### Exercise 2.39

> Compile the following program to see what happens when you forget the semicolon after a class definition. Remember the message for future reference.
>
> ```cpp
> struct Foo { /* empty  */ } // Note: no semicolon
> int main()
> {
>    return 0;
> }
> ```

Error message: `[Error] expected ';' after struct definition`

## Exercise 2.40

> Write your own version of the `Sales_data` class.

```cpp
struct Sale_data{
    std::string bookNo;
    std::string bookName;
    unsigned int units_sold = 0;
    float price = 0.0;
    double revenue = 0.0;
};
```

### Exercise 2.41

> Use your Sales_data class to rewrite the ## Exercises in 1.5.1(p. 22), 1.5.2(p. 24), and 1.6(p. 25). For now, you should define your Sales_data class in the same file as your main function.

#### 1.5.1
#### my_ex1_20.cpp

```cpp
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct Sale_data{
    std::string bookNo;
    std::string bookName;
    unsigned int units_sold = 0;
    float price = 0.0;
    double revenue = 0.0;
};
int main(int argc, char const *argv[])
{
    Sale_data item1;
    while(cin >> item1.bookNo >> item1.units_sold >> item1.price)
        cout << item1.bookNo << ' ' << item1.units_sold << ' '<< item1.price <<endl;
    return 0;
}
```

### my_ex1_21.cpp

```cpp
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct Sale_data{
    std::string bookNo;
    std::string bookName;
    unsigned int units_sold = 0;
    float price = 0.0;
    double revenue = 0.0;
    double average = 0.0;
};
int main(int argc, char const *argv[])
{
    Sale_data item1, item2, temp;
    cin >> item1.bookNo >> item1.units_sold >> item1.price;
    cin >> item2.bookNo >> item2.units_sold >> item2.price;
    if(item1.bookNo == item2.bookNo){
        temp.bookNo = item2.bookNo;
        temp.units_sold = item1.units_sold + item2.units_sold;
        temp.revenue = 1.0 * (item1.price * item1.units_sold + item2.price * item2.units_sold);
        temp.average = 1.0 * temp.revenue/temp.units_sold;
        
    }
    else{
        cout << "the bookNo is not the same, please enter again." << endl;
        exit(0);
    }
    cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
    return 0;
}
```

### my_ex1_22.cpp

```cpp
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct Sale_data{
    std::string bookNo;
    std::string bookName;
    unsigned int units_sold = 0;
    float price = 0.0;
    double revenue = 0.0;
    double average = 0.0;
};
int main(int argc, char const *argv[])
{
    Sale_data item1, item2, temp;
    if(cin >> item1.bookNo >> item1.units_sold >> item1.price){
        temp.bookNo = item1.bookNo;
        temp.units_sold = item1.units_sold;
        temp.revenue = 1.0 * item1.units_sold * item1.price;
        cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
        while(cin >> item2.bookNo >> item2.units_sold >> item2.price){
            if(temp.bookNo == item2.bookNo){
                temp.units_sold += item2.units_sold;
                temp.revenue += 1.0 * item2.price * item2.units_sold;
                temp.average = 1.0 * temp.revenue/temp.units_sold;
                cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
            }
    else{
        cout << "the bookNo is not the same, please enter again." << endl;
        exit(0);
        }
        }
    }
    cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
    return 0;
}
```

### my_ex1_23.cpp

```cpp
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
struct Sale_data{
    std::string bookNo;
    std::string bookName;
    unsigned int units_sold = 0;
    float price = 0.0;
    double revenue = 0.0;
    double average = 0.0;
};
int main(int argc, char const *argv[])
{
    Sale_data item1, currItem, temp;
    unsigned int bookcnt = 0;
    if(cin >> item1.bookNo >> item1.units_sold >> item1.price){
        temp.bookNo = item1.bookNo;
        bookcnt = 1;
        // temp.units_sold = item1.units_sold;
        // temp.revenue = 1.0 * item1.units_sold * item1.price;
        // temp.average = 1.0 * item1.price;
        //cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
        while(cin >> currItem.bookNo >> currItem.units_sold >> currItem.price){
            if(temp.bookNo == currItem.bookNo){
                bookcnt++;
                // temp.units_sold += currItem.units_sold;
                // temp.revenue += 1.0 * currItem.price * currItem.units_sold;
                // temp.average = 1.0 * temp.revenue/temp.units_sold;
                //cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
            }
    else{
        cout << temp.bookNo << " occurs " << bookcnt << string ((bookcnt == 1)? " time" : " times")<< endl;
        bookcnt = 1;
        temp.bookNo = currItem.bookNo;
    // cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
    // temp.bookNo = currItem.bookNo;
    // temp.units_sold = currItem.units_sold;
    // temp.revenue = 1.0 * currItem.units_sold * currItem.price;
    // temp.average = 1.0 * currItem.price;
        }
        }
        cout << temp.bookNo << " occurs " << bookcnt << string ((bookcnt == 1)? " time" : " times")<< endl;
    }
    //cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
    return 0;
}
```

### my_ex1_25.cpp

```cpp
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct Sale_data{
    std::string bookNo;
    std::string bookName;
    unsigned int units_sold = 0;
    float price = 0.0;
    double revenue = 0.0;
    double average = 0.0;
};
int main(int argc, char const *argv[])
{
    Sale_data item1, currItem, temp;
    if(cin >> item1.bookNo >> item1.units_sold >> item1.price){
        temp.bookNo = item1.bookNo;
        temp.units_sold = item1.units_sold;
        temp.revenue = 1.0 * item1.units_sold * item1.price;
        temp.average = 1.0 * item1.price;
        //cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
        while(cin >> currItem.bookNo >> currItem.units_sold >> currItem.price){
            if(temp.bookNo == currItem.bookNo){
                temp.units_sold += currItem.units_sold;
                temp.revenue += 1.0 * currItem.price * currItem.units_sold;
                temp.average = 1.0 * temp.revenue/temp.units_sold;
                //cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
            }
    else{
    cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
    temp.bookNo = currItem.bookNo;
    temp.units_sold = currItem.units_sold;
    temp.revenue = 1.0 * currItem.units_sold * currItem.price;
    temp.average = 1.0 * currItem.price;
        }
        }
    }
    cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
    return 0;
}
```

### Exercise 2.42

> Write your own version of the `Sales_data.h` header and use it to rewrite the ## Exercise from 2.6.2(p. 76)

- [Sales_data.h](Sales_data.h)
- [1.5.1.](see next)
- [1.5.2.](myh_ex1_22.cpp)
- [1.6.](myh_ex1_25.cpp)

#### myh_ex1_22.cpp

```cpp
#include <iostream>
#include "../include/Sales_data.h"
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
    Sales_data item1, item2, temp;
    if(cin >> item1.bookNo >> item1.units_sold >> item1.price){
        temp.SetDATA(item1);
        while(cin >> item2.bookNo >> item2.units_sold >> item2.price){
            if(temp.bookNo == item2.bookNo){
                temp.AddDATA(item2);
            }
    else{
        cout << "the bookNo is not the same, please enter again." << endl;
        exit(0);
        }
        }
    }
    temp.Print();
    return 0;
}
```

#### myh_ex1_25.cpp

```cpp
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "../include/Sales_data.h"
int main(int argc, char const *argv[])
{
    Sales_data item1, currItem, temp;
    if(cin >> item1.bookNo >> item1.units_sold >> item1.price){
        temp.SetDATA(item1);
        //cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
        while(cin >> currItem.bookNo >> currItem.units_sold >> currItem.price){
            if(temp.bookNo == currItem.bookNo){
                temp.AddDATA(currItem);
                //cout << temp.bookNo << ' ' << temp.units_sold  << ' ' << temp.revenue << ' '<< temp.average<<endl;
            }
    else{
    temp.Print();
    temp.SetDATA(currItem);
        }
        }
    }
    temp.Print();
    return 0;
```