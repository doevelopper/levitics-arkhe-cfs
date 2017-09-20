
#ifndef CFS_OSGI_EDAC_ERRORCATEGORY_HPP
#define CFS_OSGI_EDAC_ERRORCATEGORY_HPP

#include <system_error>
#include <string>

class ErrorCategory : public std::error_category
{
    enum class CfsStatusError : std::uint32_t 
    {
        STATUS_OK                    = 0,
        STATUS_FAILURE               = 1
    };

public:
    ErrorCategory();
    virtual ~ErrorCategory() = default;
    
    const std::error_category& cfsCategory();
    std::error_code make_error_code(CfsStatusError e);
    /*!
     * brief Make_error_code overload to generate custom conditions;
     */
    std::error_condition make_error_condition (CfsStatusError e);
    virtual const char* name() const;
    virtual std::string message(int ev) const;
    /*!
     * @brief Defines an error_condition that is equivalent to a given error code
     */
    virtual std::error_condition default_error_condition(int ev) const;
    virtual bool equivalent (const std::error_code& code, int condition) const;
private:

};

namespace std
{
  template <>
  struct is_error_code_enum<ErrorCategory::CfsStatusError> : public true_type {};
}

#endif

