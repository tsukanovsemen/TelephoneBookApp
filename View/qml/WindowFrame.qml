import QtQuick 2.15
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.12

Rectangle {
    id: windowFrame

    property string title: qsTr("Hello World")
    property int heightSize: 30
    property color windowFrameColor: "transparent"

    width: parent.width
    height: heightSize
    color: windowFrameColor

    Label {
        id: titleFrame

        text: windowFrame.title
        font.family: "Ubuntu"
        color: "white"

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
    Rectangle {
        id: closeButton

        width: windowFrame.heightSize
        height: windowFrame.heightSize
        x: windowFrame.width - closeButton.width
        y: windowFrame.y
        color: "transparent"

        Image {
            id: closeButtinImage

            source: "qrc:/images/close_button.svg"
            anchors.fill: parent
        }
        ColorOverlay {
            id: colorCloseButton

            anchors.fill: closeButtinImage
            source: closeButtinImage
            color: closeButtinMouseArea.containsMouse ? "lightpink" : "white";
        }
        MouseArea {
            id: closeButtinMouseArea

            anchors.fill: parent
            hoverEnabled: true

            onClicked: {
                mainWindow.close()
            }
        }
    }
}
