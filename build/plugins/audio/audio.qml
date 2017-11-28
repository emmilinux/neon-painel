import QtQuick 2.2
import QtQuick.Controls 1.2


Rectangle {
    x: 0
    y: 20
    width: parent.width
    height: parent.height
    color: "transparent"

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "#333333"
        border.width: 0

        Image {
            x: 10
            y: 0
            source: "file://" + Context.basepath + '/plugins/audio/audio2.png'
            width: 60
            height: 60
        }

        Rectangle {
            x: 80
            y: 28
            width: 150
            height: 8
            color: "#666666"

            Rectangle {
               id: volumeIdicatorColor
               x: 0
               y: 0
               width: volumeIdicator.x + 7
               height: parent.height
               color: main.detailColor
            }

            Rectangle {
                id: volumeIdicator
                x: parseInt(((Context.libraryIntLoad("getVolume", libName) - 7) * 150) / 100)
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
                    volumeIdicator.x = _x  - 7
                    _x = (_x * 100) / 150
                    _x = parseInt(_x)
                    Context.libraryVoidLoad(0, _x.toString(), "setVolume", libName)
                }
            }
        }

        Image {
            x: 10
            y: 105
            source: "file://" + Context.basepath + '/plugins/audio/micro.png'
            width: 60
            height: 55
        }

        Rectangle {
            x: 80
            y: 128
            width: 150
            height: 8
            color: "#666666"

            Rectangle {
               id: microIndicatorColor
               x: 0
               y: 0
               width: microIndicator.x + 7
               height: parent.height
               color: main.detailColor
            }

            Rectangle {
                id: microIndicator
                x: parseInt(((Context.libraryIntLoad("getMicro", libName) - 7) * 150) / 100)
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
                    microIndicator.x = _x - 7
                    _x = (_x * 100) / 150
                    _x = parseInt(_x)
                    Context.libraryVoidLoad(0, _x.toString(), "setMicro", libName)
                }
            }
        }
   }
}
