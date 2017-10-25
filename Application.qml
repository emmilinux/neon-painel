import QtQuick 2.3
import QtQuick.Controls 1.2


Rectangle {
    width: 40
    height: 40
    color: "transparent"

    property string url: ""
    property string nome: ""
    property string exec: ""
    property bool _instance: false
    property int pid: 0
    property string pidname: ""
    property bool minimize: true

    signal create
    signal destroy

    onCreate: {
        destak.visible = true;
    }

    onDestroy: {
        destak.visible = false;
    }

    Rectangle {
        id: destak
        x: 0
        y: parent.height - 2
        height: 2
        width: parent.width
        color: "#007fff"
        visible: false
    }

    Rectangle {
        id: bgOpc
        anchors.fill: parent
        color: "#ffffff"
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

        onClicked: {
            neonMenu.visible = false
            main.clickOpc = main.startOpc

            if (!_instance) {
                pid = Context.exec(exec)
                _instance = true
            } else {

                if (!Context.isMinimized(pidname)) {
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
        }


        hoverEnabled: true

        onHoveredChanged: {
            bgOpc.opacity = 0.30
        }

        onExited: {
            bgOpc.opacity = 0.0
        }

    }

}
