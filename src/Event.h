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
		KeyRepeated
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
	  public:
		Keyboard keyboard;
		EventType type = EventType::None;
	 };
}
#endif