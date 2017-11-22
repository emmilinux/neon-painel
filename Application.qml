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

    onCreate: {
        destak.visible = true
    }

    onDestroy: {
        destak.visible = false
    }

    Rectangle {
        id: destak
        x: 0
        y: parent.height - 1.5
        height: 1.5
        width: parent.width
        color: main.detailColor//"#007fff"
        visible: false
    }

    Rectangle {
        id: bgOpc
        anchors.fill: parent
        color: main.detailColor//"#ffffff"
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

            acessoRapido.visible = false
            neonMenu.visible = false

            if (mouse.button & Qt.LeftButton) {

                showAppInfo.visible = false

                neonMenu.textSearch.focus = false
                //neonMenu.addApps()
                main.clickOpc = main.startOpc

                if (!_instance) {

                    Context.exec(exec)
                    _instance = true

                } else {

                    if (!Context.isMinimized(pidname) & Context.isActive(pidname)) {

                        Context.manyMinimizes(pidname)
                        minimize = false;

                    } else {
                        Context.manyActives(pidname)
                        minimize = true;
                    }
                }
            } else {

                showAppInfo.winIds = Context.windowsBywmclass(pidname)
                showAppInfo.y = main.y - 40
                showAppInfo.setText()
                showAppInfo.visible = true

                clickOpc = startOpc
                neonMenu.textSearch.focus = false
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
