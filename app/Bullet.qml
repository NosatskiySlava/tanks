import QtQuick 2.0

import model.bullet 1.0

Item {
    id: root

    //TODO: assigne defaul value
    property var bulletData

    x: bulletData == null ? 0 : bulletData.x //TODO: check if bulletData is assigned
    y: bulletData == null ? 0 : bulletData.y

    visible: bulletData != null

    width: Props.bulletImageWidth
    height: Props.bulletImageHeight

    SpriteSequence {
        anchors.fill: root

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

    Connections {
        target: bulletData
        onHit: {
            root.destroy();
        }
    }
}
