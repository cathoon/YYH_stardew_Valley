#pragma once

struct tagClockHand
{
	POINT center;		//중점
	POINT end;			//시계침 끝점
	int length;			//시계침 길이
	float angle;		//시계침 각도
	int count;			//시계 카운트
	int value;			//시계 값(현재 시계침의 위치)
};

class Environment : public singletonBase<Environment>
{
private:
	Environment() {};

	tagClockHand _clockHand;	//시계침 struct

	int _alphaValue;			//알파값

	int _monthCount;			//월
	int _dayOfWeek;				//요일
	int _dayCount;				//일
	int _hour;					//시간
	int _minute;				//분

	float _timeRatio;			//시계 한 칸 퍼센트

	float _clockCalculate;		//시간 계산

	float _elapsedTime;			//연산용 시간
	float _realTimeSecond;		//현실시간(초)

	bool _isInventoryOpen;		//인벤토리가 열리면
	bool _isDayIncrease;		//날짜가 증가하면

	bool _isDayReset;

	bool _timeOut;

	float _delay;
	float _count;

	bool timeUpdate(const float count)
	{
		_count += count;
		if (_count >= _delay)
		{
			_count -= _delay;
			return true;
		}
		return false;
	}

public:
	~Environment() {};

	HRESULT init();
	void release();
	void update();
	void render(HDC _hdc);

	static Environment* GetInstance()
	{
		static Environment* _env;
		if (!_env)
		{
			_env = new Environment;
			return _env;
		}
		else return _env;
	}

	int GetCluckValue() { return _clockHand.value; }				//시계 값
	int GetDayCount() { return _dayCount; }							//날짜 값
	int GetHour() { return _hour; }
	bool GetIsDayIncrease() { return _isDayIncrease; }				//날짜가 증가하면
	bool GetIsInventoryOpen() { return _isInventoryOpen; }			//인벤토리가 열리면
	bool GetTimeOut() { return _timeOut; }
	void SetIsInventoryOpen(bool open) { _isInventoryOpen = open; }	//인벤토리용
	void SetIsDayReset(bool reset) { _isDayReset = reset; }			//날짜 넘기기
	void SetHour(int hour) { _hour = hour; }
	void SetMinute(int minute) { _minute = minute; }
};

