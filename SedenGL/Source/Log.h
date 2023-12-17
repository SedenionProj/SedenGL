#pragma once
#include <iostream>

#define SEDEN_ERROR(Message,...) printf((std::string("ERROR : ")+Message).c_str(),__VA_ARGS__);
#define SEDEN_WARNING(Message,...) printf((std::string("WARNING : ")+Message).c_str(),__VA_ARGS__);
#define SEDEN_INFO(Message,...) printf((std::string("INFO : ")+Message).c_str(),__VA_ARGS__);
