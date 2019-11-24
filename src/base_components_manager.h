#ifndef BASECOMPONENTMANAGER_H
#define BASECOMPONENTMANAGER_H

#include<map>
#include<string>
#include<memory>
#include"base_component.h"

class BaseComponentsManager
{
 public:
  static BaseComponentsManager& getManager() { //singleton
    static BaseComponentsManager manager;
    return manager;
  }
  BaseComponentsManager(BaseComponentsManager const&) = delete;
  void operator=(BaseComponentsManager const&)        = delete;

 private:
  BaseComponentsManager();
  std::map<std::string,  const std::unique_ptr<BaseComponent>> component_map_;
};

#endif // BASECOMPONENTMANAGER_H
