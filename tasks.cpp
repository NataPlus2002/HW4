#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>
#include <chrono>


template <typename T>
void print(const T& t) {
    for (auto elem : t)
        std::cout << elem << " ";
    std::cout << std::endl;
}


int main() {

    //generate sequence 1 - 10
    std::vector <int> v1;
    std::default_random_engine dre;
    std::uniform_int_distribution<int> di(1, 10);
    for(int i = 0; i < 10; ++i) {
        v1.push_back(di(dre));
    }
    print(v1);

    //add few numbers from cin
    int input;
    for (auto i = 0; i < 1; ++i) {
        std::cin >> input;
        v1.push_back(input);
    }
    print(v1);

    //shuffle elments
    std::shuffle (v1.begin(), v1.end(), dre);
    print(v1);

    //delete duplicates
    // skipped 
  
    //count quantity of numbers % 2 != 0
    int num = std::count_if(v1.begin(), v1.end(), [](int elem) {
        return elem % 2 == 1;
        });
    std::cout << num << std::endl;

    ////find min and max values
    std::cout << "min = " << *(std::min_element(v1.begin(), v1.end())) << " ; max = " << *(std::max_element(v1.begin(), v1.end())) << std::endl;


    //find prime number
    std::cout << *(std::find_if(v1.begin(), v1.end(), [](int elem) {
        for (int i = 2; i <= sqrt(elem); ++i)
            if (elem % i == 0)
                return false;
        return true;
        }));
    std::cout << std::endl;

    //replace all elems to elems*elems
    std::for_each(v1.begin(), v1.end(), [](int& elem) {
        elem = elem * elem;
        });
    print(v1);

    //create vector from random numbers
    std::vector <int> v2;
    for (auto i = 0; i < v1.size();++i) {
        v2.push_back(di(dre));
    }
    print(v2);

    //sum of elems of v2
    int sum = 0;
    std::for_each(v2.begin(), v2.end(), [&sum](const int& elem) {
        sum += elem;
        });
    std::cout << sum << std::endl;

    //replace few numbers of v2
    std::replace_if(v2.begin(), v2.begin() + 2, [](int elem) {return true;}, 1);
    print(v2);

    //create vector difference betweeen v1 and v2
    std::vector <int> v3;
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));
    print(v3);
    // ne poluchaetsta
}
