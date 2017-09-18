#ifndef CFS_OSGI_EDAC_CALLSTACK_ABIDEMANGLING_HPP
#define CFS_OSGI_EDAC_CALLSTACK_ABIDEMANGLING_HPP

#include <algorithm>
#include <cxxabi.h>
#include <iostream>
#include <string>
#include <memory>
#include <cassert>
#include <typeinfo>
#include <execinfo.h>

class ABIDemangling 
{
public:
    ABIDemangling();
    ABIDemangling(const ABIDemangling& orig);
    virtual ~ABIDemangling() = default;
    
    bool demangle(std::string s, std::string& res);
    template <typename T>
    std::string gccDemangle(T& e);
    std::string demangle(const char* name/*, std::string& retVal*/);
    template <class T>
    std::string type(const T& t);
    std::string demangle(const std::type_info& type);
    size_t demangle(const std::type_info& type, char* buf, size_t bufSize);
private:

};

#endif

