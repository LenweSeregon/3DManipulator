#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <vector>

#include "scene_interface.h"
#include "gui.h"
#include "Object3D.hpp"
#include "Camera.hpp"

namespace application
{
  class Scene : public SceneInterface
  {

  private:

    Camera camera;
    gui::Gui* gui;
    std::vector<Object3D> objs;

  public:

    Scene();
    ~Scene();

    void AddObjs(Object3D obj);
    geometry::Point<float,3> PerspectiveProjection(const geometry::Point<float,4>& point) const;
    geometry::Point<float,3> Perspective(const geometry::Point<float,4>& point) const;

    void LoadGeoFile(std::string filename);
    void Start();
    
    virtual void draw() const override;
    void draw_object(const Object3D& obj) const;
    void draw_wire_triangle(const geometry::Triangle<float,3>& triangle) const;
    void draw_edge(const geometry::Point<float,4>& p1, const geometry::Point<float,4>& p2, gui::Color c) const;

    virtual void press_up() override;
    virtual void press_down() override;
    virtual void press_left() override;
    virtual void press_right() override;
    virtual void press_space() override;
    virtual void press_w() override;
    virtual void press_s() override;
    virtual void press_a() override;
    virtual void press_d() override;
    virtual void press_q() override;
    virtual void press_e() override;
    virtual void press_z() override;
    virtual void press_x() override;

    virtual void release_updown() override;
    virtual void release_leftright() override;
    virtual void release_space() override;
    virtual void release_ws() override;
    virtual void release_ad() override;
    virtual void release_qe() override;
    virtual void release_zx() override;

    virtual void update() override;
  };
}

#endif
