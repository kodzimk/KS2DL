#pragma once
#ifndef COLOR_H
#define COLOR_H

namespace kl
{
	class Color
	{
	public:
		Color() = default;
		Color(float r, float g, float b,float a = 1.0f);
	public:
		static const Color Red() { return Color(255, 0, 0); }
		static const Color Green() { return Color(0, 255, 0); }
		static const Color Blue() { return Color(0, 0, 255); }
		static const Color Black() { return Color(0, 0, 0); }
		static const Color White() { return Color(255, 255, 255); }
		static const Color Yellow() { return Color(255, 255, 0); }
		static const Color Magenta() { return Color(255, 0, 144); }
		static const Color Cyan() { return Color(0, 183, 255); }
		static const Color Transperant() { return Color(255, 255, 255,0.0f); }

		float r;
		float b;
		float g;
		float a;
	};
}
#endif