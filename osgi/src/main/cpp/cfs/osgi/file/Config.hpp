
#ifndef CFS_OSGI_FILE_CONFIG_HPP
#define CFS_OSGI_FILE_CONFIG_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>

namespace cfs
{
    namespace osgi
    {
        namespace file
        {
/*!
 * @brief Simple configuration utility.
 *        Configuration options can be retrieved or set via the get and set methods:
 * @code{.cpp}
 *   std::string resolutionX = config->get("Params");
 *   config->set("Params", 163);
 * @endcode
 */
            class Config
            {
                public:

                    Config();
                    Config( std::string filename );
                    virtual ~Config() = default;
                    void
                    init (
                        std::string filename,
                        std::string delimiter = "=",
                        std::string comment = "#"
                        );
                    template < typename T >
                    T
                    read ( const std::string & in_key ) const;
                    template < typename T >
                    T
                    read (
                        const std::string & in_key,
                        const T & in_value
                        ) const;
                    template < typename T >
                    bool
                    read (
                        T & out_var,
                        const std::string & in_key
                        ) const;
                    template < typename T >
                    bool
                    read (
                        T & out_var,
                        const std::string & in_key,
                        const T & in_value
                        ) const;
                    void
                    read (
                        std::string & filename,
                        std::string delimiter = "=",
                        std::string comment = "#"
                        );
/*!
 * @brief Retrieves the value of the specified option. If the option is not present, returns an empty string.
 *        The validity of an option may be checked via hasOption.
 *
 * @param[in] option String option name
 * @return String option value
 */
                    std::string
                    get ( std::string const & option ) const;

/*!
 * @brief Sets the value of the specified option.
 *
 * @param[in] option
 * @param[in] value
 */
                    void
                    set (
                        std::string const & option,
                        std::string const & value
                        );

                private:

                    std::unordered_map < std::string, std::string > m_ConfigOptions; ///< Key: option name; Value: option valu
            };
        }
    }
}

#endif
