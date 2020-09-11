    char        buf[16];
    int         i, len, prec, s_len, base = 0;
    long        u = 0;
    char        *str;




int
    do_write(char c, int info)
{
    static int i;

    if (info == 0)
    {
        write(1, &c, 1);
        i++;
    }
    if (info == 1)
        return (i);
    if (info == 2)
        i = 0;
    return i;
}


void
    fill_buff()
{
    char *cs = "0123456789abcdef";
    buf[--i] = cs[u % base];
    u = u / base;
    if (u > 0)
        fill_buff();
}



int
    ft_printf(const char *s, ...)
{
    prec = -1;

    do_write(0, 2);
    while (*s)
    {
        if (*s == '%')
        {
            s++;
            while (*s <= '9' && *s >= '0')
            {
                len = len * 10 + *s - '0';
                s++;
            }
            if (*s == '.')
            {
                s++;
                prec = 0;
                while (*s <= '9' && *s >= '0')
                {
                    prec = prec * 10 + *s - '0';
                    s++;
                }   
            }




            if (*s == 's')
            {
                s++;
                str = argument();
                s_len = strlen(str);
                if (prec > s_len || prec == -1)
                    prec = s_len;
                while (len > prec)
                {
                    do_write(' ', 0);
                    len--;
                }
                while (0 < prec)
                {
                    do_write(*str, 0);
                    str++;
                    prec--;
                }
            }



            if (*s == 'x')
            {
                u = argument(unsigned int);
                i = 16;
                fill_buff();
                s_len = 16 - i;
            }
        }
        else
            do_write(*s);
    }
    return (do_write(0, 1));
}