import QtQuick 2.3
import QtQuick.Controls 1.2


Rectangle {
    id: applicationInfo
    width: 40
    height: 40
    color: "transparent"

    property string nome: ""
    property string pidname: ""
    property bool minimize: true
    property var destak: destak
    property bool tooTip: true
    property int winId: 0

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
        source: "image://pixmap/" + winId
        anchors.fill: parent
        anchors.margins: 3
        antialiasing: true
        fillMode: Image.Stretch
    }

    MouseArea {

        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: {

            if (mouse.button & Qt.LeftButton) {

                showAppInfo.visible = false

                neonMenu.visible = false
                neonMenu.textSearch.focus = false
                neonMenu.addApps()
                main.clickOpc = main.startOpc

                if (!Context.isMinimized(pidname) & Context.isActive(pidname)) {

                    Context.manyMinimizes(pidname)
                    minimize = false;

                } else {

                    Context.manyActives(pidname)
                    minimize = true;
                }

            } else {

                showAppInfo.winIds = Context.windowsBywmclass(pidname)
                showAppInfo.y = main.y - 40
                showAppInfo.setText()
                showAppInfo.visible = true

                clickOpc = startOpc
                neonMenu.visible = false
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
