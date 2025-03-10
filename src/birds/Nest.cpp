#include "Nest.hpp"

void Nest::addMaterial(const std::string& material) {
    materials.push_back(material);
}
void Nest::displayNest() {
    std::cout << "Nest built with: ";
    for (const auto& material : materials) {
        std::cout << material << " ";
    }
    std::cout << std::endl;
}
