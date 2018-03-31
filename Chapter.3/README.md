# Chapter 3. Strings, Vectors, and Arrays

## Chapter 3.1 Namesapce using declaration

NOTE: .h file should not contain any using declaration.

### Exercise 3.1 : **already used**

## Chapter 3.2 SLT string

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