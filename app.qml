import QtQuick 2.3
import QtQuick.Controls 1.2

Rectangle {
    id: rectangle

    x: 0
    y: 0
    width: 74
    height: 78
    color: "transparent"

    property string icone: ""
    property string nome: ""
    property string exec: ""
    property string launcherApp: ""
    property int pid: 0

    Rectangle {
        anchors.fill: parent
        color: "#ffffff"
        opacity: 0.0

        MouseArea {

            id: mouseArea
            width: 70
            anchors.fill: parent
            //drag.target: iconeApp

            property bool _pressed: false
            property bool _pressed2: false
            property int mouseStart: 0

            onClicked: { 
                pid = Context.exec(exec)
                main.subWindowPid = pid
                main.subWindowLauncher = launcherApp.replace("file://", "")

                neonMenu.visible = false
                neonMenu.textSearch.focus = false
                main.clickOpc = main.startOpc
            }

            onPressedChanged: {
                if (!_pressed) {
                    _pressed = true
                    _pressed2 = true
                    mouseStart = mouseX
                } else {
                    _pressed = false
                    _pressed2 = false
                    mouseStart = mouseX
                    parent.opacity = 0.0
                    neonMenu.visible = false
                    neonMenu.textSearch.focus = false
                    neonMenu.addApps()
                }
            }

            onMouseXChanged: {

                if (_pressed2 && mouseX > mouseStart + 10) {
                    _pressed2 = false
                    Context.dragDrop(icone.replace("file://", ""), launcherApp)
                    neonMenu.visible = false
                    neonMenu.textSearch.focus = false
                    neonMenu.addApps()
                }
                //neonMenu.visible = true
                //neonMenu.requestActivate()
            }

            hoverEnabled: true

            onHoveredChanged: {
                parent.opacity = 0.30
            }

            onExited: {
                parent.opacity = 0.0
            }

        }
    }

/*
    Rectangle {
        x: 3
        y: 3
        width: 48
        height: 48
        color: "blue"
   }
*/
    Image {
        id: iconeApp
        x: 13
        y: 5
        width: 48
        height: 48
        source: icone

        /*
        Drag.active: mouseArea.drag.active
        Drag.hotSpot.x: 0
        Drag.hotSpot.y: 0
        Drag.mimeData: { "text/uri-list": "file://" + launcherApp }
        Drag.supportedActions: Qt.CopyAction
        Drag.dragType: Drag.Automatic

        Drag.onDragStarted: {

        }
        Drag.onDragFinished: {
            console.log("Time to copy")
        }
        */
   }

   Text {
        id: name
        y: 44
        height: 8
        text: nome.length < 10 ? nome : nome.substring(0, 10) + '...'
        anchors.right: parent.right
        anchors.rightMargin: 7
        anchors.left: parent.left
        anchors.leftMargin: 7
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        font.pointSize: 8
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: "#ffffff"
   }
}
