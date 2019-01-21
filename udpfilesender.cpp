#include "udpfilesender.h"

UDPFileSender::UDPFileSender(const QString &filePath, const QHostAddress &remoteAddr, quint16 port, QObject *parent)
  : QObject(parent), filePath(filePath), remoteAddr(remoteAddr), port(port) {
}

void UDPFileSender::start()
{
  if(!QFile::exists(filePath)) {
    emit this->error(UDPFileSenderError::ERROR_FILE_OPEN); return;
  } else {
    QFile f(filePath);
    if(!f.open(QFile::ReadOnly)) {
      emit this->error(UDPFileSenderError::ERROR_FILE_EXISTS); return;
    }
    QUdpSocket socket;



    forever {

    }
  }
}

void UDPFileSender::sendFile()
{
  if(this->started)
    return;
  else {
    this->started = true;
    this->start();
  }

}
