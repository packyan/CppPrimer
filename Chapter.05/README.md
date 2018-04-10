# Charpter 5. Statements
## Charpter 5.1 Simple Statements
### Exercise 5.1

>What is a null statement? When might you use a null statement?

a null statement is a statement only contains a `;`.
e.g. 

```cpp
while(1) ;
```

>the language need a statement to make sense but the program's logic does not. 
e.g.

```cpp
// read until we hit end-of-file or find an input equal to sought
while (cin >> s && s != sought)
    ; // null statement.
```

### Exercise 5.2

>What is a block? When might you might use a block?

Block is a (possiby empty) sequence of statements and declarations surrounded by a pair of curly braces, campound statement also is called `Block`.

where the language requires a single statement but the logic of the program needs more than one. For example:

```cpp
while(val <= 10){
    sum += val;
    ++val;
}
```

### Exercise 5.3

>Use the comma operator (§ 4.10, p. 157) to rewrite the while loop from § 1.4.1 (p. 11)
so that it no longer requires a block.
Explain whether this rewrite improves or diminishes the readability of this code.


```cpp
while (val <= 10) sum += val, ++val;
```


I think this rewrite disminishes the readability of this code. The value of a comma expression is the last expression's value, the front results will be discard. Although it's fine in this example, but it's incomprehensible to discard these results.

### Exercise 5.4

>Explain each of the following examples, and correct any problems you detect.
> ```cpp
> - (a) while (string::iterator iter != s.end()) { /* . . . */ }
> - (b) while (bool status = find(word)) { /* . . . */ }
>         if (!status) { /* . . . */ }
> ```

(a) invalid. because iter point at nothing.

```cpp
std::string::iterator iter = s.begin();
    while (iter != s.end()) { /* . . . */ }
```

(b) The if statement is not in the while's block. so the `status` is invalid. If we want use `status` after the while block, declare status out of the while block.

```cpp
bool status;
while ((status = find(word))) {/* ... */}
if (!status) {/* ... */}
```

### [Exercise 5.5](ex5_5.cpp)

### [Exercise 5.6](ex5_6.cpp)

### Exercise 5.7

>Correct the errors in each of the following code fragments:

```cpp
(a) if (ival1 != ival2) ival1 = ival2
    else ival1 = ival2 = 0;
(b) if (ival < minval) minval = ival;
    occurs = 1;
(c) if (int ival = get_value())
    cout << "ival = " << ival << endl;
    if (!ival)
    cout << "ival = 0\n";
(d) if (ival = 0)
    ival = get_value();
```

```cpp
(a) if (ival1 != ival2) ival1 = ival2; // missing semicolon.
    else ival1 = ival2 = 0;
(b) if (ival < minval)
    {
        minval = ival;
        occurs = 1;
    }
(c) int ival;
    if (ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)
        cout << "ival = 0\n";
        \\or
    if(int ival = get_value())
        cout << "ival = " << ival << endl;
    else cout << "ival = 0"  << endl;

(d) if (ival == 0)
    ival = get_value();
```

### Exercise 5.8

>What is a “dangling else”? How are else clauses resolved in C++?

Colloquial term used to refer to the problem of how to process nested if statements in which there are more ifs than elses. In C++, an else is always paired with the **closest preceding unmatched if**.

### [Exercise 5.9](ex5_9.cpp)

### [Exercise 5.10](ex5_10.cpp)

### [Exercise 5.11](ex5_11.cpp)

### [Exercise 5.12](ex5_12.cpp)

### Exercise 5.13

>Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.

```cpp
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;
        case 'e': eCnt++;
        default: iouCnt++;
    }
(b) unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9:
            oddcnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;
            break;
    }
(d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```

```cpp
(a) // Error: should have a break statement
    unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++; break;
        case 'e': eCnt++; break;
        default : iouCnt++; break;
    }
(b) // Error: ix is not in scope.
    unsigned index = some_value();
    int ix;
    switch (index) {
        case 1:
            ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = static_cast<int>(ivec.size())-1;
            ivec[ ix ] = index;
    }
(c) // Error: case label syntax error
    unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1: case 3: case 5: case 7: case 9:
            oddcnt++;
            break;
        case 2: case 4: case 6: case 8: case 0:
            evencnt++;
            break;
    }
(d) // Error: case label must be a constant expression
    const unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```
