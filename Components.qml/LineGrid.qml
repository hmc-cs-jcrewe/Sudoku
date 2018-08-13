import QtQuick 2.0

Item {
    id: root
    property alias gridThickness: line1.thickness
    property alias gridWidth: line1.lineHeight
    property alias gridHeight: line3.lineHeight
    property alias gridColor: line1.color
    property string type: "grid"
    function updateProperties() {
        line2.lineHeight = root.gridWidth
        line2.color = root.gridColor
        line2.thickness = root.gridThickness

        line3.lineHeight = root.gridHeight
        line3.color = root.gridColor
        line3.thickness = root.gridThickness

        line4.lineHeight = root.gridHeight
        line4.color = root.gridColor
        line4.thickness = root.gridThickness
    }

    onGridColorChanged: root.updateProperties()
    onGridHeightChanged: root.updateProperties()
    onGridWidthChanged: root.updateProperties()
    onGridThicknessChanged: root.updateProperties()
    HorizontalLine {
        id: line1

        //    anchors.verticalCenter: parent.verticalCenter
        //   anchors.horizontalCenter: parent.horizontalCenter
        // anchors.horizontalCenterOffset: -1 * (parent.width / 6)
        y: root.gridHeight / 3
        x: 0

        onThicknessChanged: {
            root.updateProperties()
        }
        onLineHeightChanged: {
            root.updateProperties()
        }

        onColorChanged: {
            root.updateProperties()
        }
        color: "black"
    }

    HorizontalLine {
        id: line2
        //    anchors.verticalCenter: parent.verticalCenter
        //  anchors.horizontalCenter: parent.horizontalCenter
        //anchors.horizontalCenterOffset: parent.width / 6
        //  y: parent.height * 5 / 6
        color: "blue"
        y: root.gridHeight * (2 / 3)
        x: 0
    }
    VerticalLine {
        //    anchors.verticalCenter: parent.verticalCenter
        //   anchors.horizontalCenter: parent.horizontalCenter
        // anchors.verticalCenterOffset: parent.height / 6
        id: line3
        onLineHeightChanged: {
            root.updateProperties()
        }
        color: "red"
        x: root.gridWidth / 3
    }
    VerticalLine {
        //    anchors.verticalCenter: parent.verticalCenter
        //  nchors.horizontalCenter: parent.horizontalCenter
        //anchors.verticalCenterOffset: -1 * (parent.height / 6)
        //  x: parent.height
        id: line4
        color: "yellow"
        x: root.gridWidth * 2 / 3
    }
}
