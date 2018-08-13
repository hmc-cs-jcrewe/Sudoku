import QtQuick 2.0
import QtQuick.Window 2.2
import solver.io 1.0
import QtGraphicalEffects 1.0
import file.io 1.0
import QtQuick.Dialogs 1.2


//import solver 1.0
//import board 1.0
//import cell 1.0
Window {
    id: root
    visible: true
    width: 640
    minimumWidth: 640
    maximumWidth: 640
    height: 640
    minimumHeight: 640
    maximumHeight: 640
    color: "white"

    Rectangle {
        id: header
        x: (-1) * header.border.width
        y: (-1) * header.border.width
        width: root.width + 2 * header.border.width
        height: root.height / 8
        border.color: "blue"
        border.width: 6
        Text {
            id: headerText
            anchors.fill: header
            text: "Sudoku Solver \n"
            font.bold: true
            font.capitalization: Font.AllUppercase
            fontSizeMode: Text.HorizontalFit
            horizontalAlignment: Text.Center
            font.pixelSize: 72
        }
    }

    Rectangle {
        z: 100
        id: floatingWindow
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -5
        radius: 15
        width: parent.width * .8
        height: 460
        border.color: "blue"
        border.width: 2
        color: "light grey"

        Text {
            font.bold: true
            font.capitalization: Font.AllUppercase
            fontSizeMode: Text.HorizontalFit
            horizontalAlignment: Text.Center
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.Wrap
            anchors.verticalCenter: parent.top
            anchors.verticalCenterOffset: 30
            anchors.margins: 5
            text: "Would you like to open \n or create a new file?"
            font.pixelSize: 24
        }
        Button {
            id: newButton
            anchors.verticalCenter: parent.bottom
            anchors.verticalCenterOffset: -1 * newButton.buttonHeight - 20
            x: 30
            buttonColor: "blue"
            buttonHeight: 60
            buttonWidth: 120
            borderColor: "black"
            borderWidth: 3
            buttonRadius: 5
            buttonText: "New"
            fontColor: "white"
            fontSize: 12
            onClicked: {
                floatingWindow.visible = false
                floatShadow.visible = false
                for (var i = 0; i < floatingWindow.children.length; ++i) {
                    floatingWindow.children[i].visible = false
                }

                // Currently placing the new board on the screen by just removing the floating window that's stored above
            }
        }
        Button {
            id: openButton
            anchors.verticalCenter: parent.bottom
            anchors.verticalCenterOffset: -1 * newButton.buttonHeight - 20
            x: floatingWindow.x + 300
            buttonColor: "blue"
            buttonHeight: 60
            buttonWidth: 120
            borderColor: "black"
            borderWidth: 3
            buttonRadius: 5
            buttonText: "Open"
            fontColor: "white"
            fontSize: 12
            onClicked: {


                // open a file dialog
                // FileIO stuff
            }
        }
    }

    DropShadow {
        id: floatShadow
        anchors.fill: floatingWindow
        horizontalOffset: 8
        verticalOffset: 8
        source: floatingWindow
    }

    Text {
        text: "Please Enter Values in the Board Below"
        horizontalAlignment: Text.Center
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: headerText.font.pixelSize / 3
        y: header.height + 6
        anchors.margins: 12
    }

    Board {
        id: board
        x: root.width / 2 - this.boardWidth / 2
        y: root.height / 2 - this.boardHeight / 2
        //  anchors.centerIn: root
        //  anchors.horizontalCenterOffset: 0
        //  anchors.verticalCenterOffset: 0
        boardHeight: root.height / 2
        boardWidth: root.width / 2
        smallLineColor: "blue"
        smallLineThickness: 1
        largeLineColor: "black"
        largeLineThickness: 3
        onAllVallsChanged: {
            saveText.visible = false
        }
    }
    Button {
        id: solveButton
        buttonId: "save"
        buttonColor: "blue"
        buttonHeight: 30
        buttonWidth: 60
        buttonRadius: 5
        borderColor: "black"
        borderWidth: 3
        buttonText: "Solve"
        fontSize: 6
        boldSetting: true
        capSetting: Font.AllUppercase
        fontColor: "white"
        anchors.margins: 8
        x: board.x + board.boardWidth - solveButton.buttonWidth
        y: board.y + board.boardHeight + solveButton.buttonHeight
    }

    Button {
        id: clearButton
        buttonId: "clear"
        buttonColor: "grey"
        buttonHeight: 30
        buttonWidth: 60
        buttonRadius: 5
        borderColor: "black"
        borderWidth: 3
        buttonText: "Clear"
        fontSize: 6
        boldSetting: true
        capSetting: Font.AllUppercase
        fontColor: "white"
        anchors.margins: 8
        x: board.x
        y: board.y + board.boardHeight + clearButton.buttonHeight
        onClicked: {
            board.clearBoard()
            board.readOnly = false
            board.forceActiveFocus()
        }
    }

    Text {
        id: saveText
        x: board.x + board.boardWidth - this.width
        y: board.y - this.height - 3
        text: "Saving..."
        visible: false
    }

    Button {
        id: saveButton
        property int counter: 0
        buttonId: "save"
        buttonColor: "brown"
        buttonHeight: 35
        buttonWidth: 80
        buttonRadius: 8
        borderColor: "black"
        borderWidth: 3
        buttonText: "Save Board"
        fontSize: 6
        boldSetting: true
        capSetting: Font.AllUppercase
        fontColor: "white"
        anchors.margins: 8
        x: board.x + board.boardWidth / 2 - saveButton.buttonWidth / 2
        y: board.y - saveButton.buttonHeight - 4
        onClicked: {
            //Let the user know the function is runnin
            saveText.visible = true
            //Generate data
            var data = [" ", " ", " ", " ", " ", " ", " ", " ", " "]
            var k = 0
            for (var i = 0; i < board.children.length; ++i) {
                var tmp = ""
                if (board.children[i].type === "square") {
                    var square = board.children[i]
                    tmp += square.sVal1
                    tmp += square.sVal2
                    tmp += square.sVal3
                    tmp += square.sVal4
                    tmp += square.sVal5
                    tmp += square.sVal6
                    tmp += square.sVal7
                    tmp += square.sVal8
                    tmp += square.sVal9
                    console.log(tmp)
                    data[k] = tmp
                    ++k
                }
                saveText.text = "Saved!"
            }
            fileItem.write(data, "demo" + saveButton.counter + ".txt")
            ++saveButton.counter
        }
    }

    Connections {
        target: solveButton
        onClicked: {
            board.readOnly = true
            var inputVals = board.allValls

            var sols = solverItem.solutionWrapper(inputVals)
            sols.forEach(function (element) {})
            var k = 0
            for (var i = 0; i < board.children.length; ++i) {
                if (board.children[i].type === "square") {
                    var square = board.children[i]
                    square.sVal1 = sols[k]
                    ++k
                    square.sVal2 = sols[k]
                    ++k
                    square.sVal3 = sols[k]
                    ++k
                    square.sVal4 = sols[k]
                    ++k
                    square.sVal5 = sols[k]
                    ++k
                    square.sVal6 = sols[k]
                    ++k
                    square.sVal7 = sols[k]
                    ++k
                    square.sVal8 = sols[k]
                    ++k
                    square.sVal9 = sols[k]
                    ++k
                }
            }
        }
    }

    SolverItem {
        id: solverItem
    }
    FileController {
        id: fileItem
    }
}
