//------------------------------------------------------------------------------
//! @author Edited by: Kolotov R.K.
//!
/*! @file

    @brief �����-������� ��� ������� � ���������� TCP-�������� � ���������
    ������.

    @details  */
//------------------------------------------------------------------------------
#ifndef TTCPTHREAD_H
#define TTCPTHREAD_H


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
#include <iostream>

#include <QtCore/QObject>
#include <QtCore/QThread>
#include <QtCore/QCoreApplication>

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------- class TTcpThread declaration -----------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//! ����� ������ TTcpThread.
/*! �����-������� ��� ������� � ���������� TCP-�������� � ���������
    ������. */
//------------------------------------------------------------------------------
class TTcpThread : public QThread
{
  Q_OBJECT

private:
  QTcpServer*   m_cServer;
  QTcpSocket*   m_cSocket;
  bool          m_bClose;
  qint16        m_iPort;

  void sendToWii(int *data);

public:
  TTcpThread( QObject* parent = 0 );
  ~TTcpThread();

  bool setPort( qint16 port );
  void run();

public slots:
  void stop();

};

#endif // TTCPTHREAD_H
