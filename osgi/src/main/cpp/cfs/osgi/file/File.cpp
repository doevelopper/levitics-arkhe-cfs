
#include <cfs/osgi/file/File.hpp>

#include <cstring>

using namespace cfs::osgi::file;

File::File()
{
}

File::File(
    const std::string & fileName,
    const Mode mode
    )
    : m_fileName( fileName )

// , m_accessMode(mode)
{
}

File::~File()
{
// close();
}

void
File::open ( const std::ios_base::openmode accessMode )
{
    if ( this->m_accessMode != accessMode )
    {
        this->m_accessMode = accessMode;
        this->m_fileStream.open( this->m_fileName, this->m_accessMode );

        if ( this->m_fileStream.fail())
        {
// std::cerr <<std::strerror(erno) <<" File couldn't be open" << std::endl;
        }
    }
}

void File::open (
    const std::string & fileName,
    const Mode mode
    )
{
    this->m_fileName = fileName;

// this->m_accessMode = mode;
    this->close();
}

template < typename Type, typename = typename std::enable_if < !std::is_same < Type, std::string >::value >::type >
Type File::read ()
{
    if ( mode == Mode::normal )
    {
        // std::cerr << "Error: Incompatible Mode" << std::endl;
        return Type{ };
    }

    Type readInput { };
    open( std::ios::in | std::ios::binary );
    this->m_fileStream.read( reinterpret_cast < char * > ( &readInput ), sizeof( readInput ));

    return readInput;
}

template < typename Type, typename = typename std::enable_if < std::is_same < Type, std::string >::value >::type >
Type File::read ( std::size_t size )
{
    if ( mode == Mode::normal )
    {
        // std::cerr << "Error: Incompatible Mode" << std::endl;
        return Type{ };
    }

// open(std::ios::in | std::ios::binary);
// std::unique_ptr<char> readTextChar(new char[size]);
// this->m_fileStream.read(readTextChar.get(), size);
// return readTextChar.get();
}

std::string
File::readsTextContentWordByWord ()
{
    if ( mode == Mode::binary )
    {
        return std::string{ };
    }

    std::string readContent;
    open( std::ios::in );
    this->m_fileStream >> readContent;

    return ( readContent );
}

void File::close ()
{
    if ( this->m_fileStream.is_open())
    {
        this->m_fileStream.close();
    }
}

std::string File::fileName () const noexcept
{
    return ( this->m_fileName );
}

bool File::endOfFile () const
{
    return ( this->m_fileStream.eof )();
}

void File::save (
    const std::string & fileName,
    const std::string & text
    )
{
    File file( fileName );


    file.open( std::ios::out );
}

template < typename Type >
void File::write ( const Type & contentToWrite )
{
    if ( mode == Mode::binary )
    {
        return;
    }

    open( std::ios::out | std::ios::in | std::ios::app );
    this->m_fileStream << contentToWrite;
}

std::optional < std::string > File::readFile ()
{
    if ( mode == Mode::binary )
    {
        return std::string{ };
    }

    std::string readContent;
    open( std::ios::in );
    this->m_fileStream >> readContent;

    if (( this->m_fileStream.eof() && readContent.empty()) || this->m_fileStream.fail())
    {
        return ( std::nullopt );
    }

    return ( readContent );
}

std::optional < std::string > File::readLine ()
{
    if ( mode == Mode::binary )
    {
        return std::string{ };
    }

    std::string readContent;
    open( std::ios::in );
    std::getline( this->m_fileStream, readContent );

    if (( this->m_fileStream.eof() && readContent.empty()) || this->m_fileStream.fail())
    {
        return ( std::nullopt );
    }

    return ( readContent );
}
