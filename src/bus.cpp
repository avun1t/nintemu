#include <bus.h>

Bus::Bus()
{
	// clear RAM contents
	for (auto &i : ram) i = 0x00;

	// connect CPU to the communication bus
	cpu.ConnectBus(this);
}

Bus::~Bus()
{}

void Bus::write(uint16_t addr, uint8_t data)
{
	// memory guard
	if (addr >= 0x0000 && addr <= 0xFFFF)
		ram[addr] = data;
}

uint8_t Bus::read(uint16_t addr, bool bReadOnly)
{
	// memory guard
	if (addr >= 0x0000 && addr <= 0xFFFF)
		return ram[addr];
	
	return 0x00;
}