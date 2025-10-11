#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRE = 0xff;
	DDRF = 0xff;

	while (1)
	{
		uint8_t seg_digits[10] = {
			0b11000000, // 0
			0b11111001, // 1
			0b10100100, // 2
			0b10110000, // 3
			0b10011001, // 4
			0b10010010, // 5
			0b10000010, // 6
			0b11111000, // 7
			0b10000000, // 8
			0b10010000  // 9
		};

		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {

				// repeat the fast switching many times so both digits appear steady
				for (int k = 0; k < 100; k++) {
					
					// --- Left digit (tens) ---
					PORTF = 0x00;             // both off
					PORTE = seg_digits[i];
					PORTF = 0x01;             // enable left (CA1)
					_delay_ms(2);

					// --- Right digit (ones) ---
					PORTF = 0x00;             // both off
					PORTE = seg_digits[j];
					PORTF = 0x02;             // enable right (CA2)
					_delay_ms(2);
				}
			}
		}
	}
	return 0;
}
