
#ifndef CFS_OSGI_OSGI_HPP
#define CFS_OSGI_OSGI_HPP

#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

using cucumber::ScenarioScope;


class Osgi
{
    public:

        Osgi();
        Osgi(
            int argc,
            char * argv[]
            );
        virtual ~Osgi() = default;

    private:
};

#endif
