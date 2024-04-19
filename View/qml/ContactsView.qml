import QtQuick 2.15
import QtQuick.Layouts 1.3

ListView {
    id: constactsView

    property QtObject contactModel: null
    property int listSpacing: 10

    Layout.fillWidth: true
    Layout.fillHeight: true

    spacing: listSpacing
    model: /*contactModel*/ 5
    delegate: ContactDelegate {
        email: contact.email
        phoneNumber: contact.telephoneNumber
    }
}