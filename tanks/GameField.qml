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

        Keys.onUpPressed: moveUp()
        Keys.onDownPressed: moveDown()
        Keys.onLeftPressed: moveLeft()
        Keys.onRightPressed: moveRight()

        function moveUp() {
            player1.jumpTo("moveUp");
            player1.y -= 1;
        }

        function moveDown() {
            player1.jumpTo("moveDown");
            player1.y += 1;
        }

        function moveLeft() {
            player1.jumpTo("moveLeft");
            player1.x -= 1;
        }

        function moveRight() {
            player1.jumpTo("moveRight");
            player1.x += 1;
        }

        Player1 {
            id: player1

            x: 16
            y: 200
        }
    }
}

