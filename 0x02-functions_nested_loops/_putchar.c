<<<<<<< HEAD
#include <unistd.h>

=======
#include "main.h"
#include <unistd.h>
>>>>>>> 2d7c49d5315dce447cfcbf98f086c9a76b2ba4ba
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
<<<<<<< HEAD
	return (write(1, &c, 1));
=======
return (write(1, &c, 1));
>>>>>>> 2d7c49d5315dce447cfcbf98f086c9a76b2ba4ba
}
