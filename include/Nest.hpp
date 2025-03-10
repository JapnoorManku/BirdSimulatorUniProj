#ifndef NEST_HPP
#define NEST_HPP

#include <iostream>
#include <vector>
#include <string>

// Product: Nest
class Nest {
 private:
    std::vector<std::string> materials;
 public:
    void addMaterial(const std::string& material);
    void displayNest();
};

#endif
