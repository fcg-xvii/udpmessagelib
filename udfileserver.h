#ifndef UDFILESERVER_H
#define UDFILESERVER_H

#include <QObject>

class UDFileServer : public QObject
{
  Q_OBJECT

  public:
    explicit UDFileServer(QObject *parent = nullptr);

  signals:

  public slots:
};

#endif // UDFILESERVER_H
