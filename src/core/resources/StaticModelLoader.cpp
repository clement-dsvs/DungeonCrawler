//
// Created by cleme on 10/02/2024.
//

#include "StaticModelLoader.h"

StaticModelLoader::result_type StaticModelLoader::operator()(const char *filename) const {
    return std::make_shared<StaticModel>(LoadModel(filename));
}
