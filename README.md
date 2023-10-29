# Calculator
    
![image](https://raw.githubusercontent.com/wiki/jiangxincode/calculator/calculator.png)

A simple calculator, based on gtk4, and it is easy to extend.

If you have some advises, please tell me, open a issue, give me a pull request, or send me a email.

Have a good time on it.

+ Aloys
+ jiangxinnju@163.com

## Project Structure

* `include/`: The include file used in other source files
* `src`: The program source files
* `test`: The unit test source files

## License

The MIT License (MIT)

## TODO

+ 增加国际化能力, 参考: <http://ptomato.name/advanced-gtk-techniques/html/real-life-app-setup.html>
+ 添加图标, 参考: <http://ptomato.name/advanced-gtk-techniques/html/real-life-app-setup.html>
+ 按钮颜色控制
+ GTK版本控制问题
+ 表达式计算

```sh
xgettext -k_ -o inter.po main.c
```
