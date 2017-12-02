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

        Image {
            id: imgAutoFalante
            x: 10
            y: 0
            source: "file://" + Context.basepath + '/plugins/audio/audio.png'
            width: 60
            height: 60

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    volumeIdicator.x = 0
                    Context.libraryVoidLoad(0, '0', "setVolume", libName)
                    imgAutoFalante.opacity = 0.3
                }
            }
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
                    volumeIdicator.x = _x  - 7
                    _x = (_x * 100) / 150
                    _x = parseInt(_x)
                    Context.libraryVoidLoad(0, _x.toString(), "setVolume", libName)

                    if (mouseX < 5) {
                        imgAutoFalante.opacity = 0.3
                    } else {
                       imgAutoFalante.opacity = 1
                    }
                }
            }
        }

        Image {
            id: imgMicroFone
            x: 10
            y: 105
            source: "file://" + Context.basepath + '/plugins/audio/micro.png'
            width: 60
            height: 55

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    microIndicator.x = 0
                    Context.libraryVoidLoad(0, '0', "setMicro", libName)
                    imgMicroFone.opacity = 0.3
                }
            }
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
                    microIndicator.x = _x - 7
                    _x = (_x * 100) / 150
                    _x = parseInt(_x)
                    Context.libraryVoidLoad(0, _x.toString(), "setMicro", libName)

                    if (mouseX < 5) {
                        imgMicroFone.opacity = 0.3
                    } else {
                        imgMicroFone.opacity = 1
                    }

                }
            }
        }
   }

    Component.onCompleted: {

        volumeIdicator.x = parseInt(((Context.libraryIntLoad("getVolume", libName) - 7) * 150) / 100)

        if (volumeIdicator.x < 5) {
            imgAutoFalante.opacity = 0.3
        }

        microIndicator.x = parseInt(((Context.libraryIntLoad("getMicro", libName) - 7) * 150) / 100)

        if (microIndicator.x < 5) {
            imgMicroFone.opacity = 0.3
        }
    }
}
