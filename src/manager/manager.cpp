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
