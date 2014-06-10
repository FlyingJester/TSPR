#ifndef TS_COMMON_DLOPENWRAP
#define TS_COMMON_DLOPENWRAP


#ifdef _WIN32
#include <windows.h>
typedef HINSTANCE fhandle;

#define DL_LAZY   0
#define DL_NOW    1
#define DL_LOCAL  2
#define DL_GLOBAL 3

#define DLOPENLIBRARY(_name, _directory, _flags) LoadLibrary( _directory "/" _name ".dll")

#define DLOPENSYSLIBRARY(_name, _flags) LoadLibrary(_name)

#define DLCLOSELIBRARY CloseLibrary

#define DLOPENFUNCTION GetProcAddress

#else
typedef void* fhandle;

#include <stdlib.h>
#include <dlfcn.h>

#define DL_LAZY     RTLD_LAZY
#define DL_NOW      RTLD_NOW
#define DL_LOCAL    RTLD_LOCAL
#define DL_GLOBAL   RTLD_GLOBAL

#define DLOPENLIBRARY(_name, _directory, _flags) dlopen( _directory "/lib" _name ".so", _flags)

#define DLOPENSYSLIBRARY(_name, _flags) dlopen(_name, _flags)

#define DLCLOSELIBRARY dlclose

#define DLOPENFUNCTION dlsym

#endif

#endif
