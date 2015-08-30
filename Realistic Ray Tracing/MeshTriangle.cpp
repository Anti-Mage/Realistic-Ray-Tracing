#include "Mesh.h"
#include "MeshTriangle.h"


MeshTriangleUV::MeshTriangleUV(){}


MeshTriangleUV::~MeshTriangleUV(){}

MeshTriangleUV::MeshTriangleUV(Mesh* _mesh, int p0, int p1, int p2, int index):mesh_ptr(_mesh){
	p[0] = p0;
	p[1] = p1;
	p[2] = p2;
}
bool MeshTriangleUV::hit(const Ray& r, float tmin, float tmax, float time, HitRecord& rec) const{
	Vector3 p0((mesh_ptr->vertUVs[p[0]]).vertex);
	Vector3 p1((mesh_ptr->vertUVs[p[1]]).vertex);
	Vector3 p2((mesh_ptr->vertUVs[p[2]]).vertex);

	float tval;

	float A = p0.x() - p1.x();
	float B = p0.y() - p1.y();
	float C = p0.z() - p1.z();

	float D = p0.x() - p2.x();
	float E = p0.y() - p2.y();
	float F = p0.z() - p2.z();

	float G = r.direction().x();
	float H = r.direction().y();
	float I = r.direction().z();

	float J = p0.x() - r.origin().x();
	float K = p0.y() - r.origin().y();
	float L = p0.z() - r.origin().z();

	float EIHF = E*I - H*F;
	float GFDI = G*F - D*I;
	float DHEG = D*H - E*G;

	float denom = (A*EIHF + B*GFDI + C*DHEG);
	float beta = (J*EIHF + K*GFDI + L* DHEG) / denom;

	if (beta <= 0.0f || beta >= 1.0f)
		return false;

	float AKJB = A*K - J*B;
	float JCAL = J*C - A*L;
	float BLKC = B*L - K*C;

	float gamma = (I*AKJB + H*JCAL + G*BLKC) / denom;
	if (gamma <= 0.0f || beta + gamma >= 1.0f)
		return false;

	tval = -(F*AKJB + H*JCAL + D*BLKC) / denom;
	if (tval >= tmin && tval <= tmax){
		double alpha = 1.0 - beta - gamma;
		Vector2 u0((mesh_ptr->vertUVs[p[0]]).uv);
		Vector2 u1((mesh_ptr->vertUVs[p[1]]).uv);
		Vector2 u2((mesh_ptr->vertUVs[p[2]]).uv);

		rec.uv = Vector2(alpha*u0.x() + beta*u1.x() + gamma * u2.x(), alpha*u0.y() + beta*u1.y() + gamma * u2.y());
		rec.hit_tex = mesh_ptr->getTexture();
		rec.t = tval;
		rec.normal = unitVector(cross((p1 - p0), (p2 - p0)));

		return true;
	}
	return false;
}
bool MeshTriangleUV::shadowHit(const Ray& r, float tmin, float tmax, float time) const{
	Vector3 p0((mesh_ptr->vertUVs[p[0]]).vertex);
	Vector3 p1((mesh_ptr->vertUVs[p[1]]).vertex);
	Vector3 p2((mesh_ptr->vertUVs[p[2]]).vertex);

	float tval;

	float A = p0.x() - p1.x();
	float B = p0.y() - p1.y();
	float C = p0.z() - p1.z();

	float D = p0.x() - p2.x();
	float E = p0.y() - p2.y();
	float F = p0.z() - p2.z();

	float G = r.direction().x();
	float H = r.direction().y();
	float I = r.direction().z();

	float J = p0.x() - r.origin().x();
	float K = p0.y() - r.origin().y();
	float L = p0.z() - r.origin().z();

	float EIHF = E*I - H*F;
	float GFDI = G*F - D*I;
	float DHEG = D*H - E*G;

	float denom = (A*EIHF + B*GFDI + C*DHEG);
	float beta = (J*EIHF + K*GFDI + L* DHEG) / denom;

	if (beta <= 0.0f || beta >= 1.0f)
		return false;

	float AKJB = A*K - J*B;
	float JCAL = J*C - A*L;
	float BLKC = B*L - K*C;

	float gamma = (I*AKJB + H*JCAL + G*BLKC) / denom;
	if (gamma <= 0.0f || beta + gamma >= 1.0f)
		return false;

	tval = -(F*AKJB + H*JCAL + D*BLKC) / denom;

	return (tval >= tmin && tval <= tmax);
}
