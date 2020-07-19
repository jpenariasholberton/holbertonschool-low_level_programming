#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>


/**
 * print_char - print chars.
 * @parameter: string to be printed between numbers.
 * Return: void.
 */
void print_char(void *parameter)
{
	printf("%c", *(char *)(&parameter));
}

/**
 *print_int - print chars.
 *@parameter: string to be printed between numbers.
 *Return: void.
 */
void print_int(void *parameter)
{
	printf("%i", *(int *)(&parameter));
}

/**
 *print_float - print chars.
 *@parameter: string to be printed between numbers.
 *Return: void.
 */
void print_float(void *parameter)
{
	printf("%f", *(float *)(&parameter));
}

/**
 *print_s - print chars.
 *@parameter: string to be printed between numbers.
 *Return: void.
 */
void print_s(void *parameter)
{
	printf("%s", ((char *)parameter) == '\0' ? "(nil)" : (char *)parameter);
}

/**
 *print_all - that prints anything.
 *@format: string to be printed between numbers.
 *Return: void.
 */
void print_all(const char *const format, ...)
{
	va_list valist;
	int i, j;
	void (*printer)(void *parameter);
	print_t types[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_s},
		{'\0', NULL},
	};

	i = 0;
	j = 0;
	
	va_start(valist, format);	
	
	while (format[i])
	{	
		j = 0;
		while (types[j].t)
		{
			printer = (types[j].t) == format[i] ? (types[j].f) : NULL;
			if (printer != NULL){
				printer(va_arg(valist, void *));
				if (format[i+1])
					printf("%s", ", ");
				break;
			}
			j++;
		}
		i++;
	}
	
	va_end(valist);
}
