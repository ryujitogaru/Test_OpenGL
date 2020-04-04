#include "pch.h"
#include "Debug.h"

#include <windows.h>
#include <tchar.h>
#include <sstream>

#ifdef _DEBUG
#   define MyOutputDebugString( str, ... ) \
      { \
        TCHAR c[256]; \
        _stprintf( c, str, __VA_ARGS__ ); \
        OutputDebugString( c ); \
      }
#else
#    define MyOutputDebugString( str, ... ) // 空実装
#endif
// MyOutputDebugString( _T("Vector( %f, %f, %f )\n"), tmp.x, tmp.y, tmp.z );

Debug::Debug() {

}
Debug::~Debug() {

}

void Debug::DBLog(const char* log) {
	MyOutputDebugString(_T("LOG : %hs\n"), log);
}
void Debug::DBLog(std::string str) {
	const char* log = str.data();
	MyOutputDebugString(_T("LOG : %hs\n"), log);
}
