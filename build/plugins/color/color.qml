import QtQuick 2.3
import QtQuick.Controls 1.2


Rectangle {
    x: 0
    y: 0
    anchors.fill: parent
    color: "transparent"

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

                    var x = (mouseX * 100) / 220
                    x = parseInt(x)

                    var y = (x * 360) / 100
                    y = parseInt(y)

                    main.detailColor = Context.libraryQStringLoad(y, '', 'changeDatail', libName)
                    Context.changeThemeColor(main.detailColor)
                }
            }
        }
    }
}
