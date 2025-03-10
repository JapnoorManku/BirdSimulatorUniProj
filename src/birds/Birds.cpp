#include <string>
#include <map>
#include <vector>
#include "SeasonalBehavior.hpp"
#include "NestBuilder.hpp"
#include "Birds.hpp"

Bird::~Bird() {
    // Clean up all dynamically allocated SeasonalBehavior pointers
    for (auto& pair : behaviors) {
        if (pair.second) {
            delete pair.second;
            pair.second = nullptr;
        }
    }
}

void Bird::performSeasonalActivity(const std::string& season) {
    std::cout << "Season: " << season << "\n";
    if (migration.count(season)) {
        std::cout << " is migrating to ";
        std::cout << migration.at(season) << ".\n";
    }
    // Check if behavior exists for the given season
    if (behaviors.count(season) && behaviors.at(season)) {
        behaviors.at(season)->execute(name);
    } else {
        std::cout << name << " has no specific activity for this season.\n";
    }
}

void Bird::buildNest(NestBuilder* builder) {
    for (const auto& material : nestMaterials) {
        builder->addMaterial(material);
    }
    Nest* nest = builder->getNest();
    std::cout << "The nest is built of: ";
    nest->displayNest();
    delete nest;
}

const std::string& Bird::getName() const {
    return name;
}
