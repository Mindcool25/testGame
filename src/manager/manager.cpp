#include "manager.hpp"

ECSManager::ECSManager()
{
    nextEntityId = 0;
}

Entity& ECSManager::createEntity()
{
    int entityId = nextEntityId++;
    entities[entityId].id = entityId;
    return entities[entityId];
}

template<typename T>
void ECSManager::addComponent(Entity& entity, T component)
{
    std::string typeName = typeid(T).name();
    entity.components[typeName] = new T(component);
    componentEntities[typeName].push_back(entity);
}

template<typename T>
T* ECSManager::getComponent(Entity& entity)
{
    std::string typeName = typeid(T).name();
    if (entity.components.find(typeName) != entity.components.end())
    {
        return static_cast<T*>(entity.components[typeName]);
    }
    return nullptr;
}

template<typename T>
std::vector<Entity>& ECSManager::getEntitiesWithComponent()
{
    std::string typeName = typeid(T).name();
    if (componentEntities.find(typeName) != componentEntities.end())
    {
        return componentEntities[typeName];
    }
    static std::vector<Entity> emptyList;
    return emptyList;
}
