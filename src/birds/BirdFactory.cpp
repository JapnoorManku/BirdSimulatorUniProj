#include "BirdFactory.hpp"
#include "SeasonalBehavior.hpp"

EagleFactory::EagleFactory() {}

// Eagle Factory Implementation
Bird* EagleFactory::createBird(const json& birdData) {
    // Validate required keys
    if (!birdData.contains("name") || !birdData.contains("region") ||
        !birdData.contains("nestMaterials") ||
        !birdData.contains("migration") ||
        !birdData.contains("behaviors")) {
        throw std::runtime_error("Invalid birdData: Missing required keys.");
    }
    std::string name = birdData["name"];
    std::string region = birdData["region"];
    std::vector<std::string> materials = birdData["nestMaterials"];
    std::map<std::string, std::string> migration = birdData["migration"];
    std::map<std::string, SeasonalBehavior*> behaviors;

    try {
    for (const auto& pair : birdData["behaviors"].items()) {
        if (pair.value() == "EagleSpringBehavior")
            behaviors[pair.key()] = new EagleSpringBehavior();
        else if (pair.value() == "EagleSummerBehavior")
            behaviors[pair.key()] = new EagleSummerBehavior();
        else if (pair.value() == "EagleFallBehavior")
            behaviors[pair.key()] = new EagleFallBehavior();
        else if (pair.value() == "EagleWinterBehavior")
            behaviors[pair.key()] = new EagleWinterBehavior();
    }
    } catch (const std::exception& e) {
        for (auto& pair : behaviors) {
            delete pair.second;
        }
        std::cerr << "Eagle Bird factory error";
        std::cerr << e.what() << std::endl;
    }

    return new Bird(name, region, materials, migration, behaviors);
}

ParrotFactory::ParrotFactory() {}

// Parrot Factory Implementation
Bird* ParrotFactory::createBird(const json& birdData) {
    // Validate required keys
    if (!birdData.contains("name") || !birdData.contains("region") ||
        !birdData.contains("nestMaterials") ||
        !birdData.contains("migration") ||
        !birdData.contains("behaviors")) {
        throw std::runtime_error("Invalid birdData: Missing required keys.");
    }
    std::string name = birdData["name"];
    std::string region = birdData["region"];
    std::vector<std::string> materials = birdData["nestMaterials"];
    std::map<std::string, std::string> migration = birdData["migration"];
    std::map<std::string, SeasonalBehavior*> behaviors;

    try {
    for (const auto& pair : birdData["behaviors"].items()) {
        if (pair.value() == "ParrotSpringBehavior")
            behaviors[pair.key()] = new ParrotSpringBehavior();
        else if (pair.value() == "ParrotSummerBehavior")
            behaviors[pair.key()] = new ParrotSummerBehavior();
        else if (pair.value() == "ParrotFallBehavior")
            behaviors[pair.key()] = new ParrotFallBehavior();
        else if (pair.value() == "ParrotWinterBehavior")
            behaviors[pair.key()] = new ParrotWinterBehavior();
    }
    } catch (const std::exception& e) {
        for (auto& pair : behaviors) {
            delete pair.second;
        }
        std::cerr << "Parrot Bird factory error";
        std::cerr << e.what() << std::endl;
    }

    return new Bird(name, region, materials, migration, behaviors);
}
