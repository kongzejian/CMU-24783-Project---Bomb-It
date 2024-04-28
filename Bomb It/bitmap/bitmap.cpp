#include "bitmap.h"
#include "yspng.h"

RGBABitmap::RGBABitmap(const RGBABitmap &incoming)
{
	this->CopyFrom(incoming);
}

RGBABitmap &RGBABitmap::operator=(const RGBABitmap &incoming)
{
	this->CopyFrom(incoming);
	return *this;
}

RGBABitmap::RGBABitmap(RGBABitmap &&incoming)
{
	this->MoveFrom(incoming);
}
RGBABitmap &RGBABitmap::operator=(RGBABitmap &&incoming)
{
	this->MoveFrom(incoming);
	return *this;
}

bool RGBABitmap::LoadPNG(std::string fileName)
{
	YsRawPngDecoder decoder;
	decoder.Decode(fileName.data());

	TakeOwnership(decoder.wid,decoder.hei,decoder.rgba);

	decoder.wid=0;
	decoder.hei=0;
	decoder.rgba=nullptr;

	return true;
}

RGBABitmap RGBABitmap::CutOut(int x0,int y0,int wid,int hei) const
{
	RGBABitmap cutout;
	SimpleBitmapTemplate <unsigned char,4>::CutOut(cutout,x0,y0,wid,hei);
	return cutout;
}
