#ifndef DEV_QNAP_TR004_H
#define DEV_QNAP_TR004_H

#include "dev_interface.h"

class qnaptr_device : public ata_device {
public:
  qnaptr_device(smart_interface * intf, const char * name, int disk_number, uint64_t start_lba, bool force);
  virtual ~qnaptr_device() {}
  virtual bool is_open() const override;  // Add these
  virtual bool open() override;
  virtual bool close() override;         // Add these
  virtual bool ata_pass_through(const ata_cmd_in & in, ata_cmd_out & out) override;
private:
  int m_disk_number;
  uint64_t m_start_lba;
  bool m_force;
};

// Parse "qnaptr,N[,sLBA][,force]" options
const char * parse_qnaptr_options(const char * type, int * disk_number, uint64_t * start_lba, bool * force);

#endif