#pragma once

class Scene
{
public:
	virtual ~Scene() {}

	virtual void onCreate() {}
	virtual void onUpdate(float delta) {}
	virtual void onRender() {}
	virtual void onDestroy() {}
};
