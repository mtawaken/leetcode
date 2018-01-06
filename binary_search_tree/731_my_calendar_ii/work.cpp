/*************************************************************************
    > File Name: work.cpp
    > Author: mtawaken
    > Mail: mtwaken@gmail.com 
    > Created Time: 20180106 143232
 ************************************************************************/

/*
 * 1. Judge overlap algorithm: max(s1, s2) < min(e1, e2)
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto& v : overlaps) {
            if (max(start, v[0]) < min(end, v[1])) {
                // overlap happends
                return false;
            }
        }
        for (auto& v : books) {
            int s = max(start, v[0]);
            int e = min(end, v[1]);
            if (s < e) {
                overlaps.push_back(new int[2] {s, e});
            }
        }
        books.push_back(new int[2] {start, end});
        return true;
    }
private:
    std::vector<int*> overlaps;
    std::vector<int*> books;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
int main() {
    MyCalendarTwo* obj = new MyCalendarTwo();
    std::cout << obj->book(10,20) << std::endl;
    std::cout << obj->book(50,60) << std::endl;
    std::cout << obj->book(10,40) << std::endl;
    std::cout << obj->book(5,15) << std::endl;
    std::cout << obj->book(5,10) << std::endl;
    std::cout << obj->book(25,55) << std::endl;
}
