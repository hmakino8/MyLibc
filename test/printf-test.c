#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

#ifdef FT_PRINTF
# define F(...) \
	ft_printf(__VA_ARGS__)
#else
# define F(...) \
	printf(__VA_ARGS__)
#endif

int	main(void)
{
	char c;
	char *str;

	str = &c;
	F("len = %d ", F("%%c(args=A)               : [%c]\n", 'A'));
	F("len = %d ", F("%%1.c                     : [%1.c]\n", 'A'));
	F("len = %d ", F("%%3.2c                    : [%3.2c]\n", 'A'));
	F("len = %d ", F("%%c(0)                    : [%c]\n", 0));
	F("len = %d ", F("%%3c(0)                    : [%3c]\n", 0));
	F("len = %d ", F("%%%%                       : [%%]\n"));
	F("len = %d ", F("%%s(args=hmakino)         : [%s]\n", "hmakino"));
	F("len = %d ", F("%%4s                      : [%4s]\n", "hmakino"));
	F("len = %d ", F("%%-4s                     : [%-4s]\n", "hmakino"));
	F("len = %d ", F("%%8s                      : [%8s]\n", "hmakino"));
	F("len = %d ", F("%%-8s                     : [%-8s]\n", "hmakino"));
	F("len = %d ", F("%%4.0s                    : [%4.0s]\n", "hmakino"));
	F("len = %d ", F("%%4.s                     : [%4.s]\n", "hmakino"));
	F("len = %d ", F("%%4.3s                    : [%4.3s]\n", "hmakino"));
	F("len = %d ", F("%%8.3s                    : [%8.3s]\n", "hmakino"));
	F("len = %d ", F("%%-8.3s                   : [%-8.3s]\n", "hmakino"));
	F("len = %d ", F("%%*.4s                    : [%*.4s]\n", 8, "hmakino"));
	F("len = %d ", F("%%-*.4s                   : [%-*.4s]\n", 8, "hmakino"));
	F("len = %d ", F("%%8.*s                    : [%8.*s]\n", 4, "hmakino"));
	F("len = %d ", F("%%.005s                   : [%.005s]\n", "hmakino"));
	F("len = %d ", F("%%30.s                    : [%30.s]\n", "hmakino"));
	F("len = %d ", F("%%s(null)                 : [%s]\n", 0));
	F("len = %d ", F("%%*.*s                    : [%*.*s]\n", 8, 4, "hmakino"));
	F("len = %d ", F("%%--...3.s                : [%-----------3.s]\n", "hmakino"));
	F("len = %d ", F("%%i                       : [%i]\n", -127));
	F("len = %d ", F("%%-5.5i(-127)             : [%-5.5i]\n", -127));
	F("len = %d ", F("%%+5.5i                   : [%+5.5i]\n", -127));
	F("len = %d ", F("%%+9.7i                   : [%+9.7i]\n", -127));
	F("len = %d ", F("%%-9.7i                   : [%-9.7i]\n", -127));
	F("len = %d ", F("%%012i, (int)-2147483648  : [%012i]\n", (int)-2147483648));
	F("len = %d ", F("%%+09.4i                  : [%+09.4i]\n", -127));
	F("len = %d ", F("%%-09.4i                  : [%-09.4i]\n", -127));
	F("len = %d ", F("%% i(0)                   : [% .i]\n", 0));
	F("len = %d ", F("%% i(127)                 : [% i]\n", 127));
	F("len = %d ", F("%%.0i(0)                  : [%.0i]\n", 0));
	F("len = %d ", F("%%.0i(128)                : [%.0i]\n", 128));
	F("len = %d ", F("%%8.0i(0)                 : [%8.0i]\n", 0));
	F("len = %d ", F("%%08i(-127)               : [%08i]\n", -127));
	F("len = %d ", F("%%8.1i(0)                 : [%8.1i]\n", 0));
	F("len = %d ", F("%%0.8i(1234)              : [%0.8i]\n", 1234));
	F("len = %d ", F("%%0.8i(1234)              : [%-0.8i]\n", 1234));
	F("len = %d ", F("%%+9.7i                   : [%+9.7i]\n", -127));
	F("len = %d ", F("%%-9.7i                   : [%-9.7i]\n", -127));
	F("len = %d ", F("%%+09.4i                  : [%+09.4i]\n", -127));
	F("len = %d ", F("%%-09.4i                  : [%-09.4i]\n", -127));
	F("len = %d ", F("%%+ i                     : [%+ i]\n", 127));
	F("len = %d ", F("%% .i                     : [% .i]\n", 0));
	F("len = %d ", F("%% ++++    8.4i           : [% ++++     8.4i]\n", 123456));
	F("len = %d ", F("%% ++++ -   8.4i          : [% ++++ -    8.4i]\n", -1));
	F("len = %d ", F("%%   -     8.4i           : [%    -     8.4i]\n", 1));
	F("len = %d ", F("%%   -   +  .i(1)         : [%    -  +   .i]\n", 1));
	F("len = %d ", F("%% .i(0)                  : [% .i]\n", 0));
	F("len = %d ", F("%%   -     .i(1)          : [%    -     .i]\n", 1));
	F("len = %d ", F("%% - #30.29i              : [% - #15.10i]\n", 230482093));
	F("len = %d ", F("%% -+ #30.29i             : [% -+ #15.10i]\n", 230482093));
	F("len = %d ", F("%% d                      : [% d]\n", 88));
	F("len = %d ", F("%%4.3d                    : [%4.3d]\n", 88));
	F("len = %d ", F("%%4.1d                    : [%8.3d]\n", 8888));
	F("len = %d ", F("%%4.1d                    : [%8.8d]\n", 8888));
	F("len = %d ", F("%%4.1d                    : [%08.3d]\n", 8888));//プレシジョンが有効の時0フラグ無
	F("len = %d ", F("%%4.1d                    : [%-08d]\n", 8888));//-フラグの時0フラグ無
	F("len = %d ", F("%%d(-127)                 : 10base [%d]\n", -127));
	F("len = %d ", F("%%x(127)                  : 16base [%x]\n", 127));
	F("len = %d ", F("%%X                       : 16base [%X]\n", 127));
	F("len = %d ", F("%%#x                      : 16base [%#x]\n", 127));
	F("len = %d ", ("%%#X                       : 16base [%#X]\n", 127));
	F("len = %d ", F("%%p((void *)0)            : [%p]\n", (void *)0));
	F("len = %d ", F("%%p                       : 16base [%p]\n", &str));
	F("len = %d ", F("%%--.%#xp                   : [%%--.%#xp]\n", 0));

	char *intmaxlen;

	intmaxlen = malloc((size_t)INT_MAX + 1);
	intmaxlen[INT_MAX] = '\0';
	memset(intmaxlen, 'b', INT_MAX);
	printf("intmaxlen + 1            : %d", F("a%s", intmaxlen));
	//printf("--------------未定義----------------\n");
	//printf("0s : [%*.*s]\n", 10, 8, "hmakino");
	//printf("+s : [%+s]\n", "hmakino");//変換指定子sかつ+フラグ未定義
	//printf("#s : [%#s]\n", "hmakino");//変換指定子sかつ#フラグ未定義
	//printf(" s : [% s]\n", "hmakino");//変換指定子sかつ空白フラグ未定義
	//printf("0s : [%0s]\n", "hmakino");//変換指定子sかつ0フラグ未定義
	//printf("p : [%#p]\n", &len);//pはシャープフラグ兼任
	//printf("------------------------------------\n");
	//printf(NULL);//最初の引数の文字列がNULLポインターの時、セグフォ

	return (0);
}
