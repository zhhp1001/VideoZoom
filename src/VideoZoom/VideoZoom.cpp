#include "VideoZoom.h"
#include <iostream>



VideoZoom::VideoZoom(QWidget *parent)
	: QWidget(parent)
	, beishu(1)
	, delay(0)
{
	ui.setupUi(this);
	
	connect(ui.openbtn, SIGNAL(clicked()), this, SLOT(onBtnClicked()));
	connect(&timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

VideoZoom::~VideoZoom()
{
	capture.release();
}
void VideoZoom::onBtnClicked()
{
	capture.open("part3.avi");
	double rate = capture.get(CV_CAP_PROP_FPS);
	

	delay = 1000 / rate;
	timer.start(delay / beishu);
	
}
QImage VideoZoom::Mat2QImage(const cv::Mat& mat)
{
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)      
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat      
		uchar *pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3      
	else if (mat.type() == CV_8UC3)
	{
		// Copy input Mat     
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat      
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{
		// Copy input Mat      
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat      
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		return QImage();
	}
}
void VideoZoom::onTimeout()
{
	Mat frame;
	capture >> frame;


	QImage image = Mat2QImage(frame);

	ui.label->setScaledContents(true);
	QSize qs = ui.label->rect().size();
	ui.label->setPixmap(QPixmap::fromImage(image).scaled(qs));

	ui.label->repaint();
	//这里加滤波程序  



}
