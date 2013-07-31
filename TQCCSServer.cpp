#include "TQCCSServer.h"

TQCCSServer::TQCCSServer(QObject *parent) : QObject( parent )
{
  connect( this,    SIGNAL( stopTcp() ),
           &m_cTcp,   SLOT( stop()    ) );
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
TQCCSServer::~TQCCSServer()
{

}


void TQCCSServer::loop()
{
  qint16 port;

  std::cout << "Enter server port: ";
  std::cin >> port;

  while( !m_cTcp.setPort(port) )
  {
    std::cout << "Wrong port! Enter port: ";
    std::cin >> port;
  }

  std::cout << "\nStarting server...";
  m_cTcp.start();

  std::string str;

  while( str != "exit" )
  {
    std::cin >> str;
    if( str == "stop" )
      emit stopTcp();
    if( str == "start" )
    {
      if(!m_cTcp.isRunning())
      {
        std::cout << "\nStarting server...";
        m_cTcp.start();
      }
    }
  }

}

