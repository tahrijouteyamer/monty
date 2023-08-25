#include <stdlib.h>


char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
               char *buff, int buff_size);


/**
 * get_int - it gets a character pointer to new string containing int
 * @num: a number to convert to string
 *
 * Return: the character pointer to newly created string NULL if malloc fails.
 */
char *get_int(int num)
{
    unsigned int temp;
    int length = 0;
    long num_l = 0;
    char *ret;


    temp = _abs(num);
    length = get_numbase_len(temp, 10);


    if (num < 0 || num_l < 0)
        length++; /* the negative sign */
    ret = malloc(length + 1); /* to create new string */
    if (!ret)
        return (NULL);


    fill_numbase_buff(temp, 10, ret, length);
    if (num < 0 || num_l < 0)
        ret[0] = '-';


    return (ret);
}


/**
 * _abs - this gets the absolute value of an integer
 * @i: an integer to get absolute value of
 *
 * Return: the unsigned integer abs rep of i
 */
unsigned int _abs(int i)
{
    if (i < 0)
        return (-(unsigned int)i);
    return ((unsigned int)i);
}


/**
 * get_numbase_len - this gets the length of buffer needed for an unsigned int
 * @num: the number to get length needed for
 * @base: the base of number representation used by buffer
 *
 * Return: the integer containing length of buffer needed
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
    int len = 1;


    while (num > base - 1)
    {
        len++;
        num /= base;
    }
    return (len);
}


/**
 * fill_numbase_buff - this fills buffer with correct numbers up to base 36
 * @num: the number to convert to string given base
 * @base: the base of number used in conversion, only works up to base 36
 * @buff: the buffer to fill with result of conversion
 * @buff_size: the size of buffer in bytes
 *
 * Return: always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
            char *buff, int buff_size)
{
    int rem, i = buff_size - 1;


    buff[buff_size] = '\0';
    while (i >= 0)
    {
        rem = num % base;
        if (rem > 9) /* return the lowercase ASCII val representation */
            buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
        else
            buff[i] = rem + '0';
        num /= base;
        i--;
    }
}
