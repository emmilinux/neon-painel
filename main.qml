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
    property alias rectangle10: rectangle10
    flags: Qt.Tool | Qt.FramelessWindowHint | Qt.WindowDoesNotAcceptFocus

    property var neonMenu: Object
    // yellow #FFFB00, purple "#7310A2", crimson #dc143c, black "#333333", blue "#007fff", red #FF0D00, orange #ff9900, green #00ff00
    property string cor: "#000000"
    property string detailColor: "#7310A2"
    property double opc: 0.65
    property double clickOpc: 0.0
    property double startOpc: 0.0
    property int mainId: 0

    property var showAppInfo: Object
    property var acessoRapido: Object

    property int launcherX: 0
    property var launcher: []

    property int subLauncherX: 0
    property int subLauncherX2: 0
    property var subLauncher: []
    property bool subLauncherStarted: true
    property bool windowVerify: false

    signal desktopWindow(string _nome, string wmclass, int winId)
    signal clearWindows

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
                subLauncherX2 = 0
            } else {
                subLauncherX = 0
                subLauncherX2 = 0
            }
        }
    }

    onClearWindows: {

        for (var i = 0; i < subLauncher.length; i++) {
            subLauncher[i].destroy()
        }

        subLauncher = []
        subLauncherStarted = true
        separatorBar.visible = false
        windowVerify = false

        if (launcher.length > 0) {
            subLauncherX = 10
            subLauncherX2 = 0
        } else {
            subLauncherX = 0
            subLauncherX2 = 0
        }
    }

    onDesktopWindow: {

        clearWindow()

        var fixicede = false
        subAppbar.width = 50

        for (var j = 0; j < launcher.length; j++) {
            if (launcher[j].pidname === wmclass) {
                fixicede = true
            }
        }

        for (var t = 0; t < subLauncher.length; t++) {
            if (subLauncher[t].pidname === wmclass) {
                fixicede = true
            }
            subAppbar.width += 50
        }

        if (_nome !== "" && !fixicede) {

            if (subLauncherStarted) {

                if (launcher.length > 0) {
                    subLauncherX = 10
                    subLauncherX2 = 0
                } else {
                    subLauncherX = 0
                    subLauncherX2 = 0
                }

                subLauncherStarted = false
            }

            var compon = Qt.createComponent("launchers/Applications.qml")
            var obj;

            if (subAppbar.x + subLauncherX + 50 < plugins.x) {
                btnShowMore.visible = false
                obj = compon.createObject(subAppbar, {'x': subLauncherX, 'y': 0, 'nome': _nome, 'pidname': wmclass, 'winId': winId})
                subLauncherX += 50

                if (!btnShowMore.moreArea) {
                    btnShowMore.moreArea = true
                    verticaline.height -= 40
                    btnShowMore.rotation = 0
                    main.y += 40
                    main.height -= 40
                    accessSpeed.y = 0
                    Context.showMoreWindows(mainId, 40)
                }

            } else {
                btnShowMore.visible = true
                obj = compon.createObject(subAppbar2, {'x': subLauncherX2, 'y': 0, 'nome': _nome, 'pidname': wmclass, 'winId': winId})
                subLauncherX2 += 50
            }


            subLauncher.push(obj)
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

            if (applicationBar.x + applicationBar.width + 200 <  plugins.x) {

                var files = drop.urls.toString().split(',');

                for (var i = 0; i <  files.length; i++) {

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
            }

            drop.acceptProposedAction()
        }

    }

    MouseArea {
        id: mouseMain
        anchors.fill: parent
        onClicked: {
            clickOpc = startOpc
            neonMenu.visible = false
            neonMenu.textSearch.focus = false
            //neonMenu.addApps()
            showAppInfo.visible = false
            acessoRapido.visible = false
        }
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

                    acessoRapido.visible = false

                    showAppInfo.visible = false
                    neonMenu.x = 0;
                    neonMenu.y = main.y - (neonMenu.height + 5)

                    neonMenu.textSearch.text = ""
                    neonMenu.textSearch.focus = true
                    neonMenu.addApps()

                    if (!neonMenu.visible) {
                        neonMenu.visible = true
                        clickOpc = 0.50
                    } else {
                        clickOpc = startOpc
                        neonMenu.visible = false
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
            x: 42
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

        Item {
           id: subAppbar2
           y: 40
           x: 0
           width: plugins.x
           height: 40

           Rectangle {
               y: 1
               x: 0
               width: plugins.x
               height: 1
               color: "#ffffff"
               opacity: 0.1
           }

           Rectangle {
              id: separatorBar2
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
            x: parent.width - 110
            y: 0
            height: parent.height
            width: 110
            color: "transparent"

            Rectangle {
                id: verticaline
                x: 0
                y: 0
                height: 40
                width: 20
                color: "transparent"

                Image {
                    id: btnShowMore
                    y: (parent.height / 2) - (height / 2)
                    height: 20
                    width: 20
                    source: "file://" + Context.basepath + '/icon-down.png'
                    rotation: 0
                    visible: true

                    property bool moreArea: true

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {

                            acessoRapido.visible = false

                            if (parent.moreArea) {

                                main.y -= 40
                                btnShowMore.moreArea = false
                                verticaline.height += 40
                                btnShowMore.rotation = 180
                                main.height += 40
                                accessSpeed.y = 19
                                Context.showMoreWindows(mainId, 80)

                            } else {

                                btnShowMore.moreArea = true
                                verticaline.height -= 40
                                btnShowMore.rotation = 0
                                main.y += 40
                                main.height -= 40
                                accessSpeed.y = 0
                                Context.showMoreWindows(mainId, 40)
                            }

                            y = (parent.height / 2) - (height / 2)
                        }
                    }
                }
            }

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
                anchors.rightMargin: 35
                font.pointSize: 12
                color: "#ffffff"

                Timer {
                    interval: 100
                    running: true
                    repeat: true
                    onTriggered: {
                        var d = Utils.getTime().split('|')
                        clock.text = d[0]
                        acessoRapido.acessText.text = d[1]
                    }
               }
            }

            Rectangle {
                id: accessSpeed
                x: 0
                y: 0
                width: 15
                height: 40
                color: "transparent"
                anchors.right: parent.right
                anchors.rightMargin: 10

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true

                    onHoveredChanged: {
                        neonMenu.visible = false
                        acessoRapido.visible = true
                    }

                    Rectangle {
                        y: 15
                        width: parent.width
                        height: 2
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        color: "#ffffff"
                    }

                    Rectangle {
                        id: rectangle10
                        y: 20
                        width: parent.width
                        height: 2
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        color: "#ffffff"
                    }

                    Rectangle {
                        y: 25
                        width: parent.width
                        height: 2
                        anchors.right: parent.right
                        anchors.rightMargin: 0
                        anchors.left: parent.left
                        anchors.leftMargin: 0
                        color: "#ffffff"
                    }
                }
            }
        }
    }

    Component.onCompleted: {

        var component_ = Qt.createComponent("qrc:/plugins/NeonMenu.qml")
        neonMenu = component_.createObject(main)
        neonMenu.visible = false

        var info = Qt.createComponent("qrc:/launchers/appShowInfo.qml")
        showAppInfo = info.createObject(applicationBar)
        showAppInfo.visible = false

        var access = Qt.createComponent("qrc:/plugins/Access.qml")
        acessoRapido = access.createObject(main)

        Context.changeThemeColor(main.detailColor)
        main.visible = true

        //Context.libraryVoidLoad("write")
        //Context.libraryVoidLoad(17, "shenoisz", "showMsg")
    }
}
