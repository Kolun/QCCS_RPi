#include <QtCore/QCoreApplication>
#include "TQCCSServer.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  
  TQCCSServer serv;
  serv.loop();

  return a.exec();
}
