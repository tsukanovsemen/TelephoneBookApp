import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.12

Rectangle {
    id: bottomMenuContorl

    Layout.fillWidth: true
    height: 120
    color: "transparent"

    RowLayout {
        id: controlsLayout
        Layout.fillHeight: true
        Layout.fillWidth: true

        property int borderSize: 3
        property int radiusButton: 5
        property int widthButton: 50
        property int heightButton: 50

        Rectangle {
            id: addButton

            radius: controlsLayout.radiusButton
            height: controlsLayout.heightButton
            width: controlsLayout.widthButton
            color: "transparent"
            border.color: addButtonMouseArea.containsMouse ? "green" : "white"
            border.width: controlsLayout.borderSize

            Image {
                id: imageAddButton
                source: "qrc:/images/add_contact.svg"
                anchors.fill: parent
            }
            ColorOverlay {
                id: colorAddButton

                anchors.fill: imageAddButton
                source: imageAddButton
                color: addButtonMouseArea.containsMouse ? "green" : "white"
            }

            MouseArea {
                id: addButtonMouseArea

                anchors.fill: parent
                hoverEnabled: true
            }
        }

        Rectangle {
            id: addButton3

            radius: controlsLayout.radiusButton
            height: controlsLayout.heightButton
            width: controlsLayout.widthButton
            color: "transparent"
            border.color: addButtonMouseArea3.containsMouse ? "green" : "white"
            border.width: controlsLayout.borderSize

            Image {
                id: imageAddButton3
                source: "qrc:/images/add_contact.svg"
                anchors.fill: parent
            }
            ColorOverlay {
                id: colorAddButton3

                anchors.fill: imageAddButton
                source: imageAddButton
                color: addButtonMouseArea3.containsMouse ? "green" : "white"
            }

            MouseArea {
                id: addButtonMouseArea3

                anchors.fill: parent
                hoverEnabled: true
            }
        }

        Rectangle {
            id: addButton2

            radius: controlsLayout.radiusButton
            height: controlsLayout.heightButton
            width: controlsLayout.widthButton
            color: "transparent"
            border.color: addButtonMouseArea2.containsMouse ? "green" : "white"
            border.width: controlsLayout.borderSize

            Image {
                id: imageAddButton2
                source: "qrc:/images/add_contact.svg"
                anchors.fill: parent
            }
            ColorOverlay {
                id: colorAddButton2

                anchors.fill: imageAddButton
                source: imageAddButton
                color: addButtonMouseArea2.containsMouse ? "green" : "white"
            }

            MouseArea {
                id: addButtonMouseArea2

                anchors.fill: parent
                hoverEnabled: true
            }
        }
    }
}
