// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle
{
    id: rect
    width: 400
    height: 400
    color:"red"
    property color bgColor: "blue"

    onBgColorChanged:
    {
        color = bgColor
        //console.debug(bgColor)
    }

    function createComponent(x, y, qmlName)
    {
        console.debug(x, y)
        console.debug(qmlName)
        loader.qmlFileName = qmlName
    }

    function loadButton()
    {
        var component = Qt.createComponent("QML_Item.qml");
        if (component.status == Component.Ready)
        {
            var item = component.createObject(rect);
            item.color_ = "green";
        }

        var component = Qt.createComponent("QML_Item.qml");
        if (component.status == Component.Ready)
        {
            var item = component.createObject(rect);
            item.color_ = "blue";
        }
    }

    Component.onCompleted: loadButton()

}
