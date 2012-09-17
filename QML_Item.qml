// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Item
{
    id: itemMain
    width: 40
    height: 40
    focus: true

    property color color_: "blue"

    onColor_Changed:
    {
        rect.color = color_
    }

    Rectangle
    {
        id: rect
        anchors.fill: parent
        color: "blue"
    }

    signal message(string str)

    MouseArea
    {
        anchors.fill: itemMain
        drag.target: itemMain
        onClicked:
        {
            parent.message("clicked")
            console.debug("~~~~~~~~~~")
        }

    }
}
