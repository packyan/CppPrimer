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

<<<<<<< HEAD
### Exercise 7.31 [HEADER](ex_07_31.h)

### Exercise 7.32 [HEADER](ex_07_32.h) | [CPP](ex_07_32.cpp)

### Exercise 7.33

[clang]error: unknown type name 'pos'

fixed:

```cpp
Screen::pos Screen::size() const
{
    return height*width;
}
```

### Exercise 7.34

There is an error in

```cpp
dummy_fcn(pos height)
           ^
Unknown type name 'pos'
```

### Exercise 7.35

```cpp
typedef string Type;
Type initVal(); // use `string`
class Exercise {
public:
    typedef double Type;
    Type setVal(Type); // use `double`
    Type initVal(); // use `double`
private:
    int val;
};

Type Exercise::setVal(Type parm) {  // first is `string`, second is `double`
    val = parm + initVal();     // Exercise::initVal()
    return val;
}
```
=======
### [Exercise 7.41](ex_07_41_sales_data_test.cpp)
### Exercise 7.42

```cpp
class Tree{
    Tree(int p, int lc, int rc): parent(p),left_child(lc),right_child(rc){}
    Tree(int p): Tree(p,0,0){}
private:
    int parent;
    int left_child;
    int right_child;
};
```

### Exercise 7.43

```cpp
class NoDefault{
NoDefault(int ii):i(ii){}
private:
    int i;
    int j;
}

class C{
    C():nodef(0) {}
private:   
    NoDefault nodef;

}
```

### Exercise 7.44
illegal, cause there are ten elements, each would be value initialized. But no default constructor for NoDefault type.

note: candidate constructor (the implicit move constructor) not viable: requires 1 argument, but 0 were provided

### Exercise 7.45
legal, cause `C` have the default constructor.

### Exercise7.46

1. a) A class must provide at least one constructor. (untrue, "The compiler-generated constructor is known as the synthesized default constructor.")
2. b) A default constructor is a constructor with an empty parameter list. (untrue, A default constructor is a constructor that is used if no initializer is supplied.What's more, A constructor that supplies default arguments for all its parameters also defines the default constructor)
3. c) If there are no meaningful default values for a class, the class should not provide a default constructor. (untrue, the class should provide.)
4. d) If a class does not define a default constructor, the compiler generates one that initializes each data member to the default value of its associated type. (untrue, only if our class does not explicitly define any constructors, the compiler will implicitly define the default constructor for us.)


### Exercice 7.54
Should not be claimed as  `constexpr `, cause a `constexpr ` function must contain a ``return`` statement.

### Exercise 7.55
yes.
An aggregate class whose data members are all of literal type is a literal class.

### Exercise 7.56
What is a static class member?
A class member that is associated with the class, rather than with individual objects of the class type.
What are the advantages of static members?
each object can no need to store a common data. And if the data is changed, each object can use the new value.
How do they differ from ordinary members?
1. a static data member can have incomplete type.
2. we can use a static member as a default argument.

[Exercise 7.57](https://github.com/pezy/CppPrimer/blob/master/ch07/ex7_57.h)
form [@pezy](https://github.com/pezy/CppPrimer/)
### Exercise 7.58
```cpp
static double rate = 6.5;
                ^
            rate should be a constant expression.

static vector<double> vec(vecSize);
                            ^
            we may not specify an in-class initializer inside parentheses.
```
Fixed:
```cpp
// example.h
class Example {
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};

// example.C
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```
>>>>>>> 3e2407dcfe75e8a7a20463b285ca0335afea311b
