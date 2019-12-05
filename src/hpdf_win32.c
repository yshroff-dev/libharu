#include <locale.h>

#ifndef MAX_PATH
#define MAX_PATH	260
#endif

#define MAX_FILEMODE 20
#include "hpdf_win32.h"

FILE * win32_fopen(const char * filename, const char * mode) {
	wchar_t filepath[MAX_PATH];
	wchar_t filemode[MAX_FILEMODE];
	setlocale(LC_ALL, "en_US.UTF-8");
	if (mbstowcs(filepath, filename, MAX_PATH + 1) != (size_t)(-1)) {
		if (mbstowcs(filemode, mode, MAX_PATH + 1) != (size_t)(-1)) {
			return _wfopen(filepath, filemode);
		}
	}

	return 0;
}