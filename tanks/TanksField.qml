import QtQuick 2.0

import tanks.model.tank 1.0
import tanks.model.tanksfield 1.0

Rectangle {
    id: root
    focus: true

    Keys.onUpPressed: moveUp()
    Keys.onDownPressed: moveDown()
    Keys.onLeftPressed: moveLeft()
    Keys.onRightPressed: moveRight()

    function moveUp() {
        image.jumpTo("moveUp");
        image.y -= 1;
    }

    function moveDown() {
        image.jumpTo("moveDown");
        image.y += 1;
    }

    function moveLeft() {
        image.jumpTo("moveLeft");
        image.x -= 1;
    }

    function moveRight() {
        image.jumpTo("moveRight");
        image.x += 1;
    }

    width: 32 * 13
    height: 32 * 13

    color: 'black'

    Tank {
        id: tank
    }

    SpriteSequence {
        id: image

        width: 32
        height: 32

        x: 16
        y: 200

        running: true
        sprites: [
            Sprite {
                name: "stillUp"
                frameCount: 1
                frameWidth: 16
                frameHeight: 16

                frameSync: true

                source: "qrc:/NES - Battle City JPN - General Sprites.png"
            },
            Sprite {
                name: "moveUp"
                frameCount: 2
                frameWidth: 16
                frameHeight: 16

                frameSync: true

                source: "qrc:/NES - Battle City JPN - General Sprites.png"
                to: {"stillUp": 1}
            },
            Sprite {
                name: "stillDown"
                frameCount: 1
                frameWidth: 16
                frameHeight: 16

                frameX: 4 * 16

                frameSync: true

                source: "qrc:/NES - Battle City JPN - General Sprites.png"
            },
            Sprite {
                name: "moveDown"
                frameCount: 2
                frameWidth: 16
                frameHeight: 16

                frameX: 4 * 16

                frameSync: true

                source: "qrc:/NES - Battle City JPN - General Sprites.png"
                to: {"stillDown": 1}
            },
            Sprite {
                name: "stillRight"
                frameCount: 1
                frameWidth: 16
                frameHeight: 16

                frameX: 6 * 16

                frameSync: true

                source: "qrc:/NES - Battle City JPN - General Sprites.png"
            },
            Sprite {
                name: "moveRight"
                frameCount: 2
                frameWidth: 16
                frameHeight: 16

                frameX: 6 * 16

                frameSync: true

                source: "qrc:/NES - Battle City JPN - General Sprites.png"
                to: {"stillRight": 1}
            },

            Sprite {
                name: "stillLeft"
                frameCount: 1
                frameWidth: 16
                frameHeight: 16

                frameX: 2 * 16

                frameSync: true

                source: "qrc:/NES - Battle City JPN - General Sprites.png"
            },
            Sprite {
                name: "moveLeft"
                frameCount: 2
                frameWidth: 16
                frameHeight: 16

                frameX: 2 * 16

                frameSync: true

                source: "qrc:/NES - Battle City JPN - General Sprites.png"
                to: {"stillLeft": 1}
            }
        ]
    }
}

