#ifndef UDPFILESENDER_H
#define UDPFILESENDER_H

#include <QObject>
#include <QHostAddress>
#include <QUdpSocket>
#include <QFile>

namespace UDPFileSenderError {
  const QString ERROR_FILE_EXISTS = "Файл не существует";
  const QString ERROR_FILE_OPEN   = "Не удалось открыть файл для чтения";
} 

class UDPFileSender : public QObject
{
  Q_OBJECT

  private:
    QString filePath;
    QHostAddress remoteAddr;
    quint16 port;
    bool started;

  protected:
    void start();

  public:
    explicit UDPFileSender(const QString &filePath, const QHostAddress &remoteAddr, quint16 port, QObject *parent = nullptr);
    void sendFile();

  signals:
    void error(const QString &errorText);

  public slots:
};

#endif // UDPFILESENDER_H
