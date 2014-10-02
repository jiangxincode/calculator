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

void show_Bin_window()
{
        gtk_button_set_label(GTK_BUTTON(button1)," ");
        gtk_widget_show(button1);
        gtk_button_set_label(GTK_BUTTON(button2)," ");
        gtk_widget_show(button2);
        gtk_button_set_label(GTK_BUTTON(button3)," ");
        gtk_widget_show(button3);
        gtk_button_set_label(GTK_BUTTON(button4)," ");
        gtk_widget_show(button4);
        gtk_button_set_label(GTK_BUTTON(button6)," ");
        gtk_widget_show(button6);
        gtk_button_set_label(GTK_BUTTON(button14)," ");
        gtk_widget_show(button14);
        gtk_button_set_label(GTK_BUTTON(button15)," ");
        gtk_widget_show(button15);
        gtk_button_set_label(GTK_BUTTON(button18)," ");
        gtk_widget_show(button18);
        gtk_button_set_label(GTK_BUTTON(button19)," ");
        gtk_widget_show(button19);
        gtk_button_set_label(GTK_BUTTON(button20)," ");
        gtk_widget_show(button20);
        gtk_button_set_label(GTK_BUTTON(button21)," ");
        gtk_widget_show(button21);
        gtk_button_set_label(GTK_BUTTON(button23)," ");
        gtk_widget_show(button23);
        gtk_button_set_label(GTK_BUTTON(button24)," ");
        gtk_widget_show(button24);
        gtk_button_set_label(GTK_BUTTON(button25)," ");
        gtk_widget_show(button25);
        gtk_button_set_label(GTK_BUTTON(button26)," ");
        gtk_widget_show(button26);
        gtk_button_set_label(GTK_BUTTON(button28)," ");
        gtk_widget_show(button28);
        gtk_button_set_label(GTK_BUTTON(button33)," ");
        gtk_widget_show(button33);
        gtk_button_set_label(GTK_BUTTON(button38)," ");
        gtk_widget_show(button38);
        gtk_button_set_label(GTK_BUTTON(button42)," ");
        gtk_widget_show(button42);
}


void show_Dec_window()
{
        gtk_button_set_label(GTK_BUTTON(button1),"pi");
        gtk_widget_show(button1);
        gtk_button_set_label(GTK_BUTTON(button2),"sin");
        gtk_widget_show(button2);
        gtk_button_set_label(GTK_BUTTON(button3),"cos");
        gtk_widget_show(button3);
        gtk_button_set_label(GTK_BUTTON(button4),"tan");
        gtk_widget_show(button4);
        gtk_button_set_label(GTK_BUTTON(button6),"Exp");
        gtk_widget_show(button6);
        gtk_button_set_label(GTK_BUTTON(button14),"7");
        gtk_widget_show(button14);
        gtk_button_set_label(GTK_BUTTON(button15),"4");
        gtk_widget_show(button15);
        gtk_button_set_label(GTK_BUTTON(button18)," ");
        gtk_widget_show(button18);
        gtk_button_set_label(GTK_BUTTON(button19),"8");
        gtk_widget_show(button19);
        gtk_button_set_label(GTK_BUTTON(button20),"5");
        gtk_widget_show(button20);
        gtk_button_set_label(GTK_BUTTON(button21),"2");
        gtk_widget_show(button21);
        gtk_button_set_label(GTK_BUTTON(button23)," ");
        gtk_widget_show(button23);
        gtk_button_set_label(GTK_BUTTON(button24),"9");
        gtk_widget_show(button24);
        gtk_button_set_label(GTK_BUTTON(button25),"6");
        gtk_widget_show(button25);
        gtk_button_set_label(GTK_BUTTON(button26),"3");
        gtk_widget_show(button26);
        gtk_button_set_label(GTK_BUTTON(button28)," ");
        gtk_widget_show(button28);
        gtk_button_set_label(GTK_BUTTON(button33)," ");
        gtk_widget_show(button33);
        gtk_button_set_label(GTK_BUTTON(button38)," ");
        gtk_widget_show(button38);
        gtk_button_set_label(GTK_BUTTON(button42)," ");
        gtk_widget_show(button42);
}

void show_Hex_window()
{
        gtk_button_set_label(GTK_BUTTON(button1)," ");
        gtk_widget_show(button1);
        gtk_button_set_label(GTK_BUTTON(button2)," ");
        gtk_widget_show(button2);
        gtk_button_set_label(GTK_BUTTON(button3)," ");
        gtk_widget_show(button3);
        gtk_button_set_label(GTK_BUTTON(button4)," ");
        gtk_widget_show(button4);
        gtk_button_set_label(GTK_BUTTON(button6)," ");
        gtk_widget_show(button6);
        gtk_button_set_label(GTK_BUTTON(button14),"7");
        gtk_widget_show(button14);
        gtk_button_set_label(GTK_BUTTON(button15),"4");
        gtk_widget_show(button15);
        gtk_button_set_label(GTK_BUTTON(button18),"A");
        gtk_widget_show(button18);
        gtk_button_set_label(GTK_BUTTON(button19),"8");
        gtk_widget_show(button19);
        gtk_button_set_label(GTK_BUTTON(button20),"5");
        gtk_widget_show(button20);
        gtk_button_set_label(GTK_BUTTON(button21),"2");
        gtk_widget_show(button21);
        gtk_button_set_label(GTK_BUTTON(button23),"B");
        gtk_widget_show(button23);
        gtk_button_set_label(GTK_BUTTON(button24),"9");
        gtk_widget_show(button24);
        gtk_button_set_label(GTK_BUTTON(button25),"6");
        gtk_widget_show(button25);
        gtk_button_set_label(GTK_BUTTON(button26),"3");
        gtk_widget_show(button26);
        gtk_button_set_label(GTK_BUTTON(button28),"C");
        gtk_widget_show(button28);
        gtk_button_set_label(GTK_BUTTON(button33),"D");
        gtk_widget_show(button33);
        gtk_button_set_label(GTK_BUTTON(button38),"E");
        gtk_widget_show(button38);
        gtk_button_set_label(GTK_BUTTON(button42),"F");
        gtk_widget_show(button42);
}

void show_Oct_window()
{
        gtk_button_set_label(GTK_BUTTON(button1)," ");
        gtk_widget_show(button1);
        gtk_button_set_label(GTK_BUTTON(button2)," ");
        gtk_widget_show(button2);
        gtk_button_set_label(GTK_BUTTON(button3)," ");
        gtk_widget_show(button3);
        gtk_button_set_label(GTK_BUTTON(button4)," ");
        gtk_widget_show(button4);
        gtk_button_set_label(GTK_BUTTON(button6)," ");
        gtk_widget_show(button6);
        gtk_button_set_label(GTK_BUTTON(button14),"7");
        gtk_widget_show(button14);
        gtk_button_set_label(GTK_BUTTON(button15),"4");
        gtk_widget_show(button15);
        gtk_button_set_label(GTK_BUTTON(button18)," ");
        gtk_widget_show(button18);
        gtk_button_set_label(GTK_BUTTON(button19)," ");
        gtk_widget_show(button19);
        gtk_button_set_label(GTK_BUTTON(button20),"5");
        gtk_widget_show(button20);
        gtk_button_set_label(GTK_BUTTON(button21),"2");
        gtk_widget_show(button21);
        gtk_button_set_label(GTK_BUTTON(button23)," ");
        gtk_widget_show(button23);
        gtk_button_set_label(GTK_BUTTON(button24)," ");
        gtk_widget_show(button24);
        gtk_button_set_label(GTK_BUTTON(button25),"6");
        gtk_widget_show(button25);
        gtk_button_set_label(GTK_BUTTON(button26),"3");
        gtk_widget_show(button26);
        gtk_button_set_label(GTK_BUTTON(button28)," ");
        gtk_widget_show(button28);
        gtk_button_set_label(GTK_BUTTON(button33)," ");
        gtk_widget_show(button33);
        gtk_button_set_label(GTK_BUTTON(button38)," ");
        gtk_widget_show(button38);
        gtk_button_set_label(GTK_BUTTON(button42)," ");
        gtk_widget_show(button42);
}

