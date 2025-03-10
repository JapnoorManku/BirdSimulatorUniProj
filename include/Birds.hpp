#ifndef BIRD_HPP
#define BIRD_HPP

#include <string>
#include <map>
#include <vector>
#include "SeasonalBehavior.hpp"
#include "NestBuilder.hpp"

// Abstract Bird Class
class Bird {
 protected:
    std::string name;
    std::string region;
    std::vector<std::string> nestMaterials;
    std::map<std::string, std::string> migration; // Season -> Destination
    std::map<std::string, SeasonalBehavior*> behaviors; // Season -> Behavior

 public:
    Bird(const std::string& name, const std::string& region,
         const std::vector<std::string>& materials,
         const std::map<std::string, std::string>& migration,
         const std::map<std::string, SeasonalBehavior*>& behaviors)
        : name(name), region(region), nestMaterials(materials),
         migration(migration), behaviors(behaviors) {}

    virtual ~Bird();

    void performSeasonalActivity(const std::string& season);

    void buildNest(NestBuilder* builder);
    const std::string& getName() const;
};

#endif
