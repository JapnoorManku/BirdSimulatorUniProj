#ifndef SEASONAL_BEHAVIOR_HPP
#define SEASONAL_BEHAVIOR_HPP

#include <iostream>
#include <string>

// Strategy Pattern Interface
class SeasonalBehavior {
 public:
    virtual void execute(const std::string& birdName) = 0;
    virtual ~SeasonalBehavior() = default;
};

// Concrete Seasonal Behaviors
class EagleSpringBehavior : public SeasonalBehavior {
 public:
    void execute(const std::string& birdName) override {
        std::cout << birdName << " begins courtship and nesting.\n";
    }
};

class EagleSummerBehavior : public SeasonalBehavior {
 public:
    void execute(const std::string& birdName) override {
        std::cout << birdName << " is raising chicks and hunting.\n";
    }
};

class EagleFallBehavior : public SeasonalBehavior {
 public:
    void execute(const std::string& birdName) override {
        std::cout << birdName << " begins migration to warmer climates.\n";
    }
};

class EagleWinterBehavior : public SeasonalBehavior {
 public:
    void execute(const std::string& birdName) override {
        std::cout << birdName;
        std::cout << " is hunting small mammals and";
        std::cout << "birds in wintering grounds.\n";
    }
};
class ParrotSpringBehavior : public SeasonalBehavior {
 public:
    void execute(const std::string& birdName) override {
        std::cout << birdName << " is looking for a mate with sleek wings.\n";
    }
};

class ParrotSummerBehavior : public SeasonalBehavior {
 public:
    void execute(const std::string& birdName) override {
        std::cout << birdName << " is raising redheads (with no souls).\n";
    }
};
class ParrotFallBehavior : public SeasonalBehavior {
 public:
    void execute(const std::string& birdName) override {
        std::cout << birdName << " moves to lower altitudes";
        std::cout << "or stores energy for colder months.\n";
    }
};

class ParrotWinterBehavior : public SeasonalBehavior {
 public:
    void execute(const std::string& birdName) override {
        std::cout << birdName << " survives harsh";
        std::cout << "conditions by scavenging and foraging.\n";
    }
};

#endif
