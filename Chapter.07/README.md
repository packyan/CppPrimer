## Chapter 7. Classes

### [Exercise 7.1](ex_07_01.cpp)

### [Exercise 7.2](ex_07_02.h)

### [Exercise 7.3](ex_07_03.cpp)

### [Exercise 7.4](ex_07_04_05.h)

### [Exercise 7.5](ex_07_04_05.h)

### [Exercise 7.6](ex_07_06.h)

### [Exercise 7.7](ex_07_07.cpp)

### Exercise 7.8

Define `read`'s `Sales_data` parameter as plain reference since it's intended to change the `revenue`'s value.

Define `print`'s `Sales_data` parameter as a reference to `const` since it isn't intended to change any member's value of this object.

### [Exercise 7.9](ex_07_09.h)

## Exercise 7.10

```cpp
if(read(read(cin, data1), data2))
```

we can try to divide it like that:

```cpp
std::istream &firstStep = read(cin, data1);
std::istream &secondStep = read(firstStep, data2);
if (secondStep)
```

the condition of the `if` statement would read two `Sales_data` object at one time.

### Exercise 7.11

[Sales_data Definition](ex_07_06.h) | [Sales_data Implementation](ex_07_11.cpp)

### [Exercise 7.12](ex_07_12.h)

### [Exercise 7.13](ex_07_13.cpp)

### Exercise 7.14

```cpp
Sales_data() : units_sold(0) , revenue(0){}
```

### [Exercise 7.15](ex_07_15.h)

### Exercise 7.16

There are no restrictions on how often an access specifier may appear.The specified access level remains in effect until the next access specifier or the end of the class body.

The members which are accessible to all parts of the program should define after a public specifier.

The members which are accessible to the member functions of the class but are not accessible to code that uses the class should define after a private specifier.

### Exercise 7.17

The defult access level is different.
The only difference between using `class` and using `struct` to define a class is the default access level. (`class` : private, `struct` : public)

### Exercise 7.18

encapsulation is the separation of implementation from interface. 
It **hides the implementation details** of a type. (In C++, encapsulation is enforced by putting the implementation in the private part of a class)

---

Important advantages:

- User code cannot inadvertently corrupt the state of an encapsulation object.
- The implementation of an encapsulated class can change over time without requiring changes in user-level code.

### Exercise 7.19

- `public` include: constructors, `getName()`, `getAddress()`.
- `private` include: `name`, `address`.

the interface should be defined as public, the data shouldn't expose to outside of the class.

### Exercise 7.20

`friend` is a mechanism by which a class grants access to its nonpublic members. They have the same rights as members.

**Pros**:

- the useful functions can refer to class members in the class scope without needing to explicitly prefix them with the class name.
- you can access all the nonpublic members conveniently.
- sometimes, more readable to the users of class.

**Cons**:

- lessens encapsulation and therefore maintainability.
- code verbosity, declarations inside the class, outside the class.

### [Exercise 7.21](ex_07_21.h)

### [Exercise 7.22](ex_07_22.h)

### [Exercise 7.22](ex_07_22.h)

### [Exercise 7.23](ex_07_23.h)

### Exercise 7.24 [Cpp](ex_07_24.cpp) | [Header](ex_07_23.h)

### Exercise 7.25

I think this class only use built-in type an STL string, so it can rely on the default version of copy and assignment safely.

The class below can rely on it. It goes in *Section 7.1.5*:

> ..the synthesized versions are unlikely to work correctly for classes that allocate resources that reside outside the class objects themselves.
>
> Moreover, the synthesized versions for copy, assignment, and destruction work correctly for classes that have **vector or string members**.

Hence the class below which used only built-in type and strings can rely on the default version of copy and assignment. (by [@Mooophy](https://github.com/Mooophy)\)

### Exercise 7.26 [cpp](ex_07_26_sales_data.cpp) | [header](ex_07_26_sales_data.h) | [test.cpp](ex_07_26_sales_data_test.cpp)

### Exercise 7.27 [cpp](ex_07_27_Screen_display.cpp) | [header](ex_07_27.h)

### Exercise 7.28

The first call to `display` wiil print a `#` among `XXX..` but the second call to `display` couldn't print `#` among the output, cause the call to `set` would change the **temporary copy**, not myScreen.

### Exercise 7.29

```sh
#with '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
                   ^^^
# without '&'
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
                   ^^^
```

### Exercise 7.30

#### Pros

- more explicit
- less scope for misreading
- can use the member function parameter which name is same as the member name.

```cpp
void setAddr(const std::string &addr) {this->addr = addr;}
```

#### Cons

- more to read
- sometimes redundant

```cpp
std::string getAddr() const { return this->addr; } // unnecessary
```

From[@pezy](https://github.com/pezy/CppPrimer/)

