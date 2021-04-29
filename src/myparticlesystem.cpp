// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "myparticlesystem.h"

using namespace std;
using namespace agl;
using namespace glm;

void MyParticleSystem::createParticles(int size) 
{
   mTexture = theRenderer.loadTexture("../textures/ParticleCloudBlack.png");
   mBlendMode = ALPHA;
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   default_random_engine generator (seed);
   normal_distribution<double> distribution (0.0,1.0);

   vec3 start = vec3(0.0,-1.0,0.0);
   vec4 color = vec4(0.28f, 0.25f, 0.35f, 1.0);

   for(int i = 0; i < size; i++) {

      // generate random velocity
      float vx = (float) distribution(generator)*0.1;
      float vy = (float) (distribution(generator)*0.1 + 0.7);
      float vz = (float) distribution(generator)*0.1;
      
      vec3 vel = vec3(vx,vy,vz);

      // start particles in groups below screen to avoid initial "puff"
      float initial = -1.2f;
      float inc = -0.2f;
      int groups = 8;

      for(int j = 0; j < groups; j++) {
         if(i % groups == j) {
            start = vec3(0.0, initial + j*inc, 0.0);
         }
      }
      
      Particle par = {start, vel, color, 0.1f, 1.0f};
      mParticles.push_back(par);
   }
}

void MyParticleSystem::update(float dt)
{
   // update particles
   for(int i = 0; i < mParticles.size(); i++) {

      Particle p = mParticles[i];
      vec3 pos = p.pos;

      // if below screen, only modify y position
      if(pos.y < -1.0) {
         pos.y = pos.y + dt * p.vel.y;
         p.pos = pos;
         mParticles[i] = p;
         continue;
      }

      vec4 color = p.color;
      float size = p.size;

      pos = pos + dt * p.vel;
      size += 0.0025;

      float transparency = color[3];
      transparency -= 0.005;
      color[3] = transparency;

      // if particle reaches top, restart at bottom and reset
      if(pos.y > 1.0f) {
         pos.y = -1.0f;
         pos.x = 0.0f;
         pos.z = 0.0f;
         color[3] = 1.0f;
         size = 0.1f;
      }
      
      p.pos = pos;
      p.color = color;
      p.size = size;
      mParticles[i] = p;
   }

   // sorts based on z position using anonymous function
   std::sort(mParticles.begin(), mParticles.end(), [](const Particle& lhs, const Particle& rhs) {
      return lhs.pos.z < rhs.pos.z;
   });
}

