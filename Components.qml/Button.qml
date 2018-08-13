import QtQuick 2.0


Item {
    id: root
    property alias buttonWidth: rect.width
    property alias buttonHeight: rect.height
    property alias buttonText: input.text
    property alias fontSize: input.font.pointSize
    property alias boldSetting: input.font.bold
    property alias capSetting: input.font.capitalization
    property string buttonColor
    property alias buttonRadius: rect.radius
    property string borderColor
    property int borderWidth
    property string fontColor
    property string buttonId
    signal clicked(string buttonId)

    Rectangle {
        id: rect
        border.color: root.borderColor
        border.width: root.borderWidth
        color: root.buttonColor
        MouseArea {
            id: mouseArea
            anchors.fill: rect
            onClicked: root.clicked(root.buttonId)
        }
    }
    Text {
        id: input
        anchors.centerIn: rect
        color: root.fontColor
    }
}
