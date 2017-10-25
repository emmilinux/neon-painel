import QtQuick 2.3
import QtQuick.Controls 1.2
import QtGraphicalEffects 1.0

ApplicationWindow {
    id: neonMenu
    visible: false
    x: 0
    y: 0
    width: 500
    height: 480
    title: qsTr("Neon Menu")
    color: "transparent"
    flags: Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint

    onActiveChanged: {
        if (!active) {
            //neonMenu.close()
            neonMenu.visible = false;
            main.clickOpc = main.startOpc
        }
    }

    Rectangle {
        id: rectangle1
        anchors.fill: parent
        opacity: opc
        color: cor
        //"#7310A2"
    }

    Rectangle {
        id: resize
        width: 15
        height: 15
        color: "#ffffff"
        opacity: 0.0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.SizeAllCursor

            property int startX: 0
            property int startY: 0

            /*
            onReleased: {
                neonMenu.width += mouseX
                neonMenu.height -= mouseY
                neonMenu.y += mouseY
            }
            */

            onPressed: {
                startX = mouseX - 15
                startY = mouseY
            }

            onMouseXChanged: {
                neonMenu.width = Context.mouseX() - startX
                neonMenu.y = Context.mouseY() - startY
                neonMenu.height = main.y - (neonMenu.y + 5)
            }
        }
    }

    Rectangle {
        id: rectangle
        height: 80
        color: "#000000"
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        opacity: 0.3
    }

    Rectangle {
        id: mask
        width: 64
        height: 64
        antialiasing: true
        anchors.left: parent.left
        anchors.leftMargin: 14
        anchors.top: parent.top
        anchors.topMargin: 6
        visible: false
        radius: 32
    }

    Image {
        id: image
        width: 64
        height: 64
        antialiasing: true
        anchors.left: parent.left
        anchors.leftMargin: 14
        anchors.top: parent.top
        anchors.topMargin: 6
        source: "file:///home/shenoisz/Documents/estudos/html5/NeonPanel/images/02.jpg"

        fillMode: Image.PreserveAspectCrop
        layer.enabled: true
        layer.effect: OpacityMask {
            maskSource: mask
        }
    }

    Rectangle {
        id: rectangle2
        x: 0
        y: 436
        height: 50
        color: "#000000"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.rightMargin: 0
        anchors.left: parent.left
        opacity: 0.3
        anchors.right: parent.right
        anchors.leftMargin: 0
    }

    Text {
        id: text1
        width: 149
        height: 14
        text: qsTr("SHENOISZ")
        anchors.left: parent.left
        anchors.leftMargin: 90
        anchors.top: parent.top
        anchors.topMargin: 33
        font.bold: true
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 14
        color: "#ffffff"
    }

    ScrollView {
        id: scrollview1
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 56
        anchors.top: parent.top
        anchors.topMargin: 86
        antialiasing: true
        highlightOnFocus: true
        frameVisible: false

        Item {
            id: item1
            height: 338
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
        }

    }
}
