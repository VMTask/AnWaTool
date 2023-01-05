import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {

    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top
    }

    Image {
        id: image
        x: 270
        y: 62
        width: 100
        height: 100
        source: qmlCpp.imageurl()
        fillMode: Image.PreserveAspectFit
    }
}
