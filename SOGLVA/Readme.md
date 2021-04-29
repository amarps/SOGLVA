common:
	nuklearImport.h : simplify nuklear import
	standard.h		: define standard library

components:
	Graphics:
		-
	Camera
	Transform

EventHandler:
	event



workflow:

	SOGLVA	- RenderingSystem: ISystem
			- UISystem		 : ISystem
			- SceneSystem	 : ISystem

