import QtQuick 2.0


//TODO - Add mouse area as big as rect that allows users to edit text
Item {
    id: root
    property alias inputWidth: rect.width
    property alias inputHeight: rect.height
    property alias readOnly: input.readOnly
    property alias value: input.text
    property string type: "input"
    function clear() {
        input.text = " "
        root.value = " "
    }
    TextInput {
        property string type: "textInput"
        z: 1
        id: input
        readOnly: false
        color: "black"
        font.bold: true
        validator: IntValidator {
            bottom: 1
            top: 9
        }
        maximumLength: 1
        anchors.horizontalCenter: rect.horizontalCenter
        anchors.verticalCenter: rect.verticalCenter
    }
    Rectangle {
        property string type: "rect"
        z: 0
        id: rect
        color: "white"
        border.width: 0
    }
    MouseArea {
        property string type: "mouseArea"
        z: 2
        height: rect.height
        width: rect.width
        onClicked: {
            if (root.readOnly === false) {
                root.value = ""
                input.forceActiveFocus()
            }
        }
    }
}
