import QtQuick 2.2
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

        Rectangle {
            x: 25
            y: 50
            width: 200
            height: 8
            color: "#666666"

            Rectangle {
                id: brightIdicatorColor
                x: 0
                y: 0
                width: brightIdicator.x + 7
                height: parent.height
                color: main.detailColor
           }

           Rectangle {
                id: brightIdicator
                x: 0
                y: -2.5
                width: 14
                height: 14
                radius: 7
                color: main.detailColor
                border.width: 0
          }

          MouseArea {
                anchors.fill: parent

                onClicked: {

                    var _x = mouseX
                    brightIdicator.x = _x  - 7
                    _x = (_x * 100) / 200
                    _x = parseInt(_x)

                    if (_x == 99) _x = 100

                   Context.libraryIntLoad(_x, '', "setBrightness", libName)
               }
            }
        }
   }

    Component.onCompleted: {

        var maxBright = Context.libraryIntLoad("maxBrightness", libName)
        var bright = Context.libraryIntLoad("getBrightness", libName)

        bright = (bright * 100) / maxBright
        bright = parseInt(bright)

        bright = (bright * 200) / 100
        brightIdicator.x = bright
    }
}
