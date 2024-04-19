import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: mainWindow

    property QtObject contactModel: null
    property string backgroundImage: ""
    property int  backgroundZPos: 0
    property int controlsZPos: 1
    property int controlsSpacing: 50

    visible: true
    flags: Qt.FramelessWindowHint

    Image {
        source: backgroundImage
        anchors.fill: parent
        z: backgroundZPos
    }
    WindowFrame {
        id: windowFrame
        title: mainWindow.title
        window: mainWindow
        z: controlsZPos
    }
    ColumnLayout {
        id: controlsLayout

        property int margin: 40

        y: windowFrame.height * 2
        x: margin / 2
        z: controlsZPos
        spacing: controlsSpacing

        height: mainWindow.height - windowFrame.height
        width: mainWindow.width - margin

        ContactsView {
            contactModel: contactModel
        }
    }

}
