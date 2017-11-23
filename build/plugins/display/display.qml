import QtQuick 2.3
import QtQuick.Controls 1.2


Rectangle {
    x: 0
    y: 0
    anchors.fill: parent
    color: "transparent"

    property int displayLength: 0
    property int displayChange: 0

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "#333333"
        border.width: 0

        Rectangle {
            x: 5
            y: 20
            width: 25
            height: parent.height / 2
            color: "#555555"

            Text {
                anchors.fill: parent
                text: "<"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 24
                font.bold: true
                color: "#ffffff"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                   if (displayChange > 0) {
                        displayChange--
                        displaText.text = displayChange.toString()
                   }
                }
            }
        }

        Rectangle {
            x: parent.width - 30
            y: 20
            width: 25
            height: parent.height / 2
            color: "#555555"

            Text {
                anchors.fill: parent
                text: ">"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 24
                font.bold: true
                color: "#ffffff"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (displayChange < displayLength) {
                        displayChange++
                        displaText.text = displayChange.toString()
                    }
                }
            }
        }

        Rectangle {
            x: 0
            y: 0
            width: parent.width - 90
            height: parent.height / 2
            anchors.top: parent.top
            anchors.topMargin: 20
            anchors.left: parent.left
            anchors.leftMargin: 45
            anchors.right: parent.right
            anchors.rightMargin: 45
            color: "#555555"

            Text {
                id: displaText
                anchors.fill: parent
                text: "0"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 92
                color: "#ffffff"
            }
        }

        Text {
            x: 160
            y: 210
            text: "Mudar"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 24
            color: "#ffffff"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    Context.libraryVoidLoad(displayChange, "", 'displayChange', libName)
                }
            }
        }
    }

    Component.onCompleted: {
        displayLength = Context.libraryIntLoad('displayLength', libName)

        if (displayLength > 0) {
            displayLength--
        }
    }
}
