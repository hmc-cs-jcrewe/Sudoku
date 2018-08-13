import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import "file:/Users/jacksoncrewe/desktop/Sudoku/Components.qml"
import solver.io 1.0
import file.io 1.0
import Qt.labs.settings 1.0
import QtQuick.Controls 2.4 as Controls
import QtQuick.Layouts 1.3

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

    function inputVals(sols) {
        var k = 0
        for (var i = 0; i < board.children.length; ++i) {
            if (board.children[i].type === "square") {
                var square = board.children[i]

                if (sols[k] === 0) {
                    square.sVal1 = " "
                } else {
                    square.sVal1 = sols[k]
                }
                ++k

                if (sols[k] === 0) {
                    square.sVal2 = " "
                } else {
                    square.sVal2 = sols[k]
                }
                ++k

                if (sols[k] === 0) {
                    square.sVal3 = " "
                } else {
                    square.sVal3 = sols[k]
                }
                ++k

                if (sols[k] === 0) {
                    square.sVal4 = " "
                } else {
                    square.sVal4 = sols[k]
                }

                ++k

                if (sols[k] === 0) {
                    square.sVal5 = " "
                } else {
                    square.sVal5 = sols[k]
                }
                ++k

                if (sols[k] === 0) {
                    square.sVal6 = " "
                } else {
                    square.sVal6 = sols[k]
                }
                ++k

                if (sols[k] === 0) {
                    square.sVal7 = " "
                } else {
                    square.sVal7 = sols[k]
                }
                ++k

                if (sols[k] === 0) {
                    square.sVal8 = " "
                } else {
                    square.sVal8 = sols[k]
                }
                ++k

                if (sols[k] === 0) {
                    square.sVal9 = " "
                } else {
                    square.sVal9 = sols[k]
                }
                ++k
            }
        }
    }
    function hideWelcomeWindow() {
        floatingWindow.visible = false
        for (var i = 0; i < floatingWindow.children.length; ++i) {
            floatingWindow.children[i].visible = false
        }
    }

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
        onVisibleChanged: {
            smallOpenButton.visible = true
        }

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
                root.hideWelcomeWindow()
                bar.visible = true

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
                openFile.visible = true
                // open a file dialog
                // FileIO stuff
            }
        }
    }

    Text {
        id: instrText
        text: "Please Enter Values in the Board Below"
        horizontalAlignment: Text.Center
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: headerText.font.pixelSize / 3
        y: header.height + 6
        anchors.margins: 12
    }

    StackLayout {
        id: stackLayout
        width: root.width
        height: root.height - header.height
        x: 0
        y: 0
        currentIndex: 0
        Item {
            id: boardWrapper
            Board {
                id: board
                x: root.width / 2 - this.boardWidth / 2
                y: root.height / 2 - this.boardHeight / 2

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
                x: board.x + board.boardWidth - saveButton.buttonWidth
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

                            data[k] = tmp
                            ++k
                        }
                    }
                    if (fileItem.write(data,
                                       "demo" + saveButton.counter + ".txt")) {
                        saveText.text = "Saved!"
                    } else {
                        saveText.text = "Couldn't save please try again"
                    }

                    ++saveButton.counter
                }
            }
            Button {
                id: smallOpenButton
                buttonText: "Open Board"
                buttonHeight: 35
                buttonWidth: 80
                buttonRadius: 8
                buttonColor: "black"
                borderColor: "grey"
                borderWidth: 2
                visible: false
                x: board.x
                y: saveButton.y
                fontColor: "white"
                onClicked: {
                    openFile.visible = true
                }
            }
            Settings {
                property alias fileNum: saveButton.counter
            }

            Connections {
                target: solveButton
                onClicked: {
                    board.readOnly = true
                    var inputVals = board.allValls

                    var sols = solverItem.solutionWrapper(inputVals)
                    root.inputVals(sols)
                }
            }

            SolverItem {
                id: solverItem
            }
            FileController {
                id: fileItem
            }
            FileDialog {
                id: openFile
                title: "Select a location"
                folder: "file:///nfs/sc/disks/swuser_work_jcrewe/work/SSolver/savedBoards"
                modality: Qt.WindowModal
                property string fileName
                onAccepted: {
                    if (smallOpenButton.visible === true) {
                        //Calling open from small open
                        var component = Qt.createComponent(Controls.TabButton)
                        bar.addItem(component.createObject(bar, {
                                                               text: "board 2"
                                                           }))

                        // open new window
                    } else {

                        var sols = fileItem.read(openFile.fileUrl)
                        root.inputVals(sols)
                        root.hideWelcomeWindow()
                    }
                }
            }
        }
    }
}
