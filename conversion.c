#include <gtk/gtk.h>

#include "calculator.h"

int Conversion(char num[20], int t, int n)
{
        int i,ii,j,k,m,x,b[30],h[30],c;
        double d,r;
        ii=0;
        p=0;
        memset(out,0,20);
        m=strlen(num);//求字符串的长度
        x=m;
        for(k=0; k<m; k++) //主要是分段，以小数点为界限，只转换整数部分
        {
                if(num[k]=='.')
                {
                        x=k;
                        break;
                }
        }

        for(j=x-1; j>=0; j--)
        {
                if(num[j]=='-') break; //符号的处理
                else if((num[j]>='A') && (num[j]<='F'))
                {
                        r = num[j]-'A'+10;
                }
                else if((num[j]>='0') && (num[j]<='9'))
                {
                        r=num[j]-'0';
                }
                else
                {
                        perror("error:Conversion");
                        exit(1);
                }
                p=p+r*(pow ((double)t,(double)(x-j-1)));//计算结果
        }

        if(num[x]=='.')
        {
                for(j=x+1; j<m; j++)
                {
                        if((num[j]>='A') && (num[j]<='F'))
                        {
                                r = num[j]-'A'+10;
                        }
                        else if((num[j]>='0') && (num[j]<='9'))
                        {
                                r=num[j]-'0';
                        }
                        else
                        {
                                perror("error:Conversion");
                                exit(1);
                        }
                        p=p+r*(pow ((double)t, (double)(x-j)));
                }
        }

        if(n==10)//如果要转换成十进制
        {
                if(num[0]=='-')
                {
                        p=-p;
                }
                strcpy(out, num);
                return 0;
        }
        else //如果要转换成其他进制
        {
                k=(int)p;
                i=0;
                while(k)//判定需要转换的数是否变为0
                {
                        h[i++]=k%n;//取余，进行进制转换，但是顺序与正确值相反
                        k/=n;//转换一位之后进行相应的变化
                }
                c=0;
                if(p!=(int)p)//选择性计算，如果是整数就不用进行这一步的计算了
                {
                        d=p-(int)p;//取小数部分
                        while(d!=0)
                        {
                                b[c]=(int)(d*n);//算法为×N取整
                                d=d*n-b[c];
                                c++;
                                if(c>=10)
                                        break;//主要是控制小数后面万一出现无限小数的时候好跳出循环以免出现死循环
                        }
                }
                if(num[0]=='-')
                {
                        out[0]='-';
                        ii++;
                }
                for(j=i-1; j>=0; j--,ii++) //反序输出,大于10的数字进行相应的变化
                {
                        if((h[j]>=10) && (h[j]<=15))
                        {
                                out[ii] = h[j]-10+'A';
                        }
                        else if((h[j]>=0) && (h[j]<=10))
                        {
                                out[ii] = h[j]-0+'0';
                        }
                        else
                        {
                                perror("error:Conversion");
                        }
                }
                if(p!=(int)p)//选择性输出，这样可以节约输出时间和程序的运行时间
                {
                        out[ii++]='.';
                        for(j=0; j<c; j++,ii++) //正序输出
                        {
                                if((h[j]>=10) && (h[j]<=15))
                                {
                                        out[ii] = h[j]-10+'A';
                                }
                                else if((h[j]>=0) && (h[j]<=10))
                                {
                                        out[ii] = h[j]-0+'0';
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

void show_all()
{
        gtk_widget_set_sensitive(button1, TRUE);
        gtk_widget_set_sensitive(button2, TRUE);
        gtk_widget_set_sensitive(button3, TRUE);
        gtk_widget_set_sensitive(button4, TRUE);
        gtk_widget_set_sensitive(button5, TRUE);
        gtk_widget_set_sensitive(button6, TRUE);
        gtk_widget_set_sensitive(button7, TRUE);
        gtk_widget_set_sensitive(button8, TRUE);
        gtk_widget_set_sensitive(button9, TRUE);
        gtk_widget_set_sensitive(button10, TRUE);
        gtk_widget_set_sensitive(button11, TRUE);
        gtk_widget_set_sensitive(button12, TRUE);
        gtk_widget_set_sensitive(button13, TRUE);
        gtk_widget_set_sensitive(button14, TRUE);
        gtk_widget_set_sensitive(button15, TRUE);
        gtk_widget_set_sensitive(button16, TRUE);
        gtk_widget_set_sensitive(button17, TRUE);
        gtk_widget_set_sensitive(button18, TRUE);
        gtk_widget_set_sensitive(button19, TRUE);
        gtk_widget_set_sensitive(button20, TRUE);
        gtk_widget_set_sensitive(button21, TRUE);
        gtk_widget_set_sensitive(button22, TRUE);
        gtk_widget_set_sensitive(button23, TRUE);
        gtk_widget_set_sensitive(button24, TRUE);
        gtk_widget_set_sensitive(button25, TRUE);
        gtk_widget_set_sensitive(button26, TRUE);
        gtk_widget_set_sensitive(button27, TRUE);
        gtk_widget_set_sensitive(button28, TRUE);
        gtk_widget_set_sensitive(button29, TRUE);
        gtk_widget_set_sensitive(button30, TRUE);
        gtk_widget_set_sensitive(button31, TRUE);
        gtk_widget_set_sensitive(button32, TRUE);
        gtk_widget_set_sensitive(button33, TRUE);
        gtk_widget_set_sensitive(button34, TRUE);
        gtk_widget_set_sensitive(button35, TRUE);
        gtk_widget_set_sensitive(button36, TRUE);
        gtk_widget_set_sensitive(button37, TRUE);
        gtk_widget_set_sensitive(button38, TRUE);
        gtk_widget_set_sensitive(button39, TRUE);
        gtk_widget_set_sensitive(button40, TRUE);
        gtk_widget_set_sensitive(button41, TRUE);
        gtk_widget_set_sensitive(button42, TRUE);
}
void show_Bin_window()
{
        show_all();
        gtk_widget_set_sensitive(button1, FALSE);
        gtk_widget_set_sensitive(button2, FALSE);
        gtk_widget_set_sensitive(button3, FALSE);
        gtk_widget_set_sensitive(button4, FALSE);
        gtk_widget_set_sensitive(button14, FALSE);
        gtk_widget_set_sensitive(button15, FALSE);
        gtk_widget_set_sensitive(button18, FALSE);
        gtk_widget_set_sensitive(button19, FALSE);
        gtk_widget_set_sensitive(button20, FALSE);
        gtk_widget_set_sensitive(button21, FALSE);
        gtk_widget_set_sensitive(button23, FALSE);
        gtk_widget_set_sensitive(button24, FALSE);
        gtk_widget_set_sensitive(button25, FALSE);
        gtk_widget_set_sensitive(button26, FALSE);
        gtk_widget_set_sensitive(button28, FALSE);
        gtk_widget_set_sensitive(button33, FALSE);
        gtk_widget_set_sensitive(button38, FALSE);
        gtk_widget_set_sensitive(button42, FALSE);
}

void show_Dec_window()
{
        show_all();
        gtk_widget_set_sensitive(button18, FALSE);
        gtk_widget_set_sensitive(button23, FALSE);
        gtk_widget_set_sensitive(button28, FALSE);
        gtk_widget_set_sensitive(button33, FALSE);
        gtk_widget_set_sensitive(button38, FALSE);
        gtk_widget_set_sensitive(button42, FALSE);
}

void show_Hex_window()
{
        show_all();
        gtk_widget_set_sensitive(button1, FALSE);
        gtk_widget_set_sensitive(button2, FALSE);
        gtk_widget_set_sensitive(button3, FALSE);
        gtk_widget_set_sensitive(button4, FALSE);
}

void show_Oct_window()
{
        show_all();
        gtk_widget_set_sensitive(button1, FALSE);
        gtk_widget_set_sensitive(button2, FALSE);
        gtk_widget_set_sensitive(button3, FALSE);
        gtk_widget_set_sensitive(button4, FALSE);
        gtk_widget_set_sensitive(button18, FALSE);
        gtk_widget_set_sensitive(button19, FALSE);
        gtk_widget_set_sensitive(button23, FALSE);
        gtk_widget_set_sensitive(button24, FALSE);
        gtk_widget_set_sensitive(button28, FALSE);
        gtk_widget_set_sensitive(button33, FALSE);
        gtk_widget_set_sensitive(button38, FALSE);
        gtk_widget_set_sensitive(button42, FALSE);
}
