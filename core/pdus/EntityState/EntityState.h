#pragma once
#include "../Header/PDUHeader.h"
#include <cstdint>

struct EntityID {
  uint16_t site;
  uint16_t app;
  uint16_t num;
};
struct EntityState {
  PDUHeader_t header;
  EntityID id;
};