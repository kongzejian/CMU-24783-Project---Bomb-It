#ifndef BITMAP483041_H_IS_INCLUDED
#define BITMAP483041_H_IS_INCLUDED

#include <string>
#include <string.h>

template <class ComponentType,int NumComponentPerPixel>
class SimpleBitmapTemplate
{
private:
	int wid=0,hei=0;
	ComponentType *data=nullptr;
public:
	SimpleBitmapTemplate()
	{
	}
	SimpleBitmapTemplate(int wid,int hei)
	{
		data=new ComponentType[wid*hei*NumComponentPerPixel];
		this->wid=wid;
		this->hei=hei;
	}
	~SimpleBitmapTemplate()
	{
		Clear();
	}
	void Clear(void)
	{
		wid=0;
		hei=0;
		if(nullptr!=data) //Optional
		{
			delete [] data;
		}
		data=nullptr;
	}
	int GetWidth(void) const
	{
		return wid;
	}
	int GetHeight(void) const
	{
		return hei;
	}
	void Create(int WID,int HEI)
	{
		Clear();
		if(0!=WID*HEI)
		{
			wid=WID;
			hei=HEI;
			data=new ComponentType[WID*HEI*NumComponentPerPixel];
		}
	}

	void TakeOwnership(int wid,int hei,ComponentType *incoming)
	{
		if(incoming!=data)
		{
			Clear();
			this->wid=wid;
			this->hei=hei;
			data=incoming;
		}
	}

	ComponentType *GetPixel(int x,int y)
	{
		return data+(wid*y+x)*NumComponentPerPixel;
	}
	const ComponentType *GetPixel(int x,int y) const
	{
		return data+(wid*y+x)*NumComponentPerPixel;
	}
	bool IsInRange(int x,int y) const
	{
		return (0<=x && x<wid && 0<=y && y<hei);
	}

	ComponentType *GetData(void)
	{
		return data;
	}
	const ComponentType *GetData(void) const
	{
		return data;
	}

	void CopyFrom(const SimpleBitmapTemplate<ComponentType,NumComponentPerPixel> &incoming)
	{
		if(this!=&incoming)
		{
			Create(incoming.wid,incoming.hei);
			memcpy(this->data,incoming.data,sizeof(ComponentType)*incoming.wid*incoming.hei*NumComponentPerPixel);
			// memcpy does the same thing as:
			//for(int i=0; i<incoming.wid*incoming.hei*NumComponentPerPixel; ++i)
			//{
			//	this->data[i]=incoming.data[i];
			//}
		}
	}
	void MoveFrom(SimpleBitmapTemplate<ComponentType,NumComponentPerPixel> &incoming)
	{
		if(this!=&incoming)
		{
			Clear();
			this->wid=incoming.wid;
			this->hei=incoming.hei;
			this->data=incoming.data;
			incoming.wid=0;
			incoming.hei=0;
			incoming.data=nullptr;
		}
	}

	void Invert(void)
	{
		for(int y=0; y<hei/2; ++y)
		{
			auto line0=GetPixel(0,y);
			auto line1=GetPixel(0,hei-y-1);
			for(int x=0; x<wid*NumComponentPerPixel; ++x)
			{
				std::swap(line0[x],line1[x]);
			}
		}
	}



	// Returns true if incoming bitmap is same as this bitmap.
	bool IsEqualTo(const SimpleBitmapTemplate <ComponentType,NumComponentPerPixel> &incoming) const
	{
		if(wid!=incoming.wid || hei!=incoming.hei)
		{
			return false;
		}
		return 0==memcmp(data,incoming.data,sizeof(ComponentType)*NumComponentPerPixel*wid*hei);
	}



	// Complete this function.
	// To make a little bit easier for you, you DON'T have to make it safe for self-cutout.  (copyTo is same as this).
	void CutOut(SimpleBitmapTemplate <ComponentType,NumComponentPerPixel> &copyTo,int x0,int y0,int wid,int hei) const
	{
		// You need to run a double-loop, one for Y and the other for X.
		// If the pixel coordinate in the destination bitmap is (x,y), the pixel coordinate in the source (this) bitmap is
		// (x0+x,y0+y).  Copy pixel values if (x0+x,y0+y) is in range of this bitmap.  Otherwise, make all values in
		// the destination pixel zero.
		copyTo.Create(wid, hei);
		for(int i = 0; i < wid; ++i){
			for(int j = 0; j < hei; ++j){
				if(i >= this -> wid || j >= this -> hei)
					for(int k = 0; k < 4; ++k)
						*(copyTo.GetPixel(i, j) + k) = 0;
				else
					for(int k = 0; k < 4; ++k)
						*(copyTo.GetPixel(i, j) + k) = *(this -> GetPixel(x0 + i, y0 + j) + k);
			}
		}
	}
};

/*
	SimpleBitmapTemplate <unsigned char,4> bmp;
	bmp.Create(100,100);
*/

class RGBABitmap : public SimpleBitmapTemplate<unsigned char,4>
{
public:
	inline RGBABitmap(){}
	RGBABitmap(const RGBABitmap &incoming);
	RGBABitmap &operator=(const RGBABitmap &incoming);

	RGBABitmap(RGBABitmap &&incoming);
	RGBABitmap &operator=(RGBABitmap &&incoming);

	bool LoadPNG(std::string fileName);

	RGBABitmap CutOut(int x0,int y0,int wid,int hei) const;

	inline bool operator==(const RGBABitmap &incoming) const;
	inline bool operator!=(const RGBABitmap &incoming) const;
};

// Complete this function.  You can use IsEqualTo function defined in the base class.
inline bool RGBABitmap::operator==(const RGBABitmap &incoming) const
{
	
	return this -> IsEqualTo(incoming);
}

// Complete this function.  You can use IsEqualTo function defined in the base class.
inline bool RGBABitmap::operator!=(const RGBABitmap &incoming) const
{
	return !this -> IsEqualTo(incoming);
}

// Complete this function so that you can use RGBABitmaps as a hash key.
template<>   // Begin template specialization
struct std::hash<class RGBABitmap>
{
    // std::size_t is by default a 64-bit unsigned integer.
    std::size_t operator()(const RGBABitmap & key) const
    {
		std::size_t code=0;
		for(int i = 0; i < key.GetWidth() * key.GetHeight() * 4; ++i){
			switch (i%5)
			{
			case 0:
				code += *(key.GetData() + i) * 2;
				break;
			case 1:
				code += *(key.GetData() + i) * 3;
				break;
			case 2:
				code += *(key.GetData() + i) * 5;
				break;
			case 3:
				code += *(key.GetData() + i) * 7;
				break;
			case 4:
				code += *(key.GetData() + i) * 11;
				break;
			default:
				break;
			}
		}
        return code;
    }
};

#endif
