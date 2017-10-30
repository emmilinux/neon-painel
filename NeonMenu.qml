import QtQuick 2.3
import QtQuick.Controls 1.2
import QtGraphicalEffects 1.0

ApplicationWindow {
    id: neonMenu
    visible: false
    x: 0
    y: 0
    width: 530
    height: 530
    title: qsTr("Neon Menu")
    color: "transparent"
    flags: Qt.Tool | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint

    property var menuElements: []
    property var textSearch: textSearch


    function addApps() {

        var x = 0
        var y = 0

        for (var i = 0; i < menuElements.length; i++) {

            menuElements[i].x = x
            menuElements[i].y = y

            x += 74

            if (x + 74 >= neonMenu.width) {
                x = 0
                y += 78
            }

            menuElements[i].visible = true
        }

        launchersApps.height = y;
    }


    onActiveChanged: {
        if (!active) {
            //neonMenu.close()
            neonMenu.visible = false;
            main.clickOpc = main.startOpc
            textSearch.focus = false
            addApps()
        }
    }

    MouseArea {
        id: mouseMenu
        anchors.fill: parent

        onClicked: {
            textSearch.focus = false
        }
    }

    Rectangle {
        id: menuTop
        anchors.fill: parent
        opacity: opc
        color: cor
        //"#7310A2"
    }

    Rectangle {
        id: resize
        x: 470
        width: 18
        height: 18
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
            property bool btnUp: true

            /*
            onReleased: {
                neonMenu.width += mouseX
                neonMenu.height -= mouseY
                neonMenu.y += mouseY
            }
            */

            onPressedChanged: {
                if (btnUp) {

                    btnUp = false
                    startX = mouseX - 18
                    startY = mouseY

                } else {

                    btnUp = true
                    addApps()
                }
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

        Rectangle {
            id: search
            color: "#ffffff"
            anchors.right: parent.right
            anchors.rightMargin: 15
            anchors.left: parent.left
            anchors.leftMargin: 15
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 12
            anchors.top: parent.top
            anchors.topMargin: 12
            opacity: 0.1
        }
    }

    TextInput {
        id: textSearch
        x: 0
        y: 410
        height: 30
        color: "#ffffff"
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 12
        text: "Buscar..."
        antialiasing: true
        //cursorVisible: true
        font.bold: false
        font.pointSize: 12
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        selectionColor: "#007fff"
        selectByMouse: true
        wrapMode: TextEdit.Wrap

        property bool ativo: true

        onFocusChanged: {

            if (ativo)  {
                ativo = false
                text = ""
            } else {
                ativo = true
                text = "Buscar..."
            }
        }

        Keys.onReleased: {

            var x = 0
            var y = 0

            for (var i = 0; i < menuElements.length; i++) {

                if(menuElements[i].nome.toLowerCase().search(text) !== -1) {

                    menuElements[i].x = x
                    menuElements[i].y = y

                    x += 74

                    if (x + 74 >= neonMenu.width) {
                        x = 0
                        y += 78
                    }

                    menuElements[i].visible = true

                } else {
                    menuElements[i].visible = false
                }
            }

            launchersApps.height = y;
        }
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
            id: launchersApps
            height: 338
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
        }

    }

    Rectangle {
        id: rectangle3
        x: 450
        y: 30
        width: 18
        height: 14
        color: "transparent"
        anchors.top: parent.top
        anchors.topMargin: 32
        anchors.right: parent.right
        anchors.rightMargin: 34

        Rectangle {
            id: rectangle4
            width: 18
            height: 2
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle5
            x: 0
            y: 6
            width: 18
            height: 2
            color: "#ffffff"
        }

        Rectangle {
            id: rectangle6
            x: 0
            y: 12
            width: 18
            height: 2
            color: "#ffffff"
        }
    }

    Component.onCompleted: {

        var apps = Context.applications()
        var comp = Qt.createComponent("app.qml")
        var x = 0
        var y = 0

        for (var i = 0; i < apps.length; i ++) {

            var app = apps[i].split(';')

            if (app[1] !== "") {

                var obj = comp.createObject(launchersApps, {'x': x, 'y': y, 'nome': app[0], 'icone': app[1], 'exec': app[2], 'launcherApp': 'file://' + app[3]})
                menuElements.push(obj)

                x += 74

                if (x + 74 >= neonMenu.width) {
                    x = 0
                    y += 78
                }
            }
        }

        launchersApps.height = y;
    }
}
