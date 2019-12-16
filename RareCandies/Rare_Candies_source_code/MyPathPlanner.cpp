#include "MyPathPlanner.h"
#include "MyGame.h"

using namespace mathtool;

namespace GMUCS425
{

MyPathPlanner::MyPathPlanner(MyScene * scene, MyAgent * agent)
{
  m_scene=scene;
  m_agent=agent;
}

//TODO: shorten and smooth the path (Bonus: 20 pts)
//To smooth, use Quadratic Bezier curves
void MyPathPlanner::smooth(std::list<Point2d>& path)
{
  //path is both input and output
}

//TODO: (20 pts)
//return true if m_agent collide with a non-movable object
//at a given location
bool MyPathPlanner::collision_detection(const Point2d& pos)
{
  //brute force collision detection

  //methods to use: collide(), getX(), getY(), tranlateTo() in MyAgent
  //get_agents() in MyScene

  return false;
}

//estimate the cost of travelling from pos1 to pos2
//scaled using the values generated by Perlin noise
float MyPathPlanner::cost(const Point2d& pos1, const Point2d& pos2)
{
  const Uint32 * terrain = m_scene->get_terrain();
  int terrain_width = getMyGame()->getScreenWidth();
  int terrain_height = getMyGame()->getScreenHeight();

  float scale=1;
  //the scale should be larger than 1
  //estimate the scale here, if the terrain value is 0, the scale should be 1
  //if the terrain value is high, the scale should be larger

  return scale * (pos1-pos2).norm(); //scale this by the value in terrain
}

//------------
//TODO: (30 pts)
bool MyGridPathPlanner::build() //build a grid
{
  if(!m_grid.empty()) return false; //build only if the grid is empty

  m_grid=std::vector< std::vector<Node> >( m_height, std::vector<Node>(m_width,Node()) );
  float cell_w=getMyGame()->getScreenWidth()*1.0f/m_width;
  float cell_h=getMyGame()->getScreenHeight()*1.0f/m_height;

  //TODO: go through the nodes, and init the data for each node
  for(int i=0;i<m_height;i++)
  {
    for(int j=0;j<m_width;j++)
    {
      Node & n=m_grid[i][j];
      //determine the values of n.pos, n.free and n.neighbors

    }//end j
  }//end i

  return true;
}

//finding a path using A*
bool MyGridPathPlanner::find_path( const Point2d& start, const Point2d& goal, std::list<Point2d>& path )
{
  //check if the start and goal are valid (i.e., inside the screen)
  if(start[0]<0 || start[1]>=getMyGame()->getScreenWidth()) return false;
  if(goal[0]<0 || goal[1]>=getMyGame()->getScreenWidth()) return false;

  float cell_w=getMyGame()->getScreenWidth()*1.0f/m_width;
  float cell_h=getMyGame()->getScreenHeight()*1.0f/m_height;

  vector<Node *> open, close;
  Node * S=&m_grid[(int)(start[1]/cell_h)][(int)(start[0]/cell_w)];
  Node * G=&m_grid[(int)(goal[1]/cell_h)][(int)(goal[0]/cell_w)];
  if(!S->free) cerr<<"! Error: Start point makes the agent collide with something"<<endl;
  if(!G->free) cerr<<"! Error: Goal point makes the agent collide with something"<<endl;
  bool found = true;

  //dummy path planning, replace the following two lines with A*
  path.push_front(goal);
  path.push_front(start);

  return found;
}

}//end namespace GMUCS425
