import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    id: root

    visible: true

    width: 32 * 16
    height: 32 * 15

   // flags: Qt.MSWindowsFixedSizeDialogHint

    GameField {
        id: gameField
    }
}

