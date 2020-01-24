#include <iostream>
#include "WordTree.h"

int main() {
    std::cout << "Hello, World! It's a bright new day!" << std::endl;

    WordTree Tree1("cat");

    Tree1.add("Bat");
    Tree1.add("Hat");
    Tree1.add("Matt");
    Tree1.add("Matt");
    Tree1.add("Cat");
    Tree1.add("James");



    return 0;
}