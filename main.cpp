#include <QCoreApplication>
#include <udpfilesender.h>
#include <QThread>
#include <QRandomGenerator>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  forever {
    qDebug() << QRandomGenerator::global()->generate64();
    QThread::sleep(3);
  }

  return a.exec();
}
