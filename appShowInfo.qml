import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {

    id: showInfos
    x: 10
    y: 10
    width: 100
    height: 30
    color: "transparent"
    visible: false
    flags: Qt.Tool | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint

    property string appNameText: ""


    onActiveChanged: {
        if (!active) {
            //neonMenu.close()
            visible = false
        }
    }

    Rectangle {
        anchors.fill: parent
        color: "#000000"
        opacity: 0.5
    }

    Text {
        anchors.fill: parent
        text: appNameText
        font.pointSize: 10
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        color: "#ffffff"
    }
}
