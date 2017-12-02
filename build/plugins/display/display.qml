import QtQuick 2.3
import QtQuick.Controls 1.2


Rectangle {
    x: 0
    y: 20
    anchors.fill: parent
    color: "transparent"

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "#333333"
        border.width: 0

        ScrollView {
            id: scrollDisplay
            anchors.fill: parent

            Item {
                x: 0
                y: 0
                id: addDisplay
                width: parent.width
                height: 20
            }
        }
    }

    Component.onCompleted: {

        var displayLength = Context.libraryIntLoad('displayLength', libName)
        var _x = 0
        var _y = 0

        for (var i = 0; i < displayLength; i++) {

            Qt.createQmlObject('import QtQuick 2.3;
                Rectangle {
                    x: ' + _x + '
                    y: ' + _y + '
                    width: 82
                    height: 82
                    color: "#666666"

                    Text {
                        anchors.fill: parent
                        text: "' + (i + 1) + '"
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pixelSize: 42
                        color: "#ffffff"

                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                Context.libraryVoidLoad(' + i + ', "", "displayChange", libName)
                            }
                        }
                    }
                }

            ', addDisplay, 'tela-' + (i + 1))

            _x += 84

            if ((i + 1) % 3 == 0) {
                _x = 0
                _y += 84
                addDisplay.height += 84
            }
       }
    }
}
