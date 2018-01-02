#pragma once

#include <QtWidgets/QWidget>
#include "ui_VideoZoom.h"
#include <opencv2/core.hpp>            
#include <opencv2/imgcodecs.hpp>       
#include <opencv2/highgui.hpp>    
#include <QTimer>  
#include <QImage>  
using namespace cv;

class VideoZoom : public QWidget
{
	Q_OBJECT

public:
	VideoZoom(QWidget *parent = Q_NULLPTR);
	~VideoZoom();
	QImage Mat2QImage(const cv::Mat& mat);
private slots:
	void onBtnClicked();
	void onTimeout();
private:
	Ui::VideoZoomClass ui;
	VideoCapture capture; //������ȡ��Ƶ�ṹ
	QTimer timer;
	int beishu;//���ڲ�������  
	int delay;//֡�ӳ�ʱ��  
};
