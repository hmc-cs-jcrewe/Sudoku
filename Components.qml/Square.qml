import QtQuick 2.0

Item {
    id: root
    property alias squareHeight: lines.gridHeight
    property alias squareWidth: lines.gridWidth
    property alias smallLineColor: lines.gridColor
    property alias smallLineThickness: lines.gridThickness
    property alias sVal1: input1.value
    property alias sVal2: input2.value
    property alias sVal3: input3.value
    property alias sVal4: input4.value
    property alias sVal5: input5.value
    property alias sVal6: input6.value
    property alias sVal7: input7.value
    property alias sVal8: input8.value
    property alias sVal9: input9.value
    property alias readOnly: input1.readOnly
    property var sValues: [sVal1, sVal2, sVal3, sVal4, sVal5, sVal6, sVal7, sVal8, sVal9]
    property string type: "square"

    function clearSquare() {
        sVal1 = " "
        sVal2 = " "
        sVal3 = " "
        sVal4 = " "
        sVal5 = " "
        sVal6 = " "
        sVal7 = " "
        sVal8 = " "
        sVal9 = " "
    }
    LineGrid {
        id: lines
        z: 1
    }

    /* * * * * * * *
     * Input Boxes *
     * * * * * * * */
    NumInput {
        id: input1
        x: 0 + lines.gridWidth / 24
        y: 0 + lines.gridHeight / 24
        inputWidth: lines.gridWidth / 4 - lines.gridThickness
        inputHeight: lines.gridHeight / 4 - lines.gridThickness
        value: " "
        readOnly: false
        onReadOnlyChanged: {
            input2.readOnly = input1.readOnly
            input3.readOnly = input1.readOnly
            input4.readOnly = input1.readOnly
            input5.readOnly = input1.readOnly
            input6.readOnly = input1.readOnly
            input7.readOnly = input1.readOnly
            input8.readOnly = input1.readOnly
            input9.readOnly = input1.readOnly
        }
    }
    NumInput {
        id: input2
        x: lines.gridWidth / 3 + lines.gridThickness + lines.gridWidth / 24
        y: 0 + lines.gridHeight / 24
        inputWidth: lines.gridWidth / 4 - lines.gridThickness
        inputHeight: lines.gridHeight / 4 - lines.gridThickness
        value: " "
        readOnly: false
    }
    NumInput {
        id: input3
        x: root.squareWidth * (2 / 3) + lines.gridWidth / 24
        y: 0 + lines.gridHeight / 24
        inputWidth: lines.gridWidth / 4 - lines.gridThickness
        inputHeight: lines.gridHeight / 4 - lines.gridThickness
        value: " "
        readOnly: false
    }
    NumInput {
        id: input4
        x: 0 + lines.gridWidth / 24
        y: root.squareHeight / 3 + lines.gridHeight / 24
        inputWidth: lines.gridWidth / 4 - lines.gridThickness
        inputHeight: lines.gridHeight / 4 - lines.gridThickness
        value: " "
        readOnly: false
    }
    NumInput {
        id: input5
        x: root.squareWidth / 3 + lines.gridWidth / 24
        y: root.squareHeight / 3 + lines.gridHeight / 24
        inputWidth: lines.gridWidth / 4 - lines.gridThickness
        inputHeight: lines.gridHeight / 4 - lines.gridThickness
        value: " "
        readOnly: false
    }
    NumInput {
        id: input6
        x: root.squareWidth * (2 / 3) + lines.gridWidth / 24
        y: root.squareHeight / 3 + lines.gridHeight / 24
        inputWidth: lines.gridWidth / 4 - lines.gridThickness
        inputHeight: lines.gridHeight / 4 - lines.gridThickness
        value: " "
        readOnly: false
    }
    NumInput {
        id: input7
        x: 0 + lines.gridWidth / 24
        y: root.squareHeight * (2 / 3) + lines.gridHeight / 24
        inputWidth: lines.gridWidth / 4 - lines.gridThickness
        inputHeight: lines.gridHeight / 4 - lines.gridThickness
        value: " "
        readOnly: false
    }
    NumInput {
        id: input8
        x: root.squareWidth / 3 + lines.gridWidth / 24
        y: root.squareHeight * (2 / 3) + lines.gridHeight / 24
        inputWidth: lines.gridWidth / 4 - lines.gridThickness
        inputHeight: lines.gridHeight / 4 - lines.gridThickness
        value: " "
        readOnly: false
    }
    NumInput {
        id: input9
        x: root.squareWidth * (2 / 3) + lines.gridWidth / 24
        y: root.squareHeight * (2 / 3) + lines.gridHeight / 24
        inputWidth: lines.gridWidth / 4 - lines.gridThickness
        inputHeight: lines.gridHeight / 4 - lines.gridThickness
        value: " "
        readOnly: false
    }
}
