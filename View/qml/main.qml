import QtQuick 2.15
import QtQuick.Controls 2.0

ApplicationWindow {
    id: mainWindow

    property QtObject contactModel: null
    property string backgroundImage: ""
    property int  backgroundZPos: 0
    property int controlsZPos: 1

    visible: true
    flags: Qt.FramelessWindowHint

    WindowFrame {
        title: mainWindow.title
        window: mainWindow
        z: controlsZPos
    }
    Image {
        source: backgroundImage
        anchors.fill: parent
        z: backgroundZPos
    }
}
