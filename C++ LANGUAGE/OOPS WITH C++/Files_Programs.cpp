#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> names;

    names.push_back("My");
    names.push_back("Name");
    names.push_back("is");
    names.push_back("Akshit");
    names.push_back("Kumar");

    std::cout << "Names in the vector: ";
    for (const auto& name : names) {
        std::cout << name << " ";
    }
    std::cout << "\n";

    names.push_back("Akshit");
    names.push_back("Ujjwal");
    names.pop_back();

    std::cout << "Size of the vector: " << names.size() << "\n";

    names.insert(names.begin(), "Ram");
    names.insert(names.begin() + 3, "Sita");

    names.clear();

    std::cout << "Capacity of the vector: " << names.capacity() << "\n";

    return 0;
}
