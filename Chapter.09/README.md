# Sequential Containers
`vector` & `deque` &`list`
& `forward_list` & `array` & `string`  

`vector` is a good choice, unless you have a good reason to choose another container.
## Sequential Containers' Basic overview
### Exercise 9.1

>Which is the most appropriate—a vector, a deque, or a list—for the following program tasks?Explain the rationale for your choice.If there is no reason to prefer one or another container, explain why not.
(a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We’ll see in the next chapter that associative containers are better suited to this problem.
(b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.
(c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

(a). `list`
(b). `deque`
(c). `vector`

>(a) std::set is the best. now, we can select list, better than vector or deque, cause we may need to insert elements in the middle frequently to keep sorted alphabetical.
(b) deque. If the program needs to insert or delete elements at the front and the back, but not in the middle, use a deque
(c) vector, no need that insert or delete at the front or back. and If your program has lots of small elements and space overhead matters, don’t use list or forward_list.


## The Introduction of Sequential Containers
```cpp
while(begin != end){
	*begin = val;
	++begin;
}
```
the code is safe.

### Exercise 9.2
`std::list<std::deque<int>> int_deque_list;`

### Exercise 9.3
>What are the constraints on the iterators that form iterator ranges?
[begin,end)
1. two iterators, begin and end:
they refer to elements of the same container.
2. It is possible to reach end by repeatedly incrementing begin.

### Exercise 9.4
```cpp
bool FindOrNot(std::vecotr<int>::iterator beg, std::vecotr<int>::iterator end, int value){
	while(begin != end){
	if(*begin == value) return true;
	++begin;
}
return fales;
}
```

### Exercise 9.4
```cpp
bool FindOrNot(std::vecotr<int>::iterator beg, std::vecotr<int>::iterator end, int value){
	while(begin != end){
	if(*begin == value) return true;
	++begin;
}
return fales;
}
```

### Exercise 9.5
```cpp
td::vecotr<int>::iterator FindOrNot(std::vecotr<int>::iterator beg, std::vecotr<int>::iterator end, int value){
	while(begin != end){
	if(*begin == value) return begin;
	++begin;
}
return end;
}
```

### Exercise 9.6
> What is wrong with the following program? How might you correct it?
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2) /*ERROR: operator< can't be applied to iterator for list*/

Fixed:
`while(iter1 != iter2)`

### Exercise 9.7 
>What type should be used as the index into a vector of ints?

`vector<int>::size_type`

### Exercise 9.8 
What type should be used to read elements in a list of strings? To write them?

>list<string>::iterator || list<string>::const_iterator // read
>list<string>::iterator // write

### Exercise 9.9
>What is the difference between the begin and cbegin functions?

1. `cbegin` is a const member that returns the container’s const_iterator type.

2. `begin` can be nonconst and returns the container’s iterator type and also can be const depends on the container is const or not.

### Exercise 9.10
>What are the types of the following four objects?
>
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();

(@shidenggui)[https://github.com/shidenggui]:
The question example codes have an error in gcc 4.8:
`**error**: inconsistent deduction for ‘auto’: ‘__gnu_cxx::__normal_iterator<int*, std::vector<int> >’ and then ‘__gnu_cxx::__normal_iterator<const int*, std::vector<int> >’ auto it1 = v1.begin(), it2 = v2.begin();
`
Fixed:
```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(),  // cause v1 and v2 have different type
auto it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

1. iterator
2. const_iterator
3. const_iterator
4. const_iterator

### Exercise 9.11
The six ways to initialize a vector
1. `vecotr<int> v1;` 0
2. `vecotr<int> v2(v1);` same as v1
3. `vecotr<int> v3(10,1);` 1
4. `vecotr<int> v4{1,2,3,4,5};` 1,2,3,4,5
5. `vecotr<int> v5(10);` 0
6. `vector<int> v6(v4.begin(), v4.end());` same as v4

### Exercise 9.12
>Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.

[@pezy](https://github.com/pezy/CppPrimer/tree/master/ch09)

1. The constructor that takes another container as an argument (excepting array) assumes the container type and element type of both containers are identical. It will also copy all the elements of the received container into the new one:
```cpp
list<int> numbers = {1, 2, 3, 4, 5};
list<int> numbers2(numbers);        // ok, numbers2 has the same elements as numbers
vector<int> numbers3(numbers);      // error: no matching function for call...
list<double> numbers4(numbers);     // error: no matching function for call...
```
2. The constructor that takes two iterators as arguments does not require the container types to be identical. Moreover, the element types in the new and original containers can differ as long as it is possible to convert the elements we’re copying to the element type of the container we are initializing. It will also copy only the object delimited by the received iterators.

```cpp
list<int> numbers = {1, 2, 3, 4, 5};
list<int> numbers2(numbers.begin(), numbers.end);        // ok, numbers2 has the same elements as numbers
vector<int> numbers3(numbers.begin(), --numbers.end());  // ok, numbers3 is {1, 2, 3, 4}
list<double> numbers4(++numbers.beg(), --numbers.end());        // ok, numbers4 is {2, 3, 4}
forward_list<float> numbers5(numbers.begin(), numbers.end());   // ok, number5 is {1, 2, 3, 4, 5}
```

In short, constructor that takes a container to copy, the tpye must be the same, the constructor that takes two iterators, if the type can be converted to another one, it's correct.

### [Exercise 9.13](ex_09_13.cpp)

### [Exercise 9.14](ex_09_14.cpp)

### [Exercise 9.15](ex_09_15.cpp)

### [Exercise 9.16](ex_09_16.cpp)

### Exercise 9.17
>Assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types of c1 and c2?

First, there must be the identical container and same type holded. Second,the type held must support relational operation. (@Mooophy)

Both c1 and c2 are the containers except the unordered associative containers.(@pezy)

### [Exercise 9.18](ex_09_18.cpp)
### [Exercise 9.19](ex_09_19.cpp)
### [Exercise 9.20](ex_09_20.cpp)

### Exercise 9.21

>Explain how the loop from page 345 that used the return from insert to add elements to a list would work if we inserted into a vector instead.

It's the same.

>The first call to insert takes the string we just read and puts it in front of the element denoted by iter. The value returned by insert is an iterator referring to this new element. We assign that iterator to iter and repeat the while, reading another word. As long as there are words to insert, each trip through the while inserts a new element ahead of iter and reassigns to iter the location of the newly inserted element. That element is the (new) first element. Thus, each iteration inserts an element ahead of the first element in the vector.

### Exercise 9.22

Assuming iv is a vector of ints, what is wrong with the following program? How might you correct the problem(s)?

```cpp
vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
while (iter != mid)
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val);
```
**Problems:**
It's a endless loop. iter never equal mid.
mid will be invalid after the insert.(see[Mooophy/Cpp-Primer#133](https://github.com/Mooophy/Cpp-Primer/issues/133) )

**Fixed** [here](ex_09_ee.cpp)

### Exercise 9.23
>In the first program in this section on page 346, what would the values of val, val2, val3, and val4 be if c.size() is 1?

same value that equal to the first element's.

### [Exercise 9.24](ex_09_24.cpp)

###  Exercise 9.25 
>In the program on page 349 that erased a range of elements, what happens if elem1 and elem2 are equal? What if elem2 or both elem1 and elem2 are the off-the-end iterator?

if elem1 and elem2 are equal, nothing happened.

if elem2 is the off-the-end iterator, it would delete from elem1 to the end.

if both elem1 and elem2 are the off-the-end iterator, nothing happened too.

### [Exercise 9.26](ex_09_26.cpp)
### [Exercise 9.27](ex_09_27.cpp)

### [Exercise 9.28](ex_09_28.cpp)

>Given that vec holds 25 elements, what does vec.resize(100) do? What if we next wrote vec.resize(10)?

```cpp
vec.resize(100);    // adds 75 items to the back of vec. These added items are value initialized.
vec.resize(10);     // erases 90 elements from the back of vec
```

### Exercise 9.30
>What, if any, restrictions does using the version of resize that takes a single argument place on the element type?

If the container holds elements of a class type and resize adds elements, we must supply an initializer or the element type must have a default constructor.

### Exercise 9.31 [using list](ex_09_31.cpp)||[using forward_list](ex_09_31_1.cpp)

 
### Exercise 9.32
 @Brief  In the program on page 354 would it be legal to write the call to
//  insert as follows?
//          If not, why not

//          iter = vi.insert(iter, *iter++);
//  @Answer the statement is illegal, cause as said in Standard [5.2.2] :
//          "The order of evaluation of arguments is unspecified."
//          As a result, after entering function insert,
//          iter could be its original value or original value + 1 or even
//          anything else,
//          depending on how compiler implemented.
//          correct it as follows:
//  @Discuss    https://github.com/Mooophy/Cpp-Primer/issues/125

### Exercise 9.33
  >Brief  In the final example in this section what would happen
  if we did not assign the result of insert to begin?
  Write a program that omits this assignment to see if yourexpectation was correct.

crash, cause the **iterator is invalid after insert**. Because Iterators, pointers, and references to a vector or string are invalid if the container was reallocated.


### [Exercise 9.33](ex_09_34.cpp)
 "infinite loop". Casue the `++iter` out of the `while` loop. But
 even through add brackets it is still infinite loop.

### Exercise 9.34 
 >Explain the difference between a vector’s capacity and its size.
 Explain the difference between a vector’s capacity and its size.

The size of a container is the number of elements it already holds;

The capacity is how many elements it can hold before more space must be allocated.
The size of a container is the number of elements it already holds;

The capacity is how many elements it can hold before more space must be allocated.

### Exercise 9.36
> Can a container have a capacity less than its size?

cannot.

### Exercise 9.37
Why don’t list or array have a capacity member?

list elements does not store contiguously. array has the fixed size, thus cannot added elements to it.

### Exercise 9.38
```cpp
//! @Alan
//!
//! Exercise 9.38:
//! Write a program to explore how vectors grow in the library you use.
//!

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> v;
    std::string word;

    while (std::cin >> word) {
        v.push_back(word);
        std::cout << v.capacity() << "\n";
    }

    return 0;
}
```

### Exercise 9.39
>Explain what the following program fragment does:

```cpp
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
    svec.push_back(word);
svec.resize(svec.size()+svec.size()/2);
```

The while loop will read words from cin and store them in out vector. Even if we initially reserved 1024 elements, if there are more words read from cin, our vector's capacity will be automatically increased (most implementations will double the previous capacity) to accommodate them.

And now comes the catch. resize() is different from reserve(). In this case resize() will add another svec.size()/2 value initialized elements to svec. If this exceeds svec.capacity() it will also automatically increase it to accommodate the new elements.

### Exercise 9.40
>If the program in the previous exercise reads 256 words, what is its likely capacity after it is resized? What if it reads 512? 1,000? 1,048?

read	size	capacity
256	384	1024
512	768	1024
1000	1500	2000(clang is 2048)
1048	1572	2048

### [Exercise 9.41](ex_09_41.cpp)

### Exercise 9.42
>Given that you want to read a character at a time into a string, and you know that you need to read at least 100 characters, how might you improve the performance of your program?

Use member reserve(120) to allocate enough space for this string. (@Mooophy)

### [Exercise 9.43](https://github.com/pezy/CppPrimer/blob/master/ch09/ex9_43.cpp)

### [Exercise 9.44](ex_09_44.cpp)

### [Exercise 9.45](ex_09_45.cpp)

### [Exercise 9.46](ex_09_46.cpp)

### Exercise 9.47 [find_first_of](ex_09_47.cpp)||[find_first_not_of](ex_09_47_1.cpp)

### Exercise 9.48
>Given the definitions of name and numbers on page 365, what does numbers.find(name) return?

string::npos

### [Exercise 9.49](ex_09_49.cpp)

### [Exercise 9.50](ex_09_50.cpp)

### [Exercise 9.51](ex_09_51.cpp)
