#include <iostream>
#include <list>
#include <string>

// (a)
std::list<int> reverseList(std::list<int> &inputList) {
    std::list<int>::iterator itend = inputList.end();

    for (std::list<int>::iterator it = inputList.begin(); it != itend; ++it) {
        std::swap(*it, *(itend = std::prev(itend)));    
    }

    return inputList;
}

// (b)
std::list<int> zigzag(std::list<int> &inputList) {
    std::list<int> temp;
    inputList.sort();
    for (auto v : inputList)
        std::cout << v << std::endl;

    while (inputList.size() != 0) {
        temp.push_back(*(inputList.begin()));
        temp.push_back(*(inputList.end()));
        for (auto v : temp)
            std::cout << v << std::endl;
        inputList.pop_front();
        inputList.pop_back();
    }
    inputList = temp;

    return inputList;
}

int main() {
    std::list<int> empty = {};
    std::list<int> even = {2, 3, 14, 6};
    std::list<int> uneven = {5, 1, 7};
    std::list<int> zig = {4,2,7,1,8,3,5};
   
    /* (a)
    std::list<int> u = reverseList(even);
    for (auto v : u)
        std::cout << v <<  std::endl;
    */

    zigzag(even);

    return 0;
}
