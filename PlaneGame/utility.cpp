#include "stdafx.h"

#include "utility.h"
#include <cstdlib>

//Dir c2d(char c)
//{
//	c = tolower(c);
//	switch (c)
//	{
//		case 'a': return LEFT;
//		case 'd': return RIGHT;
//		case 's': return DOWN;
//		case 'w': return UP;
//		default: return NODIR;
//	}
//}

//��[a, b)֮�����һ���������
int random(int a, int b)
{
	return (rand() % (a - b)) + a;
}

void make_transparent(CImage &img)
{
	for (int i = 0; i < img.GetWidth(); i++)
	{
		for (int j = 0; j < img.GetHeight(); j++)
		{
			unsigned char* pucColor = reinterpret_cast<unsigned char *>(img.GetPixelAddress(i, j));
			pucColor[0] = (pucColor[0] * pucColor[3] + 127) / 255;
			pucColor[1] = (pucColor[1] * pucColor[3] + 127) / 255;
			pucColor[2] = (pucColor[2] * pucColor[3] + 127) / 255;
		}
	}
}