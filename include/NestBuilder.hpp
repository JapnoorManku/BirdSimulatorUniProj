#ifndef NEST_BUILDER_HPP
#define NEST_BUILDER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Nest.hpp"

// Builder Interface
class NestBuilder {
 public:
    virtual void addMaterial(const std::string& material) = 0;
    virtual Nest* getNest() = 0;
    virtual ~NestBuilder() = default;
};

// Concrete Builder
class ConcreteNestBuilder : public NestBuilder {
 private:
    Nest* nest;
 public:
    ConcreteNestBuilder() { nest = new Nest(); }
    ~ConcreteNestBuilder() { delete nest; }

    void addMaterial(const std::string& material) override;
    Nest* getNest() override;
};

#endif
