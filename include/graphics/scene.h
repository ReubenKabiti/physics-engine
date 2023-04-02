#pragma once

/*! \brief abstract class from which all scenes inherit from */
class Scene
{
public:
	virtual ~Scene() {}

	/*! initializes the scene */
	virtual void onCreate() {}
	/*! updates the scene every physical timestep
	 * @param delta the delta time (time since last frame) [fixed]
	 */
	virtual void onUpdate(float delta) {}
	/*! called everyframe */
	virtual void onRender() {}
	/*! called when the object is destroyed */
	virtual void onDestroy() {}
};
