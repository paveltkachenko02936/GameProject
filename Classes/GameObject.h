class GameObject
{
public:
	virtual void move(float dx, float dy) = 0;
	virtual void capture(bool value) = 0;
};