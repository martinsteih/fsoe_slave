#ifndef PDU_HPP
#define PDU_HPP

#include <cinttypes>
#include <vector>

namespace fsoe {

enum class Command : uint8_t {
  ProcessData = 0x36,
  Reset = 0x2A,
  Session = 0x4E,
  Connection = 0x64,
  Parameter = 0x52,
  FailSafeData = 0x08
};

struct safe_data {
  uint16_t _safe_data;
  uint16_t _crc;
};

struct pdu {
  Command _command;
  std::vector<safe_data> _data;
  uint16_t _connection_id;
};

constexpr uint32_t safety_polynoial{0x139B7};

bool CalcCrc(pdu& packet, const uint16_t start_crc,
             const uint16_t sequence_number, const uint16_t old_crc,
             bool rcv_direction);

}  // namespace fsoe

#endif