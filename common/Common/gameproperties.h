#ifndef GAMEPROPERTIES_H
#define GAMEPROPERTIES_H

#include <QObject>

class GameProperties : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int bulletIconHeight READ bulletIconHeight NOTIFY bulletIconHeightChanged)
    Q_PROPERTY(int bulletIconWidth READ bulletIconWidth NOTIFY bulletIconWidthChanged)
    Q_PROPERTY(int bulletImageHeight READ bulletImageHeight NOTIFY bulletImageHeightChanged)
    Q_PROPERTY(int bulletImageWidth READ bulletImageWidth NOTIFY bulletImageWidthChanged)
    Q_PROPERTY(int tankIconSize READ tankIconSize NOTIFY tankIconSizeChanged)
    Q_PROPERTY(int tankImageSize READ tankImageSize NOTIFY tankImageSizeChanged)
    Q_PROPERTY(int fieldWidth READ fieldWidth NOTIFY fieldWidthChanged)
    Q_PROPERTY(int fieldHeight READ fieldHeight NOTIFY fieldHeightChanged)

public:
    explicit GameProperties(QObject *parent = 0);

    static int bulletIconHeight();
    static int bulletIconWidth();
    static int bulletImageHeight();
    static int bulletImageWidth();
    static int tankIconSize();
    static int tankImageSize();
    static int fieldWidth();
    static int fieldHeight();

signals:
    void bulletIconHeightChanged();
    void bulletIconWidthChanged();
    void bulletImageHeightChanged();
    void bulletImageWidthChanged();
    void tankIconSizeChanged();
    void tankImageSizeChanged();
    void fieldHeightChanged();
    void fieldWidthChanged();

private:
    const static int m_bulletIconHeight = 4; //3x4
    const static int m_bulletIconWidth = 3; //3x4
    const static int m_bulletImageHeight = m_bulletIconHeight * 2;
    const static int m_bulletImageWidth = m_bulletIconWidth * 2;
    const static int m_tankIconSize = 16; //16x16
    const static int m_tankImageSize = m_tankIconSize * 2;
    const static int m_fieldWidth = m_tankImageSize * 13;
    const static int m_fieldHeight = m_tankImageSize * 13;
};

#endif // GAMEPROPERTIES_H
