#include <gtk/gtk.h>

#include "../include/calculator.h"

int conversion(char input_array[20], int from_radix, int to_radix)
{
	int decimal_array[30], integer_array[30];
	int dot_index = strlen(input_array);
	int out_length = 0;
	value_in_dec = 0;
	memset(out_array, 0, 20);
	for (int i = 0; i < strlen(input_array); i++) //主要是分段，以小数点为界限，只转换整数部分
	{
		if (input_array[i] == '.')
		{
			dot_index = i;
			break;
		}
	}

	for (int i = dot_index - 1; i >= 0; i--)
	{
		int digit = 0;
		if (input_array[i] == '-')
		{
			break;
		}
		else if ((input_array[i] >= 'A') && (input_array[i] <= 'F'))
		{
			digit = input_array[i] - 'A' + 10;
		}
		else if ((input_array[i] >= '0') && (input_array[i] <= '9'))
		{
			digit = input_array[i] - '0';
		}
		else
		{
			perror("error:Conversion");
			exit(1);
		}
		value_in_dec = value_in_dec + digit * (pow((double) from_radix, (double) (dot_index - i - 1)));
	}

	if (input_array[dot_index] == '.')
	{
		for (int i = dot_index + 1; i < strlen(input_array); i++)
		{
			int digit = 0;
			if ((input_array[i] >= 'A') && (input_array[i] <= 'F'))
			{
				digit = input_array[i] - 'A' + 10;
			}
			else if ((input_array[i] >= '0') && (input_array[i] <= '9'))
			{
				digit = input_array[i] - '0';
			}
			else
			{
				perror("error:Conversion");
				exit(1);
			}
			value_in_dec = value_in_dec + digit * (pow((double) from_radix, (double) (dot_index - i)));
		}
	}

	if (to_radix == 10) //如果要转换成十进制
	{
		if (input_array[0] == '-')
		{
			value_in_dec = -value_in_dec;
		}
		strcpy(out_array, input_array);
		return 0;
	}
	else //如果要转换成其他进制
	{
		int integer_value_in_dec = (int) value_in_dec;
		int integer_length = 0;
		while (integer_value_in_dec) //判定需要转换的数是否变为0
		{
			integer_array[integer_length++] = integer_value_in_dec % to_radix; //取余，进行进制转换，但是顺序与正确值相反
			integer_value_in_dec /= to_radix; //转换一位之后进行相应的变化
		}
		int decimal_length = 0;
		if (value_in_dec != (int) value_in_dec) //选择性计算，如果是整数就不用进行这一步的计算了
		{
			double decimal_value_in_dec = value_in_dec - (int) value_in_dec; //取小数部分
			while (decimal_value_in_dec != 0)
			{
				decimal_array[decimal_length] = (int) (decimal_value_in_dec * to_radix); //算法为×N取整
				decimal_value_in_dec = decimal_value_in_dec * to_radix - decimal_array[decimal_length];
				decimal_length++;
				if (decimal_length >= 10)
				{
					break; //主要是控制小数后面万一出现无限小数的时候好跳出循环以免出现死循环
				}
			}
		}
		if (input_array[0] == '-')
		{
			out_array[0] = '-';
			out_length++;
		}
		for (int i = integer_length - 1; i >= 0; i--, out_length++) //反序输出,大于10的数字进行相应的变化
		{
			if ((integer_array[i] >= 10) && (integer_array[i] <= 15))
			{
				out_array[out_length] = integer_array[i] - 10 + 'A';
			}
			else if ((integer_array[i] >= 0) && (integer_array[i] <= 10))
			{
				out_array[out_length] = integer_array[i] - 0 + '0';
			}
			else
			{
				perror("error:Conversion");
			}
		}
		if (value_in_dec != (int) value_in_dec) //选择性输出，这样可以节约输出时间和程序的运行时间
		{
			out_array[out_length++] = '.';
			for (int i = 0; i < decimal_length; i++, out_length++) //正序输出
			{
				if ((decimal_array[i] >= 10) && (decimal_array[i] <= 15))
				{
					out_array[out_length] = decimal_array[i] - 10 + 'A';
				}
				else if ((decimal_array[i] >= 0) && (decimal_array[i] <= 10))
				{
					out_array[out_length] = decimal_array[i] - 0 + '0';
				}
				else
				{
					perror("error:Conversion");
				}
			}
		}
		return 0;
	}
}
