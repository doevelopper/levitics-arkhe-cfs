
#include <cfs/osgi/edac/callstack/ABIDemangling.hpp>
ABIDemangling::ABIDemangling()
{
}

template < typename T >
std::string ABIDemangling::gccDemangle ( T & e )
{
    int status;


    std::unique_ptr < char > realname;
    const std::type_info & ti = typeid( e );
    realname.reset( abi::__cxa_demangle( ti.name(), 0, 0, &status ));

    // assert(status == 0);
    return ( std::string( realname.get()));
}

template < class T >
std::string ABIDemangling::type ( const T & t )
{
    return ( demangle( typeid( t ).name()));
}

std::string ABIDemangling::demangle ( const char * name /*, std::string& retVal*/ )
{
    int status;


    std::string retVal;
    std::unique_ptr < char, void ( * )(void *) > res  {
        abi::__cxa_demangle( name, nullptr, nullptr, &status ), std::free
    };

    switch ( status )
    {
    case -1:
        retVal = "memory allocation error";
        break;
    case -2:
        retVal = "invalid name given";
        break;
    case -3:
        retVal = "internal error: __cxa_demangle: invalid argument";
        break;
    default:
        retVal = "unknown error occured";
        break;
    }

    return (( status == 0 ) ? res.get() : retVal /*name*/ );
}

std::string
ABIDemangling::demangle ( const std::type_info & type )
{
    return ( demangle( type.name()));
}

size_t
ABIDemangling::demangle ( const std::type_info & type, char * buf, size_t bufSize )
{
    // return (demangle(type.name(), buf, bufSize));
}

void
ABIDemangling::printExceptionStack ( const std::exception & e, std::ostream & output )
{
    output << "Issue on " << abi::__cxa_demangle( typeid( e ).name(), nullptr, nullptr, nullptr ) << ": " << e.what() << std::endl;
}
