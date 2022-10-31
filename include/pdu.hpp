#ifndef PDU_HPP
#define PDU_HPP

#include <cinttypes>
#include <vector>

namespace fsoe {

/**
 * @brief
 *
 */
enum class Command : uint8_t {
  ProcessData = 0x36,
  Reset = 0x2A,
  Session = 0x4E,
  Connection = 0x64,
  Parameter = 0x52,
  FailSafeData = 0x08
};

/**
 * @brief
 *
 */
struct SafeData {
  uint16_t _safe_data;
  uint16_t _crc;
};

/**
 * @brief
 *
 */
struct Pdu {
  Command _command;
  std::vector<SafeData>
      _data; /**<Variable number of pairs of two byte safety data, and two byte
                crcs. Length is configured by the safety device description. */
  uint16_t _connection_id;
};

class Slave {
 public:
  void EventFrameReceived();
  void EventWatchdogExpired();
  void EventResetConnection();
  void EventSetDataCommand();

  void ActionSendFrame();

 private:
  uint16_t _connectionId;
  uint16_t _sessionId;
  uint16_t _lastCrC0;
  uint16_t _sequenceNumber;
};

/**
 * @brief
 *
 */
constexpr uint32_t safety_polynoial{0x139B7};

/**
 * @brief
 *
 * @param packet
 * @param start_crc
 * @param sequence_number
 * @param old_crc
 * @param rcv_direction
 * @return true
 * @return false
 */
bool CalcCrc(Pdu& packet, const uint16_t start_crc,
             const uint16_t sequence_number, const uint16_t old_crc,
             bool rcv_direction);

}  // namespace fsoe

#endif