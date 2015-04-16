#include "PSG.H"

int main()
{
	UINT32 i = 0;
	long x;
/* 	start_music(i);
	
	while(i < 512)
	{
		for (x = 0; x < 6000; x++){}
		
		i++;
		update_music(i);
	}
	 */
	 playDropEffect();
	 Cnecin();
	 	 playDropEffect();
	 Cnecin();
	 	 playDropEffect();
	 Cnecin();
	 
	 
	 
	 
	stop_sound();
	return 0;
}

void write_psg(int reg, UINT8 val)
{
	volatile char *PSG_reg_select = REG_SELECT; 
	volatile char *PSG_reg_write = REG_WRITE;	/* create pointers */
	
	long old_ssp = Super(0);					/* Enter Supervisor mode */
	
	*PSG_reg_select = reg;
	*PSG_reg_write = val;
	
	Super(old_ssp);								/* Back to User mode */
}

UINT8 read_psg(int reg)
{
	volatile char *PSG_reg_select = REG_SELECT; 
	volatile char *PSG_reg_write = REG_WRITE;	/* create pointers */
	
	UINT8 returnValue;
	
	long old_ssp = Super(0);					/* Enter Supervisor mode */
	
	*PSG_reg_select = reg;
	returnValue = *PSG_reg_write;
	
	Super(old_ssp);								/* Back to User mode */

	return returnValue;
}

void set_tone(int channel, int tuning)
{
	switch(channel)
	{
		case A:
			write_psg(FINE_TUNE_A, tuning);
		break;
		
		case B:
			write_psg(FINE_TUNE_B, tuning);
		break;
		
		case C:
			write_psg(FINE_TUNE_C, tuning);
		break;
	}
}

void set_volume(int channel, int volume)
{
	switch(channel)
	{
		case A:
			write_psg(CHAN_LEVEL_A, volume);
		break;
		
		case B:
			write_psg(CHAN_LEVEL_B, volume);
		break;
		
		case C:
			write_psg(CHAN_LEVEL_C, volume);
		break;
	}
}

void enable_channel(int channel, int tone_on, int noise_on)
{
/* 		switch(channel)
	{
		case A:
			if (tone_on == 1 && noise_on == 1)
			{
				write_psg(IO_MIXER, 0x3E);
			}
			else if (tone_on == 1)
			{
				write_psg(IO_MIXER, 0x3E);
			}
			else if(noise_on == 1)
			{
				write_psg(IO_MIXER, 0x3E);
			}
			else 
			{ 
				write_psg(IO_MIXER, 0x3E);
			}
		break;
		
		case B:
		if (tone_on == 1 && noise_on == 1)
			{
				write_psg(0x07, 0x3E);
			}else if (tone_on == 1)
			{
			
			}else if(noise_on == 1)
			{
			
			}else 
			{ 
			
			}
		break;
		
		case C:
		if (tone_on == 1 && noise_on == 1)
			{
				write_psg(0x07, 0x3E);
			}else if (tone_on == 1)
			{
			
			}else if(noise_on == 1)
			{
			
			}else
			{ 
			
			}
		break; 
	}*/
}

void stop_sound()
{
	write_psg(CHAN_LEVEL_A,0);	/* sets all channels to silent */
	write_psg(CHAN_LEVEL_B,0);
	write_psg(CHAN_LEVEL_C,0);
}

void set_noise(int tuning)
{
	
	write_psg(NOISE_FREQ,(UINT8)(tuning & 0xFF));
}

void set_envelope(int shape, unsigned int sustain)
{
	write_psg(ENVELOPE_SHAPE, shape);
	write_psg(ENVELOPE_FREQ_FINE, (UINT8)(sustain & 0xFF)); /* may need to separate for fine and rough tune */
	write_psg(ENVELOPE_FREQ_ROUGH, (UINT8)((sustain >> 8) & 0xFF));
}

void enable_all_channels()
{
	write_psg(IO_MIXER, 0x00);
}