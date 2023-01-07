import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Item {
    x: 0
    width: 1083
    height: 636
    property alias image1: image1
    property alias text1: text1


    Image {
        id: image1
        x: 253
        y: 48
        width: 80
        height: 77
        source: qmlCpp.imageurl()
        fillMode: Image.PreserveAspectFit
    }

    Text {
        id: text1
        x: 368
        y: 63
        text: qmlCpp.text_status();
        font.pixelSize: 50
        font.family: "微软雅黑"
    }
}
