#ifndef BIRD_FACTORY_HPP
#define BIRD_FACTORY_HPP

#include <string>
#include <map>
#include <vector>
#include "Birds.hpp"
#include "SeasonalBehavior.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

// Abstract Base Factory
class BirdFactory {
 public:
    virtual Bird* createBird(const json& birdData) = 0;
    virtual ~BirdFactory() = default;
};

// Eagle Factory
class EagleFactory : public BirdFactory {
 public:
    EagleFactory();
    Bird* createBird(const json& birdData) override;
};

// Parrot Factory
class ParrotFactory : public BirdFactory{
 public:
    ParrotFactory();
    Bird* createBird(const json& birdData) override;
};

#endif
