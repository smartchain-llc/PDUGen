#pragma once
#include <bit>
#include <cstdint>
#include <iostream>
#include <utility>

struct PDUHeader_t {
  uint8_t version;
  uint8_t exerciseId;
  uint8_t type;
  uint8_t family;
  uint32_t timestamp;
  uint16_t length;
  uint8_t status;
  uint8_t pad;
};
class PDUHeaderBuilder {
public:
  PDUHeaderBuilder &version(uint8_t &ver) {
    _hdr.version = std::move(ver);
    return *this;
  }
  PDUHeaderBuilder &exerciseId(uint8_t &id) {
    _hdr.exerciseId = std::move(id);
    return *this;
  }
  PDUHeaderBuilder &type(uint8_t &type) {
    _hdr.type = std::move(type);
    return *this;
  }
  PDUHeaderBuilder &family(uint8_t &family) {
    _hdr.family = std::move(family);
    return *this;
  }
  PDUHeaderBuilder &timestamp(uint32_t &ts) {
    _hdr.timestamp = std::move(ts);
    return *this;
  }
  PDUHeaderBuilder &length(uint16_t &l) {
    _hdr.length = std::move(l);
    return *this;
  }
  PDUHeaderBuilder &status(uint8_t &status) {
    _hdr.status = std::move(status);
    return *this;
  }

  std::istream &operator>>(std::istream &ins) {
    char inBuffer[sizeof(PDUHeader_t)];

    ins.readsome(inBuffer, sizeof(PDUHeader_t));
    _hdr = std::bit_cast<PDUHeader_t>(inBuffer);
    return ins;
  }

  PDUHeader_t &&get() noexcept { return std::move(_hdr); }

private:
  PDUHeader_t _hdr;
};

class PDUHeader {};

PDUHeader_t create_header();