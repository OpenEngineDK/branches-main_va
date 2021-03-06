// Box.
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _BOUNDING_BOX_H_
#define _BOUNDING_BOX_H_

#include <Geometry/FaceSet.h>
#include <Geometry/BoundingGeometry.h>
#include <string>
#include <vector>

namespace OpenEngine {
namespace Geometry {

using OpenEngine::Math::Vector;
using std::vector;

/**
 * Bounding geometry box.
 *
 * @class Box Box.h Geometry/Box.h
 */
class Box : public BoundingGeometry {

friend class Geometry;
    
private:
    Vector<3,float> center;     //!< Box center
    Vector<3,float> corner;     //!< Box corner (relative)
    Vector<3,float> corners[8]; //!< Box corners (absolute)

    void SetCorner(const bool x, const bool y, const bool z, Vector<3,float> c);

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & center;
        ar & corner;
        ar & corners;
    }


public:
    Box() {}; // empty constructor for serialization

    explicit Box(FaceSet& faces);
    
    Vector<3,float> GetCenter() const;
    Vector<3,float> GetCorner() const;
    Vector<3,float> GetCorner(const int index) const;
    Vector<3,float> GetCorner(const bool signX, const bool signY, const bool signZ) const;

    bool Intersects(const Vector<3,float> point) const;
    bool Intersects(const Line line) const;
    bool Intersects(const Plane plane) const;

};

} //NS Common
} //NS OpenEngine

#endif
