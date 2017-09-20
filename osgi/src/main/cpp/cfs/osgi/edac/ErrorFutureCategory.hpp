#ifndef CFS_OSGI_EDAC_ERRORFUTURECATEGORY_HPP
#define CFS_OSGI_EDAC_ERRORFUTURECATEGORY_HPP

#include <future>       // std::promise, std::future_error, std::future_category

class ErrorFutureCategory : std::future_category
{
public:
    ErrorFutureCategory();
    virtual ~ErrorFutureCategory() = default;
private:

};

#endif

