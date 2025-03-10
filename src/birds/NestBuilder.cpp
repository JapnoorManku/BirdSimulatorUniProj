#include <iostream>
#include <vector>
#include <string>
#include "Nest.hpp"
#include "NestBuilder.hpp"

void ConcreteNestBuilder::addMaterial(const std::string& material) {
    nest->addMaterial(material);
}

Nest* ConcreteNestBuilder::getNest() {
    Nest* result = nest;
    nest = new Nest(); // Reset for the next use
    return result;
}
