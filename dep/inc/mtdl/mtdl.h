#pragma once
#include <string>

namespace mtdl {

	/*---TYPES---*/
	#pragma region Types

	struct Vector2 {		//Vector 2D
		int x;
		int y;

		Vector2() {}
		Vector2(int _x, int _y) {
			x = _x;
			y = _y;
		}
	};

	struct Rect {			//Rectangle
		Vector2 position;
		int w;
		int h;

		Rect() {}
		Rect(int _x, int _y, int _w, int _h) {
			position.x = _x;
			position.y = _y;
			w = _w;
			h = _h;
		}
	};

	struct Color			//Color
	{
		Uint8 r;
		Uint8 g;
		Uint8 b;
		Uint8 a;

		Color() {}
		Color(Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a) {
			r = _r;
			g = _g;
			b = _b;
			a = _a;
		}
	};

	struct Font				//Font
	{
		std::string path;
		int size;
		std::string id;

		Font() {}
		Font(std::string _path, int _size, std::string _id) {
			path = _path;
			size = _size;
			id = _id;
		}
	};

	struct Text				//Text
	{
		std::string text;
		Color color;
		std::string id;

		Text() {}
		Text(std::string _text, Color _color, int _id) {
			text = _text;
			color = _color;
			id = _id;
		}
	};
	#pragma endregion

	/*---FUNCTIONS---*/
	#pragma region Functions
	bool VectorRectCollision(Vector2 v, Rect r) {
		return (v.x >= r.position.x) && (v.x <= (r.position.x + r.w)) && (v.y >= r.position.y) && (v.y <= (r.position.y + r.h));
	}

	bool RectRectCollision(Rect r, Rect t) {
		Vector2 topRight(r.position.x + r.w, r.position.y);
		Vector2 botLeft(r.position.x, r.position.y + r.h);
		Vector2 botRight(r.position.x + r.w, r.position.y + r.h);
		return VectorRectCollision(r.position, t) || VectorRectCollision(topRight, t) || VectorRectCollision(botLeft, t) || VectorRectCollision(botRight, t);
	}
	#pragma endregion

}