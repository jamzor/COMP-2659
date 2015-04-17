#ifndef PSG_H
#define PSG_H

#include <osbind.h>
#include <stdio.h>
#include "TYPES.H"
#include "SYSCALL.H"

#define REG_SELECT 0xFF8800
#define REG_WRITE 0xFF8802

#define FINE_TUNE_A 0x00
#define ROUGH_TUNE_A 0x01

#define FINE_TUNE_B 0x02
#define ROUGH_TUNE_B 0x03

#define FINE_TUNE_C 0x04
#define ROUGH_TUNE_C 0x05

#define NOISE_FREQ	0x06

#define IO_MIXER 0x07

#define CHAN_LEVEL_A 0x08
#define CHAN_LEVEL_B 0x09
#define CHAN_LEVEL_C 0x0A

#define ENVELOPE_FREQ_FINE 0x0B
#define ENVELOPE_FREQ_ROUGH 0x0C

#define ENVELOPE_SHAPE 0x0D

#define IO_DATA_A 0x0E
#define IO_DATA_B 0x0F

#define A 0
#define B 1
#define C 2

void write_psg(int reg, UINT8 val);
UINT8 read_psg(int reg);
void set_tone(int channel, int tuning);
void set_volume(int channel, int volume);
void enable_channel(int channel, int tone_on, int noise_on);
void stop_sound();
void set_noise(int tuning);
void set_envelope(int shape, unsigned int sustain);
#endif