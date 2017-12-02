import QtQuick 2.3
import QtQuick.Controls 1.2
import QtGraphicalEffects 1.0


Rectangle {
    x: 0
    y: 0
    width: 83
    height: 83
    color: "transparent"

    property string btnName: ''
    property string qmlName: ''
    property string libName: ''
    property string iconName: ''

    MouseArea {

        anchors.fill: parent

        onClicked: {
            acessItemsAdd.visible = false
            qmlShowPlugin.visible = true
            pluginName.text = btnName
            Qt.createComponent(qmlName).createObject(importPluginShow)
        }

    }

        Rectangle {
            width: 26
            height: 26
            radius: 26
            anchors.fill: parent
            anchors.margins: 14
            color: detailColor
        }

        Rectangle {
            id: pluginMask
            width: 24
            height: 24
            radius: 24
            anchors.fill: parent
            anchors.margins: 16
            color: "#ffffff"
        }

        Image {
            width: 24
            height: 24
            anchors.fill: parent
            anchors.margins: 16
            source: "file://" + Context.basepath + "/plugins/" + iconName

            fillMode: Image.PreserveAspectCrop
            layer.enabled: true
            layer.effect: OpacityMask {
                maskSource: pluginMask
            }
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

