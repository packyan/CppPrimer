//! @file   Exercise 9.16
//! @author packy
//! @date   2018-09-15
//! @Brief  Write a program to determine whether two vector<int>s are equal.

#include <iostream>
#include <vector>
#include <list>
int main()
{
    std::list<int> list1{1, 2, 3, 4, 5};
    std::vector<int> vec4{1, 2, 3, 4, 5};
    std::vector<int> vec3{1, 2, 3, 4};
    int flag=1;
    int i = 0;
    for(std::list<int>::iterator list_iter_begin = list1.begin(), list_iter_end = list1.end();
    	list_iter_begin != list_iter_end;  ++list_iter_begin,++i){
    	if(list1.size() != vec4.size()){
    		std::cout << "false1" << std::endl;
    			flag = 0;
    			break;
    	}
    	if(*list_iter_begin != vec4[i]) 
    		{
    			std::cout << "false2" << std::endl;
    			flag = 0;
    			break;
    		}
    }
    if(flag) std::cout << "true" << std::endl;

    flag=1;
    i = 0;
    for(std::list<int>::iterator list_iter_begin = list1.begin(), list_iter_end = list1.end();
    	list_iter_begin != list_iter_end;  ++list_iter_begin,++i){
    	    	if(list1.size() != vec3.size()){
    		std::cout << "false1" << std::endl;
    			flag = 0;
    			break;
    	}
    	if(*list_iter_begin != vec3[i]) 
    		{
    			std::cout << "false2" << std::endl;
    			flag = 0;
    			break;
    		}
    }
    if(flag) std::cout << "true" << std::endl;


    std::list<int> list{1, 2, 3, 4, 5};
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{1, 2, 3, 4};

    std::cout << std::boolalpha
              << (std::vector<int>(list.begin(), list.end()) == vec1)
              << std::endl;
    std::cout << std::boolalpha
              << (std::vector<int>(list.begin(), list.end()) == vec2)
              << std::endl;


    return 0;
}
