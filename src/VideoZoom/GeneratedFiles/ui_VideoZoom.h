/********************************************************************************
** Form generated from reading UI file 'VideoZoom.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOZOOM_H
#define UI_VIDEOZOOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoZoomClass
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *openbtn;
    QPushButton *zoombtn;
    QLabel *label;

    void setupUi(QWidget *VideoZoomClass)
    {
        if (VideoZoomClass->objectName().isEmpty())
            VideoZoomClass->setObjectName(QStringLiteral("VideoZoomClass"));
        VideoZoomClass->resize(691, 462);
        verticalLayoutWidget = new QWidget(VideoZoomClass);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(550, 190, 121, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        openbtn = new QPushButton(verticalLayoutWidget);
        openbtn->setObjectName(QStringLiteral("openbtn"));

        verticalLayout->addWidget(openbtn);

        zoombtn = new QPushButton(verticalLayoutWidget);
        zoombtn->setObjectName(QStringLiteral("zoombtn"));

        verticalLayout->addWidget(zoombtn);

        label = new QLabel(VideoZoomClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 70, 391, 291));
        label->setStyleSheet(QStringLiteral("background-color: rgb(207, 193, 198);"));

        retranslateUi(VideoZoomClass);
        QObject::connect(openbtn, SIGNAL(clicked()), VideoZoomClass, SLOT(onBtnClicked()));
        QObject::connect(label, SIGNAL(linkActivated(QString)), VideoZoomClass, SLOT(onBtnClicked()));

        QMetaObject::connectSlotsByName(VideoZoomClass);
    } // setupUi

    void retranslateUi(QWidget *VideoZoomClass)
    {
        VideoZoomClass->setWindowTitle(QApplication::translate("VideoZoomClass", "VideoZoom", Q_NULLPTR));
        openbtn->setText(QApplication::translate("VideoZoomClass", "\346\211\223\345\274\200\350\247\206\351\242\221", Q_NULLPTR));
        zoombtn->setText(QApplication::translate("VideoZoomClass", "\346\224\276\345\244\247\350\247\206\351\242\221", Q_NULLPTR));
        label->setText(QApplication::translate("VideoZoomClass", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VideoZoomClass: public Ui_VideoZoomClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOZOOM_H
