//
// Created by cleme on 10/02/2024.
//

#ifndef STATICMODELCACHE_H
#define STATICMODELCACHE_H
#include <entt/resource/cache.hpp>

#include "StaticModelLoader.h"
#include "components/StaticModel.h"

using StaticModelCache = entt::resource_cache<StaticModel, StaticModelLoader>;

#endif //STATICMODELCACHE_H
