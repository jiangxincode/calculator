#include <gtk/gtk.h>

#include "../include/calculator.h"

int conversion(char num[20], int from_radix, int to_radix)
{
	int i, ii, j, k, m, x, b[30], h[30], c;
	double d, r;
	ii = 0;
	value_in_decimal = 0;
	memset(out, 0, 20);
	m = strlen(num); //求字符串的长度
	x = m;
	for (k = 0; k < m; k++) //主要是分段，以小数点为界限，只转换整数部分
	{
		if (num[k] == '.')
		{
			x = k;
			break;
		}
	}

	for (j = x - 1; j >= 0; j--)
	{
		if (num[j] == '-')
			break; //符号的处理
		else if ((num[j] >= 'A') && (num[j] <= 'F'))
		{
			r = num[j] - 'A' + 10;
		}
		else if ((num[j] >= '0') && (num[j] <= '9'))
		{
			r = num[j] - '0';
		}
		else
		{
			perror("error:Conversion");
			exit(1);
		}
		value_in_decimal = value_in_decimal + r * (pow((double) from_radix, (double) (x - j - 1))); //计算结果
	}

	if (num[x] == '.')
	{
		for (j = x + 1; j < m; j++)
		{
			if ((num[j] >= 'A') && (num[j] <= 'F'))
			{
				r = num[j] - 'A' + 10;
			}
			else if ((num[j] >= '0') && (num[j] <= '9'))
			{
				r = num[j] - '0';
			}
			else
			{
				perror("error:Conversion");
				exit(1);
			}
			value_in_decimal = value_in_decimal + r * (pow((double) from_radix, (double) (x - j)));
		}
	}

	if (to_radix == 10) //如果要转换成十进制
	{
		if (num[0] == '-')
		{
			value_in_decimal = -value_in_decimal;
		}
		strcpy(out, num);
		return 0;
	}
	else //如果要转换成其他进制
	{
		k = (int) value_in_decimal;
		i = 0;
		while (k) //判定需要转换的数是否变为0
		{
			h[i++] = k % to_radix; //取余，进行进制转换，但是顺序与正确值相反
			k /= to_radix; //转换一位之后进行相应的变化
		}
		c = 0;
		if (value_in_decimal != (int) value_in_decimal) //选择性计算，如果是整数就不用进行这一步的计算了
		{
			d = value_in_decimal - (int) value_in_decimal; //取小数部分
			while (d != 0)
			{
				b[c] = (int) (d * to_radix); //算法为×N取整
				d = d * to_radix - b[c];
				c++;
				if (c >= 10)
					break; //主要是控制小数后面万一出现无限小数的时候好跳出循环以免出现死循环
			}
		}
		if (num[0] == '-')
		{
			out[0] = '-';
			ii++;
		}
		for (j = i - 1; j >= 0; j--, ii++) //反序输出,大于10的数字进行相应的变化
		{
			if ((h[j] >= 10) && (h[j] <= 15))
			{
				out[ii] = h[j] - 10 + 'A';
			}
			else if ((h[j] >= 0) && (h[j] <= 10))
			{
				out[ii] = h[j] - 0 + '0';
			}
			else
			{
				perror("error:Conversion");
			}
		}
		if (value_in_decimal != (int) value_in_decimal) //选择性输出，这样可以节约输出时间和程序的运行时间
		{
			out[ii++] = '.';
			for (j = 0; j < c; j++, ii++) //正序输出
			{
				if ((h[j] >= 10) && (h[j] <= 15))
				{
					out[ii] = h[j] - 10 + 'A';
				}
				else if ((h[j] >= 0) && (h[j] <= 10))
				{
					out[ii] = h[j] - 0 + '0';
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
