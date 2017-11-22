import QtQuick 2.3
import QtQuick.Controls 1.2


Rectangle {
    x: 0
    y: 0
    width: 83
    height: 83
    color: "transparent"

    property string btnName: ''
    property string qmlName: ''
    property string libName: ''

    MouseArea {

        anchors.fill: parent

        onClicked: {

            acessItemsAdd.visible = false
            qmlShowPlugin.visible = true
            pluginName.text = btnName

            acessoRapido.btnObj = Qt.createComponent(qmlName).createObject(importPluginShow)
        }

    }

        Rectangle {
            width: 24
            height: 24
            radius: 24
            anchors.fill: parent
            anchors.margins: 16
            color: "#ffffff"
        }

        Text {
            text: btnName
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: -5
            font.pixelSize: 12
            color: "#ffffff"
        }
}

