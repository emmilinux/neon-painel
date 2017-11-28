import QtQuick 2.3
import QtQuick.Controls 1.2


ApplicationWindow {
    id: acessoRapido
    visible: false
    x: main.width - 249
    y: main.y - (310 + 5)
    width: 249
    height: 310
    title: qsTr("Access Speed")
    color: "transparent"
    flags: Qt.Tool | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint

    property var acessText: acessText
    property var acessItemsAdd: acessItemsAdd
    property var qmlShowPlugin: qmlShowPlugin
    property var tmpShowPlugin

    onActiveChanged: {

        if (!active) {

            acessItemsAdd.visible = true
            qmlShowPlugin.visible = false

            if (acessoRapido.tmpShowPlugin) {
                acessoRapido.tmpShowPlugin.destroy()
            }

            delete acessoRapido.tmpShowPlugin

            visible = false
        }
    }

    Rectangle {
        anchors.fill: parent
        opacity: main.opc
        color: main.cor

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            onExited: {
                acessoRapido.visible = false
            }
        }
    }

    Rectangle {
        x: 0
        y: 0
        width: parent.width
        height: 50
        color: "transparent"

        Text {
            id: acessText
            x: 8
            y: 8
            text: "Access Speed"
            width: (parent.width / 2) - x
            height: parent.height - y
            color: "#ffffff"
            font.pixelSize: 24
            font.bold: true

        }
/*
        Rectangle {
            width: 20
            height: 20
            radius: 10
            anchors.top: parent.top
            anchors.topMargin: 12
            anchors.right: parent.right
            anchors.rightMargin: 8
            color: "#ffffff"
        }*/

        Image {
            width: 20
            height: 20
            anchors.top: parent.top
            anchors.topMargin: 12
            anchors.right: parent.right
            anchors.rightMargin: 8
            source: "qrc:///Resources/conf.png"
        }
    }

    ScrollView {
        id: scrollItemsAdd
        x: 0
        y: 50
        width: parent.width
        height: parent.height - 50

        Item {
            id: acessItemsAdd
            x: 0
            y: 0
            width: parent.width
            height: 10
       }

   }

    Rectangle {
        id: qmlShowPlugin
        x: 0
        y: 0
        anchors.fill: parent
        color: "#333333"
        visible: false
        z: 3

        Text {
            id: pluginName
            x: 8
            y: 8
            text: "Access Speed"
            width: (parent.width / 2) - x
            height: parent.height - y
            color: "#ffffff"
            font.pixelSize: 24
            font.bold: true

        }

        Rectangle {
            id: pluginConfMore
            width: 20
            height: 20
            radius: 10
            anchors.top: parent.top
            anchors.topMargin: 12
            anchors.right: parent.right
            anchors.rightMargin: 8
            color: "#ffffff"
        }

        Item {
            id: importPluginShow
            x: 0
            y: 50
            width: parent.width
            height: parent.height - 50
        }
    }

   Component.onCompleted: {

       var btns = Context.plugins()
       var accessBtn = Qt.createComponent("btn.qml")
       var px = 0
       var py = 0

       for (var i = 0; i < btns.length; i++) {

           var items = btns[i].split(";")
           var obj = accessBtn.createObject(acessItemsAdd, {'x': px, 'y': py, 'btnName': items[0], 'iconName': items[1], 'qmlName': 'file://' + Context.basepath + '/plugins/' + items[2], 'libName': items[3]})

           px += 83

           if (px >= acessoRapido.width) {
               py += 83
               px = 0
           }

           if (i % 3 == 0) {
               acessItemsAdd.height += 83
           }
       }
   }
}
