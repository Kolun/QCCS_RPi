#include "TTcpThread.h"


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
TTcpThread::TTcpThread(QObject *parent) : QThread( parent )
{
  m_cServer = NULL;
  m_cSocket = NULL;
  m_bClose = false;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
TTcpThread::~TTcpThread()
{
  if(m_cSocket != NULL) delete m_cSocket;
  if(m_cServer != NULL)
  {
    m_cServer->close();
    delete m_cServer;
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
bool TTcpThread::setPort(qint16 port)
{
  if( port > 1 && port < 65534 )
    m_iPort = port;
  else
    return false;
  return true;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void TTcpThread::run()
{
  m_cServer = new QTcpServer( 0 );
  if( ! m_cServer->listen( QHostAddress::Any, m_iPort ) )
  {
    std::cout << "\nUnable to start server!\n"
              << m_cServer->errorString().toStdString()
              <<"\n> ";
  }
  else
  {
    std::cout << "\nServer started > ";
    while( !m_bClose )
    {
      qApp->processEvents();
      uint con_try = 2;
      std::cout << "\nWaiting for connection (1) > ";
      while( !m_cServer->waitForNewConnection( 3000 ) && !m_bClose )
      {
        std::cout << "\nWaiting for connection (" << con_try << ") > ";
        con_try++;
        qApp->processEvents();
      }
      if( !m_bClose )
      {
        m_cSocket = m_cServer->nextPendingConnection();
        std::cout << "\nClient connected [" << m_cSocket->peerAddress().toString().toStdString() << "] > ";
        m_cSocket->write(QByteArray("HFPiS"));
        while( !m_bClose )
        {
          if( !m_cSocket || !m_cSocket->isValid() || m_cSocket->state() == QAbstractSocket::UnconnectedState )
          {
            delete m_cSocket;
            m_cSocket = NULL;
            std::cout << "\nLost connection with client! > ";
            break;
          }
          if( m_cSocket->waitForReadyRead(50) )
          {
            std::cout << "\nRead data:";
            int data[4];
            for( int i = 0; i < 4; ++i )
            {
              int tmp_int;
              m_cSocket->read(reinterpret_cast<char*>( &tmp_int ), sizeof( int ) );
              std::cout << "\n   " << tmp_int;
              data[i] = tmp_int;
            }
            m_cSocket->readAll();
            sendToWii(data);
          }
        }
      }
      else
      {
        m_cServer->close();
        m_cSocket = NULL;
      }
    }
    std::cout << "\nServer stopped > ";
  }
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void TTcpThread::stop()
{
  m_bClose = true;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void TTcpThread::sendToWii(int* data)
{
  //================================================================//
  //          Add your f'cking code HERE                            //
  //================================================================//

}
