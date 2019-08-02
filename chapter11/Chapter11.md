#associative-container
two head files: map & set.
`map` is a template, map<keys, values>

### 11.1
> the difference between `map` and `vector`
`map` is odered, but vector is not;
`map` use `pair` to acess, but `vector`use `index`;
> A `map` is a collection of key-value pairs. we can get a value lookup by key efficiently.
> A `vector` is a collection of objects, and every object has an associated index, which gives access to that object.

### 11.2
>Give an example of when each of list, vector, deque, map, and set might be most useful.

`list` : a to-do list. always need insert or delete the elements anywhere.
`vector` : save some important associated data, always need query elements by index.
`deque` : message handle. FIFO.
`map` : dictionary.
`set` : bad_checks.


### [11.3](ex11.3.cpp)

### [11.4](ex11.4.cpp)

### 11.5
> Explain the difference between a map and a set. When might you use one or the other?
1. set : the element type is the key type.
2. map : we should use a key-value pair, such as {key, value} to indicate that the items together from one element in the map.
I use set when i just need to store the key, In other hand, I　would like use map when i need to store a key-value pair.

### 11.6 
> Explain the difference between a set and a list. When might you use one or the other?

`set` is unique and order, but `list` is neither. using which one depend on whether the elements are unique and order to store.

### [11.7](ex11.7.cpp)