//
// Created by cleme on 10/02/2024.
//

#ifndef STATICMODELLOADER_H
#define STATICMODELLOADER_H
#include <memory>

#include "components/StaticModel.h"


struct StaticModelLoader final {
    using result_type = std::shared_ptr<StaticModel>;

    result_type operator()(const char* filename) const;

};



#endif //STATICMODELLOADER_H
