#include "libft.h"

static int get_digit(char c)
{
    int digit;
    if (c >= '0' && c <= '9')
        digit = c - '0';
    else if (c >= 'A' && c <= 'Z')
        digit = c - 'A' + 10;
    else if (c >= 'a' && c <= 'z')
        digit = c - 'a' + 10;
    else
        digit = -1;  // Invalid character
    return digit;
}

static int is_valid_digit(int digit, int base)
{
    if (digit >= base)
        return 0;  // Invalid digit for the given base
    return 1;
}

static int calculate_result(const char *str, int base, int i, int sign)
{
    int result;
    int digit;

    result = 0;
    while (str[i] != '\0')
	{
        digit = get_digit(str[i]);
        if (digit == -1 || !is_valid_digit(digit, base))
            return 0;
        result = result * base + digit;
        i++;
    }
    return result * sign;
}

int ft_atoi_base(const char *str, int base)
{
    int sign;
    int i;

    sign = 1;
    i = 0;
    if (str[0] == '-')
	{
        sign = -1;
        i++;
    }
    return calculate_result(str, base, i, sign);
}
