import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

RowLayout {
    id: contactDelegate

    property string name: "name"
    property string surname: "surname"
    property string email: "email"
    property string phoneNumber: "+7(...) ... .. .."
    property int textSize: 14

    height: 60
    width: parent.width
    spacing: 10

    Repeater {
        model: 4
        TextArea {
            id: textDelegate
            text: {
                switch(index) {
                    case 0: return name
                    case 1: return surname
                    case 2: return email
                    case 3: return phoneNumber
                }
            }
            color: "black"
            font.pixelSize: textSize
            font.family: "Ubuntu"
            selectByMouse: true
            readOnly: true
            selectionColor: "#ced2d9"
        }
    }
}
