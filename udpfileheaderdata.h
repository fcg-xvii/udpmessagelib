#ifndef UDPFILEHEADERDATA_H
#define UDPFILEHEADERDATA_H

// Максимальная длина данных датаграммы в IPV4, при которой мы избегаем фрагментации
#define UDP_MAX_DATA_LENGTH_IPV4 = 508
// ... Jumbograms???
#define UDP_MAX_DATA_LENGTH_IPV6 = 20000

#include <QByteArray>
#include <QString>
#include <QHash>
#include <QRandomGenerator>
#include <QDataStream>
#include <QUdpSocket>

/*
 * Структура UDP сообщения (длина датаграммы без фрагментации - 508 байтов
 *   quint64  8 байтов  1. Идентификатор UDP сообщения
 *   quint32  4 байта   2. Количество частей сообщения
 *   quint32  4 байта   3. Номер части сообщения
 *   char[]   492 байт  5. Максимальная длина данных сообщения
 *
 */

class UDPMessage {
  private:
    quint64 messageID;
    quint32 partsCount;
    QHash<quint32, QByteArray> parts;

  public:
    template<typename T>
    static QByteArray packNumber(const T& val)
    {
      int size = static_cast<int>(sizeof(T));
      QByteArray result(size, 0);
      for(int i = size - 1; i >= 0; i--)
        result[i] = static_cast<char>(val >> i * 8);
      return result;
    }

    template<typename T>
    static void unpackNumber(const QByteArray& source, T& result)
    {
      for(int i = source.length() - 1; i >= 0; i--)
        result = (result << 8) + source[i];
    }

    static QByteArray packString(QString val)
    {
      int maxLength = static_cast<int>(std::numeric_limits<quint16>::max() - sizeof(qint16));
      if(val.length() > maxLength)
       val = val.left(maxLength);
      qint16 size = static_cast<qint16>(val.length());
      QByteArray result = UDPMessage::packNumber(size);
      result.append(val.toUtf8());
      return result;
    }

    static QU PackData(const QByteArray& data)
    {
      return
    }
};

#endif // UDPFILEHEADERDATA_H
