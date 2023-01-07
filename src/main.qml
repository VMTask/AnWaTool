import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import Fluid.Controls 1.0 as FluidControls
import QtQuick.Controls.Material 2.3

FluidControls.ApplicationWindow {
    id: window
    width: 1083
    height: 636
    minimumWidth: 1083
    maximumWidth: 1083
    minimumHeight: 636
    maximumHeight: 636
    title: qsTr("AnWaTool")
    visible: true
    appBar.maxActionCount: 3
    Material.primary: Material.Blue
    Material.accent: Material.Indigo
    Timer{
    id:                             _timer
    interval:                       200
    running:                        true
    repeat:                         false
    onTriggered: {
        qmlCpp.threadStart()
        console.log(qmlCpp.imageurl())
        console.log(qmlCpp.getAndroidDeviceStatus_qstr())
    }
    }

    FluidControls.NavigationDrawer {
        id: navDrawer
        ScrollView {
            anchors.fill: parent
            clip: true

            ListView {
                id: navListView
                interactive: false
                model: ListModel {
                    ListElement {  title: qsTr("主页"); source: "qrc:/Page1.qml" }
                }
                currentIndex: -1
                section.property: "category"
                section.criteria: ViewSection.FullString
                section.delegate: FluidControls.Subheader {
                    text: section
                    width: parent.width

                    FluidControls.ThinDivider {
                        width: parent.width
                    }
                }
                delegate: FluidControls.ListItem {
                    text: model.title
                    highlighted: ListView.isCurrentItem
                    onClicked: {
                        navListView.currentIndex = index;
                        stackView.push(model.source);
                        if (navDrawer.modal)
                            navDrawer.close();
                    }
                }
            }
        }
    }
    initialPage: FluidControls.Page {
        title: window.title
        actions: [
            FluidControls.Action {
                text: qsTr("Open adb command")
                icon.source: FluidControls.Utils.iconUrl("notification/adb")
                toolTip: qsTr("Open adb command")
                onTriggered: {
                    qmlCpp.OpenAdbCommandLine();
                    console.log(qmlCpp.imageurl())
                }
            }
        ]
    }
    StackView {
            id: stackView
            anchors.fill: parent
            initialItem: FluidControls.Placeholder {
                text: qsTr("AnWaTool")
                subText: qmlCpp.qstring_command_popen("powershell -NoProfile curl.exe -X POST --data-urlencode a=b --data-urlencode c=d https://v1.hitokoto.cn/?encode=text")
            }
    }
}
