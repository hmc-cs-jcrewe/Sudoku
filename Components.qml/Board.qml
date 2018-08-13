import QtQuick 2.0

Item {
    id: root
    property string smallLineColor
    property real smallLineThickness
    property alias boardWidth: largeLines.gridWidth
    property alias boardHeight: largeLines.gridHeight
    property alias largeLineColor: largeLines.gridColor
    property alias largeLineThickness: largeLines.gridThickness
    property var allValls: [square1.sValues, square2.sValues, square3.sValues, square4.sValues, square5.sValues, square6.sValues, square7.sValues, square8.sValues, square9.sValues]
    property alias readOnly: square1.readOnly
    property string type: "board"
    function updateProperties() {

        square1.smallLineColor = root.smallLineColor
        square2.smallLineColor = root.smallLineColor
        square3.smallLineColor = root.smallLineColor
        square4.smallLineColor = root.smallLineColor
        square5.smallLineColor = root.smallLineColor
        square6.smallLineColor = root.smallLineColor
        square7.smallLineColor = root.smallLineColor
        square8.smallLineColor = root.smallLineColor
        square9.smallLineColor = root.smallLineColor

        square1.smallLineThickness = root.smallLineThickness
        square2.smallLineThickness = root.smallLineThickness
        square3.smallLineThickness = root.smallLineThickness
        square4.smallLineThickness = root.smallLineThickness
        square5.smallLineThickness = root.smallLineThickness
        square6.smallLineThickness = root.smallLineThickness
        square7.smallLineThickness = root.smallLineThickness
        square8.smallLineThickness = root.smallLineThickness
        square9.smallLineThickness = root.smallLineThickness

        square1.readOnly = root.readOnly
        square2.readOnly = root.readOnly
        square3.readOnly = root.readOnly
        square4.readOnly = root.readOnly
        square5.readOnly = root.readOnly
        square6.readOnly = root.readOnly
        square7.readOnly = root.readOnly
        square8.readOnly = root.readOnly
        square9.readOnly = root.readOnly
    }
    function saveBoard(filepath) {}
    function clearBoard() {
        for (var i = 0; i < root.children.length; ++i) {
            if (root.children[i].type === "square") {
                root.children[i].clearSquare()
            }
        }
        square1.clearSquare()
        square2.clearSquare()
        square3.clearSquare()
        square4.clearSquare()
        square5.clearSquare()
        square6.clearSquare()
        square7.clearSquare()
        square8.clearSquare()
        square9.clearSquare()
    }

    Rectangle {
        id: background
        property string type: "rect"
        z: 0
        x: (-1 / 2) * root.largeLineThickness
        y: (-1) * root.largeLineThickness
        border.color: root.largeLineColor
        border.width: root.largeLineThickness
        width: boardWidth + root.largeLineThickness
        height: boardHeight + 2 * root.largeLineThickness
        color: "light grey"
    }

    LineGrid {
        id: largeLines
        z: 1
    }

    /* * * * * *
     * Squares *
     * * * * * */
    Square {
        id: square1
        objectName: "square"
        x: 0
        y: 0
        squareHeight: largeLines.gridHeight / 3 - largeLines.gridThickness
        squareWidth: largeLines.gridWidth / 3 - largeLines.gridThickness
        readOnly: false
        smallLineColor: root.smallLineColor
        smallLineThickness: root.smallLineThickness
        onSmallLineColorChanged: root.updateProperties()
        onSmallLineThicknessChanged: root.updateProperties()
        onReadOnlyChanged: root.updateProperties()
    }

    Square {
        id: square2
        objectName: "square"
        x: largeLines.gridWidth / 3 + largeLines.gridThickness
        y: 0
        squareHeight: largeLines.gridHeight / 3 - largeLines.gridThickness
        squareWidth: largeLines.gridWidth / 3 - largeLines.gridThickness
        readOnly: false
        smallLineColor: root.smallLineColor
        smallLineThickness: root.smallLineThickness
    }
    Square {
        id: square3
        x: largeLines.gridWidth * (2 / 3) + largeLines.gridThickness
        y: 0
        squareHeight: largeLines.gridHeight / 3 - largeLines.gridThickness
        squareWidth: largeLines.gridWidth / 3 - largeLines.gridThickness
        readOnly: false
        smallLineColor: root.smallLineColor
        smallLineThickness: root.smallLineThickness
    }
    Square {
        id: square4
        y: largeLines.gridHeight / 3 + largeLines.gridThickness
        x: 0
        squareHeight: largeLines.gridHeight / 3 - largeLines.gridThickness
        squareWidth: largeLines.gridWidth / 3 - largeLines.gridThickness
        readOnly: false
        smallLineColor: root.smallLineColor
        smallLineThickness: root.smallLineThickness
    }
    Square {
        id: square5
        x: largeLines.gridWidth / 3 + largeLines.gridThickness
        y: largeLines.gridHeight / 3 + largeLines.gridThickness
        squareHeight: largeLines.gridHeight / 3 - largeLines.gridThickness
        squareWidth: largeLines.gridWidth / 3 - largeLines.gridThickness
        readOnly: false
        smallLineColor: root.smallLineColor
        smallLineThickness: root.smallLineThickness
    }
    Square {
        id: square6
        x: largeLines.gridWidth * (2 / 3) + largeLines.gridThickness
        y: largeLines.gridHeight / 3 + largeLines.gridThickness
        squareHeight: largeLines.gridHeight / 3 - largeLines.gridThickness
        squareWidth: largeLines.gridWidth / 3 - largeLines.gridThickness
        readOnly: false
        smallLineColor: root.smallLineColor
        smallLineThickness: root.smallLineThickness
    }
    Square {
        id: square7
        x: 0
        y: largeLines.gridHeight * (2 / 3) + largeLines.gridThickness
        squareHeight: largeLines.gridHeight / 3 - largeLines.gridThickness
        squareWidth: largeLines.gridWidth / 3 - largeLines.gridThickness
        readOnly: false
        smallLineColor: root.smallLineColor
        smallLineThickness: root.smallLineThickness
    }
    Square {
        id: square8
        x: largeLines.gridWidth / 3 + largeLines.gridThickness
        y: largeLines.gridHeight * (2 / 3) + largeLines.gridThickness
        squareHeight: largeLines.gridHeight / 3 - largeLines.gridThickness
        squareWidth: largeLines.gridWidth / 3 - largeLines.gridThickness
        smallLineColor: root.smallLineColor
        smallLineThickness: root.smallLineThickness
        readOnly: false
    }
    Square {
        id: square9
        x: largeLines.gridWidth * (2 / 3) + largeLines.gridThickness
        y: largeLines.gridHeight * (2 / 3) + largeLines.gridThickness
        squareHeight: largeLines.gridHeight / 3 - largeLines.gridThickness
        squareWidth: largeLines.gridWidth / 3 - largeLines.gridThickness
        smallLineColor: root.smallLineColor
        smallLineThickness: root.smallLineThickness
        readOnly: false
    }
}
