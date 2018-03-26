#exercise 1.1

>C++ source files conventionally use one of the suffixes ‘.C’, ‘.cc’, ‘.cpp’, ‘.CPP’, ‘.c++’, ‘.cp’, or ‘.cxx’; C++ header files often use ‘.hh’, ‘.hpp’, ‘.H’, or (for shared template code) ‘.tcc’; and preprocessed C++ files use the suffix ‘.ii’. GCC recognizes files with these names and compiles them as C++ programs even if you call the compiler the same way as for compiling C programs (usually with the name gcc).

>However, the use of gcc does not add the C++ library. g++ is a program that calls GCC and automatically specifies linking against the C++ library. It treats ‘.c’, ‘.h’ and ‘.i’ files as C++ source files instead of C source files unless -x is used. This program is also useful when precompiling a C header file with a ‘.h’ extension for use in C++ compilations. On many systems, g++ is also installed with the name c++. 
