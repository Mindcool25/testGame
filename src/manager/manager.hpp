#ifndef MANAGER_H_
#define MANAGER_H_

#include <iostream>
#include <unordered_map>
#include <vector>

struct Entity {
    int id;
    std::unordered_map<std::string, void*> components;
};

struct Pos {
    int x;
    int y;
};

class ECSManager {
    public:
        ECSManager();
        Entity& createEntity();

        template<typename T>
        void addComponent(Entity& entity, T component);

        template<typename T>
        T* getComponent(Entity& entity);

        template<typename T>
        std::vector<Entity>& getEntitiesWithComponent();

    private:
        int nextEntityId;
        std::unordered_map<int, Entity> entities;
        std::unordered_map<std::string, std::vector<Entity>> componentEntities;

};

#endif // MANAGER_H_
