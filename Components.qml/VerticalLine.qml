import QtQuick 2.0

Item {

    id: root
    property alias thickness: rect.width
    property alias lineHeight: rect.height
    property alias color: rect.color
    property string type: "line"
    onThicknessChanged: {

    }

    Rectangle {
        id: rect
        property string type: "rect"
        border.width: 0
    }
}
