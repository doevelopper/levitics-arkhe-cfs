
#ifndef CFS_OSGI_FILE_CONFIG_HPP
#define CFS_OSGI_FILE_CONFIG_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <map>


namespace cfs
{
    namespace osgi
    {
        namespace file
        {
            
            class Config 
            {
            public:
                Config();
                virtual ~Config() = default;

                void init(std::string filename, std::string delimiter = "=", std::string comment = "#");
                template<typename T> 
                T read(const std::string &in_key) const;
                template<typename T> 
                T read(const std::string &in_key, const T &in_value) const;
                template<typename T> 
                bool read(T &out_var, const std::string &in_key) const;
                template<typename T> 
                bool read(T &out_var, const std::string &in_key, const T &in_value) const;
                void read(std::string &filename, std::string delimiter="=", std::string comment = "#");
            private:

            };
        }
    }
}

#endif

