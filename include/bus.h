#ifndef __BUS_H_
#define __BUS_H_

#include <cstdint>

class Bus {
public:
	Bus();
	~Bus();

	// devices
	nes6502 cpu;
	
	// fake RAM for now
	std::array<uint8_t, 64 * 1024> ram;

	// r/w
	void write(uint16_t addr, uint8_t data);
	uint8_t read(uint16_t addr, bool bReadOnly = false);
};

#endif // __BUS_H_