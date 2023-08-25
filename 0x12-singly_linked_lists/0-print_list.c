#include <stdio.h>
#include "lists.h"

/**
 * main - print all element of a list_t
 * @print_list - a container for elements to print.
 * @h: element to print
 * @str - string
 * @next - points to the next node
 *
 * Return: the length of the string
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;
	int i;

	while  (h != NULL)
	{
		if (h->str == NULL)
		{
			write(1, "[0] (nil)\n", 10)char zero_str[] = "[0] (nil)\n";
		} else
		{
			size_t len = h->len;
			const char *str = h->str;

			char len_str[20];
			int len_count = 0;

			while (len > 0)
			{
				len_str[len_count++] = '0' + len % 10;
				len /= 10;
			}
			for (int i = len_count - 1; i >= 0; i--)
			{
				write(1, &len_str[i], 1);
			}

			write(1, " ", 1);
			write(1, str, len);
			write(1, "\n", 1);
		}
		count++;
		h = h->next;
	}
	return (count);
}
