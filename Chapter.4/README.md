# Chapter 4. Expressions
## Chapter 4.1 Basic
### Exercise 4.1
> What is the value returned by 5 + 10 * 20/2?

105

### Exercise 4.2

> Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:
>
> ```cpp
> * vec.begin() //=> *(vec.begin())
> * vec.begin() + 1 //=> (*(vec.begin())) + 1
> ```

### Exercise 4.3

> Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

I think it's acceptable. Because the biggest advantage for C++ is the speed. 
Regardless of whether the compiler has optimized it, do not use binary operators that do not define the order of evaluation.

## Arithmetic operators

### Exercise 4.4

> Parenthesize the following expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.
>
> ```cpp
> 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
> // parenthesize
> ((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2)
> // 16 + 75 + 0 = 91
> // print: 91
> ```

### Exercise 4.5
> Determine the result of the following expressions.
>
> ```cpp
> -30 * 3 + 21 / 5  // -90+4 = -86
> -30 + 3 * 21 / 5  // -30+63/5 = -30+12 = -18
> 30 / 3 * 21 % 5   // 10*21%5 = 210%5 = 0
> -30 / 3 * 21 % 4  // -10*21%4 = -210%4 = -2
> ```

### Exercise 4.5
> Write an expression to determine whether an int value is even or odd.


`(int_val%2)?1:0` 1 means "odd", 0 means "even"

### Exercise 4.7

> What does overflow mean? Show three expressions that will overflow.
> 
> ```cpp
> short short_val = 32767;
> short_val++;
> char char_val = 254;
> char++;
> unsigned unsigned_val = 0;
> unsigned_val--;
> ```

## Chapter 4.3 Logical and relational operators

###Exercise 4.8

> Explain when operands are evaluated in the logical `AND`, logical `OR`, and `EQU` operators.

from the book:

> The logical `AND` and `OR` operators always evaluate their left operand before the right. Moreover, the right operand is evaluated if and only if the left operand does not determine the result. This strategy is known as **short-circuit evaluation**.

- logical `AND` : the second operand is evaluated if and only if the left side is `true`.
- logical `OR` : the second operand is evaluated if and only if the left side is `false`
- `EQU` operators : `true` only if both operands have the same value, otherwise, it returns `false`.

### Exercise 4.9

> Explain the behavior of the condition in the following `if`:
>
> ```cpp
> const char *cp = "Hello World";
> if (cp && *cp)
> ```

`cp` is  `const char*` type, only when `cp`  is not a `nullptr` it's true,
`*cp` is `const char` type, when `cp[0]` is explicit a nonzero value, so its true.

then `true && true` -> `true`

### Exercise 4.10

> Write the condition for a while loop that would read ints from the standard input and stop when the value read is equal to 42.
> ```cpp
> int int_put = 0;
> while(cin >> int_put && int_put != 42)
> ```

### Exercise 4.11

> Write an expression that tests four values, a, b, c, and d, and ensures that a is greater than b, which is greater than c, which is greater than d.
> ```cpp
> if(a > b && b > c && c > d)
> ```

### Exercise 4.12

> Assuming `i`, `j`, and `k` are all ints, explain what `i != j < k` means.

According to Operator precedence, `i != j < k` is the same as `i != (j < k)`.

reference:

> It is usually a bad idea to use the boolean literals `true` and `false` as operands in a comparison. These literals should be used only to compare to an object of type `bool`.




## Assignment operator

### Exercise 4.13

> What are the values of i and d after each assignment?
>
> ```cpp
> int i;   double d;
> d = i = 3.5; // i = 3, d = 3.0
> i = d = 3.5; // d = 3.5, i = 3
> ```


### Exercise 4.14

> Explain what happens in each of the if tests:
>
> ```cpp
> if (42 = i)   // compile error: expression is not assignable
> if (i = 42)   // true.
> ```

### Exercise 4.15

> The following assignment is illegal. Why? How would you correct it?
>
> ```cpp
> double dval; int ival; int *pi;
> dval = ival = pi = 0;
> // pi is a pointer to int.
> // can not assign to 'int' from type 'int *'
> // correct:
> dval = ival = 0;
> pi = 0;
> ```

### Exercise 4.16

> Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.
>
> ```cpp
> if (p = getPtr() != 0)
> if (i = 1024)
> // use an assigment as a condition. assigment should use `( )`
> // correct
> if ((p = getPtr()) != 0)
> if (i == 1024)
> ```

## Chapter 4.5 Increment and decrement operators

### Exercise 4.17

> Explain the difference between prefix and postfix increment.

The postfix operators increment(or decrement) the operand but yield a copy of the original, unchanged value as its result.

The prefix operators return the object itself as an **lvalue**.

The postfix operators return a copy of the object's original value as an **rvalue**.

### Exercise 4.18

> What would happen if the while loop on page 132 that prints the elements from a vector used the prefix increment operator?

It will print from the second element and dereference `v.end()` at last.(It's undefined and very dangerous)

### Exercise 4.19

> Given that `ptr` points to an `int`, that `vec` is a `vector<int>`, and that `ival` is an `int`, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?
>
> ```cpp
> ptr != 0 && *ptr++  // check ptr is not a nullptr. and check the pointer value.
> ival++ && ival // check ival and ival+1 whether equal zero.
> // I think because ival is a built-in type, so the order of operations can be determined but it is not well written, it's bad.
> //should be :
> ival && ival+1
> 
> vec[ival++] <= vec[ival] // incorrect. It is an **Undefined Behavior**
> //If the compiler first evaluates the value of vec[ival], it's will always be equal 
> // correct:
> vec[ival] <= vec[ival+1]
> ```

NOTE:
1. Every value computation and side effect of the first (left) argument of the built-in logical `AND` operator` && `and the built-in logical `OR` operator` || `is sequenced before every value computation and side effect of the second (right ) argument.see [order of evaluation](http://en.cppreference.com/w/cpp/language/eval_order).
2. If you change the value of an operand, do not use this operand elsewhere in the expression

## Chapter 4.6 Member access operator

NOTE:
1. if `p` is a pointer, `p->mem` means `(*p).mem`.

### Exercise 4.20

> Assuming that iter is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren’t legal are in error.
>
> ```cpp
> *iter++;  // return *iter, then ++iter.
> (*iter)++;  // illegal, *iter is a string, cannot increment value.
> *iter.empty() // illegal, iter should use '->' to indicate whether empty.
> iter->empty();  // indicate the iter' value whether empty.
> ++*iter;        // illegal, string have not increment.
> iter++->empty();  // return iter->empty(), then ++iter.
> ```

## Chapter 4.7 Conditional operators

### [Exercise 4.21](ex4_21.cpp)

### [Exercise 4.22](ex4_22.cpp)

### Exercise 4.23

> The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 147), explain why it fails. How would you fix it?
>
> ```cpp
> string s = "word";
> string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
> ```

Operator Precedence: `?:` < `+`

**Fix it**:

```cpp
string pl = s + ((s[s.size() - 1] == 's') ? "" : "s") ;
```

### Exercise 4.24

> Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.

if the operator were left associative.

```cpp
finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
```

would same as :

```cpp
finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";
```

if `grade > 90`, first conditional operator's result is `high pass`. so the finalgrade is always fail. It's contradictory obviously.

### Exercise 4.25

> What is the value of ~'q' \<< 6 on a machine with 32-bit ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the bit pattern 01110001?
The final value in decimal representation is `-7296`.

The bitwise NOT operator (`~`) yields us the Ones' Complement of `0000 0000 0000 0000 0000 0000 0111 0001`, which is `1111 1111 1111 1111 1111 1111 1000 1110`. The value of `1111 1111 1111 1111 1111 1111 1000 1110` in decimal form is `-114`. This may come as a surprise to some as the unsigned value of said binary sequence is `4294967182`. The most significant bit (the left-most bit, commonly referred to as the sign bit) is however "turned on", or `1`, which signifies a negation operation on that particular bit. The value of that particular bit is then `-2147483648`.

We then shift the bits `6` digits to the left, which yields us `1111 1111 1111 1111 1110 0011 1000 0000`. Overflowing bits were discarded. The decimal representation of the binary sequence is `-7296`.

### Exercise 4.26
> In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?

There are 30 students in the example of this section. `unsigned long` have at least 32 bits on any machine. Thus, it is ensured that the bits start out with well-define values. The standard define that `unsigned int` is guaranteed to hold 16 bits. If `unsigned int` adopted, the result is undefined.

## Exercise 4.27

> What is the result of each of these expressions?
>
> ```cpp
> unsigned long ul1 = 3, ul2 = 7;
> ul1 & ul2 // == 3  0011 & 0111 = 0011
> ul1 | ul2 // == 7 0011 | 0111 = 0111
> ul1 && ul2 // == true
> ul1 || ul2 // == ture
> ```


## Chapter 4.9 sizeof

### [Exercise 4.28](ex4_28.cpp)
### Exercise 4.29

> Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.
>
> ```cpp
> int x[10];   int *p = x;
> cout << sizeof(x)/sizeof(*x) << endl;
> cout << sizeof(p)/sizeof(*p) << endl;
> ```

The first result is 10. It returns the number of elements in x. 

But the second result depends on your machine. It would be 2 on the 64-bit machine(pointer size is 8 bytes) and 1 on the 32-bit machine(pointer size is 4 bytes). Because of the size of pointer depends on machines.

---

reference: [Why the size of a pointer is 4bytes in C++](http://stackoverflow.com/a/2428809)

### Exercise 4.30

> Using Table 4.12 (p. 147), parenthesize the following expressions to match the default evaluation:
>
> ```cpp
> sizeof x + y      // (sizeof x)+y . "sizeof" has higher precedence than binary`\+`.
> sizeof p->mem[i]  // sizeof(p->mem[i])
> sizeof a < b      // sizeof(a) < b
> sizeof f()        // if`f()`returns`void`, this statement is undefined, otherwise it returns the size of return type.
> ```

---

reference: [sizeof operator](http://en.cppreference.com/w/cpp/language/sizeof)

