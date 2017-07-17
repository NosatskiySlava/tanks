#ifndef GAMEPROPERTIES_H
#define GAMEPROPERTIES_H

#include <QObject>

class GameProperties : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int tankIconSize READ tankIconSize NOTIFY tankIconSizeChanged)
    Q_PROPERTY(int tankImageSize READ tankImageSize NOTIFY tankImageSizeChanged)
    Q_PROPERTY(int fieldWidth READ fieldWidth NOTIFY fieldWidthChanged)
    Q_PROPERTY(int fieldHeight READ fieldHeight NOTIFY fieldHeightChanged)

public:
    explicit GameProperties(QObject *parent = 0);

    int tankIconSize() const;
    int tankImageSize() const;
    int fieldWidth() const;
    int fieldHeight() const;

signals:
    void tankIconSizeChanged();
    void tankImageSizeChanged();
    void fieldHeightChanged();
    void fieldWidthChanged();

private:
    const static int m_tankIconSize = 16; //16x16
    const static int m_tankImageSize = m_tankIconSize * 2;
    const static int m_fieldWidth = m_tankImageSize * 13;
    const static int m_fieldHeight = m_tankImageSize * 13;
};

#endif // GAMEPROPERTIES_H
