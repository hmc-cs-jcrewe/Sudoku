import QtQuick 2.0

Item {

    id: root
    property alias thickness: rect.height
    property alias lineHeight: rect.width
    property alias color: rect.color
    property string type: "line"
    Rectangle {
        id: rect
        property string type: "rect"
        border.width: 0
    }
}
