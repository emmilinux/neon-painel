import QtQuick 2.3
import QtQuick.Controls 1.2

import "utils.js" as Utils


ApplicationWindow {
    id: main
    visible: false
    x: 0
    y: 0
    width: 1000
    height: 40
    title: qsTr("Neon Painel")
    color: "transparent"
    flags: Qt.Tool | Qt.FramelessWindowHint | Qt.WindowDoesNotAcceptFocus

    property var neonMenu: Object
    // yellow #FFFB00, purple "#7310A2", crimson #dc143c, black "#333333", blue "#007fff", red #FF0D00, orange #ff9900, green #00ff00
    property string cor: "#7310A2"
    property double opc: 0.75
    property double clickOpc: 0.0
    property double startOpc: 0.0
    property int mainId: 0

    property int launcherX: 0
    property var launcher: []
    property int appId: 0

    property int subLauncherX: 0
    property var subLauncher: []
    property bool subLauncherStarted: true
    property bool windowVerify: false
    property int subWindowPid: 0
    property string subWindowLauncher: ""

    signal desktopWindow(int isLaucher, string nitems, string desktopFile, string wmclass)

    function clearWindow() {

        if (windowVerify) {

            for (var i = 0; i < subLauncher.length; i++) {
                subLauncher[i].destroy()
            }

            subLauncher = []
            subLauncherStarted = true
            separatorBar.visible = false
            windowVerify = false

            if (launcher.length > 0) {
                subLauncherX = 10
            } else {
                subLauncherX = 0
            }
        }
    }

    onDesktopWindow: {

        clearWindow()

        var list = []

        if (isLaucher) {
            list = Context.addLauncher(desktopFile)
        } else {
            list = nitems.split(';')
        }

        var fixicede = false
        list[3] = wmclass

        for(var i = 0; i < launcher.length; i++) {
            if (launcher[i].pidname === list[3]) fixicede = true
        }

        if (list[0] !== "" && !fixicede) {

            if (subLauncherStarted) {

                if (launcher.length > 0) {
                    subLauncherX = 10
                } else {
                    subLauncherX = 0
                }

                subLauncherStarted = false
            }

            var compon = Qt.createComponent("launchers/Application.qml")
            var obj = compon.createObject(subAppbar, {'x': subLauncherX, 'y': 0, 'url': list[1], 'nome': list[0], 'exec': list[2], 'pidname': list[3], '_instance': true})

            subLauncherX += 50
            subLauncher.push(obj)
            subAppbar.width += 50
            obj.destak.visible = true
            if (launcher.length > 0) separatorBar.visible = true
        }
    }

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
                    var obj = component.createObject(applicationBar, {'x': launcherX, 'y': 0, 'url': list[1], 'nome': list[0], 'exec': list[2], 'pidname': list[3]})

                    launcherX += 50
                    launcher.push(obj)
                    applicationBar.width += 50
                    subAppbar.x = applicationBar.x + applicationBar.width
                }

            }

            drop.acceptProposedAction()
        }

    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            clickOpc = startOpc
            neonMenu.visible = false
            neonMenu.textSearch.focus = false
            neonMenu.addApps()
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
/*
        Rectangle {
            id: bottomBar
            x: 0
            y: parent.height - 1.5
            height: 1.5
            width: parent.width
            color: "#000000"
            opacity: 0.7
        }
*/
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
                        neonMenu.textSearch.focus = false
                        neonMenu.addApps()
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
            id: applicationBar
            x: 52
            y: 0
            z: 9
            width: 0
            height: 40    
        }

        Item {
           id: subAppbar
           x: applicationBar.x + applicationBar.width
           width: 3
           height: 40

           Rectangle {
              id: separatorBar
              x: 0
              y: 5
              width: 1
              height: 30
              color: "#ffffff"
              opacity: 0.3
              visible: false
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
                    interval: 100
                    running: true
                    repeat: true
                    onTriggered: clock.text = Utils.getTime()
               }
            }
        }
    }

    Component.onCompleted: {
        main.menuShow()
        Context.changeThemeColor(main.cor)
        main.visible = true
    }
}
