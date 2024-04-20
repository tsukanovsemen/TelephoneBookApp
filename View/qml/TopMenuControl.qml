import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

Rectangle {
    id: topMenuControl

    color: "#e1e6ed"
    property int controlsHeight: 0.6 * topMenuControl.height

    RowLayout {
        anchors.fill: parent
        spacing: 20

        Rectangle {
            id: searchTextInput

            property int textSize: 14

            height: topMenuControl.controlsHeight
            width: topMenuControl.width * 0.25
            color: "white"
            Layout.leftMargin: 0.3 * topMenuControl.height

            TextInput {
                height: parent.height

                anchors.fill: parent
                color: "black"
                selectByMouse: true
                selectionColor: "#ced2d9"
                font.pixelSize: searchTextInput.textSize
            }
        }
        ComboBox {
            implicitHeight: topMenuControl.controlsHeight
            implicitWidth: topMenuControl.width * 0.25
        }
    }
}
