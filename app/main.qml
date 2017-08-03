import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    id: root

    visible: true

    width: Props.tankImageSize * 16
    height: Props.tankImageSize * 15

   // flags: Qt.MSWindowsFixedSizeDialogHint

    GameField {
        id: gameField
    }
}

