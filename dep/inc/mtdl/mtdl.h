#pragma once

namespace mtdl {

	/*---TYPES---*/
	
	struct Vector2 {		//Vector 2D
		int x;
		int y;

		Vector2(int _x, int _y) : x(_x), y(_y) {}
	}; 

	struct Rect {			//Rectangle
		Vector2 position;
		int w;
		int h;

		Rect(int _x, int _y, int _w, int _h) : position.x(_x), position.y(_y), w(_w), h(_h){}
	};


	/*---FUNCTIONS---*/

	bool VectorRectCollision(Vector2 v, Rect r) {
		return (v.x >= r.position.x) && (v.x <= (r.position.x + r.w)) && (v.y >= r.position.y) && (v.y <= (r.position.y + r.h));
	}

	bool RectRectCollision(Rect r, Rect t) {
		return VectorRectCollision(r.position, t) || VectorRectCollision(new Vector2(r.position.x + r.w, r.position.y), t) || VectorRectCollision(new Vector2(r.position.x, r.position.y + r.h), t) || VectorRectCollision(new Vector2(r.position.x + r.w, r.position.y + r.h) + r.w, t);
	}
}