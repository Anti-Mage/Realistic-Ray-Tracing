#ifndef __ONB_H__
#define __ONB_H__

#include "Vector3.h"

class ONB
{
public:
	Vector3 U, V, W;
public:
	ONB(){}
	~ONB(){}
	ONB(const Vector3& a, const Vector3& b, const Vector3& c){
		U = a;
		V = b;
		W = c;
	}

	void initFromU(const Vector3& u);
	void initFromV(const Vector3& v);
	void initFromW(const Vector3& w);

	void set(const Vector3& a, const Vector3& b, const Vector3& c){
		U = a;
		V = b;
		W = c;
	}

	void initFromUV(const Vector3& u, const Vector3& v);
	void initFromVU(const Vector3& v, const Vector3& u);

	void initFromUW(const Vector3& u, const Vector3& w);
	void initFromWU(const Vector3& w, const Vector3& u);

	void initFromVW(const Vector3& v, const Vector3& w);
	void initFromWV(const Vector3& w, const Vector3& v);

	friend std::istream& operator>>(std::istream& is, ONB& t);
	friend std::ostream& operator<<(std::ostream& os, const ONB& t);
	friend bool operator==(const ONB& o1, const ONB& o2);

	Vector3 u() const { return U; }
	Vector3 v() const { return V; }
	Vector3 w() const { return W; }
};


#endif