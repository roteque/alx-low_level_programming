#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * print_binary - prints the binary of any number
 * @n: number to print in binary
 *
 * Return: 0
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

0x14. C - Bit Manipulation
0x14. C - Bit Manipulation


README.md


Project

0x14. C - Bit Manipulation



































main.h


#ifndef MAIN_H

#define MAIN_H


unsigned int binary_to_uint(const char *b);

void print_binary(unsigned long int n);

int get_bit(unsigned long int n, unsigned int index);

int set_bit(unsigned long int *n, unsigned int index);

int clear_bit(unsigned long int *n, unsigned int index);

unsigned int flip_bits(unsigned long int n, unsigned long int m);

int _atoi(const char *s);

int _putchar(char c);

int get_endianness(void);


#endif

























_putchar.c


#include "main.h"

#include <unistd.h>

/**

 * _putchar - writes the character c to stdout

 * @c: The character to print

 *

 * Return: On success 1.

 * On error, -1 is returned, and errno is set appropriately.

 */

int _putchar(char c)

{

        return (write(1, &c, 1));

}


























0-binary_to_uint.c


#include "main.h"


/**

 * binary_to_uint - converts a binary number to unsigned int

 * @b: string containing the binary number

 *

 * Return: the converted number

 */

unsigned int binary_to_uint(const char *b)

{

        int i;

        unsigned int dec_val = 0;


        if (!b)

                return (0);


        for (i = 0; b[i]; i++)

        {

                if (b[i] < '0' || b[i] > '1')

                        return (0);

                dec_val = 2 * dec_val + (b[i] - '0');

        }


        return (dec_val);

}














1-print_binary.c


#include "main.h"


/**

 * print_binary - prints the binary equivalent of a decimal number

 * @n: number to print in binary

 */
0x14. C - Bit Manipulation
0x14. C - Bit Manipulation


README.md


Project

0x14. C - Bit Manipulation



































main.h


#ifndef MAIN_H

#define MAIN_H


unsigned int binary_to_uint(const char *b);

void print_binary(unsigned long int n);

int get_bit(unsigned long int n, unsigned int index);

int set_bit(unsigned long int *n, unsigned int index);

int clear_bit(unsigned long int *n, unsigned int index);

unsigned int flip_bits(unsigned long int n, unsigned long int m);

int _atoi(const char *s);

int _putchar(char c);

int get_endianness(void);


#endif

























_putchar.c


#include "main.h"

#include <unistd.h>

/**

 * _putchar - writes the character c to stdout

 * @c: The character to print

 *

 * Return: On success 1.

 * On error, -1 is returned, and errno is set appropriately.

 */

int _putchar(char c)

{

        return (write(1, &c, 1));

}


























0-binary_to_uint.c


#include "main.h"


/**

 * binary_to_uint - converts a binary number to unsigned int

 * @b: string containing the binary number

 *

 * Return: the converted number

 */

unsigned int binary_to_uint(const char *b)

{

        int i;

        unsigned int dec_val = 0;


        if (!b)

                return (0);


        for (i = 0; b[i]; i++)

        {

                if (b[i] < '0' || b[i] > '1')

                        return (0);

                dec_val = 2 * dec_val + (b[i] - '0');

        }


        return (dec_val);

}














1-print_binary.c


#include "main.h"


/**

 * print_binary - prints the binary equivalent of a decimal number

 * @n: number to print in binary

 */

void print_binary(unsigned long int n)

{
	int i, count = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)		
	{
		current = n >> i;

                if (current & 1)

		_putchar('1');
		count++;
    }
		else if (count)
		_putchar('0');
	}
	if (!count)
	_putchar('0');

}
