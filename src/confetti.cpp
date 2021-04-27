// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "confetti.h"

using namespace std;
using namespace agl;
using namespace glm;

void Confetti::createParticles(int size) 
{
   mTexture = theRenderer.loadTexture("../textures/particle.png");
   for(int i = 0; i < size; i++) {
      Particle par = {random_unit_cube(), random_unit_vector()*0.5f, vec4(random_unit_vector(), random_float()), 0.25f, 1.0f};
      mParticles.push_back(par);
   }
}

void Confetti::update(float dt)
{
  // update particles
  for(int i = 0; i < mParticles.size(); i++) {
    Particle p = mParticles[i];
    vec3 pos = p.pos;
    vec3 vel = p.vel;
    pos = pos + dt * vel;

    //reflect velocity if out of bounds
    if(pos.x > 1.0f) {
      pos.x = 1.0f;
      vel.x = -vel.x;
    }
    if(pos.x < -1.0f) {
      pos.x = -1.0f;
      vel.x = -vel.x;
    }
    if(pos.y > 1.0f) {
      pos.y = 1.0f;
      vel.y = -vel.y;
    }
    if(pos.y < -1.0f) {
      pos.y = -1.0f;
      vel.y = -vel.y;
    }
    if(pos.z > 1.0f) {
      pos.z = 1.0f;
      vel.z = -vel.z;
    }
    if(pos.z < -1.0f) {
      pos.z = -1.0f;
      vel.z = -vel.z;
    }
    p.pos = pos;
    p.vel = vel;
    mParticles[i] = p;
  }

  // sorts based on z position using anonymous function
  std::sort(mParticles.begin(), mParticles.end(), [](const Particle& lhs, const Particle& rhs) {
    return lhs.pos.z < rhs.pos.z;
  });

  // cheap sort
  /*
    if(mParticles.size() > 1) {
      Particle pPrev = mParticles[0];
      for(int i = 1; i < mParticles.size(); i++) {
          Particle p = mParticles[i];
          float d2 = distance(theRenderer.cameraPosition(), p.pos);
          float d1 = distance(theRenderer.cameraPosition(), pPrev.pos);
          if(d2 > d1) {
            swap(mParticles[i], mParticles[i-1]);
          }
          pPrev = mParticles[i];
      }
    }*/
}


