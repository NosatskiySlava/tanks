import QtQuick 2.0

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

        Bullet {
            x: 160
            y: 100
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
            onBulletAdded: console.log("Cha Cha cha");
        }
    }
}

