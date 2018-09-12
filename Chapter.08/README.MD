# Chapter 8. The IO Library
## Chapter8.1 IO Class

### Exercise 8.1 && Exercise 8.2
```cpp
#include <iostream>
#include <string>
using namespace std;
istream& istream_test(istream& in){
    std::string buf;    
    while(in >> buf)
        cout << buf << '\n' << endl;
    in.clear();
    return in;
} 
int main(int argc, char const *argv[])
{
    istream_test(cin);
    return 0;
}
```
### Exercise 8.3
What causes the following while to terminate?

while (cin >> i) /*  ...    */
putting cin in an error state cause to terminate. such as eofbit, failbit and badbit.

### [Exercise 8.4](ex_08_04.cpp)

### [Exercise 8.5](ex_08_05.cpp)

### [Exercise 8.6](ex_08_06.cpp)

### [Exercise 8.7](ex_08_07.cpp)
### [Exercise 8.8](ex_08_08.cpp)
### [Exercise 8.9](ex_08_09.cpp)
### [Exercise 8.10](ex_08_10.cpp)
### [Exercise 8.11](ex_08_11.cpp)

### Exercise 8.12
Why didn’t we use in-class initializers in PersonInfo?

Cause we need a aggregate class here. so it should have no in-class initializers.

### [Exercise8.13](https://github.com/pezy/CppPrimer/blob/master/ch08/ex8_13.cpp)



### Exercise 8.14
Why did we declare entry and nums as const auto &?

cause they are all class type, not the built-in type. so reference more effective.
output shouldn't change their values. so we added the const.