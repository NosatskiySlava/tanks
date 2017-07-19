import QtQuick 2.0

SpriteSequence {
    id: root

    width: Props.bulletImageWidth
    height: Props.bulletImageHeight

    sprites: [
        Sprite {
            name: "up"
            frameCount: 1
            frameWidth: Props.bulletIconWidth
            frameHeight: Props.bulletIconHeight

            frameX: 107 * Props.bulletIconWidth + 2
            frameY: 25 * Props.bulletIconHeight + 2

            frameSync: true

            source: "qrc:/NES - Battle City JPN - General Sprites.png"
        }
    ]
}
