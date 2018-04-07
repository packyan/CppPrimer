# Chapter 3. Strings, Vectors, and Arrays

## Chapter 3.1 Namesapce using declaration

NOTE: .h file should not contain any using declaration.

### Exercise 3.1 : **already used**

## Chapter 3.2 STL String

NOTE:
there are different ways to initialize a string 

```cpp
string(const char *s);    //用c字符串s初始化
string(int n,char c);     //用n个字符c初始化
//e.g.
string s1; //空串
string s2 = s1;
string s2(s1);//与上面等价，创建s1的副本s2
string s3 = "hello";
string s4(10,'x');//10个x构成的字符串
```

if use '=' to initialize a variable, actually perform **copy initialization**,
and if not, performing  **direct initialization**.The difference between this two ways is copy initialization needs to create a t**emporary variable**.

if you want to reserve blank space in the string inputed, using `getline(std::cin,str)`

if a experssion have `size()` fuction, do not use int, but  `string::size_type` instead

> C++11 : Want to do something to each character in a string, best way is using **range for**, expression:

```cpp
for (declaration, experssion)
    statement
//e.g.

string str("some thing");
for(auto c : str)
    cout << c <<endl;
```

### Exercise 3.2 : [Part1](ex3_2a.cpp) & [Part2](ex3_2b.cpp)

### Exercise 3.3

>Explain how whitespace characters are handled in the string
input operator and in the `getline` function.

> The `getline` function takes an input stream and a string.
This function reads the given stream up to and including
the first newline and stores what it read—not including
the newline—in its string argument.
After `getline` sees a newline, even if it is the first character in the input,
it stops reading and returns.
If the first character in the input is a newline,
then the resulting string is the empty string.

> `getline` function whitespace handling,
do not ignore the beginning of the line blank characters read characters
until it encounters a line break,
read to termination and discard newline
(line breaks removed from the input stream
  but is not stored in the string object).

[Read more](http://www.cplusplus.com/reference/string/string/getline/)

### Exercise 3.4 : [Part1](ex3_4a.cpp) & [Part2](ex3_4b.cpp)

### Exercise 3.5 : [Part1](ex3_5a.cpp) & [Part2](ex3_5b.cpp)

> EOF must on the begining of a line.

### Exercise 3.6 : [CODE](ex3_6.cpp) 

### Exercise 3.7

>What would happen if you define the loop control variable in the previous
exercise as type char? Predict the results and then change your program
to use a char to see if you were right.

No different.

    auto& c : str

We use `auto` to let the compiler determine the type of `c`.
which in this case will be `char&`.

### Exercise 3.8: [code](ex3_08.cpp)

I think using **for** is better, because `for` is more simple.

>What does the following program do? Is it valid? If not, why not?

```cpp
string s;
cout << s[0] << endl;
```

### Exercise 3.9

> Try to get the first element of the `string`. It is invalid, cause this is **undefined behavior**. 
Because s is a empty string.

### [Exercise 3.10](ex3_10.cpp)

### Exercise 3.11

>Is the following range for legal? If so, what is the type of c?

```cpp
const string s = "Keep out!";
for (auto &c : s){/*... */}
```

When you don't change `c`'s value, it's legal, else it's illegal.

For example:

    cout << c;  // legal.
    c = 'X';    // illegal.

The type of `c` is `const char&`. read-only variable is not assignable.

## Chapter 3.3 STL Vector

NOTE: `Vector` is a **class template**, ofen called **cantainer**. 

using '()' to construct vector object.
using '{}' to list initialize vector object.
**but** if the values in {} can not be used to initialize vector object, they will be used to construct vector object.
e.g.

```cpp
vector<string> v{10}; // v is a vector contain 10 empty string.
vector<string> v2{10, "hi"}; // v2 has 10 string which value is "hi"
```


### Exercise 3.12

>Which, if any, of the following vector definitions are in error?
For those that are legal, explain what the definition does.
For those that are not legal, explain why they are illegal.

```cpp
vector<vector<int>> ivec;         // legal(c++11), vectors.
vector<string> svec = ivec;       // illegal, different type.
vector<string> svec(10, "null");  // legal, vector have 10 strings: "null".
```

### Exercise 3.13

>How many elements are there in each of the following
vectors? What are the values of the elements?

```cpp
vector<int> v1;         // size:0,  no values.
vector<int> v2(10);     // size:10, value:0
vector<int> v3(10, 42); // size:10, value:42
vector<int> v4{10};     // size:1,  value:10
vector<int> v5{10, 42}; // size:2,  value:10, 42
vector<string> v6{10};  // size:10, value:""
vector<string> v7{10, "hi"};  // size:10, value:"hi"
```


### [Exercise 3.14](ex3_14.cpp)

### [Exercise 3.15](ex3_15.cpp)

### [Exercise 3.16](ex3_16.cpp)

### [Exercise 3.17](ex3_17.cpp)

### Exercise 3.18

> Is the following program legal? If not, how to modify?

```cpp
vector<int> ivec;
ivec[0] = 42;
```

it's illegal. modified one:

```cpp
vector<int> ivec{42};
```

### [Exercise 3.19](ex3_19.cpp)

## Chapter 3.4 Iterator introduction

### Exercise 3.20 : [partA](ex3_20a.cpp) & [partB](ex3_20b.cpp)

### [Exercise 3.21](ex3_21.cpp)

### [Exercise 3.22](ex3_22.cpp)

### [Exercise 3.23](ex3_23.cpp)

### [Exercise 3.24](ex3_24.cpp)

### [Exercise 3.25](ex3_25.cpp)

### Exercise 3.26

>In the binary search program on page 112,
why did we write `mid=beg+(end-beg)/2;` instead of `mid=(beg+end) /2;`?

Because the iterator of vector don't define the `+` operator **between the two iterators**.
`beg + end` is illegal.

We can only use the subtraction `-` between the two iterators.

## 3.5 Array

### Exercise 3.27

>Assuming txt_size is a function that takes no arguments
and returns an int value, which of the following definitions are illegal?
Explain why.

```cpp
unsigned buf_size = 1024;

int ia[buf_size];   // illegal, The dimension value must be a constant expression.
int ia[4 * 7 - 14]; // legal
int ia[txt_size()]; // illegal, The dimension value must be a constant expression.
char st[11] = "fundamental";  // illegal, the string's size is 12.
```

### Exercise 3.28

>What are the values in the following arrays?

```cpp
string sa[10];
int ia[10];

int main() {
  string sa2[10];
  int ia2[10];
}
```

please see 2.2.1. Variable Definitions -> Default Initialization.

`std::string` isn't a build-in type. The initializer will set it empty.
`ia` and `ia2` are build-type. But `ia` isn't in the function body, so it
will be initialized to **zero**. `ia2` is in the function body. so it's
value is **undefined**.


### Exercise 3.29

>List some of the drawbacks of using an array instead of a vector.

1. can't add elements to an array.
2. vector is better supported bt std.

### Exercise 3.30

>Identify the indexing errors in the following code:

```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
      ia[ix] = ix;
```

The size of ia is 10, so the index of value should less than 10.
ix **cannot** equal the array_size.

### [Exercise 3.31](ex3_31.cpp)

### [Exercise 3.32](ex3_32.cpp)

### Exercise 3.33

>What would happen if we did not initialize the scores array in the program
on page 116?

If we did not initialize the scores array. the array is undefined. the value
will be Unknown.

### Exercise 3.34

>Given that p1 and p2 point to elements in the same array, what does the following code do?
Are there values of p1 or p2 that make this code illegal?

```cpp
p1 += p2 - p1;
```

`p1 += p2 - p1;` means `p1 = p2;`. if `p1` and `p2` is legal, `p1 += p2 - p1;`also is legal.

### Exercise 3.37

>What does the following program do?

```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```

Print all the elements of the array.

-----
**WARNING!!!!**
When we use a string, the compiler put it in the section `.rodata`, the code uses C-style character string without adding a '\0' in the end of `ca`.
So, when we code like this:

```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char s[] = "world";
const char *cp = ca;
while (*cp) {
cout << *cp;
++cp;
}
```

The code will print "helloworld" when you run it.
because the character list in the `.rodata` like this:

    h e l l o w o r l d \0
`While(*cp)` judge weather *cp is 0 or not. when *cp is not 0, it will print the character until 0.
When you change the code like this:

    const char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'};
the character list in the `.rodata`:

    h e l l o \0 w o r l d \0
The program will run correctly. So when using C-style character string, be careful!!

-----

see `.rodata`, you can use this command:

    hexdump -C a.out

### Exercise 3.38

>In this section, we noted that it was not only illegal but meaningless to try to add two pointers.
Why would adding two pointers be meaningless?

Because Subtracting two points gives a logically explainable result - the offset
in memory between two points. Similarly, you can subtract or add an integral number to/from a pointer,
which means "move the pointer up or down". Adding a pointer to a pointer is something which is hard to
explain. The result is meaningless.

-----

References:

- [Why can't I add pointers](http://stackoverflow.com/questions/2935038/why-cant-i-add-pointers)

### [Exercise 3.39](ex3_39.cpp)

### [Exercise 3.40](ex3_40.cpp)

### [Exercise 3.41](ex3_41.cpp)

### [Exercise 3.42](ex3_42.cpp)

### [Exercise 3.43](ex3_43.cpp)

### [Exercise 3.44](ex3_44.cpp)

### [Exercise 3.45](ex3_45.cpp)