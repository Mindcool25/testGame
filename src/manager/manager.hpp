#ifndef MANAGER_H_
#define MANAGER_H_

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

struct Entity {
    int id;
    std::unordered_map<std::string, void*> components;
};

class ECSManager {
    public:
        ECSManager();
        Entity& createEntity();

        template<typename T>
        void addComp(Entity& entity, T comp)
        {
            std::string typeName = typeid(T).name();
            entity.components[typeName] = new T(comp);
            componentEntities[typeName].push_back(entity);
        }

        template<typename T>
        T* getComponent(Entity& entity)
        {
            std::string typeName = typeid(T).name();
            if (entity.components.find(typeName) != entity.components.end())
            {
                return static_cast<T*>(entity.components[typeName]);
            }
            return nullptr;
        }

        template<typename T, typename U>
        bool hasBothComponents(Entity& e)
        {
            return getComponent<T>(e) != nullptr && getComponent<U>(e) != nullptr;
        }

        template<typename T>
        std::vector<Entity>& getEntitiesWithComponent()
        {
            std::string typeName = typeid(T).name();
            if (componentEntities.find(typeName) != componentEntities.end())
            {
                return componentEntities[typeName];
            }
            static std::vector<Entity> emptyList;
            return emptyList;
        }

        template<typename T, typename U>
        std::vector<Entity>& getBothComponents()
        {
            std::vector<Entity>& entities = getEntitiesWithComponent<T>();
            static std::vector<Entity> ent;

            if (!entities.empty())
            {
                for(auto i = entities.begin(); i != entities.end(); i++)
                {
                    if (hasBothComponents<T, U>(i))
                    {
                        ent.push_back(*i);
                    }
                }
            }
            return ent;
        }


    private:
        int nextEntityId;
        std::unordered_map<int, Entity> entities;
        std::unordered_map<std::string, std::vector<Entity>> componentEntities;

};

#endif // MANAGER_H_
