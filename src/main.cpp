#include <iostream>
#include <fstream>
#include "BirdFactory.hpp"
#include "NestBuilder.hpp"
#include "SeasonalBehavior.hpp"

using json = nlohmann::json;


int main() {
    std::ifstream f("/home/manj2720/birdsimulator/src/birdsconfig.json");
    if (!f.is_open()) {
        std::cerr << "Error file not found." << std::endl;
        return 0;
    }
    json config = json::parse(f);

    //BirdFactory factory;
    ConcreteNestBuilder builder;

    std::vector<Bird*> birds;

    for (const auto& birdData : config["birds"]) {
        BirdFactory* factory = nullptr;

        try {
        if (!birdData.contains("type")) {
            throw std::runtime_error("Missing 'type' key in birdData.");
        }
        // Dynamically select factory based on bird type
        if (birdData["type"] == "eagle") {
            factory = new EagleFactory();
        } else if (birdData["type"] == "parrot") {
            factory = new ParrotFactory();
        } else {
            throw std::runtime_error("Unknown bird type: " +
             birdData["type"].get<std::string>());
        }

        if (factory) {
            birds.push_back(factory->createBird(birdData));
            delete factory; // Clean up the factory after use
        }
        } catch (const std::exception& e) {
            std::cerr << "Error creating bird: " << e.what() << std::endl;
            delete factory;
        }
    }


    // Simulate seasonal activities
    std::vector<std::string> seasons = {"Spring", "Summer", "Fall", "Winter"};

    for (auto bird : birds) {
        std::cout << "----- " << bird->getName() << " -----\n";
        for (const auto& season : seasons) {
            bird->performSeasonalActivity(season);
            if (season == "Spring") {
                bird->buildNest(&builder);
            }
            std::cout << "\n";
        }
        std::cout << "----------------------------------\n";
    }

    // Cleanup
    for (auto bird : birds) {
        delete bird;
    }
    birds.clear();

    return 0;
}
