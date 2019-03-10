# Calculator #
    
![image](https://raw.githubusercontent.com/jiangxincode/calculator/master/data/calculator.png)

A simple calculator, based on GTK+3.0, and it is easy to extend.

If you have some advises, please tell me, open a issue, give me a pull request, or send me a email.

Have a good time on it.

+ Aloys
+ jiangxinnju@163.com

## License

The MIT License (MIT)

## Update Log

* Version 0.01 完成基本架构。
* Version 0.02 优化了部分函数，提高了效率和可读性。
* Version 0.03 去除g_locale_to_utf8函数，用g_convert进行替换。
* Version 0.04 进一步精简了代码。
* Version 0.05 增加了图片展示。
* Version 0.06 暂时将中文替代为英文，之后会再次修复，解决了button显示问题。
* Version 0.07 解决了最大化变形问题，同时精简了代码。
* Version 0.08 设置了程序图标。


## TODO

+ 按钮颜色控制
+ GTK版本控制问题
+ 表达式计算

```sh
xgettext -k_ -o inter.po main.c
```
