import QtQuick 2.0

SpriteSequence {
    id: root

    width: Props.tankImageSize
    height: Props.tankImageSize

    running: true
    sprites: [
        Sprite {
            name: "stillUp"
            frameCount: 1
            frameWidth: Props.tankIconSize
            frameHeight: Props.tankIconSize

            frameSync: true

            source: "qrc:/NES - Battle City JPN - General Sprites.png"
        },
        Sprite {
            name: "moveUp"
            frameCount: 2
            frameWidth: Props.tankIconSize
            frameHeight: Props.tankIconSize

            frameSync: true

            source: "qrc:/NES - Battle City JPN - General Sprites.png"
            to: {"stillUp": 1}
        },
        Sprite {
            name: "stillDown"
            frameCount: 1
            frameWidth: Props.tankIconSize
            frameHeight: Props.tankIconSize

            frameX: 4 * Props.tankIconSize

            frameSync: true

            source: "qrc:/NES - Battle City JPN - General Sprites.png"
        },
        Sprite {
            name: "moveDown"
            frameCount: 2
            frameWidth: Props.tankIconSize
            frameHeight: Props.tankIconSize

            frameX: 4 * Props.tankIconSize

            frameSync: true

            source: "qrc:/NES - Battle City JPN - General Sprites.png"
            to: {"stillDown": 1}
        },
        Sprite {
            name: "stillRight"
            frameCount: 1
            frameWidth: Props.tankIconSize
            frameHeight: Props.tankIconSize

            frameX: 6 * Props.tankIconSize

            frameSync: true

            source: "qrc:/NES - Battle City JPN - General Sprites.png"
        },
        Sprite {
            name: "moveRight"
            frameCount: 2
            frameWidth: Props.tankIconSize
            frameHeight: Props.tankIconSize

            frameX: 6 * Props.tankIconSize

            frameSync: true

            source: "qrc:/NES - Battle City JPN - General Sprites.png"
            to: {"stillRight": 1}
        },

        Sprite {
            name: "stillLeft"
            frameCount: 1
            frameWidth: Props.tankIconSize
            frameHeight: Props.tankIconSize

            frameX: 2 * Props.tankIconSize

            frameSync: true

            source: "qrc:/NES - Battle City JPN - General Sprites.png"
        },
        Sprite {
            name: "moveLeft"
            frameCount: 2
            frameWidth: Props.tankIconSize
            frameHeight: Props.tankIconSize

            frameX: 2 * Props.tankIconSize

            frameSync: true

            source: "qrc:/NES - Battle City JPN - General Sprites.png"
            to: {"stillLeft": 1}
        }
    ]
}
