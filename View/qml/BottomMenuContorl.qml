import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.12

Rectangle {
    id: bottomMenuContorl

    Layout.fillWidth: true
    height: 100
    color: "#ced2d9"
    layer.enabled: true
    layer.effect: DropShadow {
                    transparentBorder: true
                    verticalOffset: -3
                    color: "#80000000"
                    radius: 8.0
                    samples: 17
                }

    signal addButtonClicked()

    RowLayout {
        id: controlsLayout
        anchors.fill: parent

        property int borderSize: 3
        property int radiusButton: 10
        property int widthButton: 50
        property int heightButton: 50

        Rectangle {
            id: addButton

            property color hoveredColor: "#8ebf99"

            radius: controlsLayout.radiusButton
            height: controlsLayout.heightButton
            width: controlsLayout.widthButton
            color: "transparent"
            border.color: addButtonMouseArea.containsMouse ? hoveredColor : "white"
            border.width: controlsLayout.borderSize
            Layout.leftMargin: 55

            Image {
                id: imageAddButton
                source: "qrc:/images/add_contact.svg"
                anchors.fill: parent
            }
            ColorOverlay {
                id: colorAddButton

                anchors.fill: imageAddButton
                source: imageAddButton
                color: addButtonMouseArea.containsMouse ? addButton.hoveredColor : "white"
            }

            MouseArea {
                id: addButtonMouseArea

                anchors.fill: parent
                hoverEnabled: true
                cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
                onClicked: addButtonClicked()
            }
        }
        Rectangle {
            id: editButton

            property color hoveredColor: "#8e918f"

            radius: controlsLayout.radiusButton
            height: controlsLayout.heightButton
            width: controlsLayout.widthButton
            color: "transparent"
            border.color: editButtonMouseArea.containsMouse ? hoveredColor : "white"
            border.width: controlsLayout.borderSize
            Layout.leftMargin: 55

            Image {
                id: imageEditButton
                source: "qrc:/images/edit_contact.svg"
                anchors.fill: parent

                ColorOverlay {
                    id: colorEditButton

                    anchors.fill: parent
                    source: imageEditButton
                    color: editButtonMouseArea.containsMouse ? editButton.hoveredColor : "white"
                }
            }
            MouseArea {
                id: editButtonMouseArea

                anchors.fill: parent
                hoverEnabled: true
                cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
            }
        }
        Rectangle {
            id: deleteButton

            property color hoveredColor: "red"

            radius: controlsLayout.radiusButton
            height: controlsLayout.heightButton
            width: controlsLayout.widthButton
            color: "transparent"
            border.color: deleteButtonMouseArea.containsMouse ? hoveredColor : "white"
            border.width: controlsLayout.borderSize
            Layout.leftMargin: 55

            Image {
                id: imageDeleteButton
                source: "qrc:/images/delete_contact.svg"
                anchors.fill: parent

                ColorOverlay {
                    id: colorDeleteButton

                    anchors.fill: parent
                    source: imageDeleteButton
                    color: deleteButtonMouseArea.containsMouse ? deleteButton.hoveredColor : "white"
                }
            }
            MouseArea {
                id: deleteButtonMouseArea

                anchors.fill: parent
                hoverEnabled: true
                cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
            }
        }
    }
}
