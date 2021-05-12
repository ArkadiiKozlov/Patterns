#ifndef LOGGERIMP_H
#define LOGGERIMP_H
// LoggerImpl.h - ����������
using namespace std;
#include <string>


class LoggerImpl
{
  public:
    virtual ~LoggerImpl( ) {}
    virtual void console_log( string & str ) = 0;
    virtual void file_log(
                    string & file, string & str ) = 0;
    virtual void socket_log(
           string & host, int port, string & str ) = 0;
};

class ST_LoggerImpl : public LoggerImpl
{
  public:
    void console_log( string & str );
    void file_log   ( string & file, string & str );
    void socket_log (
            string & host, int port, string & str );
};

class MT_LoggerImpl : public LoggerImpl
{
  public:
    void console_log( string & str );
    void file_log   ( string & file, string & str );
    void socket_log (
            string & host, int port, string & str );
};

#endif // LOGGERIMP_H
