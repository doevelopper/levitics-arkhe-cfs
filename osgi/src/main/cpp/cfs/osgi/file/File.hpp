
#ifndef CFS_OSGI_FILE_FILE_HPP
#define CFS_OSGI_FILE_FILE_HPP

#include <fstream>
#include <string>
#include <optional>
namespace cfs
{
    namespace osgi
    {
        namespace file
        {
            enum class
            Mode
            {
                binary,
                normal,
                both
            };

            class File
            {
                public:

                    File();
                    File(
                        const std::string & fileName,
                        const Mode mode = Mode::both
                        );
                    virtual ~File();

                    void
                    open ( const std::ios_base::openmode accessMode );
                    void
                    open (
                        const std::string & fileName,
                        const Mode mode = Mode::both
                        );
                    template < typename Type, typename = typename std::enable_if < !std::is_same < Type, std::string >::value >::type >
                    Type
                    read ();
                    template < typename Type, typename = typename std::enable_if < std::is_same < Type, std::string >::value >::type >
                    Type
                    read ( std::size_t size );
                    std::optional < std::string >
                    readFile ();
                    std::optional < std::string >
                    readLine ();
                    std::string
                    readsTextContentWordByWord ();
                    template < typename Type >
                    void
                    write ( const Type & contentToWrite );
                    void
                    close ();
                    std::string
                    fileName () const noexcept;
                    bool
                    endOfFile () const;
                    static void
                    save (
                        const std::string & fileName,
                        const std::string & text
                        );

                private:

                    std::fstream m_fileStream;
                    std::ios_base::openmode m_accessMode;
                    std::string m_fileName;
                    Mode mode { Mode::both };
            };
        }
    }
}

#endif
