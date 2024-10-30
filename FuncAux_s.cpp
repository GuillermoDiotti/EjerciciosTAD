#include "FuncAux_s.h"

#ifdef A1_WIN

//errno_t strcpy_s (char *dest, size_t dmax, const char *src)
//{
//	return strcpy_s(dest, dmax, src);
//}
//
//errno_t strcat_s (char *dest, size_t dmax, const char *src)
//{
//	return strcat_s(dest, dmax, src);
//}
//
//errno_t _itoa_s (int value, char *dest, size_t dmax, int radix)
//{
//	return _itoa_s(value, dest, dmax, radix);
//}
//
//char * strtok_s (char *str, const char *delim, char **context)
//{
//	return strtok_s(str, delim, context);
//}

#else


int strcpy_s (char *dest, size_t dmax, const char *src)
{
	assert(strlen(src) < dmax);
	strcpy(dest, src);
	return 0;
}

int strcat_s (char *dest, size_t dmax, const char *src)
{
	assert(strlen(src) < dmax);
	strcat(dest, src);
	return 0;
}

int _itoa_s (int value, char *dest, size_t dmax, int radix)
{
	snprintf(dest, dmax, "%d", value);
	return 0;
}

char * strtok_s (char *str, const char *delim, char **context)
{
	return strtok_r(str, delim, context);
}

int _stricmp(const char *a, const char *b)
{
    for (;; a++, b++) {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d != 0 || !*a)
            return d;
    }
}

void _mkdir(const char *dirname) 
{
	mkdir(dirname, S_IRWXU);
}

#endif
