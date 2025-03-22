#include "dev_qnap_tr004.h"
#include <windows.h>
#include <setupapi.h>
#include <string.h>

qnaptr_device::qnaptr_device(smart_interface * intf, const char * name, int disk_number, uint64_t start_lba, bool force)
  : ata_device(intf, name, "qnaptr"), m_disk_number(disk_number), m_start_lba(start_lba), m_force(force) {}

bool qnaptr_device::is_open() const {
  return ata_device::is_open();  // Delegate to base
}

bool qnaptr_device::open() {
  // TODO: Detect TR-004 via USB (VID 152d, PID 0567 for JMicron)
  return ata_device::open();
}

bool qnaptr_device::close() {
  return ata_device::close();  // Delegate to base
}

bool qnaptr_device::ata_pass_through(const ata_cmd_in & in, ata_cmd_out & out) {
  // TODO: Route commands to disk_number via USB
  return ata_device::ata_pass_through(in, out);
}

const char * parse_qnaptr_options(const char * type, int * disk_number, uint64_t * start_lba, bool * force) {
  // Simple parser for "N[,sLBA][,force]"
  *disk_number = 0;
  *start_lba = 0;
  *force = false;

  if (!type || !*type)
    return nullptr;

  const char * p = type;
  if (*p && *p != ',') {
    *disk_number = atoi(p);
    while (*p && *p != ',') p++;
    if (*p == ',') p++;
  }
  if (*p && *p != ',') {
    *start_lba = strtoull(p, nullptr, 10);
    while (*p && *p != ',') p++;
    if (*p == ',') p++;
  }
  if (*p && strcmp(p, "force") == 0) {
    *force = true;
    p += strlen("force");
  }
  return (*p ? p : nullptr);  // Return remaining string or nullptr if fully parsed
}