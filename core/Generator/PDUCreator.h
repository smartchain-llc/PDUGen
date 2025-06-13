#pragma once
#include "../pdus/EntityState/EntityState.h"
#include "Header/PDUHeader.h"

class PDUCreator {
public:
  static inline size_t NumEntities = 0;
  static EntityState CreateEntity() {
    EntityState ret;
    ret.id.num = (uint16_t)PDUCreator::NumEntities++;
    return ret;
  }
};