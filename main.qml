import QtQuick 2.3
import QtQuick.Controls 1.2

import "utils.js" as Utils


ApplicationWindow {
    id: main
    visible: true
    x: 0
    y: 0
    width: 1000
    height: 40
    title: qsTr("Neon Painel")
    color: "transparent"
    property alias clockFontbold: clock.font.bold
    flags: Qt.DockWidgetArea_Mask | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint | Qt.NoFocus

    property var neonMenu: Object
    property string cor: "#333333" //"#00ff00" //"#ff0000" //"#7310A2" //"#ff9900"
    property double opc: 0.75
    property double clickOpc: 0.0
    property double startOpc: 0.0
    property int mainId: 0

    property int launcherX: 0
    property var launcher: []
    property int appId: 0

    MouseArea {
        anchors.fill: parent
        onClicked: {
            neonMenu.visible = false
            clickOpc = startOpc
        }
    }

    function menuShow() {
        var component_ = Qt.createComponent("plugins/NeonMenu.qml")
        neonMenu = component_.createObject(main)
        neonMenu.visible = false
    }

    Rectangle {
        anchors.fill: parent
        opacity: opc
        color: cor
    }

    Rectangle {
        anchors.fill: parent
        color: "transparent"

        Rectangle {
            id: bottomBar
            x: 0
            y: parent.height - 2
            height: 2
            width: parent.width
            color: "#000000"
        }

        Rectangle {
            id: btnMenuSub
            x: 2
            y: 4
            width: 34
            height: 32
            color: "#000000"
            opacity: clickOpc
            radius: 0
            border.width: 0
        }

        Rectangle {
            id: btnMenu
            x: 2
            y: 4
            width: 32
            height: 32
            color: "transparent"

            MouseArea {
                id: mouseArea
                anchors.bottomMargin: 0
                anchors.leftMargin: 1
                anchors.topMargin: 0
                anchors.rightMargin: -1
                anchors.fill: parent

                onClicked: {

                    neonMenu.x = 0;
                    neonMenu.y = main.y - (neonMenu.height + 5)

                    if (!neonMenu.visible) {
                        neonMenu.visible = true
                        clickOpc = 0.50
                    } else {
                        clickOpc = startOpc
                        neonMenu.visible = false
                    }

                }

                Rectangle {
                    id: rectangle
                    x: 1
                    y: 14
                    width: 4
                    height: 4
                    color: "#ffffff"
                    radius: 0
                    anchors.right: parent.right
                    anchors.rightMargin: 21
                    anchors.left: parent.left
                    anchors.leftMargin: 6
                    border.width: 0
                }

                Rectangle {
                    id: rectangle1
                    y: 21
                    width: 4
                    height: 4
                    color: "#ffffff"
                    radius: 0
                    anchors.right: parent.right
                    anchors.rightMargin: 21
                    anchors.left: parent.left
                    anchors.leftMargin: 6
                    border.width: 0
                }

                Rectangle {
                    id: rectangle2
                    y: 14
                    width: 4
                    height: 4
                    color: "#ffffff"
                    radius: 0
                    anchors.right: parent.right
                    anchors.rightMargin: 6
                    anchors.left: parent.left
                    anchors.leftMargin: 22
                    border.width: 0
                }

                Rectangle {
                    id: rectangle3
                    x: -2
                    y: 21
                    width: 4
                    height: 4
                    color: "#ffffff"
                    radius: 0
                    anchors.leftMargin: 22
                    anchors.rightMargin: 6
                    anchors.right: parent.right
                    border.width: 0
                    anchors.left: parent.left
                }

                Rectangle {
                    id: rectangle4
                    x: 8
                    y: 14
                    width: 4
                    height: 4
                    color: "#ffffff"
                    radius: 0
                    anchors.leftMargin: 14
                    anchors.rightMargin: 13
                    anchors.right: parent.right
                    border.width: 0
                    anchors.left: parent.left
                }

                Rectangle {
                    id: rectangle5
                    x: 9
                    y: 21
                    width: 4
                    height: 4
                    color: "#ffffff"
                    radius: 0
                    anchors.leftMargin: 14
                    anchors.rightMargin: 13
                    anchors.right: parent.right
                    border.width: 0
                    anchors.left: parent.left
                }

                Rectangle {
                    id: rectangle6
                    x: 6
                    y: 7
                    width: 4
                    height: 4
                    color: "#ffffff"
                    radius: 0
                    anchors.leftMargin: 6
                    anchors.rightMargin: 21
                    anchors.right: parent.right
                    border.width: 0
                    anchors.left: parent.left
                }

                Rectangle {
                    id: rectangle7
                    x: 5
                    y: 7
                    width: 4
                    height: 4
                    color: "#ffffff"
                    radius: 0
                    anchors.leftMargin: 22
                    anchors.rightMargin: 6
                    anchors.right: parent.right
                    border.width: 0
                    anchors.left: parent.left
                }

                Rectangle {
                    id: rectangle8
                    x: 5
                    y: 7
                    width: 4
                    height: 4
                    color: "#ffffff"
                    radius: 0
                    anchors.leftMargin: 14
                    anchors.rightMargin: 13
                    anchors.right: parent.right
                    border.width: 0
                    anchors.left: parent.left
                }
            }
        }

        Item {
            id: item1
            x: 52
            y: 0
            z: 9
            width: 800
            height: 40

            DropArea {
                id: drop
                anchors.fill: parent
                enabled: true

                onEntered: {
                    //console.log("entered")
                }

                onExited: {
                    //console.log("exited")
                }

                onDropped: {

                    var files = drop.urls.toString().split(',');

                    for (var i = 0; i <  files.length; i++) {
                        //console.log("item", files[i])
                        var list = Context.addLauncher(files[i])

                        if (list[0] !== "") {

                            var component = Qt.createComponent("launchers/Application.qml")
                            var obj = component.createObject(parent, {'x': launcherX, 'y': 0, 'url': list[1], 'nome': list[0], 'exec': list[2], 'pidname': list[3]})

                            launcherX += 50
                            launcher.push(obj)
                        }

                    }

                    drop.acceptProposedAction()
                }

            }
        }

        Rectangle {
            id: plugins
            x: parent.width - 150
            y: 0
            height: parent.height
            width: 150
            color: "transparent"

            Text {
                id: clock
                x: 102
                text: Utils.getTime()
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 11
                anchors.top: parent.top
                anchors.topMargin: 12
                anchors.right: parent.right
                anchors.rightMargin: 8
                font.pointSize: 12
                color: "#ffffff"

                Timer {
                    interval: 100; running: true; repeat: true;
                    onTriggered: clock.text = Utils.getTime()
               }

            }
        }
    }

    Component.onCompleted: {
        main.menuShow()
        Context.changeThemeColor(main.cor)
    }

}
