import QtQuick 2.3
import QtQuick.Controls 1.2


Rectangle {
    x: 0
    y: 0
    anchors.fill: parent
    color: "transparent"

    property string light: "115"

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "#333333"
        border.width: 0


        Rectangle {
            x: 14
            y: 50
            width: 220
            height: 50
            color: "#999999"

            Image {
                id: hue
                anchors.fill: parent
                source: "file://" + Context.basepath + "/plugins/color/hue.png"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {

                    var _x = (mouseX * 100) / 220
                    _x = parseInt(_x)

                    var _y = (_x * 360) / 100
                    _y = parseInt(_y)

                    main.detailColor = Context.libraryQStringLoad(_y, light, 'changeDatail', libName)
                    Context.changeThemeColor(main.detailColor)
                }
            }
        }

        Rectangle {
                    x: 14
                    y: 130
                    width: 220
                    height: 8
                    color: "#666666"

                    Image {
                        id: lightness
                        anchors.fill: parent
                        source: "file://" + Context.basepath + "/plugins/color/lightness.png"
                    }

                   Rectangle {
                        id: brightIdicator
                        x: 110 //0
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
                            _x = (_x * 100) / 220
                            _x = parseInt(_x)

                            if (_x == 99) _x = 100

                            var _y = (_x * 255) / 100
                            _y = parseInt(_y)

                            light = _y.toString()
                       }
                 }
           }

    }
}
