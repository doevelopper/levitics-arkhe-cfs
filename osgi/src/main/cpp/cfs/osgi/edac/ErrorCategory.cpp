
#include <cfs/osgi/edac/ErrorCategory.hpp>

ErrorCategory::ErrorCategory()
{
}

const char *
ErrorCategory::name () const
{
    return "CFS Error Category";
}

std::string
ErrorCategory::message ( int ev ) const
{
    switch ( ev )
    {
    case ErrorCategory::CfsStatusError::STATUS_OK:

        return ( "OK" );

        break;
    default:

        return "Unknown CFS error";

        break;
    }
}

const std::error_category & ErrorCategory::cfsCategory ()
{
}

std::error_code
ErrorCategory::make_error_code ( CfsStatusError e )
{
    return std::error_code( static_cast < int > ( e ), cfsCategory());
}

std::error_condition
ErrorCategory::make_error_condition ( CfsStatusError e )
{
    return std::error_condition( static_cast < int > ( e ), cfsCategory());
}

std::error_condition
ErrorCategory::default_error_condition ( int ev ) const
{
    switch ( ev )
    {
    case CfsStatusError::STATUS_FAILURE:

        return ( std::errc::state_not_recoverable );

    default:

        return std::error_condition( ev, *this );
    }
}

bool equivalent ( const std::error_code & code, int condition ) const
{
    return ( *this == code.category() && static_cast < int > ( default_error_condition( code.value()).value()) == condition );
}
