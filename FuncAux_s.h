#pragma once

#include <iostream> 
using namespace std;
#include <cerrno>
#include <string.h>
#include <cassert>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#define A1_WIN
#endif

#ifdef A1_WIN

//errno_t strcpy_s (char *dest, size_t dmax, const char *src);
//
//errno_t strcat_s (char *dest, size_t dmax, const char *src);
//
//errno_t _itoa_s (int value, char *dest, size_t dmax, int radix);
//
//char * strtok_s (char *str, const char *delim, char **context);

#else

	#include <sys/stat.h>
	#include <unistd.h>

int strcpy_s (char *dest, size_t dmax, const char *src);

int strcat_s (char *dest, size_t dmax, const char *src);

int _itoa_s (int value, char *dest, size_t dmax, int radix);

char * strtok_s (char *str, const char *delim, char **context);

int _stricmp(const char *a, const char *b);

void _mkdir(const char *dirname);

#endif
