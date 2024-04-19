import QtQuick 2.15
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.12

Rectangle {
    id: windowFrame

    property string title: qsTr("Hello World")
    property int heightSize: 30
    property color windowFrameColor: "transparent"
    property int zPosMouseAreaCloseButton: 1
    property int zPosMouseAreaWindowFrame: 0
    property ApplicationWindow window: null

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
        z: zPosMouseAreaCloseButton
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
            z: zPosMouseAreaCloseButton
            cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor

            onClicked: {
                window.close()
            }
        }
    }
    MouseArea {
        id: frameWindowMouseArea

        property point offset: Qt.point(0, 0)
        property bool move: false

        z: zPosMouseAreaWindowFrame
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor

        onPressed: {
            offset.x = mouseX
            offset.y = mouseY
            move = true
        }

        onMouseXChanged: {
            if (move)
                window.x += mouseX - offset.x
        }

        onMouseYChanged: {
            if(move)
                window.y += mouseY - offset.y
        }
        onReleased: {
            move = false
        }
    }
}
