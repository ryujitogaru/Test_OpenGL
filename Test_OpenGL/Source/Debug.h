#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <string>

class Debug {
public:
	Debug();
	~Debug();

	static void DBLog(const char*);
	static void DBLog(std::string);
private:
};

#endif // _DEBUG_H_
