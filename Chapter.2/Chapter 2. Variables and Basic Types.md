# Exerise 2.9 - 2.1
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
int i = 0, &r1 = i; double d = 0, &r2 = d;
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
```c++
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

`10, 10`

