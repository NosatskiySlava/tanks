import QtQuick 2.0

import model.bullet 1.0
import CommonTypes 1.0


Rectangle {
    id: root

    anchors.fill: parent

    color: "#857F71"

    Rectangle {
        id: tanksField

        x: Props.tankImageSize
        y: Props.tankImageSize

        focus: true

        width: Props.fieldWidth
        height: Props.fieldHeight

        color: 'black'

        Keys.onPressed: {
            Input.executeCommand(event.key);
        }

        Player1 {
            id: player1

            x: TankPlayer1.x
            y: TankPlayer1.y
        }

        Connections  {
             target: TankPlayer1
             onMovedLeft: player1.jumpTo("moveLeft");
             onMovedRight: player1.jumpTo("moveRight");
             onMovedUp: player1.jumpTo("moveUp");
             onMovedDown: player1.jumpTo("moveDown");
         }

        Connections {
            target: TanksField
            onBulletAdded: {
                var component = Qt.createComponent("Bullet.qml");
                var bulletImage = component.createObject(tanksField, {"bulletData": bullet, "rotation": bullet.dir == Direction.DOWN  ? 180 :
                                                                                                                 bullet.dir == Direction.LEFT  ? -90 :
                                                                                                                 bullet.dir == Direction.RIGHT ? 90  :
                                                                                                                 0});
                if (bulletImage == null) {
                    console.log("Error creating bullet");
                }
            }
        }
    }
}

