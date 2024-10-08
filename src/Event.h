#pragma once
#ifndef EVENT_H
#define EVENT_H

namespace kl
{
	enum EventType
	{
		None = -1,
		KeyPressed,
		KeyReleased,
		KeyRepeated,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseButtonRepeated,
		MouseMoved,
		MouseWheelScroll,
		Resized
	};
	class MousePos
	{
	public:
		double x, y;
		EventType type = EventType::None;
	public:
		MousePos()
		{
			x = -1.0f;
			y = -1.0f;
		}

		void update(double x, double y)
		{
			this->x = x;
			this->y = y;
			type = EventType::MouseMoved;
		}
	};
	class MouseWheel
	{
	public:
		float delta;
		EventType type = EventType::None;
	public:
		MouseWheel()
		{
			delta = 1.0f;
		}

		void update(double x, double y)
		{
			delta += y;
			type = EventType::MouseWheelScroll;
		}
	};
	class MouseButton
	{
	public:
		EventType type;
	public:
		MouseButton()
		{
			type = EventType::None;
		}
	private:
		void update(int key, int mode)
		{
			switch (mode)
			{
			case 0: this->type = EventType::MouseButtonReleased; break;
			case 1: this->type = EventType::MouseButtonPressed; break;
			case 2: this->type = EventType::MouseButtonRepeated; break;
			default:this->type = EventType::None; break;
			}
		}

		friend class Window;
	};
    class Keyboard
	 {
	 public:
		 int key;
		 EventType type;
	 public:
		 Keyboard()
		 {
			 type = EventType::None;
			 key = -1;
		 }
		 void update(int key, int mode)
		 {
			 this->key = key;

			 switch (mode)
			 {
			  case 0: this->type = EventType::KeyReleased; break;
			  case 1: this->type = EventType::KeyPressed; break;
			  case 2: this->type = EventType::KeyRepeated; break;
			  default:this->type = EventType::None; break;
			 }
		 }

		 friend class Window;
	 };
	class Event
	 {
	  public:
		Event() = default;
		~Event()
		{

		}
		void clear()
		{
			keyboard.key = -1;
			type = EventType::None;
			keyboard.type = EventType::None;
			mouseMoved.type = EventType::None;
			mouseWheel.type = EventType::None;
			mouse.type = EventType::None;
		}
	  public:
		Keyboard keyboard;
		MouseButton mouse;
		MousePos mouseMoved;
		MouseWheel mouseWheel;
		EventType type = EventType::None;
	 };
}
#endif