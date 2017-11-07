import QtQuick 2.3
import QtQuick.Controls 1.2


Rectangle {
    id: applicationInfo
    width: 40
    height: 40
    color: "transparent"

    property string url: ""
    property string nome: ""
    property string exec: ""
    property bool _instance: false
    property string pidname: ""
    property bool minimize: true
    property var destak: destak
    property bool tooTip: true

    signal create
    signal destroy

    /* not work
    ToolTip {
             id: toolTip
             text: "ToolTip"
    }
*/
    onCreate: {
        destak.visible = true;
    }

    onDestroy: {
        destak.visible = false;
    }

    Rectangle {
        id: destak
        x: 0
        y: parent.height - 1.5
        height: 1.5
        width: parent.width
        color: "#7310A2"//"#007fff"
        visible: false
    }

    Rectangle {
        id: bgOpc
        anchors.fill: parent
        color: "#7310A2"//"#ffffff"
        opacity: 0.0
    }

    Image {
        id: appIcon
        source: url
        anchors.fill: parent
        anchors.margins: 3
        antialiasing: true
        fillMode: Image.Stretch
    }

    MouseArea {

        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: {

            if(mouse.button & Qt.LeftButton) {

                showAppInfo.visible = false

                neonMenu.visible = false
                neonMenu.textSearch.focus = false
                neonMenu.addApps()
                main.clickOpc = main.startOpc

                if (!_instance) {

                    Context.exec(exec)
                    _instance = true

                } else {

                    if (!Context.isMinimized(pidname) & Context.isActive(pidname)) {
                        Context.manyMinimizes(pidname)
                        minimize = false;
                        // fix bug, but why this bug?
                        Context.active(main.mainId)
                    } else {
                        Context.manyActives(pidname)
                        minimize = true;
                        // fix bug, but why this bug?
                        Context.active(main.mainId)
                    }
                }
            } else {

                var size = applicationInfo.nome.length * 8
                showAppInfo.appNameText = nome
                showAppInfo.width = size

                var pos = Context.mouseX() - (size / 2)

                showAppInfo.x = pos < 0 ? 0 : pos
                showAppInfo.y = main.y - 40
                showAppInfo.visible = true
            }
        }


        hoverEnabled: true

        onHoveredChanged: {
            bgOpc.opacity = 0.75
        }

        onExited: {
            bgOpc.opacity = 0.0
        }

    }
}
