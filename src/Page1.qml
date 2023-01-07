import QtQuick 2.10

Page1Form {
    width: 1083
    height: 636
	Timer{
    id:                             _timer
    interval:                       1000
    running:                        true
    repeat:                         true
    onTriggered: {
        console.log(qmlCpp.getAndroidDeviceStatus_qstr());
        image1.source = qmlCpp.imageurl();
        text1.text = qmlCpp.text_status();
    }
    }
}
